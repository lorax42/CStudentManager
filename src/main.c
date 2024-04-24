/*
 * CStudentManager is (c) Lloyd Bush 2024 and under the MIT-License.
 * It can be found at https://www.github.com/lloydbush/CStudentManager
 *
 *   _____  _____ _             _            _   __  __
 *  / ____|/ ____| |           | |          | | |  \/  |
 * | |    | (___ | |_ _   _  __| | ___ _ __ | |_| \  / | __ _ _ __   __ _  __ _  ___ _ __
 * | |     \___ \| __| | | |/ _` |/ _ \ '_ \| __| |\/| |/ _` | '_ \ / _` |/ _` |/ _ \ '__|
 * | |____ ____) | |_| |_| | (_| |  __/ | | | |_| |  | | (_| | | | | (_| | (_| |  __/ |
 *  \_____|_____/ \__|\__,_|\__,_|\___|_| |_|\__|_|  |_|\__,_|_| |_|\__,_|\__, |\___|_|
 *                                                                         __/ |
 *                                                                        |___/
 * CStudentManager
 * ├build
 * │└cmake_stuff
 * ├src
 * │└main.c
 * ├CMakeLists.txt
 * ├LICENSE
 * ├README.md
 * └TODO
 */

// PRECOMPILE COMMANDS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"

#include "readStudents.h"
#include "writeStudents.h"
#include "printList.h"

#define LEN(arr) sizeof(arr)/sizeof(arr[0])

// FUNCTIONS

// print the options and return the one selected by index
int getOpt(const char* opts[]){
    int opt=-1;
    int i=0;

    while(strcmp(opts[i],"\0")!=0){
        printf("%d) %s\n",i,opts[i]);
        i++;
    }

    printf("> ");
    int x=scanf("%d",&opt);
    if(x<=0){
        return -1;
    }

    return opt;
}

// MAIN FUNCTION
int main(){
    // VARS
    const char* logo=
"\
  _____  _____ _             _            _   __  __\n\
 / ____|/ ____| |           | |          | | |  \\/  |\n\
| |    | (___ | |_ _   _  __| | ___ _ __ | |_| \\  / | __ _ _ __   __ _  __ _  ___ _ __\n\
| |     \\___ \\| __| | | |/ _` |/ _ \\ '_ \\| __| |\\/| |/ _` | '_ \\ / _` |/ _` |/ _ \\ '__|\n\
| |____ ____) | |_| |_| | (_| |  __/ | | | |_| |  | | (_| | | | | (_| | (_| |  __/ |\n\
 \\_____|_____/ \\__|\\__,_|\\__,_|\\___|_| |_|\\__|_|  |_|\\__,_|_| |_|\\__,_|\\__, |\\___|_|\n\
                                                                        __/ |\n\
                                                                       |___/\n";
    int cont=1; // continue the main loop (0->no, 1->yes)
    int opt=-1; // what to do?
    const char* opts[]={
        "Exit",
        "Print List",
        "Read File",
        "Write File",
        "\0"
    };

    Students students;
    students.list=(Student*) malloc(sizeof(Student));
    students.len=1;

    // TEST STUDENT
    ///*
    strcat(students.list[0].last_name,"Doe");
    strcat(students.list[0].first_name,"John");
    students.list[0].sex='m';
    students.list[0].age=17;
    strcat(students.list[0].email,"doe.john@lernsax.de");
    strcat(students.list[0].phone,"1234 5678910");
    //*/

    // STARTUP
    printf("%s",logo);

    // LOOP
    while(cont){
        // get option
        opt=getOpt(opts);

        switch(opt){
            case 0:
                cont=0;
                break;

            case 1:
                printf("Printing...\n");
                printList(students);
                break;

            case 2:
                readStudents(students);
                break;

            case 3:
                writeStudents(students);
                break;

            default:
                fprintf(stderr,"ERROR: invalid option: %d\n",opt);
        }
    }

    // CLEANUP
    free(students.list);

    printf("%s",logo);
    return(0);
}

