#include <stdio.h>
#include <stdlib.h>

#include "student.h"

#define DEBUG printf("DEBUG: %s:%d\n",__FILE__,__LINE__)
#define ERROR(str) fprintf(stderr,"ERROR: %s:%d: %s",__FILE__,__LINE__,str)

#define ARR_LEN(arr) sizeof(arr)/sizeof(arr[0])

void readStudents(Students students){
    // READ FILE
    FILE* file;
    char fileName[100];

    printf("File Name: ");
    scanf("%s",fileName);
    printf("Reading %s...\n",fileName);

    file=fopen(fileName,"r"); // open file

    if(file==NULL){
        fprintf(stderr,"ERROR: File %s not found",fileName);
        return;
    }
    
    // PARSE text
    rewind(file); // sets file stream back to beginning of file
    size_t i=0;
    //while(fscanf(file,"%s,%s,%c,%d,%s,%s\n",students.list[i].last_name,
    while(fscanf(file,"%[^,],%[^,],%c,%d,%[^,],%s\n",students.list[i].last_name,
                                            students.list[i].first_name,
                                            &students.list[i].sex,
                                            &students.list[i].age,
                                            students.list[i].email,
                                            students.list[i].phone)==6){
        // EDIT
        int x=addStudent(&students);
        if(x!=0){
            ERROR("trouble adding student");
        }

        i++;
    }

    fclose(file); // close file

    ///*
    for(int i=0;i<students.len;i++){
        printf(" last_name: %s\n",students.list[i].last_name);
        printf("first_name: %s\n",students.list[i].first_name);
        printf("       sex: %c\n",students.list[i].sex);
        printf("       age: %d\n",students.list[i].age);
        printf("     email: %s\n",students.list[i].email);
        printf("     phone: %s\n\n",students.list[i].phone);
    }
    //*/

    // CLEANUP
}

