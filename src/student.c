#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "student.h"

// adds 1 student to students.list and increases students.len
int addStudent(Students* students){
    Students* temp=students;

    students->list=(Student*) realloc(students->list,(students->len+1)*sizeof(Student));
    if(!students){
        printf("ERROR: %s:%d: Memory reallocation failed\n",__FILE__,__LINE__);
        students=temp;
        return(1);
    }
    else{
        printf("ALERT: %s:%d: Memory reallocation succeeded\n",__FILE__,__LINE__);

        for(size_t i=0;i<temp->len;i++){
            students->list[i]=temp->list[i];
        }

        students->len++;
    }

    return(0);
}

/*
int main(){
    Students students;
    students.list=(Student*) malloc(sizeof(Student));
    students.len=1;

    // TEST STUDENT
    strcat(students.list[0].last_name,"Doe");
    strcat(students.list[0].first_name,"John");
    students.list[0].sex='m';
    students.list[0].age=17;
    strcat(students.list[0].email,"doe.john@lernsax.de");
    strcat(students.list[0].phone,"1234 5678910");
    printf("%s\n",students.list[0].last_name);

    int x=addStudent(&students);
    printf("RETURNED %d\n",x);

    strcat(students.list[1].last_name,"Doe");
    strcat(students.list[1].first_name,"John");
    students.list[1].sex='m';
    students.list[1].age=17;
    strcat(students.list[1].email,"doe.john@lernsax.de");
    strcat(students.list[1].phone,"1234 5678910");
    printf("%s\n",students.list[1].last_name);

    return(0);
}
*/

