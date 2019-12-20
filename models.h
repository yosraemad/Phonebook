
typedef struct {
    char day[3];
    char month[3];
    char year[5];
} DateOfBirth;

typedef struct {
    char lastName[15];
    char firstName[15];
    char stName[100];
    char email[256];
    char phoneNum[11];
    DateOfBirth dateOfBirth;
} Contact;

extern int Count;
extern Contact *Contacts;

DateOfBirth *BirthdayConstructor(char* s);
void printContact(Contact c);
char* readInput(char* input, int n);
void printContacts(Contact* contacts, int length);

#ifndef PHONEBOOK_MODELS_H
#define PHONEBOOK_MODELS_H

#endif //PHONEBOOK_MODELS_H

