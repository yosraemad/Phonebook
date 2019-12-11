#include <stdio.h>
#include <stdlib.h>

#include "io.h"
#include "useroptions.h"

int Count = 0;
Contact Contacts[100];

void showMenu();

void main() {


    int choice;
    while(1) {
        showMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                load();
                break;
            case 2:
                printf("Please enter the contact's last name: \n");
                break;
            case 3:
                add_new_contact();
                break;
            case 4:
                printf("Deleting..\n");
                break;
            case 5:
                printf("Modifying..\n");
                break;
            case 6:
                printf("Sorting..\n");
                break;
            case 7:
                printf("Saving..\n");
                break;
            case 8:
                exit(0);
            default:
                printf("Command not recognized\n");


        }
    }
}


void showMenu(){
    printf("Please choose one of the following commands\n");
    printf("1 --> Load\n");
    printf("2 --> Search\n");
    printf("3 --> Add\n");
    printf("4 --> Delete\n");
    printf("5 --> Modify\n");
    printf("6 --> Sort\n");
    printf("7 --> Save\n");
    printf("8 --> Quit\n");
}