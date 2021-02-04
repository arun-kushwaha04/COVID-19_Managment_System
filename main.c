#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

//###########################################################function declartion########################################################
void welcome_screen();
void title();
void login();
void main_menu();

int main(){
    welcome_screen();
    title();
    login();
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
//logging in valid user
void login(){
    int attempt=0;
    char username[12];
    char password[12];
    char original_username[12]="IIITM-G";
    char original_password[12]="cubepatient";


    do{
        printf("\t\t\t\t\t\t\t\tEnter your Username and Password :)\n");
        printf("\t\t\t\t\t\t\t\t\tUSERNAME: ");
        scanf("%s",&username);
        printf("\t\t\t\t\t\t\t\t\tPASSWORD: ");
        scanf("%s",&password);
        // using strcmp to compare strings --->https://www.geeksforgeeks.org/strcmp-in-c-cpp/
        if(strcmp(username,original_username)==0 && strcmp(password,original_password)==0){
            printf("\n\n\t\t\t\t\t\t\t\t\tLOGGED in SICCSSFULLY !! :) :)\n");
            break;
        }
        else{
            attempt++;
            printf("\n\n\t\t\t\t\t\t\t\t\tInvalid Username or Password!!\n");
            printf("\t\t\t\t\t\t\t\t\tYou are left with %d attempts\n\n\n",(3-attempt));
        }
    }while(attempt<3);
    if(attempt>=3){
        printf("\n\n\t\t\t\t\t\t\t\tSorry! You are a Unauthorized user :( :(\n");
    }
    else{
        printf("Press any key to continue...");
        getch();
        system("cls");   
        main_menu(); 
    }
}
void main_menu(){

}