#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "io.h"

Contact saveToStruct(char* str){
    Contact res ;
    int flag = 0;
    char *token = strtok(str, ",");
    while( token != NULL)
    {
        if (flag == 0)
            strcpy(res.lastName, token);
        else if (flag == 1)
            strcpy(res.firstName, token);
        else if(flag == 2)
            strcpy(res.stName,token);
        else if(flag == 3)
            strcpy(res.email,token);
        else if(flag == 4) {
            strcpy(res.phoneNum, token);
            token = strtok(NULL, "\n");
            flag++;
            continue;
        }
        else if(flag == 5) {
            res.dateOfBirth  = *BirthdayConstructor(token);
        }
        flag++;
        token = strtok( NULL, "," );
    }
    return res;
}

void getNumOfLines(FILE * f){
    char c;
    for (c = getc(f); c != EOF; c = getc(f)) {
        if (c == '\n')
            Count++;
    }
    rewind(f);
}

void load(){
    //system("clear");

    char str[512];
    char fileName[] = "contacts.txt";
    FILE *f = fopen(fileName,"a+");
    getNumOfLines(f);

    if(!Count) {
        char dummy[] = "Steven,Thomas,26 Elhoreya Street,sthomas@gmail.com,03-4876321,10-06-1995\n";
        fputs(dummy, f);
        Count++;
        rewind(f);
    }
    printf("The total number of contacts: %d\n\n", Count);

    int i = 0;
    while(fgets(str, sizeof(str), f) != NULL)
    {
        Contacts[i] = saveToStruct(str);
        printContact(Contacts[i]);
        printf("\n");
        i++;
    }


    fclose(f);

    printf("Press any key to continue ..");
    //getch();

}