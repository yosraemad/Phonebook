#include <stdio.h>
#include <stdlib.h>

#include "io.h"
#include "useroptions.h"

int Count = 0;
Contact *Contacts ;

void showMenu();

void main() {
    //  BUG TO BE FIXED OF ENTERTING STRING
    char fileName[30] = "contacts.txt";
    char lastName[15];

    load(fileName);
    int choice;
    while(1) {
        showMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Please the enter the file name with extension ex'contacts.txt':\n");
                scanf("%s", fileName);
                load(fileName);
                printContacts(Contacts, Count);
                break;
            case 2:
                printf("Please enter the contact's last name: \n");
                scanf("%s", lastName);
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
                exit(0);
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