#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tarea {
    int assignmentID;
    char* description;
    int duration;
} Assignment;

void initializeAssignments(Assignment** assignment1,Assignment** assignment2,int number) {
    for(int i = 0 ; i < number ; i++) {
        assignment1[i] = NULL;
    }
    for(int i = 0 ; i < number ; i++) {
        assignment2[i] = NULL;
    }
}

void assignmentsInterface(Assignment** assignment,int number) {
    char* buffer = malloc(100*sizeof(*buffer));
    for(int i = 0 ; i < number ; i++) {
        fflush(stdin);
        assignment[i] = malloc(sizeof(*(assignment[i])));
        printf("\n------TAREA %d------\n",i+1);
        assignment[i]->assignmentID = i + 1;
        printf("Descripcion de la tarea: ");
        gets(buffer);
        fflush(stdin);
        assignment[i]->description = malloc(strlen(buffer) + 1);
        strcpy(assignment[i]->description,buffer);
        printf("\nDuracion de la tarea: ");
        scanf("%d",&assignment[i]->duration);
        fflush(stdin);
    }
    free(buffer);
}

void searchAssignmentByID(Assignment** assignment,int number,int id) {
    for(int i = 0 ; i < number ; i++) {
        if(assignment[i]->assignmentID == id) {
            printf("\n------TAREA DE ID %d------\n",id);
            printf("ID: %d",assignment[i]->assignmentID);
            printf("\nDescripcion de la tarea: %s",assignment[i]->description);
            printf("\nDuracion de la tarea: %d",assignment[i]->duration);
        }
    }
}

void moveAssignment(Assignment** assignmentCompleted,Assignment** assignmentPending,int number) {
    int option;
    for(int i = 0 ; i < number ; i++) {
        printf("\nSe realizo la tarea %d?\n1-SI\n2-NO\n",i+1);
        scanf("%d",&option);
        switch(option) {
            case 1:
                assignmentCompleted[i] = malloc(sizeof(*(assignmentCompleted[i])));
                assignmentCompleted[i] = assignmentPending[i];
                assignmentPending[i] = NULL;
                break;
            case 2:
                break;
        }
        fflush(stdin);
    }
}

void showPendingAssignments(Assignment** assignment,int number) {
    printf("\n------TAREAS PENDIENTES------\n");
    for(int i = 0 ; i < number ; i++) {
        if(assignment[i] != NULL) {            
            printf("\n------TAREA %d------\n",i+1);
            printf("ID: %d",assignment[i]->assignmentID);
            printf("\nDescripcion de la tarea: %s",assignment[i]->description);
            printf("\nDuracion de la tarea: %d",assignment[i]->duration);
        }
    }
}

void showCompletedAssignments(Assignment** assignment,int number) {
    printf("\n------TAREAS COMPLETADAS------\n");
    for(int i = 0 ; i < number ; i++) {
        if(assignment[i] != NULL) {
            printf("\n------TAREA %d------\n",i+1);
            printf("ID: %d",assignment[i]->assignmentID);
            printf("\nDescripcion de la tarea: %s",assignment[i]->description);
            printf("\nDuracion de la tarea: %d",assignment[i]->duration);
        }
    }
}

void freeMemory(Assignment** assignment,int number) {
    for(int i = 0 ; i < number ; i++) {
        free(assignment[i]);
    }
    free(assignment);
}

int main(int argc,char** argv) {
    int numberAssignments;
    printf("Ingresar la cantidad de tareas a realizar: ");
    scanf("%d",&numberAssignments);
    Assignment** assignments = malloc(numberAssignments*sizeof(*assignments));
    Assignment** assignmentsCompleted = malloc(numberAssignments*sizeof(*assignmentsCompleted));
    initializeAssignments(assignments,assignmentsCompleted,numberAssignments);
    assignmentsInterface(assignments,numberAssignments);
    searchAssignmentByID(assignments,numberAssignments,2);
    moveAssignment(assignmentsCompleted,assignments,numberAssignments);
    showCompletedAssignments(assignmentsCompleted,numberAssignments);
    showPendingAssignments(assignments,numberAssignments);
    freeMemory(assignments,numberAssignments);
    freeMemory(assignmentsCompleted,numberAssignments);
    return 0;
}