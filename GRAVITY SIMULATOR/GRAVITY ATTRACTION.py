#!/usr/bin/env python
# coding: utf-8

# In[3]:




import numpy as np
from sklearn.linear_model import LinearRegression as Lm
from tkinter import *
import random
import time
import math
import cmath
pi = math.pi

def create_circle(x, y, r, canvasName,clr): #center coordinates, radius
    x0 = x - r
    y0 = y - r
    x1 = x + r
    y1 = y + r
    return canvasName.create_oval(x0, y0, x1, y1,fill=clr)

def cn(i,j):
    return cmath.rect(i,j)

def vect(i,j,k,l):
    return [complex((k-i),(l-j)),complex((k-i),(l-j))/abs(complex((k-i),(l-j)))]

def stat_pnts(tmp_pnt,cns):
    for i in tmp_pnt:
        create_circle(i[0],i[1],18,cns,'red')
#         cns.update()
        
def move_pnts(tmp_pnt,cns):
    #print(tmp_pnt,'\n')
    for i in tmp_pnt:
        create_circle(i[0],i[1],2.8,cns,'blue')   
#         cns.update()
        
        
def movecrsr_pnts(tmp_pnt,cns):
    for i in tmp_pnt:
        create_circle(i[0],i[1],3,cns,'green')   
       
        

def srt_vect(mp,mv_nt,length):
    temp = []
    mv_nt[abs(mv_nt)< .95 ][:]=0
    for i,j in zip(mp,mv_nt*length):
        temp.append([i[0]-j.real,i[1]-j.imag])
    return temp    
        
   
    
    

def net_vctr(fp,mp,fw,mw,period):
    fp,mp=np.array(fp),np.array(mp)
    mv_nt = np.array([])
    for i,l in zip(mp,mw):
        te = np.array([])
        for j,k in zip(fp,fw):
            if abs(complex((i-j)[0],(i-j)[1])) < 5:
                te = np.append(te,complex(0,0))
                continue
            te = np.append(te,(complex((i-j)[0],(i-j)[1])* (l*k)/(abs( complex((i-j)[0],(i-j)[1]) ) )**3 ))
        mv_nt = np.append(mv_nt,np.sum(te))  
    scaler = np.interp(abs(mv_nt),(abs(mv_nt).min(),abs(mv_nt).max()),(1,period)).astype(int)
    
    return srt_vect(mp,mv_nt/abs(mv_nt),scaler)
    


root = Tk()
root.title('GRAVITY SIMULATION')
wv = root.winfo_screenwidth()
wh = root.winfo_screenheight()
root.geometry(str(wv)+'x'+str(wh)+'+0+0')
myCanvas = Canvas(root,height=int(wh),width=int(wv))
myCanvas.pack()


def motion1(event):
    global mw,mp,ans 
    x, y = event.x, event.y
    ans=np.vstack([ans,[x,y]])
    mw=np.append(mw,5)
  

root.bind('<Button 1>', motion1)


def motion2(event):
    global fw,fp
    x, y = event.x, event.y
    fp=np.vstack([fp,[x,y]])
    fw=np.append(fw,5)
root.bind('<Button 3>', motion2)



def motion(event):
    global movecrsr,p
    if p!=1:
        return
    x, y = event.x, event.y
    movecrsr=np.array([x,y])

root.bind('<Motion>', motion)


def release(event):
    global p
    p*=-1
    
root.bind('<Button-2>',release)    

elmnts = 500

mw = np.array([random.randint(1,1200) for i in range(elmnts)])
mp = np.array([ np.array([random.randint(0,1500),random.randint(0,1000)]) for i in range(elmnts) ])

fw = np.array([21,2])
fp = np.array([[200,400],[800,400]])

ans = np.copy(mp)

movecrsr = np.array([])

sleeptime=.00001

p =-1
for i in range(100000):
    myCanvas.update()
    myCanvas.delete('all')
    move_pnts(ans,myCanvas)
    stat_pnts(fp,myCanvas)
    ans1=np.copy([movecrsr])
    
    if len(movecrsr)!=0 and p==1 :
        for i in range(20000):      
            movecrsr_pnts(ans1,myCanvas)
            temp = net_vctr(fp,ans1,fw,[6],15)
            if np.any(abs(fp-temp)<8):
                break
            ans1[0] = np.copy(temp[0])

    ans = net_vctr(fp,ans,fw,mw,4)
    
    #time.sleep(sleeptime)


print('iteration ended')



root.mainloop()


