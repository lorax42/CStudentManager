#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"

void writeFile(char* text){
    FILE* file;
    char fileName[50];

    printf("Enter file name: ");
    scanf("%s",fileName);
    printf("\n");

    file=fopen(fileName,"w");
    if(file==NULL){
        fprintf(stderr,"ERROR %s:%d: unable to open file %s\n",__FILE__,__LINE__,fileName);
    }

    fprintf(file,"%s",text);
    fclose(file);
}

void writeStudents(Students students){
    char buffer[50];

    char* text=(char*) malloc(students.len*(sizeof(Student)+10)); // allocate memory for size of students.list +
                                                        //__^______ commas (for separating attributes)
    for(size_t i=0;i<=students.len;i++){
        // append last_name to student from students.list
        strcat(text,students.list[i].last_name);
        strcat(text,",");

        // append first_name to student from students.list
        strcat(text,students.list[i].first_name);
        strcat(text,",");

        // append sex to student from students.list
        strcat(text,&students.list[i].sex);
        strcat(text,",");

        // append age to student from students.list
        sprintf(buffer,"%d",students.list[i].age);
        strcat(text,buffer);
        strcat(text,",");

        // append email to student from students.list
        strcat(text,students.list[i].email);
        strcat(text,",");

        // append phone to student from students.list
        strcat(text,students.list[i].phone);

        strcat(text,"\n");
    }
    strcat(text,"\0");

    printf("%s",text);

    writeFile(text);

    free(text);
}

