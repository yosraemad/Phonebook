#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "io.h"
#include "useroptions.h"
#include "validation.h"
#if defined(_WIN32)
    #define PLATFORM_NAME "windows" // Windows
#elif defined(__linux__)
    #define PLATFORM_NAME "linux"
#endif
int Count = 0;
Contact *Contacts ;

void showMenu();
void clearScreen();

void main() {
    char fileName[30] = "contacts";
    char lastName[15];
    int flag = 1;

    load(fileName);
    char help[2];
    char *end;
    char c;
    int choice;
    while (1) {
        clearScreen();
        showMenu();
        fgets(help, 10000, stdin);
        help[1] = 0;
        choice = strtol(help, &end, 10);
        while (!choice) {
            printf("Please enter a number\n");
            fgets(help, 100, stdin);
            help[1] = 0;
            choice = strtol(help, &end, 10);
        }
        clearScreen();
        switch (choice) {
            case 1:
                printf("Please the enter the file name:\n");
                scanf("%s", fileName);
                load(fileName);
                printContacts(Contacts, Count);
                break;
            case 2:
                printf("Do you want to search by (L)ast name or (M)ulti-search?\n");
                scanf("%c", &c);
                getchar();
                fflush(stdin);
                flag = 1;
                while (flag) {
                    flag = 0;
                    switch (c) {
                        case ('L'):
                            printf("Please enter the contact's last name: \n");
                            strcpy(lastName, readInput(lastName, sizeof(lastName)));
                            strcpy(lastName, v_name(lastName));
                            //scanf("%s", lastName);

                            int num = 0;
                            searchContacts(lastName, &num);
                            break;
                        case ('M'):
                            multiSearch();
                            break;
                        default:
                            printf("Command not recognized please renter the operation:\n");
                            scanf(" %c", &c);
                            fflush(stdin);
                            flag = 1;
                            continue;
                    }
                    break;
                    case 3:
                        add_new_contact();
                    break;
                    case 4:
                        delete_contact();
                    break;
                    case 5:
                        modify_contact();
                    break;
                    case 6:
                        sort();
                    break;
                    case 7:
                        saveFile(fileName);
                    break;
                    case 8:
                        printContacts(Contacts, Count);
                    break;

                    case 9:
                        printf("Make sure you've saved your changes before quitting or all changes will be discarded\n");
                    printf("Please enter the number of the command:\n");
                    printf("1. Exit\n");
                    printf("2. Save and Exit\n");
                    scanf(" %c", &c);
                    fflush(stdin);
                    flag = 1;
                    while (flag) {
                        flag = 0;
                        switch (c) {
                            case ('1'):
                                printf("Goodbye!");
                                exit(0);
                            case ('2'):
                                saveFile(fileName);
                                printf("Goodbye!");
                                exit(0);
                            default:
                                printf("Command not recognized please renter the number of operation:\n");
                                scanf(" %c", &c);
                                flag = 1;
                                break;
                        }
                    }

                    default:
                        printf("Command not recognized\n");
                }
        }
        printf("Press any key to continue");
        getch();
    }
}

void showMenu() {
    printf("\t\t --------Welcome to the Phonebook!!--------\n\n");
    printf("\t\tPlease choose one of the following commands\n\n");
    printf("\t\t\t\t1 --> Load\n");
    printf("\t\t\t\t2 --> Search\n");
    printf("\t\t\t\t3 --> Add\n");
    printf("\t\t\t\t4 --> Delete\n");
    printf("\t\t\t\t5 --> Modify\n");
    printf("\t\t\t\t6 --> Sort\n");
    printf("\t\t\t\t7 --> Save\n");
    printf("\t\t\t\t8 --> Print\n");
    printf("\t\t\t\t9 --> Quit\n\n");
}
//checks OS version and clears the screen
void clearScreen(){
    if(strcmp(PLATFORM_NAME,"windows") == 0)
        system("cls");
    else if (strcmp(PLATFORM_NAME,"linux") == 0)
        system("clear");
}