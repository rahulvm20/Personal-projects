// This below c.Header file is in the same directory as the current file.
// It contains all used libraries and structures.
#include "library.cpp"



// A time delay function to delay processing time to make the experience more realistic
void delay(int number_of_seconds) {
    
    int milli_seconds = 1000 * number_of_seconds;
    
    clock_t start_time = clock();
    
    while (clock() < start_time + milli_seconds);
}



/*Linear_Search_Algorithm to access data of customers from multiple den 
  of databases */
int search_deck(char *str) {
    
    int z = 0;
    while(1) {
        if(strcmp(str, deck.store[z]) == 0) {
            return z;
        }
            z += 1;
    }

    return User.Id;
}



// Simple OTP generating function.
int generateOTP() {
    
    delay(600);
    
    srand(time(0));
    
    return ( rand() % 9999 );
}



/* A portal accessed only by officials to display account details 
    and order history of customers */
void display_details() {
    
    int q = 0;
    printf("\n**********************");
    
    while( q <= User.Id) {
        printf("\n%d\t%s", q, user[q].email);
        q += 1;
    }
    
    printf("\n**********************");

    int R;
    printf("\n\nEnter serial number : ");
    scanf("%d", &R);    

    printf("\nName     : %s", user[R].name);
    printf("\nEmail    : %s", user[R].email);
    printf("\nLocation : %s", user[R].qZoneNumber);
    
    printf("\n*********ORDER HISTORY*********");
    
    int x = 0;
    while(1) {
        
        if(user[R].count_arr[x] != 0) {
            printf("\n%s\t%0.2f X %d", user[R].final_order[x], user[R].cost_arr[x], user[R].count_arr[x]);
            x += 1;
        }
        
        else {
            break;
        }
    }
    
    printf("\n*******************************");
    printf("\nTotal amount : %0.2f\n\n", user[R].damount);

}



/* A decent password_validator with refutes and prompts to change 
    weak passwords to a medium/strong password */ 
int isValidPassword(char *str) {
    
    delay(600);
    
    int i, upperCase, lowerCase, specialChar;
    int digits, length = strlen(str);
    upperCase = lowerCase = specialChar = digits = 0; 

    if(length > 6) {
    
        for(i = 0; str[i]; ++i) {

            if(str[i] >= 'a' && str[i] <= 'z')
                ++lowerCase;

            else if(str[i] >= 'A' && str[i] <= 'Z')
                ++upperCase;

            else if(str[i] >= '0' && str[i] <= '9')
                ++digits;

            else
                ++specialChar;

            if(lowerCase > 0 && upperCase > 0 && digits > 0 && specialChar > 0) {
                return 1;
            }
        }


        if(upperCase && lowerCase && digits && specialChar)
            return 1;
        
        else if((lowerCase && digits) || (upperCase && specialChar) || (specialChar && digits))
            return 1;
        
        else {
            return 0;
        }
    }

    return 0;

}



/* A huge function to control ordering, payment, modifying etc.. 
    containing a bunch of functional goto functions */
void order_food(int h) {
    
    int serialno, count = 0, orderno = 0, items = 4;
    int offcount = 1, person = h, customer = 0, staff = 1, i = 0;
//here person is 0 if its a customer else 1 if its hotel staff

    float amount = 0;
    //user[User.Id].damount = 0;
    
    off[1].serialno = 1;
    off[1].code = 123456;
    off[1].discount = 40;


// Initialiser of starting food, cost..
    initial_menu: {
        
        x[1].foodno = 1;
        x[1].cost = 10;
        strcpy(x[1].food, "IDLI VADA");
        
        x[2].foodno = 2;
        x[2].cost = 20;
        strcpy(x[2].food, "MASALA DOSA");
        
        x[3].foodno = 3;
        x[3].cost = 30;
        strcpy(x[3].food, "VANGI BATH");
        
        x[4].foodno = 4;
        x[4].cost = 40;
        strcpy(x[4].food, "UTTHAPPA");
    }

    if(person == customer)
        goto cdef;
    
    else if(person == staff)
        goto sdef;


// Portal accessible by customers only to carry out ordering related stuffs..
    cdef:   {

        printf("\nENTER 0 TO SHOW THE MENU\nENTER 1 TO START/CONTINUE ORDERING\nENTER 2 TO DELETE ITEMS");
        printf("\nENTER 3 TO DISPLAY YOUR ITEMS\nENTER 4 TO APPLY OFFER COUPON\nENTER 5 TO PROCEED TO PAYMENT\n");
        printf("ENTER 6 TO QUIT\n\n : "); {
            
            int a;
            scanf("%d", &a);
            
            if(a == 0)
                goto menu;
            
            else if(a == 1)
                goto order;
            
            else if(a == 2)
                goto Delete;
            
            else if(a == 3)
                goto display;
            
            else if(a == 4)
                goto offer;
            
            else if(a == 5)
                goto payment;
            
            else if(a == 6) {

                printf("\n\n**** THANK YOU ****\n\n");
                goto refresh;
                conti:
                return;
            }

            else
                printf("\n----INVALID ENTERY----\n");
        }
        goto cdef;
    }



// Portal accessible to only officials to carry out modifications, assessing data
    sdef: {

        printf("\nENTER 1 TO MODIFY\nENTER 2 TO QUIT\nENTER 3 FOR DATA ACCESS\n : "); {
            
            int a;
            scanf("%d",&a);
            
            if(a == 1)
                goto moddef;
            
            else if(a == 2) {
                printf("\n**** THANK YOU ****\n");
                return;
            }

            else if(a == 3) {
                
                display_details();

            }

            else
                printf("\n----INVALID ENTERY----\n");
        }
        
        goto sdef;
    }

    

// To display the current updated menu    
    menu: {
            
        printf("\n*********MENU*******************\n");
        
        for(int i = 1; i <= items; i++) {
            
            printf(" %d\t%.2fRs\t\t%s\n", x[i].foodno, x[i].cost, x[i].food);
        
        }
        
        printf("********************************\n");
        
        if(person == customer)
            goto cdef;
        
        else if(person == staff)
            goto sdef;
    }


// Ordering portal to choose food required on basis of serial number..
    order: {
        
        printf("\nENTER THE SERIAL NUMBER OF ITEM YOU WANT TO ORDER\n : ");
        scanf("%d", &serialno);
        
        printf("\nENTER THE QUANTITY OF ITEM YOU WANT TO ORDER\n : ");
        scanf("%d", &count);
        
        
        x[serialno].mark = 1;
        amount = amount + x[serialno].cost * count;
        
        user[User.Id].damount = amount;
        x[serialno].count = x[serialno].count + count;

        strcpy(user[User.Id].final_order[i], x[serialno].food);
        user[User.Id].cost_arr[i] = x[serialno].cost;
        user[User.Id].count_arr[i] = x[serialno].count;
        i += 1;
        
        if(person == customer)
            goto cdef;
        
        else if(person == staff)
            goto sdef;
    }


// Offer coupons
    offer: {
        
        if(amount > 0) {
        
        printf("\nIF YOU HAVE ANY OFFER COUPON ENTER 1 ELSE 2 TO CONTINUE : "); {
            int a, b;
            scanf("%d", &a);
            
            if(a == 1) {
                
                printf("\nENTER OFFER CODE\n : ");
                scanf("%d", &b);

                for(int i = 1; i <= offcount; i++) {

                    if(b == off[offcount].code) {
                        
                        printf("\nOFFER APPLIED...\n");
                        user[User.Id].damount = amount - amount * (((float)off[offcount].discount)/100);
                        break;
                    }

                    else
                        printf("\nINVALID CODE...\n");
                }
            }
            
            else if(a == 2)
                goto display;
        }
    }
        
        else 
            printf("\nTHERE IS NO AMOUNT TO PAY...\n");
        
        
        if(person == customer)
            goto cdef;
        
        else if(person == staff)
            goto sdef;
    }

    

// UserFriendlyPayment portal to pay using various methods..
    payment: {
        
        if (user[User.Id].damount > 0) {
        
            int ch;
            printf("\n\n*** YOUR ITEMS ***\n");
        
            for(int i = 1; i <= items; i++) {
             
                if(x[i].mark == 1) {
                    printf(" %d\t%s\t%.2fRs X %d = %.2fRs\n",x[i].foodno,x[i].food, x[i].cost, x[i].count, (x[i].cost*x[i].count));
                }
            }
        
            printf("************\n");
            printf(" TOTAL AMOUNT:\t%.2fRs\n",amount);
        
            printf(" AMOUNT TO BE PAID:\t%.2fRs\n",user[User.Id].damount);
            printf("************\n\n");

            printf("\nSELECT PAYMENT OPTIONS\nENTER 1 FOR CASH ON DELIVERY\nENTER 2 FOR CREDIT CARD PAYMENT\n");
            printf("ENTER 3 FOR NETBANKING PAYMENT\nENTER 4 FOR MOBILE PAYMENT\nENTER 5 TO EXIT\n : ");
            scanf("%d", &ch);
        
            if(ch == 1) {
        

        delivery:
            
            delay(550);
            
            printf("\nORDER WILL BE DELIVERED TO %s IN ABOUT 15 MINUTES\n\n", user[User.Id].qZoneNumber);
            goto cdef;
    }


        else if(ch == 2) {
            
            long int cd_no;
            int mm, yy, cv, pc;
            
            delay(550);

            printf("\nAMOUNT TO BE PAID : \t%0.2fRs", user[User.Id].damount);
            printf("\nENTER CREDIT CARD NUMBER : ");
            scanf("%ld",&cd_no);
            
            printf("\nENTER EXPIRY DATE IN THE FORM MM YY : ");
            scanf("%d %d",&mm,&yy);
            
            printf("\nENTER CVC Code : ");
            scanf("%d", &cv);
        
        
        pay:
            
            printf("\nENTER 1 TO PAY AND 2 TO GO BACK : ");
            scanf("%d", &pc);
            
            if(pc == 1)   {

            printf("VALIDATING INFORMATION.......\n");
            delay(550);
            printf("PROCESSING......\n");
            delay(500);
            printf("*******\nPAYMENT SUCCESSFULL\n\n");
            goto delivery;

            }


            else if(pc == 2) {
                goto payment;
            }
        
            
            else {
                printf("\nINVALID OPTION!!!!!!!!!!");
                goto pay;
            }
        }
    
        
        else if(ch == 3) {
        
            char bank[20], bankid[20], bankpassword[20];
            printf("\nENTER BANK NAME: ");
            scanf("%s", bank);
        
            printf("REDIRECTING TO %s BANK......\n-----------------------\n",bank);
            
            delay(550);

            printf("ENTER BANK LOGIN DETAILS\nENTER LOGIN ID : ");
            scanf("%s", bankid);
        
            printf("ENTER PASSWORD : ");
            scanf("%s", bankpassword); 

            delay(550);

            printf("\nAMOUNT :\t%0.2fRs", user[User.Id].damount);
            printf("\nINTERNET CHARGE:\t 3Rs\n--------------------------");
            printf("\nTOTAL AMOUNT TO BE PAID:%0.2fRs", user[User.Id].damount+3);
            goto pay;
        }
        
        
        else if(ch == 4) {
            
            int chh,phonepin;
            long int phoneno;
        
        pay1:
            
            printf("\nCHOOSE METHOD OF PAYMENT\nENTER 1 FOR GPAY\nENTER 2 FOR PHONEPE\nENTER 3 FOR PAYTM\n : ");
            scanf("%d", &chh);
        
            if(chh == 1) {
                printf("REDIRECTING TO GOOGLEPAY\n");
                delay(550);
            }
        
            else if(chh == 2) {
                printf("REDIRECTING TO PHONEPE\n");
                delay(550);
            }
        
            else if(chh == 3) {
                printf("REDIRECTING TO PAYTM\n");
                delay(500);
            }
        
            else {
                printf("INVALID OPTION!!!!");
                goto pay1;
            }
        
            printf("\n------------------------");
            printf("\nTOTAL AMOUNT TO BE PAID : \t%0.2fRs", user[User.Id].damount);
        
            printf("\nENTER MOBILE NO : ");
            scanf("%ld",&phoneno);
        
            printf("ENTER PIN : ");
            scanf("%d",&phonepin);
            goto pay;

        }

    }
        
        else 
            printf("\nTHERE IS NO AMOUNT TO PAY...\n");
        
        if(person == customer)
            goto cdef;
        
        else if(person == staff) 
            goto sdef;
    }



// To display updated ordered list..
    display: {
        
        printf("\n\n*** YOUR ITEMS ***\n");
        for(int i = 1; i <= items; i++) {
            
            if(x[i].mark == 1) {
                
                printf(" %d\t%s\t%.2fRs X %d = %.2fRs\n",x[i].foodno,x[i].food, x[i].cost, x[i].count, (x[i].cost*x[i].count));

            }
        }

        printf("********\n");
        printf(" TOTAL AMOUNT : \t%.2fRs\n",amount);
        printf(" FINAL AMOUNT : \t%.2fRs\n", user[User.Id].damount);
        printf("********\n\n");

        if(person == customer)
            goto cdef;
        
        else if(person == staff)
            goto sdef;
    }



// To delete food items if required..
    Delete: {
        
        if(amount > 0) {

            printf("\nENTER SERIAL NUMBER OF ITEM YOU WANT TO REMOVE\n : "); {
            
            int a;
            scanf("%d", &a);
            
            if(a <= items) {
                amount = amount - (x[a].cost * x[a].count);
                user[User.Id].damount = amount;
                
                x[a].mark = 0;
                x[a].count = 0;

            }


            else
                printf("\nINVALID ENTRY...\n");
        
            }   
        }
        
        
        else 
            printf("\nTHERE ARE NO ITEMS TO BE DELETED...\n");

        
        if(person == customer)
            goto cdef;
        else if(person == staff)
            goto sdef;
    }



    moddef: {
        
        printf("\nENTER 1 TO DISPLAY MENU AND OFFER\nENTER 2 TO MODIFY\nENTER 3 TO GO TO MAIN MENU\n : "); {
        int a;
        scanf("%d", &a);
        
        if(a == 1)
            goto moddisplay;
        
        else if(a == 2)
            goto modify;
        
        else if(a == 3)
            goto sdef;
        }
    }



// Modification portal to add and delete items..
    modify: {

        printf("\nENTER 1 TO MODIFY MENU\nENTER 2 TO MODIFY OFFER COUPONS\n : "); {
        int a;//to store temporary value...
        scanf("%d", &a);
        
        if(a == 1) {
            
            int aa;//to store temporary value...
            printf("ENTER 1 TO DELETE MENU ITEMS\nENTER 2 TO ADD MENU ITEMS\n : ");
            scanf("%d",&aa);
            
            if(aa == 1) {
                
                if(items > 0) {
                    
                    printf("ENTER SERIAL NUMBER OF ITEM TO BE DELETED\n : ");
                    scanf("%d",&serialno);
                    for(int j = 1;j <= items; j++) {
                        if(x[j].foodno == serialno) {

                            for(int i = j; i < items; i++) {
                                strcpy(x[i].food, x[i+1].food);
                                x[i].foodno = x[i+1].foodno;
                                x[i].cost = x[i+1].cost;
                            }
                        }
                    }

                    strcpy(x[items].food, "");
                    x[items].cost = 0;
                    x[items].foodno = 0;

                    items--;
                        //myItems -= 1;
                }
                
                
                else 
                    printf("\nTHERE ARE NO ITEMS TO DELETE\n");

                }

            
            if(aa==2) {
                
                items++;
                printf("ENTER SERIAL NUMBER OF ITEM TO BE ADDED\n : ");
                scanf("%d",&x[items].foodno);
                
                printf("\nENTER NAME OF ITEM\n : ");
                scanf("%s", x[items].food);
                
                printf("\nENTER COST OF ITEM\n : ");
                scanf("%f",&x[items].cost);

            }

            printf("\n\n**************MENU**************\n");
            for(int i = 1; i <= items; i++) {
                
                printf(" %d\t%.2fRs\t\t%s\n", x[i].foodno, x[i].cost, x[i].food);
            
            }
            
            printf("***********************************\n\n");

        }
            
            
        else if(a == 2) {

            int aa;//to store temporary value...
            printf("\nENTER 1 TO DELETE OFFER COUPONS\nENTER 2 TO ADD OFFER COUPONS\n : ");
            scanf("%d", &aa);
            
            if(aa == 1) {
                        
                if(offcount > 0) {
                        
                    printf("\nENTER SERIAL NUMBER OF OFFER COUPON TO BE DELETED...\n : ");
                    scanf("%d", &serialno);
                        
                    for(int i = 1; i <= offcount; i++) {
                        if(off[i].serialno == serialno) {

                            for(int j = i; j < offcount; j++) {
                                off[j].code = off[j+1].code;
                                off[j].serialno = off[j+1].serialno;
                                off[j].discount = off[j+1].discount;
                            }

                            off[offcount].code = 0;
                            off[offcount].serialno = 0;
                            off[offcount].discount = 0;
                        }
                    }

                    offcount--;
                }
                    
                
                else 
                    printf("\nTHERE ARE NO OFFER COUPONS TO BE DELETED...\n : ");

            }
                    
            
            if(aa==2) {
                        
                offcount++;

                printf("ENTER SERIAL NUMBER OF OFFER COUPON TO BE ADDED...\n : ");
                scanf("%d", &off[offcount].serialno);
                        
                printf("\nENTER CODE OF OFFER COUPON...\n : ");
                scanf("%d", &off[offcount].code);
                        
                printf("\nENTER DISCOUNT PERCENTAGE OF OFFER COUPON...\n : ");
                scanf("%d", &off[offcount].discount);
            }

            
            printf("*** OFFERS ***\n");

            for(int i = 1; i <= offcount; i++) {
                printf(" %d\t%d\t\t%d\n", off[i].serialno, off[i].code, off[i].discount);
            }

            printf("********\n\n");

        }

            goto moddef;
        }

    }



// Another diplay portal with offerCoupons and extra added stuff
    moddisplay: {
        
        printf("\n\n**** MENU ****\n");
        
        for(int i = 1; i <= items; i++) {
            
            printf(" %d\t%.2fRs\t\t%s\n",x[i].foodno,x[i].cost,x[i].food);
        
        }
        
        printf("********\n\n");
        printf("*** OFFERS ***\n");
        
        for(int i = 1; i <= offcount; i++) {
            
            printf(" %d\t%d\t\t%d\n", off[i].serialno, off[i].code, off[i].discount);
        
        }

        printf("********\n\n");

        goto moddef;
    }



    refresh: {

        for(int i = 0; i <= 100; i++) {
            
            x[i].count = 0;
            x[i].mark = 0;
            //user[User.Id].Orders = 0;

        }
        
        goto conti;
    }
}



// To set a valid strong password with password invisibility feature..
void set_password() {
	
    H:
    printf("\nGIVE A STRONG PASSWORD : ");
	//scanf(" %s", user[User.Id].password);
    user[User.Id].password = getpass("\n: ");
    
    if(isValidPassword(user[User.Id].password)) {
	    printf("\nPASSWORD SET SUCCESSFULLY!!!");
	    printf("\n\n----------------------------------------------------\n\n");
    }

    else {
        printf("INVALID/weak_PASSWORD\n\n");
        goto H;
    }
}



/* To create account or edit details of an existing account..
    Also to store unique id and email of each customer */
void create_account(int F) {
	
	printf("\nUSER_NAME : ");
	scanf(" %s", user[User.Id].name);
	
	printf("USER_GENDER : ");
	scanf(" %s", user[User.Id].gender);
	
	printf("USER_EMAIL_ID : ");
	scanf(" %s", user[User.Id].email);
	
	printf("USER_MOBILE_NUMBER : ");
	scanf("%ld", &user[User.Id].mobile);
	
	printf("USER_AGE : ");
	scanf("%d", &user[User.Id].age);
	
	printf("WardNumber-RoomNumber : ");
	scanf(" %s", user[User.Id].qZoneNumber);

    if(F == 0)
	    set_password();

    strcpy(deck.store[User.Id], user[User.Id].email);

}



// Login portal with all features.
void user_login() {

	int doubt;
	long int confirm;
    char key[20], key1[20];
	printf("\n\n\nENTER your USER_EMAIL_ID : ");
	scanf(" %s", key);

	printf("ENTER your PASSWORD : ");
    scanf(" %s", key1);

    int newID = User.Id;
    newID = search_deck(key);

    delay(700);

	if(strcmp(key, user[newID].email) == 0) {
		
		if(strcmp(key1, user[newID].password) == 0) {
			printf("\nYou are logged in successfully...\n\n");
			order_food(0);
		}

		else {
			
			printf("\n\n\nForgot Password??\t\t|| 1.Yes | 2.No ||\n");
			scanf("%d", &doubt);
			
			if(doubt == 1) {
				
				printf("\nENTER your MOBILE_NUMBER : ");
				scanf("%ld", &confirm);

				if(confirm == user[newID].mobile) {
					
                    int otp, lamda = generateOTP();

                    printf("\nAn OTP is sent to this number : %d", lamda);
                    printf("   Please change your PASSWORD..\n");
                    scanf("%d", &otp);

                    if(otp == lamda) {
					    set_password();
					    user_login();
                    }

                    else {
                        
                        printf("\nFraud detected!!...BOOM!!!\n");
                        delay(1000);
                        
                        exit(0);
                    }
				}

				else {
					
                    printf("Sorry!! We think you are a fraud using someone else's account..\n");
					printf("Create a new account for yourselves...\n");

                    delay(700);

					create_account(0);
					user_login();
				}
			}

			else {
				printf("Try again to login..\n");
				user_login();
			}
		}
	}

	else {
		printf("INCORRECT NAME or EMAIL...Try again..\n");
		user_login();
	}
}



void set_official_password() {
	printf("\nEnter a strong passkey : ");
	scanf(" %s", emp.official_password);
	printf("Successful!!!!\n\n");
}



void create_official_account() {
	
	printf("\n\nOFFICIAL_ID : ");
	scanf(" %s", emp.official_id);

	printf("OFFICIAL_STATUS [manager | staff_chef] : ");
	scanf(" %s", emp.official_status);

	set_official_password();
}



void official_login() {
	
	char code[50], id[20];
    int w;

	printf("\n\n\nEnter your official id : ");
	scanf(" %s", id);

	printf("Enter your official password : ");
	scanf(" %s", code);

	if(strcmp(id, emp.official_id) == 0) {

		if(strcmp(code, emp.official_password) == 0) {
			
			printf("You have logged in as an Hotel_Official\n\n");
			order_food(1);

		}
			
	    else {
	    	printf("\n\n\nForgot your official password??\t\t|| 1.Yes | 2.No ||\n : ");
		    scanf("%d", &w);
			
		    if(w == 1) {
		    set_official_password();
		    official_login();
		    }

		    else if(w == 2) {
			    printf("\n\n!!Your actions has been noted as fraud behavior!!");
                printf("\nThis account has been deleted\n");
			    printf("Create a new account now...");
			    create_official_account();
		    }
	    }
    }

	else {
		printf("\nAn issue has arised unfortunately!!...Try to Login again!!");
		official_login();
	}
}



int main() {
	
    int new_user, random, who;
    User.Id = -1;

    FILE *file;
	
    X:
    printf("\n\nENTER : \t\t|| 1.Create(switch) account | 2.Login to account ||\n : ");
	scanf("%d", &new_user);


	if(new_user == 1) {
		
        printf("\nThank you for choosing our app..Please proceed to create your account!\n");
		AGAIN:
        printf("\nWHO ARE YOU??\t\t\t|| 1.Customers | 2.Officials ||\n : ");
		scanf("%d", &who);

		if(who == 1) {
            User.Id += 1;
		    create_account(0);
        }

		else if(who == 2)
		create_official_account();

        else {
            printf("\n******InVaLiD eNtRy*******\n");
            goto AGAIN;
        }

	}


	printf("\nPlease provide your login details..\n\n\n");
	
    again:
    printf("WHO ARE YOU??\t\t\t|| 1.Customers | 2.Officials ||\n : ");
	scanf("%d", &who);


	if(who == 1)
	    user_login();

	else if(who == 2)
	    official_login();

    else {
        printf("\n**********InVaLid OpTiOn EnTeReD***************\n");
        goto again;
    }


	printf("\nThank_you for your time and love---------\n");
	printf("Do you like to shutdown[stop trade]???\n");
    

    onceagain:
    printf("\nAll your current_data will be lost :\t\t|| 1.Yes | 2.No ||\n : ");
	scanf("%d", &random);


	if(random == 1) {
		

        delay(800);

        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("!!You have LOST all Account_Data stored Previously!!");
        printf("\n\n------THANK_YOU_ONCE_AGAIN------\n\nPlease provide feedback----\n");
        printf("\nPress '|' ..and next the 'enterKey' to exit input : \n");
        
        
// A feedback system to input feedback and reviews and store them in a separate txt file
        char notepad[2000];
        scanf(" %[^|]s", notepad);
        file = fopen("feedbacks.txt", "a+");
        fprintf(file, "%s\n", notepad);
        fclose(file);
        
        delay(550);

        return 0;
	}

	else if(random == 2){
		
        int omega;
        printf("\n\n\n\n\n\n\n\n\nYour Previous_data is saved!!\n");
        
        if(who == 1) {
            printf("Do you want to edit your account details\t|| 1.Yes | 0.No ||\n : ");
            scanf("%d", &omega);
        
            if(omega == 1) {
                create_account(1);
                printf("\nDetails edited successfully!!\n");

                delay(700);
            }
        }

		goto X;
	}

    else {
        printf("\n**********InVaLid OpTiOn EnTeReD***************\n");
        goto onceagain;
    }

	return 0;
}