#include "list_functions.h"

void assignmentsInterface(AssignmentNode** startingNode) {
    char* buffer = (char*)malloc(100*sizeof(*buffer));
    int addAssignment;
    Assignment assignment;
    for(int i = 0 ; addAssignment ; i++) {
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
        printf("Agregar nueva tarea?\n1-SI\0-NO\n\n");
        scanf("%d",&addAssignment);
    }
    free(buffer);
}

void searchAssignmentByKeyword(AssignmentNode** startingNode,char* keyword) {
    AssignmentNode* tempNode = *startingNode;
    for(int i = 0 ; tempNode != NULL ; i++) {
        if(strstr(tempNode->assignment.description,keyword)) {
            printf("\n------TAREA CON %s CONTENIDA------\n",keyword);
            printf("ID: %d",tempNode->assignment.assignmentID);
            printf("\nDescripcion de la tarea: %s",tempNode->assignment.description);
            printf("\nDuracion de la tarea: %d\n",tempNode->assignment.duration);
        }
        tempNode = tempNode->next;
    }
}

void searchAssignmentByID(AssignmentNode** startingNode,int id) {
    AssignmentNode* tempNode = *startingNode;
    for(int i = 0 ; tempNode != NULL ; i++) {
        if(tempNode->assignment.assignmentID == id) {
            printf("\n------TAREA DE ID %d------\n",id);
            printf("ID: %d",tempNode->assignment.assignmentID);
            printf("\nDescripcion de la tarea: %s",tempNode->assignment.description);
            printf("\nDuracion de la tarea: %d\n",tempNode->assignment.duration);
        }
        tempNode = tempNode->next;
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

int isAssignmentCompleted(AssignmentNode** completedAssignments,int id) {
    AssignmentNode* tempNode = *completedAssignments;
    while(tempNode != NULL) {
        if(tempNode->assignment.assignmentID == id) {
            return 1;
        }
        tempNode = tempNode->next;
    }
    return 0;
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