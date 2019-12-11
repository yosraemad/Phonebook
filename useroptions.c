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

void modify_contact(char* lastName)
{
    char c;
    int s, num;
    char birthday[10];
    Contact** contacts = searchContacts(lastName, &num);
    printContacts(*contacts, num);
    printf("Please enter the number of the contact you want to modify:\n");
    scanf("%d",&s);
    Contact *selectedContact = contacts[s-1];
    printContact(*selectedContact);
    printf("Please enter the property that you would like to edit\n");
    printf("(L)ast name, (F)irst name,(S)treet name, (E)mail, (P)hone, (D)ate of birth:\n");
    scanf(" %c", &c);
    printf("Please enter the new value:\n");
    switch (c)
    {
        case('L'):
        scanf("%s", selectedContact->lastName);
            break;
        case('F'):
            scanf("%s", selectedContact->firstName);
            break;
        case('S'):
            scanf("%s", selectedContact->stName);
            break;
        case('E'):
            scanf("%s", selectedContact->email);
            break;
        case('P'):
            scanf("%s", selectedContact->phoneNum);
            break;
        case('D'):
            scanf("%s", birthday);
            selectedContact->dateOfBirth = *BirthdayConstructor(birthday);
            break;
    }
    printf("Contact Edited Successfully.\n");
    printContact(*selectedContact);
}
