#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* v_number(char* phone)
{
    char* error = malloc(sizeof(char) * 65);
    strcpy(error, "");
    int n = strlen(phone);

    if (n != 9)
        strcpy(error, "Please use the correct form for numbers ex: 03483999");
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