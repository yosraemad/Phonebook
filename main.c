#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "io.h"
#include "useroptions.h"
#include "validation.h"

int Count = 0;
Contact *Contacts ;

void showMenu();

void main() {
    //  TODO BUG TO BE FIXED OF ENTERING STRING
    char fileName[30] = "contacts";
    char lastName[15];
    int flag = 1;

    load(fileName);
    char help[2];
    char *end;
    char c;
    int choice;
    while(1) {
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

        switch (choice) {
            case 1:
                printf("Please the enter the file name:\n");
                scanf("%s", fileName);
                load(fileName);
                printContacts(Contacts, Count);
                break;
            case 2:
                printf("Please enter the contact's last name: \n");
                strcpy(lastName, readInput(lastName, sizeof(lastName)));
                strcpy(lastName, v_name(lastName));
                //scanf("%s", lastName);

                int num = 0;
                searchContacts(lastName, &num);
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
}


void showMenu(){
    printf("Welcome to the Phonebook!!\n");
    printf("Please choose one of the following commands\n");
    printf("1 --> Load\n");
    printf("2 --> Search\n");
    printf("3 --> Add\n");
    printf("4 --> Delete\n");
    printf("5 --> Modify\n");
    printf("6 --> Sort\n");
    printf("7 --> Save\n");
    printf("8 --> Print\n");
    printf("9 --> Quit\n");
}