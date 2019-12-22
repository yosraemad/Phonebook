#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "models.h"

char* v_number(char* phone)
{
    fflush(stdin);
    int flag =1;
    while(flag) {
        int length = strlen(phone);
        flag = 0;
        if (length== 0)
            flag = 1;
        char *ptr;
        int num = strtol(phone,&ptr,length+2);
        if (*ptr != '\0' || !num) {
            printf("Please make sure you enter numbers\n");
            flag = 1;
        }
        if (flag)
        {
            printf("Please re-enter the phone number:\n");
            strcpy(phone, readInput(phone, 100));
        }
    }
    return phone;
}

char* v_email(char* email)
{
    int index;
    int i;
    int flag = 1;

    while(flag) {
        int atFlag = 0;
        int dotFlag = 0;
        flag = 0;
        if (strlen(email) == 0)
            flag = 1;
        if (email[0] < 'a' || email[0] > 'z') {
            flag = 1;
        } else {
            for (i = 0; i < strlen(email); i++) {
                if(email[i] == ',')
                    flag = 1;
                if (email[i] == '@') {
                    atFlag++;
                    index = i;
                }
            }
            if (atFlag != 1) {
                flag = 1;
            }
            if (email[index + 1] < 'a' || email[index + 1] > 'z') {
                flag = 1;
            }
            for (i = index; i < strlen(email); i++) {
                if(email[i] == ',')
                    flag = 1;
                if (email[i] == '.') {
                    dotFlag++;
                    index = i;
                }
            }
            if (dotFlag != 1) {
                flag = 1;
            }
            if (email[index + 1] != 'c' || email[index + 2] != 'o' || email[index + 3] != 'm') {
                flag = 1;
            }
        }
        if (flag)
        {
            printf("Invalid email address\n");
            printf("Please enter the contact email ex'steven@gmail.com':\n");
            strcpy(email, readInput(email, 256));
            fflush(stdin);
        }
    }
    return email;
}

char* v_name(char* name)
{
    int flag = 1;
    while(flag) {
        int length = strlen(name);
        int i;
        flag = 0;

        if (length == 0)
            flag = 1;
        else {

            for (i = 0; i < length; ++i) {
                char c = name[i];
                if (!name[i]) break;
                if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z')) {
                    flag = 1;
                    break;
                }
            }
        }

        if (flag)
        {
            printf("Make sure you are entering letters from the alphabet.\n");
            printf("Please re-enter the name:\n");
            strcpy(name, readInput(name, 14));
        }
        else {
            return name;
        }
    }
}
char* v_address(char* address)
{
    int flag = 1;

    while(flag) {
        int i;
        int length = strlen(address);
        flag = 0;
        if (length == 0)
            flag = 1;
        for (i = 0; i < length; ++i) {
            char c = address[i];
            if (!address[i]) break;
            if (c == ',' ) {
                flag = 1;
                break;
            }
        }

        if (flag)
        {
            printf("Make sure you don't enter a coma\n");
            printf("Please re-enter the address:\n");
            strcpy(address, readInput(address, 14));
        }
        else {
            return address;
        }
    }
}
char* v_dob(char* dob)
{
    int day, month,year;
    sscanf(dob,"%d-%d-%d",&day, &month, &year);

    while (strlen(dob) == 0 ||((dob[2] != '-' || dob[5] != '-') && (dob[1] != '-' || dob[3] != '-') && (dob[2] != '-' || dob[4] != '-') && (dob[1] != '-' || dob[4] != '-'))|| (day > 31 || day < 1 || month < 1 || month > 12 || year > 2020))
    {
        printf("Please make sure you're entering logical values and in the correct format!\n");
        printf("Please enter the contact birthday ex'13-03-2000':\n");
        scanf("%10s", dob);
        sscanf(dob,"%d-%d-%d",&day, &month, &year);
    }
    return dob;
}