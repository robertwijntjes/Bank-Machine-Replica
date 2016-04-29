/*
    Author:Robert Wijntjes    Code:C14356786
    Program:C
    Assignment to create a security Authorization system.
    1:Entering your pin
    2:Encrypting your pin.Cannot do when already encrypted
    3:decrypt your pin.Cannot be done when already decrypted and no code.
    4:Shows incorrect and correct times
    5:Exits Program.
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 4

void entercode(int *,int *);
void encrypt(int *,int *,int *,int *,int *);
void decrypt(int *,int *);

main()
{
    int option,q,r,i,access;
    int pinori[SIZE]={4,5,2,3};
    int newpin[SIZE]={};
    option = 0;
    q = 0;
    r = 0;
    i = 0;
    access = 0;
    //DECLARE VARIABLES

    printf("\nSecurity Authorization Code");
    printf("\n*******************************");
    printf("\nDefault Code : 1234");
    printf("\n*******************************");
    //STARTUP BAR


    do
    {
        printf("\n1:Please Enter your Code.");
        printf("\n2:Encrypt Code!");
        printf("\n3:Decrypt Code!");
        printf("\n4:Display Success/Fail Rate");
        printf("\n5:Exit\n");
        scanf("%d",&option);
        fflush(stdin);
        //MENU BAR

            switch(option)
                {
                case 1 :
                    {
                        entercode(&newpin[i],&access);
                        break;
                    }//END CASE
                case 2 :
                    {
                        encrypt(&newpin[i],&pinori[i],&q,&r,&access);
                        break;
                    }//END CASE
                case 3 :
                    {
                        decrypt(&newpin[i],&access);
                        break;
                    }//END CASE
                case 4 :
                    {
                        printf("\n%d times correct! %d times incorrect!",q,r);
                        break;
                    }//END CASE
                case 5 :
                    {
                        return 0;
                        break;
                    }//END CASE
                }//END SWITCH
                //FUNCTION SLOTS

        }//END DO
    while(option != 5);
    getchar();
}//END MAIN

void entercode(int *code,int *access_fxn)
{
    int i;
    i=0;


        printf("\nPlease Enter your code now!\n");
        for (i=0;i<SIZE;i++)
        {
            scanf("%d",&*(code+i));
        }//END FOR
        (*access_fxn) = 0;
        (*access_fxn)++;
}//END ENTERCODE

void encrypt(int *code_enc,int *code_compare,int *q,int *r,int *access_fxn2)
{
    int temp,i,failcount;
    temp = 0;
    i=0;
    failcount = 0;

    if(*(access_fxn2) == 1 )
    {
        temp = *(code_enc);
        *(code_enc) = *(code_enc + 2);
        *(code_enc + 2) = temp;
        //first switch

        temp = *(code_enc + 1);
        *(code_enc + 1) = *(code_enc + 3);
        *(code_enc + 3) = temp;
        //second switch

        for(i=0;i<SIZE;i++)
        {
            *(code_enc + i)= *(code_enc + i)+1;
        }//END INCREMENT LUUP

        for(i=0;i<SIZE;i++)
        {
            if(*(code_enc + i) == 10 )
            {
                *(code_enc + i) = 0;
            }//END CHANGE 10 --> 0
            else
            {
                break;
            }//END ELSE
        }//END FOR

        if(*(code_enc) == *(code_compare))
        {
            printf("\nCorrect!");
            (*q)++;
        }//END IF
        else
        {
            printf("\nIncorrect!");
            (*r)++;
        }//END ELSE

        for(i=0;i<SIZE;i++)
        {
            printf("%d",*(code_enc + i));
        }//SHOWS MASK
        (*access_fxn2)++;
    }//END IF
    else
    {

    }//END ELSE
}//END ENCRYPT

void decrypt(int *code_dnc,int *access_fxn3)
{
    int temp,i;
    temp = 0;
    i = 0;

    if(*(access_fxn3) == 2)
    {
        temp = *(code_dnc);
        *(code_dnc) = *(code_dnc + 2);
        *(code_dnc + 2) = temp;
        //first switch

        temp = *(code_dnc + 1);
        *(code_dnc + 1) = *(code_dnc + 3);
        *(code_dnc + 3) = temp;
        //second switch

        for(i=0;i<SIZE;i++)
        {
            *(code_dnc + i)= *(code_dnc + i)-1;
        }//END INCREMENT LUUP

        for(i=0;i<SIZE;i++)
        {
            if(*(code_dnc + i) == -1 )
            {
                *(code_dnc + i) = 9;
            }//END CHANGE 10 --> 0
            else
            {
                break;
            }//END ELSE
        }//END FOR

        for(i=0;i<SIZE;i++)
        {
            printf("%d",*(code_dnc + i));
        }//SHOWS MASK
        (*access_fxn3)--;
    }//END IF
    else
    {

    }
}//END DECRYPT


