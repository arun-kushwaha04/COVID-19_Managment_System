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
void deleterecord();
void show_vacant_beds();
void get_id();
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
    while(1){
        system("cls");
        title();
        mainmenu_heading();
        
        give_tab();printf("1. Display Vacants Beds\n\n"); 
        give_tab();printf("2. Add Patient Record\n\n"); 
        give_tab();printf("3. List Patient Record\n\n"); 
        give_tab();printf("4. Edit Patient Record\n\n"); 
        give_tab();printf("5. Delete Patient Record\n\n");
        give_tab();printf("6. Exit\n\n"); 
        give_tab();printf("Enter a number between 1-6\n\n");
        give_tab();printf("Enter your choice: ");
        int n;
        scanf("%d", &n);
        switch(n){
            case 1:
            show_vacant_beds();
            break;
            case 2:
            addrecord();
            break;
            case 3:
            listrecord();
            break;
            case 4:
            editrecord();
            break;
            case 5: 
            deleterecord(); 
            break;
            case 6:
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
    title();
    give_tab();printf("This code is written and maintained by---\n");
    give_tab();printf("1. Ansh IMT-014\n");
    give_tab();printf("2. Ketan IMT-044\n");
    give_tab();printf("3. Arun IMT-016\n");
    give_tab();printf("Press any key to exit...\n");getch();
    give_tab();printf("exiting............\n");
    return;
}

//checker function...
void checker(char str[]){
    
}
void addrecord(){
    system("cls");
    title();printf("\t\t\t\t\t\t\t\t\t!!!!!!!!!!!!!!! ADD PATIENT RECORD !!!!!!!!!!!!!!!\n\n\n");
    FILE *ptr,*ptr2;
    int n;
    give_tab();printf("1. AIIMS\n\n"); 
    give_tab();printf("2. Apollo\n\n"); 
    give_tab();printf("3. Fortis\n\n"); 
    give_tab();printf("4. Max Super\n\n"); 
    give_tab();printf("5. Vedanta\n\n");
    give_tab();printf("Enter a number between 1-5\n\n");
    give_tab();printf("Enter your choice: ");
    scanf("%d", &n);
    switch(n){
        case 1:
        ptr = fopen("./Database/AIIMS/patient.csv","a+");
        if(ptr==NULL){
        perror("Unable to open file");
        return ;
        }
        break;
        case 2:
        ptr = fopen("./Database/Apollo/patient.csv","a+");
        if(ptr==NULL){
        perror("Unable to open file");
        return ;
        }
        break;
        case 3:
        ptr = fopen("./Database/Fortis/patient.csv","a+");
        if(ptr==NULL){
        perror("Unable to open file");
        return ;
        }
        break;
        case 4:
        ptr = fopen("./Database/Max Super/patient.csv","a+");
        if(ptr==NULL){
        perror("Unable to open file");
        return ;
        }
        break;
        case 5: 
        ptr = fopen("./Database/Vedanta/patient.csv","a+");
        if(ptr==NULL){
        perror("Unable to open file");
        return ;
        }
        break;
        default: 
        give_tab();printf("Invalid entry, press enter to try again\n"); getch();
        break;
    }

    char b[4],c[11],d[11],e[4],f,g[11];
    get_id(n,b);
    fflush(stdin);
    printf("\n\n");
    give_tab();printf("Generated I'd and Bed Number are %s,%s\n",b,b);fflush(stdin);
    give_tab();printf("Enter patient's First name: ");scanf("%s",c);fflush(stdin);
    give_tab();printf("Enter patient's Last name: ");scanf("%s",d);fflush(stdin);
    give_tab();printf("Enter patient's Age: ");scanf("%s",e);fflush(stdin);
    give_tab();printf("Enter patient's gender: ");scanf("%c",&f);fflush(stdin);
    give_tab();printf("Enter patient's Number: ");scanf("%s",g);fflush(stdin);
    fprintf(ptr,"%s,%s,%s,%s,%s,%c,%s\n",b,b,c,d,e,f,g);
    fclose(ptr);
    give_tab();printf("Record Created Successfully!!\n\n");
    char choice;
    give_tab();printf("Want to add another record[Y/N]");scanf("%c",&choice);
    if(choice=='Y')addrecord();
    else main_menu();
}

//Generating Id and bed number
void get_id(int n,char b[4]){
    FILE *ptr = fopen("./Database/Vacant.csv","a+"), *ptr2 = fopen("./Database/temp.csv","a+");
    if(ptr==NULL){
        perror("Unable to open file");
        return ;
    }
    char info[50];
    int i=1;
    
    while(fgets(info,sizeof(info),ptr)){
        char *token,*name,*seats,*id;
        token = strtok(info, ",");
        int j=1;
        while( token != NULL ) {
            if(i==n+1 && j==3){
                int c;  
                c=atoi(token);c=c+1;
                sprintf(b, "%d", c);
                token = strtok(NULL, ",");
            }
            else if(j==1){
                name = token;
                token = strtok(NULL, ",");
            }
            else if(j==2){
                seats = token;
                token = strtok(NULL, ",");
            }
            else if(j==3){
                id = token;
                token = strtok(NULL, ",");
            }
            j++;
        }
        if(i==n+1){fprintf(ptr2,"%s,%s,%s\n",name,seats,b);}
        else {fprintf(ptr2,"%s,%s,%s",name,seats,id);}
        i++;
    }
    fclose(ptr);
    fclose(ptr2);
    remove("./Database/Vacant.csv");
    rename("./Database/temp.csv","./Database/Vacant.csv");
}

// Listing patient record
void listrecord(){
    system("cls");
    title();printf("\t\t\t\t\t\t\t\t!!!!!!!!!!!!!!! PATIENT RECORD !!!!!!!!!!!!!!!\n");
    FILE *ptr;
    int n;
    give_tab();printf("1. AIIMS\n\n"); 
    give_tab();printf("2. Apollo\n\n"); 
    give_tab();printf("3. Fortis\n\n"); 
    give_tab();printf("4. Max Super\n\n"); 
    give_tab();printf("5. Vedanta\n\n");
    give_tab();printf("Enter a number between 1-5\n\n");
    give_tab();printf("Enter your choice: ");
    scanf("%d", &n);
    switch(n){
        case 1:
        ptr = fopen("./Database/AIIMS/patient.csv","a+");
        if(ptr==NULL){
        perror("Unable to open file");
        return ;
        }
        break;
        case 2:
        ptr = fopen("./Database/Apollo/patient.csv","a+");
        if(ptr==NULL){
        perror("Unable to open file");
        return ;
        }
        break;
        case 3:
        ptr = fopen("./Database/Fortis/patient.csv","a+");
        if(ptr==NULL){
        perror("Unable to open file");
        return ;
        }
        break;
        case 4:
        ptr = fopen("./Database/Max Super/patient.csv","a+");
        if(ptr==NULL){
        perror("Unable to open file");
        return ;
        }
        break;
        case 5: 
        ptr = fopen("./Database/Vedanta/patient.csv","a+");
        if(ptr==NULL){
        perror("Unable to open file");
        return ;
        }
        break;
        default: 
        give_tab();printf("Invalid entry, press enter to try again\n"); getch();
        break;
    }
        printf("\n\n");
    char info[100];
    while(fgets(info,sizeof(info),ptr)){
        char *token;
        token = strtok(info, ",");
        while( token != NULL ) {
            printf("\t");
            printf( " %-20s", token );
            token = strtok(NULL, ",");
        }
        printf("\n");
    }
    fclose(ptr);
    printf("\n");
    give_tab();printf("This is the end of record");
    getch();
    main_menu();
}

/*different hospital data*/
void show_vacant_beds(){
    system("cls");
    title();
    printf("\t\t\t\t\t\t\t\t\t\t---------------------------\n");
    printf("\t\t\t\t\t\t\t\t\t\t         Vacant Beds\n");
    printf("\t\t\t\t\t\t\t\t\t\t---------------------------\n\n\n\n");
    FILE *ptr;
    ptr = fopen("./Database/Vacant.csv","r");
    if(ptr==NULL){
        perror("Unable to open file");
        return ;
    }  
    char info[50];
    while(fgets(info,sizeof(info),ptr)){
        char *token;
        token = strtok(info, ",");
        while( token != NULL ) {
            printf("\t\t\t");
            printf( " %-10s", token );
            token = strtok(NULL, ",");
        }
        printf("\n");
    }
    fclose(ptr);
    printf("\n");
    give_tab();printf("This is the end of record");
    getch();
    main_menu();
}

void editrecord(){
    system("cls");
    title();printf("\t\t\t\t\t\t\t\t!!!!!!!!!!!!!!! EDIT PATIENT RECORD !!!!!!!!!!!!!!!\n");
    char choice; 
    while(1){
        FILE* ptr = NULL;
        int n;
        ptr = fopen("patientdata.csv", "r+");
        if (ptr == NULL){
            printf("Cannot access file");
            return;
        }
        give_tab();printf("Enter the Patient ID: ");
        scanf("%d", &n);
        while (1){
            fscanf(ptr,"%*[^\n]s");
            if (fgetc(ptr) == EOF){
                printf("This patient number does not exist, try again");
                getch();
                break;
            } 
            if (fgetc(ptr) - '0' == n){
                fseek(ptr, 0, SEEK_CUR);
                char b[4],c[11],d[11],e[4],f,g[11];
                fflush(stdin);
                give_tab();printf("Enter patient's Bed number: ");scanf("%s",b);fflush(stdin);
                give_tab();printf("Enter patient's First name: ");scanf("%s",c);fflush(stdin);
                give_tab();printf("Enter patient's Last name: ");scanf("%s",d);fflush(stdin);
                give_tab();printf("Enter patient's Age: ");scanf("%s",e);fflush(stdin);
                give_tab();printf("Enter patient's gender: ");scanf("%c",&f);fflush(stdin);
                give_tab();printf("Enter patient's Number: ");scanf("%s",g);fflush(stdin);
                fprintf(ptr,",%3s,%10s,%10s,%3s,%c,%10s",b,c,d,e,f,g);
                fseek(ptr, 0, SEEK_SET);
                break;
            }
        }
        fclose(ptr);
        printf("Do you want to edit more patient records? [Y/N]");
        scanf(" %c", &choice);
        give_tab();printf("Record Edited Successfully!!\n\n");
        if (choice == 'Y') continue; 
        else break;
    }    
}

void deleterecord(){
    system("cls");
    title();printf("\t\t\t\t\t\t\t\t!!!!!!!!!!!!!!! DELETE PATIENT RECORD !!!!!!!!!!!!!!!\n");
    char choice; 
    while(1){
        FILE* ptr = NULL;
        int n;
        ptr = fopen("patientdata.csv", "r+");
        if (ptr == NULL){
            printf("Cannot access file");
            return;
        }
        give_tab();printf("Enter the Patient ID: ");
        scanf("%d", &n);
        while (1){
            fscanf(ptr,"%*[^\n]s");
            if (fgetc(ptr) == EOF){
                printf("This patient number does not exist, try again");
                getch();
                break;
            } 
            if (fgetc(ptr) - '0' == n){
                fseek(ptr, -1, SEEK_CUR);
                fflush(stdin);
                fprintf(ptr, "%45s", " ");
                fseek(ptr, 0, SEEK_SET);
                break;
            }
        }
        fclose(ptr);
        give_tab();printf("Record Edited Successfully!!\n\n");
        give_tab();printf("Do you want to delete more patient records? (Y/N)");
        scanf(" %c", &choice);
        if (choice == 'Y') continue; 
        else break;
    }    
}