#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "models.h"

char* v_number(char* phone)
{
    char* error = malloc(sizeof(char) * 65);
    strcpy(error, "");
    int n = strlen(phone);

    if (n != 9)
        strcpy(error, "Please use the correct form for numbers ex: 03-483999");
    else {

        unsigned int num;
        char *ptr;
        num = strtol(phone, &ptr, 0);

        if (num != 8) {
            strcpy(error, "Phone numbers must consist of numbers only");
        }
    }

    return error;
}

char* v_name(char* name)
{
    int i, flag = 1;
    int length = strlen(name);
    while(flag) {
        flag = 0;
        for (i = 0; i < length; ++i) {
            char c = name[i];
            if (!name[i]) break;
            if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z')) {
                flag = 1;
                break;
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

char* v_dob(char* dob)
{
    int day, month,year;
    sscanf(dob,"%d-%d-%d",&day, &month, &year);

    while (dob[2] != '-' || dob[5] != '-' || day > 31 || day < 1 || month < 1 || month > 12 || year > 2020)
    {
        printf("Please make sure you're entering logical values and in the correct format!\n");
        printf("Please enter the contact birthday ex'13-03-2000':\n");
        scanf("%10s", dob);
        sscanf(dob,"%d-%d-%d",&day, &month, &year);
    }
    return dob;
}
