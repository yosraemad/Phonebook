#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "validation.h"

char* v_number(char* phone)
{
    char* error = malloc(sizeof(char) * 65);
    strcpy(error, "");
    char*TO = malloc(8);
    strncpy(TO,phone +3,7);
    TO[7] = 0;
    int num = atoi(TO);
    if(phone[2]!='-'||!num){
            strcpy(error,"Please enter a valid number ex: 03-1234567\n");
            return error;
        }
    strncpy(TO,phone,2);
    TO[2] = 0;
    num = atoi(TO);
    if(!num){
        strcpy(error,"Please enter a valid number ex: 03-1234567\n");
        return error;
    }
    if(strlen(phone) != 10){
        strcpy(error,"Phone number must be 9 digits\n");
        return error;
    }
    free(TO);
    return error;


}
char* v_email(char* email)
{
    char* error = malloc(sizeof(char) * 65);
    strcpy(error, "");
    int index;
    int i;
    int atFlag = 0;
    int dotFlag = 0;
    if(email[0] < 'a' || email[0] >'z' ){
        strcpy(error, "Invalid email format\n");
        return error;
    }

    else {
        for (i = 0; i < strlen(email); i++) {
            if (email[i] == '@') {
                atFlag++;
                index = i;
            }
        }
        if (atFlag != 1) {
            strcpy(error, "Invalid email format\n");
            return  error;
        }
        if(email[index+1] < 'a'|| email[index+1] > 'z'){
            strcpy(error, "Invalid email format\n");
            return  error;
        }
        for (i = index; i < strlen(email); i++) {
            if (email[i] == '.') {
                dotFlag++;
                index = i;
            }
        }
        if (dotFlag != 1) {
            strcpy(error, "Invalid email format\n");
            return  error;
        }
        if(email[index+1] != 'c'|| email[index+2] != 'o'|| email[index+3] != 'm'){
            strcpy(error, "Invalid email format\n");
            return  error;
        }
    }
    return error;
}