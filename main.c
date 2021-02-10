#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

//###########################################################function declartion########################################################
void welcome_screen();
void title();
void login();
void main_menu();
void signup();
void mainmenu_heading();
void give_tab();
void addrecord();
void listrecord();
void editrecord();
void _e_xit();

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
//main menu heading
void mainmenu_heading(){
    printf("\t\t\t\t\t\t\t\t\t\t---------------------------\n");
    printf("\t\t\t\t\t\t\t\t\t\t         Main Menu\n");
    printf("\t\t\t\t\t\t\t\t\t\t---------------------------\n\n\n\n");
}
// printinging tab
void give_tab(){
    printf("\t\t\t\t\t\t\t\t");
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
void login(){
    int attempt=0;
    char username[12];
    char password[12];
    char original_username[12]="IIITM-G";
    char original_password[12]="cubepatient";


    do{
        printf("\t\t\t\t\t\t\t\tEnter your Username and Password :)\n");
        printf("\t\t\t\t\t\t\t\t\tUSERNAME: ");
        scanf("%s",username);
        printf("\t\t\t\t\t\t\t\t\tPASSWORD: ");
        scanf("%s",password);
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
    return;
}
//main menu 
void main_menu(){
    system("cls");  
    while(1){
        title();
        mainmenu_heading();
        
        give_tab();printf("1. Add Patient Record\n\n"); 
        give_tab();printf("2. List Patient Record\n\n"); 
        give_tab();printf("3. Edit Patient Record\n\n"); 
        give_tab();printf("4. Exit\n\n"); 
        give_tab();printf("Enter a number between 1-4\n\n");
        give_tab();printf("Enter your choice: ");
        int n;
        scanf("%d", &n);
        switch(n){
            case 1:
            addrecord();
            break;
            case 2:
            listrecord();
            break;
            case 3:
            editrecord();
            break;
            case 4:
            _e_xit();
            return;
            break;
            default: 
            give_tab();printf("Invalid entry, press enter to try again\n"); getch();
            continue;
        }
    }
    return;
}
//exit function
void _e_xit(){
    system("cls");  
    title();printf("\t\t\t\t\t\t\t\t\t\t         Main Menu\n");
    give_tab();printf("This code is written and maintained by---\n");
    give_tab();printf("1. Ansh IMT-014\n");
    give_tab();printf("2. Ketan IMT-044\n");
    give_tab();printf("3. Arun IMT-016\n");
    give_tab();printf("Press any key to exit...\n");getch();
    give_tab();printf("exiting............\n");
    return;
}

struct patient{
    char name[100];
    int number; 
    char status;  
} arrpatient[1000];

int n = 0; 
void addrecord(){
    n += 1;
    arrpatient[n - 1].number = n;
    printf("\n\n");
    give_tab();printf("Patient %d", n);
    printf("\n\n");
    give_tab();printf("Patient Name: ");
    fflush(stdin);
    gets(arrpatient[n - 1].name);
    fflush(stdin);
    printf("\n");
    give_tab();printf("Patient Status(P/N) :");
    scanf(" %c", &arrpatient[n - 1].status);
    getch();
}

void listrecord(){
    printf("\n\n");
    for (int i = 0; i < n; i++){
        printf("\n\n");
        give_tab();printf("Patient %d", i + 1);
        printf("\n\n");
        give_tab();printf("Patient Name: %s", arrpatient[i].name);
        printf("\n\n");
        give_tab();printf("Patient Status: %c", arrpatient[i].status);
    }
    getch();
}
void editrecord(){}

