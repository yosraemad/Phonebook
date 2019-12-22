#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "models.h"
#include "validation.h"

DateOfBirth *BirthdayConstructor(char* s)
{
    DateOfBirth *birthday = (DateOfBirth*)malloc(sizeof(DateOfBirth));
    int i = 0;
    char *p = strtok(v_dob(s),"/'\'- ");
    while(p)
    {
        if (i == 0) {
            strcpy(birthday->day, p);
        }
        else if (i == 1) {
            strcpy(birthday->month, p);
        }
        else if (i == 2) {
            strcpy(birthday->year, p);
        }
        p = strtok(NULL, "/'\'- ");
        i++;
    }
    return birthday;
}

char* readInput(char* input, int n)
{
/*
    char result[n];
    //scanf("%s", input);
    scanf (" %[^\n]s", input);
    strncpy(result, input, n - 1);
    return input;
*/


    //getchar();
    char buffer[1000];
    fgets(buffer, sizeof(buffer), stdin);
    for (int i = 0; i < n; i++) {
        if (buffer[0] == '\n')
        {
            input[0] = '\0';
            return input;
        }
        else if (buffer[i] == '\n' || buffer[i] == '\0'){
            input[i] = '\0';
            break;
        }
        input[i] = buffer[i];
    }
    input[n-1] = '\0';
    return input;
}

void printContact(Contact c){
    printf("First Name = %s\n", c.firstName);
    printf("Last Name = %s\n", c.lastName);
    printf("Street Name = %s\n", c.stName);
    printf("email = %s\n", c.email);
    printf("Phone Number = %s\n", c.phoneNum);
    printf("Birthday = %s - %s - %s\n", c.dateOfBirth.day,c.dateOfBirth.month,c.dateOfBirth.year);
}

void printContacts(Contact* contacts, int length)
{
    int i = 0;
    for (i = 0; i < length; i++) {
        printf("%d.\n", i +1);
        printContact(contacts[i]);
        printf("\n");
    }
}

char* stristr( const char* str1, const char* str2 )
{
    const char* p1 = str1 ;
    const char* p2 = str2 ;
    const char* r = *p2 == 0 ? str1 : 0 ;

    while( *p1 != 0 && *p2 != 0 )
    {
        if( tolower( (unsigned char)*p1 ) == tolower( (unsigned char)*p2 ) )
        {
            if( r == 0 )
            {
                r = p1 ;
            }

            p2++ ;
        }
        else
        {
            p2 = str2 ;
            if( r != 0 )
            {
                p1 = r + 1 ;
            }

            if( tolower( (unsigned char)*p1 ) == tolower( (unsigned char)*p2 ) )
            {
                r = p1 ;
                p2++ ;
            }
            else
            {
                r = 0 ;
            }
        }

        p1++ ;
    }

    return *p2 == 0 ? (char*)r : 0 ;
}