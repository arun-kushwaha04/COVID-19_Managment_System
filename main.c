#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

//###########################################################function declartion########################################################
void welcome_screen();
void welcome_screen_infection_checker();
void title();
void login();
void main_menu();
void signup();
void mainmenu_heading();
void give_tab();
void hospitals();
int recordchecker(char [],int );
void infectionrate();
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
void welcome_screen_infection_checker(){
    printf("\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t###################################################\n");
    printf("\t\t\t\t\t\t\t#                                                 #\n");
    printf("\t\t\t\t\t\t\t#                                                 #\n");
    printf("\t\t\t\t\t\t\t#             COVID-19 INFECTION CHECKER          #\n");
    printf("\t\t\t\t\t\t\t#                                                 #\n");
    printf("\t\t\t\t\t\t\t#                                                 #\n");  
    printf("\t\t\t\t\t\t\t###################################################\n");
    printf("Press any key to continue...");
    getch();
    system("cls");
}
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
    printf("\t\t\t\t\t\t\t\t\t\t---------------------------\n\n\n");
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
            printf("\n\t\t\t\t\t\t\t\t\tLOGGED in SICCSSFULLY !! :) :)\n");
            break;
        }
        else{
            attempt++;
            printf("\n\t\t\t\t\t\t\t\t\tInvalid Username or Password!!\n");
            printf("\t\t\t\t\t\t\t\t\tYou are left with %d attempts\n\n",(3-attempt));
        }
    }while(attempt<3);
    if(attempt>=3){
        printf("\t\t\t\t\t\t\t\tSorry! You are a Unauthorized user :( :(\n");
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
        give_tab();printf("6. Check your Saftey\n\n");
        give_tab();printf("7. Exit\n\n"); 
        give_tab();printf("Enter a number between 1-7\n\n");
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
            infectionrate();
            return;
            break;
            case 7:
            _e_xit();
            return;
            break;
            default:
            printf("\n"); 
            give_tab();printf("Invalid entry, press enter to try again "); getch();printf("\n");
            continue;
        }
    }
    return;
}
//exit function
void _e_xit(){
    system("cls");  
    title();
    give_tab();printf("This code is written and maintained by---\n\n");
    give_tab();printf("1. Ankit IMT-011\n");
    give_tab();printf("2. Ansh IMT-013\n");
    give_tab();printf("3. Arun IMT-016\n");
    give_tab();printf("4. Ketan IMT-044\n\n");
    give_tab();printf("Press any key to exit...");
    getch();
    printf("\n\n");
    give_tab();printf("Exiting............");
    exit(0);
    return;
}

//List of hospitals
void hospitals(){
    give_tab();printf("1. AIIMS\n\n"); 
    give_tab();printf("2. Apollo\n\n"); 
    give_tab();printf("3. Fortis\n\n"); 
    give_tab();printf("4. Max Super\n\n"); 
    give_tab();printf("5. Vedanta\n\n");
    give_tab();printf("Enter a number between 1-5\n\n");
    give_tab();printf("Enter your choice: ");
}
//checker function...
void checker(char str[]){
    
}
void addrecord(){
    system("cls");
    title();printf("\n\t\t\t\t\t\t\t\t!!!!!!!!!!!!!!!!!!! ADD PATIENT RECORD !!!!!!!!!!!!!!!!!!!\n\n\n");
    FILE *ptr,*ptr3,*ptr4;
    int n;
    hospitals();
    scanf("%d", &n);
    switch(n){
        case 1:
        ptr = fopen("./Database/AIIMS/patient.csv","a+");
        ptr3 = fopen("./Database/AIIMS/ID.txt", "a+");
        ptr4 = fopen("./Database/AIIMS/temp.txt", "w");
        if(ptr==NULL){
        perror("Unable to open file");
        return ;
        }
        break;
        case 2:
        ptr = fopen("./Database/Apollo/patient.csv","a+");
        ptr3 = fopen("./Database/Apollo/ID.txt", "a+");
        ptr4 = fopen("./Database/Apollo/temp.txt", "w");
        if(ptr==NULL){
        perror("Unable to open file");
        return ;
        }
        break;
        case 3:
        ptr = fopen("./Database/Fortis/patient.csv","a+");
        ptr3 = fopen("./Database/Fortis/ID.txt", "a+");
        ptr4 = fopen("./Database/Fortis/temp.txt", "w");
        if(ptr==NULL){
        perror("Unable to open file");
        return ;
        }
        break;
        case 4:
        ptr = fopen("./Database/Max Super/patient.csv","a+");
        ptr3 = fopen("./Database/Max Super/ID.txt", "a+");
        ptr4 = fopen("./Database/Max Super/temp.txt", "w");
        if(ptr==NULL){
        perror("Unable to open file");
        return ;
        }
        break;
        case 5: 
        ptr = fopen("./Database/Vedanta/patient.csv","a+");
        ptr3 = fopen("./Database/Vedanta/ID.txt", "a+");
        ptr4 = fopen("./Database/Vedanta/temp.txt", "w");
        if(ptr==NULL){
        perror("Unable to open file");
        return ;
        }
        break;
        default: 
        give_tab();printf("Invalid entry, press enter to try again\n"); getch();
        break;
    }

    char b[4],c[11],d[11],e[4],f[4],g[11];
    int rc,check1,check2,check3,check4,check5;
    rc = check1 = check2 = check3 = check4 = check5 = 0;
    get_id(n,b,ptr3,ptr4);
    fflush(stdin);
    printf("\n\n");
    give_tab();printf("Generated I'D and bed number is %s %s\n",b,b);
    start:
    rc = 0;
    give_tab();printf("Enter patient's First name: ");scanf("%s",c);rc++;while(1) {if(c[0]>=97 && c[0]<=122) c[0] = c[0] - 32; break;} check1 = recordchecker(c,rc); if(!check1) goto start ; fflush(stdin);
    start1:
    rc = 1;
    give_tab();printf("Enter patient's Last name: ");scanf("%s",d);rc++;while(1) {if(d[0]>=97 && d[0]<=122) d[0] = d[0] - 32; break;} check2 = recordchecker(d,rc); if(!check2) goto start1; fflush(stdin);
    start2:
    rc = 2;
    give_tab();printf("Enter patient's Age: ");scanf("%s",e);rc++; check3 = recordchecker(e,rc); if(!check3) goto start2; fflush(stdin);
    start3:
    rc = 3;
    give_tab();printf("Enter patient's gender: ");scanf("%s",f);rc++;while(1) {if(f[0]>=97 && f[0]<=122) f[0] = f[0] - 32; break;} check4 = recordchecker(f,rc); if(!check4) goto start3; fflush(stdin);
    start4:
    rc = 4;
    give_tab();printf("Enter patient's Number: ");scanf("%s",g);rc++; check5 = recordchecker(g,rc); if(!check5) goto start4; fflush(stdin);
    fprintf(ptr,"%s,%2s,%10s,%10s,%2s,%s,%10s\n",b,b,c,d,e,f,g);
    fclose(ptr);
    give_tab();printf("Record Created Successfully!!\n\n");
    char choice;
    give_tab();printf("Want to add another record[Y/N]");scanf("%c",&choice);
    if(choice=='Y')addrecord();
    else return;
}

//Generating Id and bed number
void get_id(int n,char b[4],FILE *ptr3,FILE *ptr4){
    char info1[100];
    char *token;
    int c=100,row=1;
    while(fgets(info1,sizeof(info1),ptr3)){
        fseek(ptr3, 0L, SEEK_END); 
        long int size = ftell(ptr3); 
        if(size==0)break;
        token = strtok(info1, ",");
        while( token != NULL ) {
            if(row==1){
                c=atoi(token);
                sprintf(b, "%d", c);
                b = token;printf("%s",b);
                row++;
                token = strtok(NULL, ",");continue;
            }
            fprintf(ptr4,"%s,",token);
            token = strtok(NULL, ",");
    }
    fclose(ptr4);fclose(ptr3);
    switch(n){
            case 1:
            remove("./Database/AIIMS/ID.txt");
            rename("./Database/AIIMS/temp.txt","./Database/AIIMS/ID.txt");
            break;
            case 2:
            remove("./Database/Apollo/ID.txt");
            rename("./Database/Apollo/temp.txt","./Database/Apollo/ID.txt");
            break;
            case 3:
            remove("./Database/Fortis/ID.txt");
            rename("./Database/Fortis/temp.txt","./Database/Fortis/ID.txt");
            break;
            case 4:
            remove("./Database/Max Super/ID.txt");
            rename("./Database/Max Super/temp.txt","./Database/Max Super/ID.txt");
            break;
            case 5: 
            remove("./Database/Vedanta/ID.txt");
            rename("./Database/Vedanta/temp.txt","./Database/Vedanta/ID.txt");
            break;
    }
    return;
    }
    fclose(ptr4);fclose(ptr3);
    FILE *ptr = fopen("./Database/Vacant.csv","a+"), *ptr2 = fopen("./Database/temp.csv","w");
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
                if(c>=101){
                    printf("\n\t\t\t");
                    printf("Seats in Choosen Hospital are full please choose other hospitals :)");
                    remove("./Database/temp.csv");
                    getch();
                    main_menu();
                }
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
    title();
    printf("\n\t\t\t\t\t\t\t\t!!!!!!!!!!!!!!!!!!!!! PATIENT RECORD !!!!!!!!!!!!!!!!!!!!!\n\n");
    FILE *ptr;
    int n;
    hospitals();
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
    give_tab();printf("This is the end of record\n");
    give_tab();printf("Press any key to continue.....");
    getch();
    return;
}

/*different hospital data*/
void show_vacant_beds(){
    system("cls");
    title();
    printf("\t\t\t\t\t\t\t\t\t\t---------------------------\n");
    printf("\t\t\t\t\t\t\t\t\t\t         Vacant Beds\n");
    printf("\t\t\t\t\t\t\t\t\t\t---------------------------\n\n");
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
    give_tab();printf("This is the end of record\n");
    give_tab();printf("Press any key to continue.....");
    getch();
    return;
}

void editrecord(){
    while(1){
        system("cls");
        title();printf("\n\t\t\t\t\t\t\t\t!!!!!!!!!!!!!!!!!!!! EDIT PATIENT RECORD !!!!!!!!!!!!!!!!!\n\n");
        FILE *ptr;
        int n, id, id1, i, occupied;
        hospitals();
        scanf("%d", &n);
        printf("\n\n");
        switch(n){
            case 1:
            ptr = fopen("./Database/AIIMS/patient.csv","r+");
            if(ptr==NULL){
            perror("Unable to open file");
            return ;
            }
            break;
            case 2:
            ptr = fopen("./Database/Apollo/patient.csv","r+");
            if(ptr==NULL){
            perror("Unable to open file");
            return ;
            }
            break;
            case 3:
            ptr = fopen("./Database/Fortis/patient.csv","r+");
            if(ptr==NULL){
            perror("Unable to open file");
            return ;
            }
            break;
            case 4:
            ptr = fopen("./Database/Max Super/patient.csv","r+");
            if(ptr==NULL){
            perror("Unable to open file");
            return ;
            }
            break;
            case 5: 
            ptr = fopen("./Database/Vedanta/patient.csv","r+");
            if(ptr==NULL){
            perror("Unable to open file");
            return ;
            }
            break;
            default: 
            give_tab();printf("Invalid entry, press enter to try again\n"); getch();
            break;
        }

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
        switch(n){
            case 1:
            ptr = fopen("./Database/AIIMS/patient.csv","r+");
            if(ptr==NULL){
            perror("Unable to open file");
            return ;
            }
            break;
            case 2:
            ptr = fopen("./Database/Apollo/patient.csv","r+");
            if(ptr==NULL){
            perror("Unable to open file");
            return ;
            }
            break;
            case 3:
            ptr = fopen("./Database/Fortis/patient.csv","r+");
            if(ptr==NULL){
            perror("Unable to open file");
            return ;
            }
            break;
            case 4:
            ptr = fopen("./Database/Max Super/patient.csv","r+");
            if(ptr==NULL){
            perror("Unable to open file");
            return ;
            }
            break;
            case 5: 
            ptr = fopen("./Database/Vedanta/patient.csv","r+");
            if(ptr==NULL){
            perror("Unable to open file");
            return ;
            }
            break;
            default: 
            give_tab();printf("Invalid entry, press enter to try again\n"); getch();
            break;
        }
        
        printf("\n");
        give_tab();printf("Enter patient ID: ");
        scanf("%d", &id);
        fscanf(ptr, "%*[^\n]s");
        
        while(fscanf(ptr, "%d", &id1) != EOF){
            if (id1 == id){
                fseek(ptr, 0, SEEK_CUR);
                char b[4],c[11],d[11],e[4],f,g[11];
                fflush(stdin);
                give_tab();printf("Enter the new info: \n");
                //give_tab();printf("Enter patient's Bed number: ");scanf("%s",b);fflush(stdin);
                sprintf(b,"%d",id);
                give_tab();printf("Enter patient's First name: ");scanf("%s",c);fflush(stdin);
                give_tab();printf("Enter patient's Last name: ");scanf("%s",d);fflush(stdin);
                give_tab();printf("Enter patient's Age: ");scanf("%s",e);fflush(stdin);
                give_tab();printf("Enter patient's gender: ");scanf("%c",&f);fflush(stdin);
                give_tab();printf("Enter patient's Number: ");scanf("%s",g);fflush(stdin);
                fprintf(ptr,",%s,%10s,%10s,%s,%c,%10s",b,c,d,e,f,g); 
                fseek(ptr, 0, SEEK_SET);
                break;
            }
            fscanf(ptr, "%*[^\n]s");
        }
        fclose(ptr);
        give_tab();printf("Do you want to edit more records (y/n) ?");
        char choice; 
        fflush(stdin);
        scanf("%c", &choice);
        if (choice == 'y') continue;
        else break;
    }
}

void deleterecord(){
    while(1){
        system("cls");
        title();printf("\n\t\t\t\t\t\t\t\t!!!!!!!!!!!!!!!!!! DELETE PATIENT RECORD !!!!!!!!!!!!!!!!!\n\n");
        FILE *ptr, *ptr2;
        int n, id, id1, i, occupied;
        hospitals();
        scanf("%d", &n);
        switch(n){
            case 1:
            ptr = fopen("./Database/AIIMS/patient.csv","r+");
            ptr2 = fopen("./Database/AIIMS/ID.txt", "a+");
            if(ptr==NULL){
            perror("Unable to open file");
            return ;
            }
            break;
            case 2:
            ptr = fopen("./Database/Apollo/patient.csv","r+");
            ptr2 = fopen("./Database/Apollo/ID.txt", "a+");
            if(ptr==NULL){
            perror("Unable to open file");
            return ;
            }
            break;
            case 3:
            ptr = fopen("./Database/Fortis/patient.csv","r+");
            ptr2 = fopen("./Database/Fortis/ID.txt", "a+");
            if(ptr==NULL){
            perror("Unable to open file");
            return ;
            }
            break;
            case 4:
            ptr = fopen("./Database/Max Super/patient.csv","r+");
            ptr2 = fopen("./Database/Max Super/ID.txt", "a+");
            if(ptr==NULL){
            perror("Unable to open file");
            return ;
            }
            break;
            case 5: 
            ptr = fopen("./Database/Vedanta/patient.csv","r+");
            ptr2 = fopen("./Database/Vedanta/ID.txt", "a+");
            if(ptr==NULL){
            perror("Unable to open file");
            return ;
            }
            break;
            default: 
            give_tab();printf("Invalid entry, press enter to try again\n"); getch();
            break;
        }
        give_tab();printf("Enter patient ID: ");
        scanf("%d", &id);
        fscanf(ptr, "%*[^\n]s");
        while(fscanf(ptr, "%d", &id1) != EOF){
            if (id1 == id){
                fseek(ptr, -1,SEEK_CUR);
                fprintf(ptr, "%44s"," ");
                fseek(ptr, 0, SEEK_SET);
                give_tab();printf("Record deleted successfully\n");
                break;
            }
            fscanf(ptr, "%*[^\n]s");
        }
        fprintf(ptr2,"%d,", id);
        fclose(ptr);
        fclose(ptr2);
       // give_tab();printf("Press enter to go back to main menu....");
        give_tab();printf("Do you wish to delete more records (y/n) ?");
        fflush(stdin);
        char choice;
        scanf("%c", &choice);
        if (choice == 'y') continue;
        else break;
    }
}


// For checking the input record by the user 
int recordchecker(char check[],int rc)
{
    int l,zz=1,i;
    l = strlen(check);

    if(rc==1 || rc==2)
    {
        for(i=0;i<l;i++)
        {
            if(!isalpha(check[i]))
            {
                zz = 0;
                printf("Enter carefully, some character is not a alphabet\n");
                break;
            }
        }
    }

    else if(rc==3)
    {
        for(i=0;i<l;i++)
        {
            if(!isdigit(check[i]))
            {
                zz = 0;
                printf("Enter carefully, some are not digits\n");
                break;
            }
        }
    }

    else if(rc==4)
    {
        for(i=0;i<l;i++)
        {
            if(check[i]=='f' || check[i]=='F' || check[i]=='m' || check[i]=='M')
            {
                continue;
            }
            else
            {
                zz = 0;
                printf("Enter carefully, characters are not F/f/M/m\n");
            }
        }
    }

    else if(rc==5)
    {
        for(i=0;i<l;i++)
        {
            if(l!=10)
            {
                zz = 0;
                printf("Length of number is either more or less than 10\n");
                break;
            }
            else if(check[0]<'6')
            {
                zz = 0;
                printf("Not valid number\n");
                break;
            }
            else if(!isdigit(check[i]))
            {
                zz = 0;
                printf("Enter carefully, number did not have number\n");
                break;
            }
        }
    }
    return (zz);
}

// To find the infection rate of any patient
void infectionrate()
{
    system("cls");
    welcome_screen_infection_checker();
    char a,b,c,d,e,f,firstname[20],lastname[20],state[20];
    int i,j=1,age,x,count=0,p;
        for (int i=0;i<100;i++)
        {
           printf("%c",j);
        }
        printf("\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 INFECTION RATE TEST COVID19  \xB3\xB2=\xB2=\xB2-\xB3\n\n");
 
        for(int i=0;i<100;i++)
        {
            printf("%c",j);
        }

   printf("\n\n");
   printf("\t\t\t\tPLEASE ENTER YOUR BASIC INFORMATION \n\n");
   printf("\tFIRST NAME:- ");
   scanf("%s",firstname);
   printf("\tLAST NAME:-");
   scanf("%s",lastname);
   printf("\tAGE:- ");
   scanf("%d", &age);
   if (age<=13 || age>=50)
   {
       count+=1;
   }

   printf("\tSTATE:- ");
   scanf("%s",state);

   for(int i=0;i<100;i++)
    {
        printf("%c",j);
    }

   printf("\n");


   printf("\t\t\t\t PLEASE ANSWER THE FOLLOWING QUESTION CORRECTLY\n");
   printf("\n\n\tDo you have any travel history across INDIA between jan to mar?(y/n)\nAns:- ");
   fflush(stdin);
   scanf("%c",&a);
   if(a=='y' || a=='Y')
   {
        count+=2;
   }
    printf("\n\n\t Do you came in contact with any covid infected parson?(y/n)\nAns:- ");
    fflush(stdin);
    scanf("%c", &b);
    if(b=='y' || b=='Y')
    {
        count+=2;
    }

    printf("\n\n\t Is there any covid patient in the range of 1 km?(y/n)\nAns:-  ");
    fflush(stdin);
    scanf("%c", &c);
    if(c=='y' || c=='Y')
    {
       count+=2;
    }
    printf("\n\n\tAre you suffering of any kind of diseases like CANCER,DIABETES or LUNGS DISEASES?(y/n)\nAns:- ");
    fflush(stdin);
    scanf("%c", &d);
    if(d=='y' || d=='Y')
    {
       count+=1;
    }
    printf("\n\n\tPlease let us know your body temperature(in C)\n Ans:-");
    scanf("%d",&x);
    if (x>=38)
    {
       count+=1;
    }
    printf("\n\n\t If you are suffering from any one write (y/n)\n\t1) Dry cough \n\t2) Shortness of breath \n\t3) Headaches \n\t4) Aches and Pains \n\t5) Sore throat \n\t6) fatigue \n\t7) Diarrhea  \nAns:- ");
    fflush(stdin);
    scanf("%c",&e);
    if(e=='y' || e=='Y')
    {
       count+=1;
    }
    printf("\n\n\tAre you suffering from bp or suger problem?(y/n)\n Ans:- ");
    fflush(stdin);
    scanf("%c",&f);
    if (f=='y'|| f=='Y')
    {
       count+=1;
    }

    printf("\n\n");
    for(int i=0;i<100;i++)
    {
        printf("%c",j);
    }
    printf("\n");
    printf("\t\t\t\t PLEASE WAIT WHILE WE ARE ANALYSING DATA \n");
    int s=10;
    while (1)
    {
        //printf("\n\t%d",s);
        sleep(0);
        // give_tab();
        // printf("Analysing./././\n");
        // give_tab();printf("\n\nPress any key to continue....");
        // getch();
        s--;

        if (s==0 )
        {
            printf("\n");
            for(int i=0;i<100;i++)
            {
                printf("%c",j);
            }
            printf("\n");
            printf("\n\n");
            for(int i=0;i<100;i++)
            {
                printf("%c",j);
            }
            printf("\n\n\t\t  \xB3\xB2=\xB2=\xB2-\xB3\xB3\xB2=\xB2=\xB2-\xB3            REPORT            \xB3\xB2=\xB2=\xB2-\xB3\xB3\xB2=\xB2=\xB2-\xB3\n\n");
            for(int i=0;i<100;i++)
            {
                printf("%c",j);
            }
            printf("\n");
            printf("\n\t \t\tFirst Name\t\tLast Name  \t\tAge \t\tState \n");
            printf("\n\t \t\t %s\t\t\t%s  \t\t\t%d \t\t%s \n",firstname,lastname,age,state);
            count=count*10;

           printf("\n\nYOUR RATE OF BEING INFECTED IS %d percent\n",count);
           break;
 
        }
    }
    char z1[4];
    give_tab();printf("\n\nPress any key to continue....");
    getch();
    give_tab();printf("\n\nWant to find infection rate of any other ?[y/n] ");
    scanf("%s",z1);
    printf("\n\n");
    if(strcmp(z1,"y")==0)
    infectionrate();
    
    system("cls");
}
