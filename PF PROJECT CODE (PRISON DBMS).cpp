// Libraries
#include <conio.h>

#include <stdlib.h>

#include <stdio.h>

#include <string.h>

#include <time.h>

int CategorySelector();
int login(int categ);
int LoginSuccessful(int categ, char clear[10]);
int AddRecord();
int ViewRecord(int categ, char clear[10]);
int EditRecord();
int SearchRecord();
int DeleteRecord();
int ScheduleViewer(char clear[10]);
int VisitingTime();
int Feedback(int categ, char clear[10]);
int Exit();
int AccessChecker(int categ, int selection);
int ViewFeedback();
int PrisonerViewRecord(int categ, char clear[10]);

struct record {
  char id[100];
  char name[100];
  char weight[100];
  char height[100];
  char age[100];
  char gender[100];
  char haircolour[100];
  char eyecolour[100];
  char crime[100];
  char convictedcity[100];
  char court[100];
  char punishment[100];
  char lawyer[100];
  char punishmentstart[100];
  char punishmentend[100];
  char emergencyc[100];
  char emergencycn[100];
  char emergencycr[100];
  char cell[100];
  char block[100];
}
a;
struct feedback {
  char id[10];
  char complain[10000];
  char user[10];
  char position[100];
}
b;

int main() {
  int categ, clear;
  categ = CategorySelector();
  login(categ);
  return 0;
}

//Functions

//Category Selector

int CategorySelector() {
  int categ;
  printf("**************************************************\n");
  printf("**     Welcome to ABC Prison\n");
  printf("**     Please enter your category from the following categories:\n");
  printf("**     1. Cleaner\n**     2. Warden\n**     3.Prisoner\n**     4.Visitor\n");
  printf("     Category: ");
  scanf("%d", & categ);
  system("cls");
  return categ;
}

int login(int categ) {
  char username[10], password[10], c;
  int i = 0;
  char clear[10];
  for (i = 0; i < 10; i++)
    clear[i] = 'a';
  i = 0;
  printf("**************************************************\n");
  printf("     Please Enter Your Username");
  printf("\n     ");
  scanf("%s", & username);
  printf("\n");
  printf("     Please Enter Your Password");
  printf("\n     ");
  while (i < 10) {
    password[i] = getch();
    c = password[i];
    if (c == 13) break;
    else printf("*");
    i++;
  }
  password[i] = '\0';
  if (categ == 1) {
    if ((strcmp(username, "c1") == 0 && strcmp(password, "a") == 0) || strcmp(username, "c2") == 0 && strcmp(password, "b") == 0) {
      strcpy(clear, username);
      printf("\n\n     Welcome to the Prison Portal!");
      printf("\n     Please Enter Any Key To Continue!");
      getch();
      system("cls");
      LoginSuccessful(categ, clear);
    }
  }

  if (categ == 2) {
    if ((strcmp(username, "w1") == 0 && strcmp(password, "a") == 0) || strcmp(username, "w2") == 0 && strcmp(password, "b") == 0) {
      strcpy(clear, username);
      printf("\n\n     Welcome to the Prison Portal!");
      printf("\n     Please Enter Any Key To Continue!");
      getch();
      system("cls");
      LoginSuccessful(categ, clear);

    }
  }

  if (categ == 3) {
    if ((strcmp(username, "p1") == 0 && strcmp(password, "a") == 0) || strcmp(username, "p2") == 0 && strcmp(password, "b") == 0) {
      strcpy(clear, username);
      printf("\n\n     Welcome to the Prison Portal!");
      printf("\n     Please Enter Any Key To Continue!");
      getch();
      system("cls");
      LoginSuccessful(categ, clear);
    }
  }

  if (categ == 4) {
    if ((strcmp(username, "v1") == 0 && strcmp(password, "a") == 0) || strcmp(username, "v2") == 0 && strcmp(password, "b") == 0) {
      strcpy(clear, username);
      printf("\n\n     Welcome to the Prison Portal!");
      printf("\n     Please Enter Any Key To Continue!");
      getch();
      system("cls");
      LoginSuccessful(categ, clear);
    }
  } else {
    printf("\n     !!!!!Wrong Category, Username and Password combination!!!!!");
    printf("\n\n     Press any key to exit.");
    getch();
    system("cls");
    exit(1);
  }
  return 0;
}

int LoginSuccessful(int categ, char clear[10]) {
  int selection = 0, temp = 0;
  
  while (1) {
  	 printf("\n**************************************************\n");
    printf("\n\n\n     Access Menu (ABC Prison)\n ");
    printf("\n\n\n USER LOGGED IN RIGHT NOW \n");
    puts(clear);
    printf("\n");
    printf("\n**     ADD RECORD      <<1>>");
    printf("\n**     VIEW RECORD     <<2>>");
    printf("\n**     EDIT RECORD     <<3>>");
    printf("\n**     SEARCH RECORD   <<4>>");
    printf("\n**     DELETE RECORD   <<5>>");
    printf("\n**     SCHEDULE VIEWER <<6>>");
    printf("\n**     FEEDBACK PORTAL <<7>>");
    printf("\n**     VISITING TIME   <<8>>");
    printf("\n**     VIEW FEEDBACK   <<9>>");
    printf("\n**     EXIT 			 <<10>>");
    printf("\n \n \n");
    printf("**     PLEASE ENTER THE NUMBER CORRESPONDING TO YOUR CHOICE");
    scanf("%d", & selection);
    temp = AccessChecker(categ, selection);
    while (temp == 1) {
      switch (selection) {
      case 1:
        AddRecord();
        break;

      case 2:
        ViewRecord(categ, clear);
        break;

      case 3:
        EditRecord();
        break;

      case 4:
        SearchRecord();
        break;

      case 5:
        DeleteRecord();
        break;

      case 6:
        ScheduleViewer(clear);
        break;

      case 7:
        Feedback(categ, clear);
        break;

      case 8:
        VisitingTime();
        break;

      case 9:
        ViewFeedback();
        break;

      case 10:
        Exit();
        break;

      }
      break;
    }
  }
}
int AccessChecker(int categ, int selection) {
  if (categ == 1) {
    if ((selection == 6) || (selection == 7) || (selection == 10)) {
      return 1;
    } else {
      printf("\n**     YOU CANNOT ACCESS THE FOLLOWING CATEGORY.\n ACCESS DENIED!!");
      printf("\n**     PRESS ENTER TO CONTINUE");
      getch();
      system("cls");
      return 0;
    }
  }

  if (categ == 2) {
    if ((selection == 1) || (selection == 2) || (selection == 3) || (selection == 4) || (selection == 5) || (selection == 7) || (selection == 9) || (selection == 10)) {
      return 1;
    } else {
      printf("\n**     YOU CANNOT ACCESS THE FOLLOWING CATEGORY.\n ACCESS DENIED!!");
      printf("\n**     PRESS ENTER TO CONTINUE");
      getch();
      system("cls");
      return 0;
    }
  }
  if (categ == 3) {
    if ((selection == 2) || (selection == 7) || (selection == 10)) {
      return 1;
    } else {
      printf("\n**     YOU CANNOT ACCESS THE FOLLOWING CATEGORY.\n ACCESS DENIED!!");
      printf("\n**     PRESS ENTER TO CONTINUE");
      getch();
      system("cls");
      return 0;
    }
  }
  if (categ == 4) {
    if ((selection == 4) ||(selection == 7) ||  (selection == 8) || (selection == 10)) {
      return 1;
    } else {
      printf("\n**     YOU CANNOT ACCESS THE FOLLOWING CATEGORY.\n ACCESS DENIED!!");
      printf("\n**     PRESS ENTER TO CONTINUE");
      getch();
      system("cls");
      return 0;
    }
  }

  return 0;
}

int AddRecord() {
  FILE * fp;
  struct record a;
  char another = 'Y', id[10];
  char filename[30]; 	
  int choice;
  system("cls");

  printf("**************************************************\n");
  printf("\n**     WELCOME TO THE ADD MENU *");
  printf("**************************************************\n");
  printf("\n**     ENTER FIRST NAME OF PRISONER:");
  fflush(stdin);
  gets(filename);

  fp = fopen("filename", "ab+");

  if (fp == NULL) {

    fp = fopen("filename", "wb+");
    if (fp == NULL) {

      printf("\nSYSTEM ERROR...");
      printf("\nPRESS ANY KEY TO EXIT");
      getch();

    }
  }

  while (another == 'Y' || another == 'y')

  {
    choice = 0;
    fflush(stdin);

    printf("\n\n**     ENTER PRISONER ID:");
    scanf("%s", id);

    rewind(fp);

    while (fread( & a, sizeof(a), 1, fp) == 1) {
      if (strcmp(a.id, id) == 0) {

        printf("\n**     THE RECORD ALREADY EXISTS.\n");
        choice = 1;

      }

    }

    if (choice == 0) {

      strcpy(a.id, id);

      printf("\n**     ENTER PRISONER NAME: ");
      fflush(stdin);
      gets(a.name);

      printf("\n**     ENTER WEIGHT: ");
      gets(a.weight);
      fflush(stdin);

      printf("\n**     ENTER HEIGHT: ");
      gets(a.height);
      fflush(stdin);

      printf("\n**     ENTER AGE: ");
      gets(a.age);
      fflush(stdin);

      printf("\n**     ENTER GENDER: ");
      gets(a.gender);
      fflush(stdin);

      printf("\n**     ENTER EYE COLOUR: ");
      gets(a.eyecolour);
      fflush(stdin);

      printf("\n**     ENTER HAIR COLOUR: ");
      gets(a.haircolour);
      fflush(stdin);

      printf("\n**     ENTER CRIME: ");
      gets(a.crime);
      fflush(stdin);

      printf("\n**     ENTER THE CITY IN WHICH THE PRISONER WAS CONVICTED: ");
      gets(a.convictedcity);
      fflush(stdin);

      printf("\n**     ENTER COURT: ");
      gets(a.court);
      fflush(stdin);

      printf("\n**     ENTER LAWYER: ");
      gets(a.lawyer);
      fflush(stdin);

      printf("\n**     ENTER CONVICTION: ");
      gets(a.punishment);
      fflush(stdin);

      printf("\n**     ENTER THE DATE PUNISHMENT STARTED AT: ");
      gets(a.punishmentstart);
      fflush(stdin);

      printf("\n**     ENTER THE DATE PUNISHMENT ENDS AT: ");
      gets(a.punishmentend);
      fflush(stdin);

      printf("\n**     ENTER NAME OF EMERGENCY CONTACT: ");
      gets(a.emergencyc);
      fflush(stdin);

      printf("\n**     ENTER PHONE NUMBER OF EMERGENCY CONTACT: ");
      gets(a.emergencycn);

      printf("\n**     ENTER RELATION OF EMERGENCY CONTACT WITH PRISONER: ");
      gets(a.emergencycr);
      fflush(stdin);

      printf("\n**     ENTER CELL NUMBER OF PRISONER: ");
      gets(a.cell);
      fflush(stdin);

      printf("\n**     ENTER BLOCK NUMBER OF PRISONER: ");
      gets(a.block);
      fflush(stdin);
      fwrite( & a, sizeof(a), 1, fp);
      printf("\nYOUR RECORD IS ADDED...\n");

    }

    printf("\n**     ADD ANOTHER RECORD...(Y/N)      ");
    fflush(stdin);
    another = getch();

  }

  fclose(fp);
  printf("\n\n\n**     PRESS ANY KEY TO EXIT...");
  getch();
  system("cls");
}

int ViewRecord(int categ, char clear[10]) {
  if (categ == 3) {
    PrisonerViewRecord(categ, clear);
    return 0;
  }
  FILE * fp;
  struct record a;
  char filename[30];
  system("cls");

  printf("**************************************************\n");
  printf("\n**     PRISONER LIST");
  printf("**************************************************\n");

  fp = fopen("filename", "rb");
  rewind(fp);
  while ((fread( & a, sizeof(a), 1, fp)) == 1) {
    printf("||NOTE:-PRESS ENTER KEY TO LOAD OTHER RECORDS||\n");
    printf("\n**     PRISONER'S NAME IS: %s", a.name);
    printf("\n**     PRISONER'S WEIGHT IS: %s", a.weight);
    printf("\n**     PRISONER'S HEIGHT IS: %s", a.height);
    printf("\n**     PRISONER'S AGE IS: %s", a.age);
    printf("\n**     PRISONER'S GENDER IS: %s", a.gender);
    printf("\n**     PRISONER'S EYE COLOUR IS: %s", a.eyecolour);
    printf("\n**     PRISONER'S HAIR COLOUR IS: %s", a.haircolour);
    printf("\n**     PRISONER'S CRIME IS: %s", a.crime);
    printf("\n**     THE CITY IN WHICH THE PRISONER WAS CONVICTED IS: %s", a.convictedcity);
    printf("\n**     COURT IS: %s", a.court);
    printf("\n**     PRISONER'S LAWYER IS: %s", a.lawyer);
    printf("\n**     PRISONER'S CONVICTION IS: %s", a.punishment);
    printf("\n**     THE DATE PUNISHMENT STARTED AT IS: %s", a.punishmentstart);
    printf("\n**     THE DATE PUNISHMENT ENDS AT IS: %s", a.punishmentend);
    printf("\n**     PRISONER'S EMERGENCY CONTACT IS: %s", a.emergencyc);
    printf("\n**     RELATION OF EMERGENCY CONTACT WITH PRISONER IS: %s", a.emergencycr);
    printf("\n**     EMERGENCY CONTACT'S PHONE NUMBER IS: %s", a.emergencycn);
    printf("\n**     CELL NUMBER IS: %s", a.cell);
    printf("\n**     BLOCK NUMBER IS: %s", a.block);
    getch();
    printf("\n\n");

  }
  fclose(fp);
  getch();
  system("cls");
}
int PrisonerViewRecord(int categ, char clear[10]) {
  FILE * fp;
  char id[16], choice, filename[14];
  int ch;
  system("cls");

  printf("**************************************************\n");
  printf("**     FOLLOWING ARE YOUR DETAILS");
  printf("**************************************************\n");

  fflush(stdin);
  gets(filename);
  fp = fopen("filename", "rb");
  system("cls");
  strcpy(id, clear);
  printf("\nTHE WHOLE RECORD IS:");
  printf("\nYour ID is: ");
  puts(clear);
  while (fread( & a, sizeof(a), 1, fp) == 1)

    //{
    if (strcmpi(a.id, id) == 0) {
      printf("\n**     PRISONER'S NAME IS: %s", a.name);
      printf("\n**     PRISONER'S WEIGHT IS: %s", a.weight);
      printf("\n**     PRISONER'S HEIGHT IS: %s", a.height);
      printf("\n**     PRISONER'S AGE IS: %s", a.age);
      printf("\n**     PRISONER'S GENDER IS: %s", a.gender);
      printf("\n**     PRISONER'S EYE COLOUR IS: %s", a.eyecolour);
      printf("\n**     PRISONER'S HAIR COLOUR IS: %s", a.haircolour);
      printf("\n**     PRISONER'S CRIME IS: %s", a.crime);
      printf("\n**     THE CITY IN WHICH THE PRISONER WAS CONVICTED IS: %s", a.convictedcity);
      printf("\n**     COURT IS: %s", a.court);
      printf("\n**     PRISONER'S LAWYER IS: %s", a.lawyer);
      printf("\n**     PRISONER'S CONVICTION IS: %s", a.punishment);
      printf("\n**     THE DATE PUNISHMENT STARTED AT IS: %s", a.punishmentstart);
      printf("\n**     THE DATE PUNISHMENT ENDS AT IS: %s", a.punishmentend);
      printf("\n**     PRISONER'S EMERGENCY CONTACT IS: %s", a.emergencyc);
      printf("\n**     RELATION OF EMERGENCY CONTACT WITH PRISONER IS: %s", a.emergencycr);
      printf("\n**     EMERGENCY CONTACT'S PHONE NUMBER IS: %s", a.emergencycn);
      printf("\n**     CELL NUMBER IS: %s", a.cell);
      printf("\n**     BLOCK NUMBER IS: %s", a.block);

      printf("\n");
    }

  fclose(fp);
  printf("PRESS ENTER TO EXIT.");
  getch();
  system("cls");
  return 0;
}

int EditRecord() {
  FILE * fp;
  char id[10], choice, filename[14];
  int num, count = 0;
  system("cls");

  printf("**************************************************\n");
  printf("**     WELCOME TO THE EDITING MENU");
  printf("**************************************************\n");

  do {

    printf("\n**     ENTER THE PRISONER NAME TO BE EDITED:");
    fflush(stdin);
    gets(filename);

    printf("\n**     ENTER ID:");
    gets(id);
    fp = fopen("filename", "rb+");

    if (fp == NULL) {

      printf("\n**     ERROR IN OPENING FILE.");
      printf("\n**     PRESS ANY KEY TO GO BACK");
      getch();
      return 0;
    }

    while (fread( & a, sizeof(a), 1, fp) == 1) {

      if (strcmp(a.id, id) == 0) {

        printf("\n**     CURRENT RECORD IS AS FOLLOWS\n:");
        printf("\n**     PRISONER'S NAME IS: %s", a.name);
        printf("\n**     PRISONER'S WEIGHT IS: %s", a.weight);
        printf("\n**     PRISONER'S HEIGHT IS: %s", a.height);
        printf("\n**     PRISONER'S AGE IS: %s", a.age);
        printf("\n**     PRISONER'S GENDER IS: %s", a.gender);
        printf("\n**     PRISONER'S EYE COLOUR IS: %s", a.eyecolour);
        printf("\n**     PRISONER'S HAIR COLOUR IS: %s", a.haircolour);
        printf("\n**     PRISONER'S CRIME IS: %s", a.crime);
        printf("\n**     THE CITY IN WHICH THE PRISONER WAS CONVICTED IS: %s", a.convictedcity);
        printf("\n**     COURT IS: %s", a.court);
        printf("\n**     PRISONER'S LAWYER IS: %s", a.lawyer);
        printf("\n**     PRISONER'S CONVICTION IS: %s", a.punishment);
        printf("\n**     THE DATE PUNISHMENT STARTED AT IS: %s", a.punishmentstart);
        printf("\n**     THE DATE PUNISHMENT ENDS AT IS: %s", a.punishmentend);
        printf("\n**     PRISONER'S EMERGENCY CONTACT IS: %s", a.emergencyc);
        printf("\n**     RELATION OF EMERGENCY CONTACT WITH PRISONER IS: %s", a.emergencycr);
        printf("\n**     EMERGENCY CONTACT'S PHONE NUMBER IS: %s", a.emergencycn);
        printf("\n**     CELL NUMBER IS: %s", a.cell);
        printf("\n**     BLOCK NUMBER IS: %s", a.block);

        printf("\n\n**     WHAT WOULD YOU LIKE TO EDIT..");

        printf("\n**     1.NAME.");
        printf("\n**     2.GENDER.");
        printf("\n**     3.AGE.");
        printf("\n**     4.WEIGHT.");
        printf("\n**     5.HEIGHT.");
        printf("\n**     6.HAIR COLOUR.");
        printf("\n**     7.EYE COLOUR.");
        printf("\n**     8.CRIME.");
        printf("\n**     9.PLACE WHERE THE PRISONER WAS CONVICTED.");
        printf("\n**     10.COURT.");
        printf("\n**     11.LAWYER.");
        printf("\n**     12.CONVICTION.");
        printf("\n**     13.STARTING DATE OF PUNISHMENT.");
        printf("\n**     14.ENDING DATE OF PUNISHMENT.");
        printf("\n**     15.EMERGENCY CONTACT.");
        printf("\n**     16.RELATION OF EMERGENCY CONTACT.");
        printf("\n**     17.EMERGENCY CONTACT'S PHONE NUMBER.");
        printf("\n**     18.CELL NUMBER.");
        printf("\n**     19.BLOCK NUMBER.");
        printf("\n**     20.WHOLE RECORD.");
        printf("\n**     21.GO BACK TO MAIN MENU.");

        do {

          printf("\n**     ENTER YOUR CHOICE:");
          fflush(stdin);
          scanf("%d", & num);
          fflush(stdin);

          switch (num) {

          case 1:
            printf("\n**     ENTER THE NEW DATA:");
            printf("\n**     NAME:");
            gets(a.name);
            break;

          case 2:
            printf("\n**     ENTER THE NEW DATA:");
            printf("\n**     GENDER:");
            gets(a.gender);
            break;

          case 3:
            printf("\n**     ENTER THE NEW DATA:");
            printf("\n**     AGE:");
            gets(a.age);
            break;

          case 4:
            printf("\n**     ENTER THE NEW DATA:");
            printf("\n**     WEIGHT:");
            gets(a.weight);
            break;

          case 5:
            printf("**     ENTER THE NEW DATA:");
            printf("\n**     HEIGHT:");
            gets(a.height);
            break;

          case 6:
            printf("**     ENTER THE NEW DATA:");
            printf("\n**     haircolour:");
            gets(a.haircolour);
            break;

          case 7:
            printf("**     ENTER THE NEW DATA:");
            printf("\n**     EYE COLOUR:");
            gets(a.eyecolour);
            break;

          case 8:
            printf("**     ENTER THE NEW DATA:");
            printf("\n**     CRIME:");
            gets(a.crime);
            break;

          case 9:
            printf("**     ENTER THE NEW DATA:");
            printf("\n**     CITY:");
            gets(a.convictedcity);
            break;

          case 10:
            printf("**     ENTER THE NEW DATA:");
            printf("\n**     COURT:");
            gets(a.court);
            break;

          case 11:
            printf("**     ENTER THE NEW DATA:");
            printf("\n**     LAWYER:");
            gets(a.lawyer);
            break;

          case 12:
            printf("**     ENTER THE NEW DATA:");
            printf("\n**     CONVICTION:");
            gets(a.punishment);
            break;

          case 13:
            printf("**     ENTER THE NEW DATA:");
            printf("\n**     STARTING DATE OF PUNISHMENT:");
            gets(a.punishmentstart);
            break;

          case 14:
            printf("**     ENTER THE NEW DATA:");
            printf("\n**     ENDING DATE OF PUNISHMENT:");
            gets(a.punishmentend);
            break;

          case 15:
            printf("**     ENTER THE NEW DATA:");
            printf("\n**     EMERGENCY CONTACT:");
            gets(a.emergencyc);
            break;

          case 16:
            printf("**     ENTER THE NEW DATA:");
            printf("\n**     RELATION OF EMERGENCY CONTACT:");
            gets(a.emergencycr);
            break;

          case 17:
            printf("**     ENTER THE NEW DATA:");
            printf("\n**     PHONE NUMBER OF EMERGENCY CONTACT:");
            gets(a.emergencyc);
            break;
          case 18:
            printf("**     ENTER THE NEW DATA:");
            printf("\n**     CELL NUMBER:");
            gets(a.cell);
            break;
          case 19:
            printf("**     ENTER THE NEW DATA:");
            printf("\n**     BLOCK NUMBER:");
            gets(a.block);
            break;

          case 20:
            printf("\n**     ENTER THE NEW DATA:");
            printf("\n**     PRISONER NAME:");
            gets(a.name);
            printf("\n**GENDER:");
            gets(a.gender);
            printf("\n**AGE:");
            gets(a.age);
            printf("\n**WEIGHT:");
            gets(a.weight);
            printf("\n**HEIGHT:");
            gets(a.height);
            printf("\n**haircolour:");
            gets(a.haircolour);
            printf("\n**EYE COLOUR:");
            gets(a.eyecolour);
            printf("\n**CRIME:");
            gets(a.age);
            printf("\n**THE CITY IN WHICH THE PRISONER WAS CONVICTED:");
            gets(a.convictedcity);
            printf("\n**COURT:");
            gets(a.court);
            printf("\n**LAWYER:");
            gets(a.lawyer);
            printf("\n**CONVICTION:");
            gets(a.punishment);
            printf("\n**THE DATE PUNISHMENT STARTED AT:");
            gets(a.punishmentstart);
            printf("\n**THE DATE PUNISHMENT ENDS AT:");
            gets(a.punishmentend);
            printf("\n**NAME OF EMERGENCY CONTACT:");
            gets(a.emergencyc);
            printf("\n**RELATION OF EMERGENCY CONTACT WITH PRISONER:");
            gets(a.emergencycr);
            printf("\n**PHONE NUMBER OF EMERGENCY CONTACT:");
            gets(a.emergencycn);
            printf("\nCELL NUMBER IS: %s", a.cell);
            gets(a.cell);
            printf("\nBLOCK NUMBER IS: %s", a.block);
            gets(a.block);

            break;

          case 21:
            printf("\nPRESS ANY KEY TO GO BACK...\n");
            getch();
            return 0;
            break;

          default:
            printf("\nYOU TYPED SOMETHING ELSE...TRY AGAIN\n");
            break;

          }

        }
        while (num < 1 || num > 20);

        fseek(fp, -sizeof(a), SEEK_CUR);

        fwrite( & a, sizeof(a), 1, fp);

        fseek(fp, -sizeof(a), SEEK_CUR);

        fread( & a, sizeof(a), 1, fp);

        choice = 5;

        break;

      }
    }

    if (choice == 5)

    {

      system("cls");

      printf("\n**     EDITING COMPLETED **     \n");
      printf("**************************************************\n");
      printf("THE NEW RECORD IS:\n");
      printf("**************************************************\n");

      printf("\n**     PRISONER'S NAME IS: %s", a.name);
      printf("\n**     PRISONER'S WEIGHT IS: %s", a.weight);
      printf("\n**     PRISONER'S HEIGHT IS: %s", a.height);
      printf("\n**     PRISONER'S AGE IS: %s", a.age);
      printf("\n**     PRISONER'S GENDER IS: %s", a.gender);
      printf("\n**     PRISONER'S EYE COLOUR IS: %s", a.eyecolour);
      printf("\n**     PRISONER'S HAIR COLOUR IS: %s", a.haircolour);
      printf("\n**     PRISONER'S CRIME IS: %s", a.crime);
      printf("\n**     THE CITY IN WHICH THE PRISONER WAS CONVICTED IS: %s", a.convictedcity);
      printf("\n**     COURT IS: %s", a.court);
      printf("\n**     PRISONER'S LAWYER IS: %s", a.lawyer);
      printf("\n**     PRISONER'S CONVICTION IS: %s", a.punishment);
      printf("\n**     THE DATE PUNISHMENT STARTED AT IS: %s", a.punishmentstart);
      printf("\n**     THE DATE PUNISHMENT ENDS AT IS: %s", a.punishmentend);
      printf("\n**     PRISONER'S EMERGENCY CONTACT IS: %s", a.emergencyc);
      printf("\n**     RELATION OF EMERGENCY CONTACT WITH PRISONER IS: %s", a.emergencycr);
      printf("\n**     EMERGENCY CONTACT'S PHONE NUMBER IS: %s", a.emergencycn);
      printf("\n**     CELL NUMBER IS: %s", a.cell);
      printf("\n**     BLOCK NUMBER IS: %s", a.block);

      fclose(fp);

      printf("\n\n**     WOULD YOU LIKE TO EDIT ANOTHER RECORD.(Y/N)");
      scanf("%c", & choice);
      count++;

    } else {

      printf("\n**     THE RECORD DOES NOT EXIST::\n");
      printf("\n**     WOULD YOU LIKE TO TRY AGAIN...(Y/N)");
      scanf("%c", & choice);

    }
  }
  while (choice == 'Y' || choice == 'y');

  fclose(fp);
  printf("**     PRESS ENTER TO EXIT EDITING MENU.");
  getch();
  system("cls");
}


int SearchRecord() {
  FILE * fp;
  char id[16], choice, filename[14];
  int ch;
  system("cls");

  printf("**************************************************\n");
  printf("\n**     RECORD SEARCHING MENU");
  printf("**************************************************\n");

  do {

    printf("\n\n**     ENTER THE PRISONER NAME TO BE SEARCHED:");
    fflush(stdin);
    gets(filename);

    fp = fopen("filename", "rb");
    system("cls");

    printf("\nENTER PRISONER ID:");
    gets(id);
    system("cls");
    printf("\nTHE WHOLE RECORD IS:");

    while (fread( & a, sizeof(a), 1, fp) == 1)

      //{
      if (strcmpi(a.id, id) == 0) {
        printf("\n");
        printf("\nPRISONER'S NAME IS: %s", a.name);
        printf("\nPRISONER'S WEIGHT IS: %s", a.weight);
        printf("\nPRISONER'S HEIGHT IS: %s", a.height);
        printf("\nPRISONER'S AGE IS: %s", a.age);
        printf("\nPRISONER'S GENDER IS: %s", a.gender);
        printf("\nPRISONER'S EYE COLOUR IS: %s", a.eyecolour);
        printf("\nPRISONER'S HAIR COLOUR IS: %s", a.haircolour);
        printf("\nPRISONER'S CRIME IS: %s", a.crime);
        printf("\nTHE CITY IN WHICH THE PRISONER WAS CONVICTED IS: %s", a.convictedcity);
        printf("\nCOURT IS: %s", a.court);
        printf("\nPRISONER'S LAWYER IS: %s", a.lawyer);
        printf("\nPRISONER'S CONVICTION IS: %s", a.punishment);
        printf("\nTHE DATE PUNISHMENT STARTED AT IS: %s", a.punishmentstart);
        printf("\nTHE DATE PUNISHMENT ENDS AT IS: %s", a.punishmentend);
        printf("\nPRISONER'S EMERGENCY CONTACT IS: %s", a.emergencyc);
        printf("\nRELATION OF EMERGENCY CONTACT WITH PRISONER IS: %s", a.emergencycr);
        printf("\nEMERGENCY CONTACT'S PHONE NUMBER IS: %s", a.emergencycn);
        printf("\nCELL NUMBER IS: %s", a.cell);
        printf("\nBLOCK NUMBER IS: %s", a.block);
        printf("\n");
      }

    printf("\n\nWOULD YOU LIKE TO CONTINUE VIEWING...(Y/N):");
    fflush(stdin);

    scanf("%c", & choice);

  }
  while (choice == 'Y' || choice == 'y');

  fclose(fp);
  getch();
  system("cls");
  return 0;
}

int DeleteRecord() {
  FILE * fp, * ft;
  struct record file;
  char filename[15], another = 'Y', id[16];;
  int choice, check;
  system("cls");

  printf("**************************************************\n");
  printf("\n**     RECORD DELETE/REMOVAL MENU");
  printf("**************************************************\n");

  while (another == 'Y' || another == 'y') {
    fflush(stdin);
    printf("\n\n**     ENTER THE NAME OF PRISONER TO BE DELETED:");
    gets(filename);
    fp = fopen("filename", "rb");
    if (fp == NULL) {
      printf("\nTHE FILE DOES NOT EXIST");
      printf("\nPRESS ANY KEY TO GO BACK.");
      getch();
      return 0;
    }
    ft = fopen("temp", "wb");

    if (ft == NULL) {
      printf("\nSYSTEM ERROR");
      printf("\nPRESS ANY KEY TO GO BACK");
      getch();
      return 0;
    }
    printf("\n\n**     ENTER THE ID OF RECORD TO BE DELETED:");
    fflush(stdin);
    gets(id);

    while (fread( & file, sizeof(file), 1, fp) == 1)

    {

      if (strcmp(file.id, id) != 0)

        fwrite( & file, sizeof(file), 1, ft);

    }
    fclose(ft);
    fclose(fp);
    remove("filename");
    rename("temp", "filename");
    printf("\nDELETED SUCCESFULLY...");
    getch();

    printf("\n\n**     WOULD YOU LIKE TO DELETE ANOTHER RECORD.(Y/N):");
    fflush(stdin);
    scanf("%c", & another);
  }
  printf("\n\n**     PRESS ANY KEY TO EXIT...");
  getch();
}

int ScheduleViewer(char clear[10]) {
  system("cls");
  printf("**************************************************\n");
  printf("\n\n\n");
  if (strcmp(clear, "c1") == 0) {
    printf("Your Schedule is as Follows:\n\n");
    printf("Monday to Thursday, 8AM to 9:30PM");
    printf("\n\n Emergency Duty: On Call Friday Through Sunday");
    printf("\n PLEASE PRESS ENTER TO CONTINUE");
    getch();
    system("cls");
  }
  if (strcmp(clear, "c2") == 0) {
    printf("Your Schedule is as Follows:\n\n");
    printf("Saturday to Tuesday, 5AM to 6:30PM");
    printf("\n\n Emergency Duty: On Call Wednesday Through Friday");
    printf("\n PLEASE PRESS ENTER TO CONTINUE");
    getch();
    system("cls");
  }
}

int Feedback(int categ, char clear[10]) {
  FILE * fp;
  struct feedback b;
  char filename2[30];
  int choice;
  system("cls");

  printf("**************************************************\n");
  printf("\n**      WELCOME TO THE FEEDBACK MENU ");
  printf("\n**************************************************\n");
  fflush(stdin);
  gets(filename2);

  fp = fopen("filename2", "a");
  if (fp == NULL) {

    printf("\nSYSTEM ERROR...");
    printf("\nPRESS ANY KEY TO EXIT");
    getch();

  }
  printf("\n**     ENTER ID OF WHO YOU ARE LODGING A COMPLAINT AGAINST. ");
  scanf("%s", & b.id);
  //who is complaining;
  strcpy(b.user, clear);
 
  
  if (categ == 1) {
    strcpy(b.position, "cleaner");
  }
  if (categ == 2) {
    strcpy(b.position, "warden");
  }
  if (categ == 3) {
    strcpy(b.position, "prisoner");
  }
  if (categ == 4) {
    strcpy(b.position, "visitor");
  }

  fflush(stdin);
  printf("\n**     ENTER YOUR COMPLAINT/FEEDBACK");
  gets(b.complain);

  fwrite( & b, sizeof(b), 1, fp);
  printf("\nYOUR COMPLAIN HAS BEEN RECORDED...\n");

  fclose(fp);
  printf("\n\n\n**     PRESS ANY KEY TO EXIT...");
  getch();
  system("cls");

}

int VisitingTime() {
  srand(time(NULL));
  int a = rand() % 100;
  printf("**************************************************\n");
  printf("\n\n\n PLEASE NOTE: DUE TO COVID RESTRICTIONS\n\n\nENTRY WITHOUT PPE IS STRICTLY NOT ALLOWED");
  printf("\n PPE IS PERSONAL PROTECTIVE EQUIPMENT, AND INCLUDES GLOVES AND MASKS.");
  printf("\n\n ALSO, SUNDAY HAS BEEN ALLOCATED A FREE DAY, VISITING TIMES FOR SUNDAY ARE 8AM TO 11PM");

  if (a < 30) {
    printf("\n\n\nVISITING HOURS FOR TODAY ARE 12PM TO 4PM");
  }
  if (a > 30 && a < 70) {
    printf("\n\n\nVISITING HOURS FOR TODAY ARE 9AM TO 11AM");
  }
  if (a > 70 && a < 100) {
    printf("\n\n\nVISITING HOURS FOR TODAY ARE 4PM TO 6PM");
  }
  printf("\n\nPLEASE PRESS ENTER TO CONTINUE.");
  getch();
  system("cls");
  return 0;
}

int ViewFeedback() {
  printf("**************************************************\n");
  ("Please Press Enter to View All Feedback/Complaints/Comments Lodged To Date.");
  system("cls");
  FILE * fp;
  struct feedback b;
  char filename2[30];
  fp = fopen("filename2", "rb");
  while ((fread( & b, sizeof(b), 1, fp)) == 1) {
    printf("||NOTE:-PRESS ENTER KEY TO LOAD OTHER RECORDS||\n");
    printf("\nTHE CATEGORY TO WHICH THE LODGER OF THE FEEDBACK BELONGS TO IS %s", b.position);
    printf("\nTHE ID OF THE LODGER IS %s", b.user);
    printf("\nTHE COMPLAIN HAS BEEN LODGED AGAINSTED ID #%s", b.id);
    printf("\n THE COMPLAIN IS AS FOLLOWS \n %s\n", b.complain);
    getch();
    printf("\n\n");
  }
  fclose(fp);
  getch();
}

int Exit() {
  system("cls");
  printf("**************************************************\n");
  printf("\n\n\n\n\n");
  printf("THIS WAS A PRISON MANAGEMENT SYSTEM DEVELOPED BY TEAM PRO1\n");
  printf("\n THANK YOU FOR USING THIS PROGRAM!");
  exit(1);
}
