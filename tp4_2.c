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