#include <stdio.h>
#include <string.h>

#include "student.h"

void printList(struct Student students[]){
    int i=0;
    while(strcmp(students[i].last_name,"\0")!=0){
        printf("%s,%s,%d\n",students[i].last_name,students[i].first_name,students[i].age);
    }
}

