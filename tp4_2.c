#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tarea {
    int assignmentID;
    char* description;
    int duration;
} Assignment;

void assignmentsInterface(Assignment** assignment,int number) {
    char* buffer = malloc(100*sizeof(*buffer));
    for(int i = 0 ; i < number ; i++) {
        assignment[i] = malloc(sizeof(*(assignment[i])));
        printf("\n------TAREA %d------\n",i+1);
        assignment[i]->assignmentID = i + 1;
        printf("Descripcion de la tarea: ");
        gets(buffer);
        assignment[i]->description = malloc(strlen(buffer) + 1);
        strcpy(assignment[i]->description,buffer);
        printf("\nDuracion de la tarea: ");
        scanf("%d",&assignment[i]->duration);
    }
    free(buffer);
}

void moveAssignment(Assignment** assignment,int number) {
    int option;
    Assignment** assignmentsCompleted = malloc(number*sizeof(*assignmentsCompleted));
    for(int i = 0 ; i < number ; i++) {
        assignmentsCompleted[i] = NULL;
    }
    for(int i = 0 ; i < number ; i++) {
        printf("\nSe realizo la tarea %d?\n1-SI\n2-NO");
        scanf("%d",&option);
        switch(option) {
            case 1:
                assignmentsCompleted[i] = malloc(sizeof(*(assignmentsCompleted[i])));
                assignmentsCompleted[i] = assignment[i];
                assignment[i] = NULL;
                break;
            case 2:
                break;
        }
    }
}

int main(int argc,char** argv) {
    int numberAssignments;
    printf("Ingresar la cantidad de tareas a realizar: ");
    scanf("%d",&numberAssignments);
    Assignment** assignments = malloc(numberAssignments*sizeof(*assignments));
    for(int i = 0 ; i < numberAssignments ; i++) {
        assignments[i] = NULL;
    }

    return 0;
}