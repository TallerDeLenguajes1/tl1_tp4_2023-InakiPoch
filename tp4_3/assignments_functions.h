#include "list_functions.h"

void assignmentsInterface(AssignmentNode** startingNode,int number) {
    char* buffer = (char*)malloc(100*sizeof(*buffer));
    Assignment assignment;
    for(int i = 0 ; i < number ; i++) {
        fflush(stdin);
        printf("\n------TAREA %d------\n",i+1);
        assignment.assignmentID = i + 1;
        printf("Descripcion de la tarea: ");
        gets(buffer);
        fflush(stdin);
        assignment.description = (char*)malloc(strlen(buffer) + 1);
        strcpy(assignment.description,buffer);
        printf("\nDuracion de la tarea: ");
        scanf("%d",&assignment.duration);
        fflush(stdin);
        addNode(startingNode,assignment);
    }
    free(buffer);
}

void searchAssignmentByKeyword(Assignment** assignment,int number,char* keyword) {
    for(int i = 0 ; i < number ; i++) {
        if(strstr(assignment[i]->description,keyword)) {            
            printf("\n------TAREA CON PALABRA CLAVE %s ENCONTRADA------\n",keyword);
            printf("ID: %d",assignment[i]->assignmentID);
            printf("\nDescripcion de la tarea: %s",assignment[i]->description);
            printf("\nDuracion de la tarea: %d\n",assignment[i]->duration);
        }
    }
}

void searchAssignmentByID(Assignment** assignment,int number,int id) {
    for(int i = 0 ; i < number ; i++) {
        if(assignment[i]->assignmentID == id) {
            printf("\n------TAREA DE ID %d------\n",id);
            printf("ID: %d",assignment[i]->assignmentID);
            printf("\nDescripcion de la tarea: %s",assignment[i]->description);
            printf("\nDuracion de la tarea: %d\n",assignment[i]->duration);
        }
    }
}


void moveAssignment(AssignmentNode** assignmentCompleted,AssignmentNode** assignmentPending) {
    int option;
    AssignmentNode* tempNode = *assignmentPending;
    for(int i = 0 ; tempNode != NULL ; i++) {
        printf("\nSe realizo la tarea %d?\n1-SI\n2-NO\n",i+1);
        scanf("%d",&option);
        switch(option) {
            case 1:
                addNode(assignmentCompleted,tempNode->assignment);
                removeNode(assignmentPending,tempNode->assignment);
                break;
            case 2:
                break;
        }
        fflush(stdin);
        tempNode = tempNode->next;
    }
}

void showPendingAssignments(AssignmentNode* startingNode) {
    if(startingNode != NULL) {
        printf("\n------TAREAS PENDIENTES------\n");
        AssignmentNode* tempNode = startingNode;
        for(int i = 0 ; tempNode ; i++) {
            printf("\n------TAREA %d------\n",i+1);
            printf("ID: %d",tempNode->assignment.assignmentID);
            printf("\nDescripcion de la tarea: %s",tempNode->assignment.description);
            printf("\nDuracion de la tarea: %d",tempNode->assignment.duration);
            tempNode = tempNode->next;
        }
    }
}

void showCompletedAssignments(AssignmentNode* startingNode) {
    if(startingNode != NULL) {
        printf("\n------TAREAS COMPLETADAS------\n");
        AssignmentNode* tempNode = startingNode;
        for(int i = 0 ; tempNode ; i++) {
            printf("\n------TAREA %d------\n",i+1);
            printf("ID: %d",tempNode->assignment.assignmentID);
            printf("\nDescripcion de la tarea: %s",tempNode->assignment.description);
            printf("\nDuracion de la tarea: %d",tempNode->assignment.duration);
            tempNode = tempNode->next;
        }
    }
}

void freeMemory(AssignmentNode** startingNode) {
    AssignmentNode* tempNode = *startingNode;
    AssignmentNode* deleteNode = *startingNode;
    while(tempNode != NULL) {
        deleteNode = tempNode;
        tempNode = tempNode->next;
        free(deleteNode);
    }
    free(startingNode);
}