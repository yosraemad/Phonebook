#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "models.h"

void add_new_contact()
{
    // VALIDATIONS TO BE DONE

    char birthday[11];
    Contact *contact = (Contact*)malloc(sizeof(Contact));
    printf("Please enter the contact first name:\n");
    scanf("%s", contact->firstName);
    printf("Please enter the contact last name:\n");
    scanf("%s", contact->lastName);
    printf("Please enter the contact number:\n");
    scanf("%s", contact->phoneNum);
    printf("Please enter the contact email:\n");
    scanf("%s", contact->email);
    printf("Please enter the contact address:\n");
    scanf (" %[^\n]s", contact->stName);
    printf("Please enter the contact birthday:\n");
    scanf("%s", birthday);

    DateOfBirth *bd = BirthdayConstructor(birthday);
    contact->dateOfBirth = *bd;
    Contacts[Count] = *contact;
    Count++;

    printf("Contact added Successfully!\n");
    printContact(*contact);
    printf("\n");
}

Contact** searchContacts(char* lastName, int* number)
{
    Contact** contacts = (Contact**)malloc(1 *sizeof(Contact));
    int i, j = 0;
    for (i = 0; i < Count; i++){
        if (!strcasecmp(Contacts[i].lastName, lastName)) {
            contacts = realloc(contacts, (j+1)* sizeof(Contact));
            contacts[j] = &Contacts[i];
            j++;
        }
    }

    if (!j) {
        printf("No contact with this last name is found\n");
        return NULL;
    }

    printContacts(*contacts, j);

    *number = j;
    return contacts;
}

void delete_contact()
{
    char firstName[15];
    char lastName[15];
    int i,j, flag = 0;
    printf("Please enter the first and last name of the contact ex'Ahmed Muhammed':\n");
    scanf("%s %s", firstName, lastName);
    for (i = 0; i < Count; i++) {
        if (!strcasecmp(Contacts[i].firstName, firstName))
            if (!strcasecmp(Contacts[i].lastName, lastName)) {
                printContact(Contacts[i]);
                flag = 1;
                break;
            }
    }

    if (!flag) {
        printf("No contact with these first name and last name found\n");
        return;
    }


    for(j = i; j < Count; j++)
        Contacts [j]=Contacts[j+1] ;

    printf("Contact deleted successfully!\n");
    Count--;
}

void modify_contact()
{
    char c;
    int num,flag = 0, s = 0;
    char birthday[10];
    char lastName[15];
    printf("Please enter the contact's last name: \n");
    scanf(" %s", lastName);
    Contact** contacts = searchContacts(lastName, &num);
    printContacts(*contacts, num);
    printf("Please enter the number of the contact you want to modify:\n");
    scanf("%d",&s);
    while(s > num || s <= 0) {
        printf("Please enter a correct number:\n ");
        scanf(" %d",&s);
    }
    Contact *selectedContact = contacts[s-1];
    printContact(*selectedContact);
    printf("Please enter the property that you would like to edit\n");
    printf("(L)ast name, (F)irst name,(S)treet name, (E)mail, (P)hone, (D)ate of birth:\n");
    while (!flag) {
        flag = 1;
        scanf(" %c", &c);
        printf("Please enter the new value:\n");
        switch (c) {
            case ('L'):
                scanf("%s", selectedContact->lastName);
                break;
            case ('F'):
                scanf("%s", selectedContact->firstName);
                break;
            case ('S'):
                scanf("%s", selectedContact->stName);
                break;
            case ('E'):
                scanf("%s", selectedContact->email);
                break;
            case ('P'):
                scanf("%s", selectedContact->phoneNum);
                break;
            case ('D'):
                scanf("%s", birthday);
                selectedContact->dateOfBirth = *BirthdayConstructor(birthday);
                break;
            default:
                printf("Property not recognized, make sure you using a capital letter\n");
                flag = 0;
                break;
        }
    }
    printf("Contact Edited Successfully.\n\n");
    printContact(*selectedContact);
}

void sortLastName ()
{
    int i,pass,sorted=0;
    Contact temp;
    for(pass=1;pass<Count&&!sorted;pass++) {
        sorted = 1;
        for (i = 0; i < Count - pass; i++) {
            int n = strcasecmp(Contacts[i].lastName, Contacts[i + 1].lastName);
            if (n > 0) {
                temp = Contacts[i];
                Contacts[i] = Contacts[i + 1];
                Contacts[i + 1] = temp;
                sorted = 0;
            }
        }
    }

    printContacts(Contacts, Count);
}
void sortDateOfBirth() {
    int i, pass, sorted = 0;
    Contact temp;
    for (pass = 1; pass < Count && !sorted; pass++) {
        sorted = 1;
        for (i = 0; i < Count - pass; i++) {
            int n = strcmp(Contacts[i].dateOfBirth.year, Contacts[i+1].dateOfBirth.year);
            if (n > 0) {
                temp = Contacts[i];
                Contacts[i] = Contacts[i + 1];
                Contacts[i + 1] = temp;
                sorted = 0;
            } else if (n == 0) {
                sorted =1;
                n = strcmp(Contacts[i].dateOfBirth.month, Contacts[i + 1].dateOfBirth.month);
                if (n > 0) {
                    temp = Contacts[i];
                    Contacts[i] = Contacts[i + 1];
                    Contacts[i + 1] = temp;
                    sorted = 0;
                } else if (n == 0) {
                    sorted =1 ;
                    n = strcmp(Contacts[i].dateOfBirth.day, Contacts[i + 1].dateOfBirth.day);
                    if (n > 0) {
                        temp = Contacts[i];
                        Contacts[i] = Contacts[i + 1];
                        Contacts[i + 1] = temp;
                        sorted = 0;
                    }
                }
            }
        }
    }
    printContacts(Contacts, Count);
}
void sort()
{
    char sortType;
    printf("Would you like to sort contacts according to (L)ast name or (D)ate of birth?\n");
    scanf(" %c",&sortType);
    if(sortType == 'L')
    {
        sortLastName();
    }
    else if(sortType == 'D'){
        sortDateOfBirth();
    } else {
        printf("Command not recognized please try again!\n\n");
    }
}
