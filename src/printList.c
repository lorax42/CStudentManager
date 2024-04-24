#include <stdio.h>
#include <string.h>

#include "student.h"

void printList(Students students){
    for(size_t i=0;i<students.len;i++){
        printf("%s,%s,%d\n",students.list[i].last_name,students.list[i].first_name,students.list[i].age);
    }
}

