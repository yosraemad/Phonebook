#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "models.h"
#include "validation.h"

void add_new_contact()
{
    char name[15];
    char birthday[11];
    char phone[11];
    char email[256];
    Contact contact;

    printf("Please enter the contact first name:\n");
    strcpy(name, readInput(name, sizeof(name)));
    strcpy(contact.firstName, v_name(name));

    printf("Please enter the contact last name:\n");
    strcpy(name, readInput(name, sizeof(name)));
    strcpy(contact.lastName, v_name(name));

    printf("Please enter the contact number ex'03-4320121':\n");
    strcpy(phone, readInput(phone, sizeof(phone)));
    strcpy(contact.phoneNum, v_number(phone));

    printf("Please enter the contact email ex'steven@gmail.com':\n");
    strcpy(email, readInput(email, sizeof(email)));
    strcpy(contact.email, v_email(email));

    printf("Please enter the contact address:\n");
    strcpy(contact.stName, readInput(contact.stName, sizeof(contact.stName)));
    //scanf (" %[^\n]s", contact.stName);

    printf("Please enter the contact birthday ex'13-03-2000':\n");
    strcpy(birthday, readInput(birthday, sizeof(birthday)));
    strcpy(birthday,v_dob(birthday));
    DateOfBirth *bd = BirthdayConstructor(birthday);
    contact.dateOfBirth = *bd;

    Count++;
    Contacts = (Contact*)realloc(Contacts,Count* sizeof(*Contacts));
    Contacts[Count-1] = contact;

    printf("Contact added Successfully!\n\n");
    printContact(contact);
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
        printf("No contact with this last name is found\n\n");
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
    int i,j = 0,s = 0, flag = 0;
    //printf("Please enter the first and last name of the contact ex'Ahmed Muhammed':\n");
    //scanf("%s %s", firstName, lastName);

    printf("Please enter the first name:\n");
    strcpy(firstName, readInput(firstName, sizeof(firstName)));
    strcpy(firstName, v_name(firstName));

    printf("Please enter the last name:\n");
    strcpy(lastName, readInput(lastName, sizeof(lastName)));
    strcpy(lastName, v_name(lastName));


    Contact** contacts = (Contact**)malloc(1 *sizeof(Contact));
    for (i = 0; i < Count; i++){
        if (!strcasecmp(Contacts[i].lastName, lastName)) {
            if (!strcasecmp(Contacts[i].firstName, firstName)) {
                contacts = realloc(contacts, (j + 1) * sizeof(Contact));
                contacts[j] = &Contacts[i];
                j++;
            }
        }
    }

    if (!j) {
        printf("No contact with first and last name is found\n\n");
        return;
    }

    printContacts(*contacts, j);
    printf("Please enter the number of the contact you wish to delete:\n");
    scanf(" %d",&s);
    while(s > j || s <= 0) {
        printf("Please enter a correct number:\n");
        scanf(" %d",&s);
    }

    Contact* selectedContact = contacts[s - 1];

    printf("You've chosen this contact:\n");
    printContact(*selectedContact);



    /*
    for (i = 0; i < Count; i++) {
        if (!strcasecmp(Contacts[i].firstName, firstName))
            if (!strcasecmp(Contacts[i].lastName, lastName)) {
                printContact(Contacts[i]);
                flag = 1;
                break;
            }
    }
     */
    /*
    if (!flag) {
        printf("No contact with these first name and last name found\n");
        return;
    }
    */

    for(j = i; j < Count; j++)
        Contacts [j]=Contacts[j+1] ;

    printf("Contact deleted successfully!\n\n");
    Count--;
}

void modify_contact()
{
    char c;
    char phone[11];
    char email[256];
    int num = 0,flag = 0, s = 0;
    char birthday[10];
    char name[15];
    printf("Please enter the contact's last name: \n");
    scanf(" %s", name);
    Contact** contacts = searchContacts(name, &num);
    if (!num) return;
    //printContacts(*contacts, num);
    printf("Please enter the number of the contact you want to modify:\n");
    scanf(" %d",&s);
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
                //scanf("%14s", name);
                strcpy(name, readInput(name, sizeof(name)));
                strcpy(selectedContact->lastName, v_name(name));
                break;
            case ('F'):
                //scanf("%14s", name);
                strcpy(name, readInput(name, sizeof(name)));
                strcpy(selectedContact->firstName, v_name(name));
                break;
            case ('S'):
                //scanf("%99s", selectedContact->stName);
                strcpy(selectedContact->stName, readInput(selectedContact->stName, sizeof(selectedContact->stName)));
                break;
            case ('E'):
                //scanf("%255s", selectedContact->email);
                strcpy(email, readInput(email, sizeof(email)));
                strcpy(selectedContact->email, v_email(email));
                break;
            case ('P'):
                //scanf("%10s", selectedContact->phoneNum);
                strcpy(phone, readInput(phone, sizeof(phone)));
                strcpy(selectedContact->phoneNum, v_number(phone));
                break;
            case ('D'):
                //scanf("%s", birthday);
                strcpy(birthday, readInput(name, sizeof(birthday)));
                strcpy(birthday,v_dob(birthday));
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
    printf("\n");
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

Contact** multiSearch(int* number)
{
    int j = 0;
    Contact** contacts = (Contact**)malloc(1 *sizeof(Contact));

    Contact* contact = (Contact*)malloc(sizeof(Contact));
    char birthday[10];

    printf("Please enter the contact last name:\n");
    scanf("%14s", contact->lastName);
    strcpy(contact->lastName, v_name(contact->lastName));

    printf("Please enter the contact first name:\n");
    scanf("%14s", contact->firstName);
    strcpy(contact->lastName, v_name(contact->lastName));

    printf("Please enter the contact number ex'03-4320121':\n");
    strcpy(contact->phoneNum, readInput(contact->phoneNum, sizeof(contact->phoneNum)));
    strcpy(contact->phoneNum, v_number(contact->phoneNum));

    printf("Please enter the contact email ex'steven@gmail.com':\n");
    strcpy(contact->email, readInput(contact->email, sizeof(contact->email)));
    strcpy(contact->email, v_email(contact->email));

    printf("Please enter the contact address:\n");
    strcpy(contact->stName, readInput(contact->stName, sizeof(contact->stName)));

    printf("Please enter the contact birthday ex'13-03-2000':\n");
    strcpy(birthday, readInput(birthday, sizeof(birthday)));
    strcpy(birthday,v_dob(birthday));
    contact->dateOfBirth = *BirthdayConstructor(birthday);
    *number = j;
    return contacts;
}
