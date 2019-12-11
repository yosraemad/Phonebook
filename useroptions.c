#include <stdio.h>
#include <stdlib.h>

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


