#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

//###########################################################function declartion########################################################
void welcome_screen();
void title();
void login(char [20],char [20]);
void main_menu();
void signup();

int main(){
    welcome_screen();
    title();
    signup();
    return 0;
}


//##################################################################function logic########################################################

//printing welcome screen
void welcome_screen(){
    printf("\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t###################################################\n");
    printf("\t\t\t\t\t\t\t\t#                                                 #\n");
    printf("\t\t\t\t\t\t\t\t#                                                 #\n");
    printf("\t\t\t\t\t\t\t\t#             COVID-19 MANGEMENT SYSTEM           #\n");
    printf("\t\t\t\t\t\t\t\t#                                                 #\n");
    printf("\t\t\t\t\t\t\t\t#                                                 #\n");  
    printf("\t\t\t\t\t\t\t\t###################################################\n");
    printf("Press any key to continue...");
    getch();
    system("cls");
}
//printing title
void title(){
    printf("\n\n\n");
    printf("\t\t\t\t\t\t\t\t----------------------------------------------------------\n");
    printf("\t\t\t\t\t\t\t\t                     STAY HOME,STAY SAFE                  \n");
    printf("\t\t\t\t\t\t\t\t----------------------------------------------------------\n");
}
// Creating Id for user
void signup()
{
    char username[20],password[20];
    printf("\t\t\t\t\t\t\t\t\tCreate your Username and Password\n");
    printf("\t\t\t\t\t\t\t\t\tUsername : ");
    scanf("%s",username);
    printf("\t\t\t\t\t\t\t\t\tPassword : ");
    scanf("%s",password);
    system("cls");
    
    login(username,password);
}

//logging in valid user
void login(char ori_username[20],char ori_password[20])
{  
    char username[20],password[20];
    int attempt = 0;
    start:
  //  printf("%s %s",ori_username,ori_password);
    do{
        printf("\t\t\t\t\t\t\t\tEnter your Username and Password :)\n");
        printf("\t\t\t\t\t\t\t\t\tUsername: ");
        scanf("%s",username);
        printf("\t\t\t\t\t\t\t\t\tPassword: ");
        scanf("%s",password);
        // using strcmp to compare strings --->https://www.geeksforgeeks.org/strcmp-in-c-cpp/
        if(strcmp(username,ori_username)==0 && strcmp(password,ori_password)==0){
            printf("\n\n\t\t\t\t\t\t\t\t\tLOGGED in SICCSSFULLY !! :) :)\n");
            break;
        }
        else{
            attempt++;
            printf("\n\n\t\t\t\t\t\t\t\tInvalid Username or Password!!\n");
            printf("\t\t\t\t\t\t\t\tYou are left with %d attempts\n\n\n",(3-attempt));
        }
    }while(attempt<3);
    if(attempt>=3)
    {
        char user_auth[5];
        int choice;
        printf("\t\t\t\t\t\t\t\tForgot Username or Password ?\n");
        printf("\t\t\t\t\t\t\t\tPress y for Yes and n for No\n");
        printf("\t\t\t\t\t\t\t\tResponse : ");
        scanf("%s",user_auth);
        if(strcmp(user_auth,"y")==0)
        {
            printf("\n\t\t\t\t\t\t\t\tWhat do you want to change ?\n");
            printf("\t\t\t\t\t\t\t\tPress 1 for Username\n");
            printf("\t\t\t\t\t\t\t\tPress 2 for Password\n");
            printf("\t\t\t\t\t\t\t\tPress 3 for Username and Password both\n");
            printf("\t\t\t\t\t\t\t\tPress 4 for exit\n");
            printf("\t\t\t\t\t\t\t\tResponse : ");
            scanf("%d",&choice);
            printf("\n");
            switch(choice)
            {
                case 1:
                printf("\t\t\t\t\t\t\tEnter new Username\n");
                printf("\t\t\t\t\t\t\t\tNEW USERNAME : ");
                scanf("%s",ori_username);
                printf("\n");
                attempt = 0;
                goto start;
                break;

                case 2:
                printf("\t\t\t\t\t\t\tEnter new password\n");
                printf("\t\t\t\t\t\t\t\tNEW PASSWORD : ");
                scanf("%s",ori_password);
                printf("\n");
                attempt = 0;
                goto start;
                break;

                case 3:
                printf("\t\t\t\t\t\t\t\tEnter new Username and Password\n");
                printf("\t\t\t\t\t\t\t\t\tNew Username : ");
                scanf("%s",ori_username);
                printf("\t\t\t\t\t\t\t\t\tNew Password : ");
                scanf("%s",ori_password);
                printf("\n");
                attempt = 0;
                goto start;
                break;

                case 4:
                exit(0);
                break;
            }
        }
        else if(strcmp(user_auth,"n")==0)
        {
            printf("\n\n\t\t\t\t\t\t\t\tSorry! You are a Unauthorized user :( :(\n");
            exit(0);
        }     
    }
    else{
        printf("Press any key to continue...");
        getch();
        system("cls");   
        main_menu(); 
    }
}
//main menu 
void main_menu(){
    printf("\t\t\t\t\t\t\t---------------------------\n");
    printf("\t\t\t\t\t\t\t          Main Menu\n");
    printf("\t\t\t\t\t\t\t---------------------------\n\n\n\n");
    int n;
    while(1){
        printf("1. Exit\n\n"); 
        printf("Enter the choice: ");
        scanf("%d", &n);
        switch(n){
            case 1: printf("Exiting ..."); return; break;
            default: printf("\nInvalid choice, try again\n"); continue;
        }
    }

    
}