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
    size_t fileLength;
    int fileLines;
    char* text;

    printf("File Name: ");
    scanf("%s",fileName);
    printf("Reading %s...\n",fileName);

    file=fopen(fileName,"r"); // open file

    if(file==NULL){
        fprintf(stderr,"ERROR: File %s not found",fileName);
        return;
    }

    fseek(file,0L,SEEK_END); // sets file stream to end of file
    fileLength=ftell(file); // reads position of file stream
    rewind(file); // sets file stream back to beginning of file

    text=(char*)malloc(fileLength); // allocate as much memory to text as file is long

    // read file into text
    char ch;
    for(size_t i=0;i<=fileLength;i++){
        ch=getc(file);

        if(ch=='\n'){
            fileLines++;
        }

        text[i]=ch;
    }

    fclose(file); // close file
    printf("%s",text); //DEBUG
    
    // PARSE text
    char* c=text; // pointer to first char in text
    int i=0; // index of character of attribute of student pointed to by c

    // read loop
    // ERRORS!!!
    for(int line=0;line<fileLines;line++){
        DEBUG;
        // add new student to array students
        students.list=(Student*) realloc(students.list,(line+1)*sizeof(Student));
        students.len++;

        if(students.list==NULL){
            //fprintf(stderr,"ERROR: %s:%d: problem in realloc\n",__FILE__,__LINE__);
            ERROR("problem in realloc");
        }

        // READ
        // last_name
        i=0;
        while(*c!=',' && i<=ARR_LEN(students.list[line].last_name)){
            printf("%d:%c\n",i,*c);
            students.list[line].last_name[i]=*c;
            c++;i++;
        }
        c++;
        printf("last_name: %s\n",students.list[i].last_name);

        // first_name
        i=0;
        while(*c!=',' && i<=ARR_LEN(students.list[line].first_name)){
            printf("%d:%c\n",i,*c);
            students.list[line].first_name[i]=*c;
            c++;i++;
        }
        c++;

        // sex
        i=0;
        while(*c!=',' && i<=1){
            printf("%d:%c\n",i,*c);
            students.list[line].sex=*c;
            c++;i++;
        }
        c++;

        // age
        i=0;
        while(*c!=',' && i<=3){
            char age[3];
            printf("%d:%c\n",i,*c);
            age[i]=*c;
            students.list[line].age=atoi(age);
            c++;i++;
        }
        c++;

        // email
        i=0;
        while(*c!=',' && i<=ARR_LEN(students.list[line].email)){
            printf("%d:%c\n",i,*c);
            students.list[line].first_name[i]=*c;
            c++;i++;
        }
        c++;

        // phone
        i=0;
        while(*c!='\n' && i<=ARR_LEN(students.list[line].phone)){
            printf("%d:%c\n",i,*c);
            students.list[line].first_name[i]=*c;
            c++;i++;
        }
        c++;
    }

    for(int i=0;i<students.len;i++){
        printf(" last_name: %s\n",students.list[i].last_name);
        printf("first_name: %s\n",students.list[i].first_name);
        printf("       sex: %c\n",students.list[i].sex);
        printf("       age: %d\n",students.list[i].age);
        printf("     email: %s\n",students.list[i].email);
        printf("     phone: %s\n\n",students.list[i].phone);
    }

    // CLEANUP
    free(text);
    text=NULL;
}

