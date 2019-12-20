#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "io.h"

Contact saveToStruct(char* str){
    Contact res ;
    char birthday[11];
    sscanf(str,"%[^,],%[^,],%[^,],%[^,],%[^,],%s\n",res.lastName,res.firstName,birthday,res.stName,res.email,res.phoneNum);
    res.dateOfBirth = *BirthdayConstructor(birthday);
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

void load(char* fileName){
    // TODO Count the last contact without \n in the end if added manually
    strcat(fileName,".txt");
    char str[512];
    Count = 0;
    FILE *f = fopen(fileName,"a+");
    getNumOfLines(f);

    if(!Count) {
        printf("File not found we've created a new file for you.\n\n");
        char dummy[] = "Steven,Thomas,10-06-1995,26 Elhoreya Street,sthomas@gmail.com,03-4876321\n";
        fputs(dummy, f);
        Count++;
        rewind(f);
    }
    Contacts = (Contact*)malloc(Count* sizeof(*Contacts));

    int i = 0;
    while(fgets(str, sizeof(str), f) != NULL)
    {
        Contacts[i] = saveToStruct(str);
        i++;
    }

    fclose(f);
}

void saveFile(char* fileName){
    FILE *fp = fopen(fileName,"w");
    int i;
    for(i = 0; i<Count; i++){
        fprintf(fp,"%s,%s,%s-%s-%s,%s,%s,%s\n",Contacts[i].lastName,Contacts[i].firstName,Contacts[i].dateOfBirth.day,Contacts[i].dateOfBirth.month,Contacts[i].dateOfBirth.year,Contacts[i].stName,Contacts[i].email,Contacts[i].phoneNum);
    }
    fclose(fp);

    printf("Changes are saved to the file successfully!\n");
}