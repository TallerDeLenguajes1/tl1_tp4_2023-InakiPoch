#include "list_functions.h"

void assignmentsInterface(AssignmentNode** startingNode) {
    char* buffer = (char*)malloc(100*sizeof(*buffer));
    int addAssignment = 1;
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
        printf("Agregar nueva tarea?\n1-SI\n0-NO\n");
        scanf("%d",&addAssignment);
    }
    free(buffer);
}

void listAssignments(AssignmentNode** startingNode) {
    AssignmentNode* tempNode = *startingNode;
    for(int i = 0 ; tempNode != NULL ; i++) {
        printf("\n------TAREA %d------\n",i+1);
        printf("ID: %d",tempNode->assignment.assignmentID);
        printf("\nDescripcion de la tarea: %s",tempNode->assignment.description);
        printf("\nDuracion de la tarea: %d\n",tempNode->assignment.duration);
        tempNode = tempNode->next;
    }
}

Assignment searchAssignmentByKeyword(AssignmentNode** startingNode,char* keyword) {
    AssignmentNode* tempNode = *startingNode;
    for(int i = 0 ; tempNode != NULL ; i++) {
        if(strstr(tempNode->assignment.description,keyword)) {
            printf("\n------TAREA CON %s CONTENIDA------\n",keyword);
            printf("ID: %d",tempNode->assignment.assignmentID);
            printf("\nDescripcion de la tarea: %s",tempNode->assignment.description);
            printf("\nDuracion de la tarea: %d\n",tempNode->assignment.duration);
            return tempNode->assignment;
        }
        tempNode = tempNode->next;
    }
    return tempNode->assignment;
}

Assignment searchAssignmentByID(AssignmentNode** startingNode,int id) {
    AssignmentNode* tempNode = *startingNode;
    for(int i = 0 ; tempNode != NULL ; i++) {
        if(tempNode->assignment.assignmentID == id) {
            printf("\n------TAREA DE ID %d------\n",id);
            printf("ID: %d",tempNode->assignment.assignmentID);
            printf("\nDescripcion de la tarea: %s",tempNode->assignment.description);
            printf("\nDuracion de la tarea: %d\n",tempNode->assignment.duration);
            return tempNode->assignment;
        }
        tempNode = tempNode->next;
    }
    return tempNode->assignment;
}

void showData(AssignmentNode** startingNode) {
    AssignmentNode* tempNode = *startingNode;
    int numberAssignments = 0;
    int totalTime = 0;
    while(tempNode != NULL) {
        totalTime += tempNode->assignment.assignmentID;
        numberAssignments++;
        tempNode = tempNode->next;
    }
    printf("\nCantidad de tareas: %d\nTiempo asociado a la lista: %d",numberAssignments,totalTime);
}

int isAssignmentInList(AssignmentNode** assignments,int id) {
    AssignmentNode* tempNode = *assignments;
    while(tempNode != NULL) {
        if(tempNode->assignment.assignmentID == id) {
            return 1;
        }
        tempNode = tempNode->next;
    }
    return 0;
}

void moveAssignment(AssignmentNode** assignmentCompleted,AssignmentNode** assignmentPending,AssignmentNode** inProcessList) {
    int id;
    int option;
    int moveOption;
    while(option != 2) {
        printf("\n-----LISTA DE TAREAS COMPLETAS-----\n");
        listAssignments(assignmentCompleted);
        printf("\n-----LISTA DE TAREAS PENDIENTES-----\n");
        listAssignments(assignmentPending);
        printf("\n-----LISTA DE TAREAS EN PROCESO-----\n");
        listAssignments(inProcessList);
        printf("\n\nIngrese la id de la tarea a seleccionar: ");
        scanf("%d",&id);
        fflush(stdin);
        printf("\n\nQue desea hacer con la tarea?\n1-Moverla\n2-Borrarla\n3-Continuar\n");
        scanf("%d",&option);
        fflush(stdin);
        switch(option) {
            case 1:
                printf("\n\nMover tarea a:\n1-Tareas completadas\n2-Tareas en proceso\n");
                scanf("%d",&moveOption);
                fflush(stdin);
                if(moveOption == 1) {
                    if(isAssignmentInList(assignmentCompleted,id)) {
                        printf("\nTarea ya completada\n");
                    }
                    else {
                        if(isAssignmentInList(assignmentPending,id)) {
                            addNode(assignmentCompleted,searchAssignmentByID(assignmentPending,id));
                            removeNode(assignmentPending,searchAssignmentByID(assignmentPending,id));
                        }
                        else {
                            addNode(assignmentCompleted,searchAssignmentByID(inProcessList,id));
                            removeNode(inProcessList,searchAssignmentByID(inProcessList,id));
                        }
                    }
                    break;
                }
                if(moveOption == 2) {
                    if(isAssignmentInList(inProcessList,id)) {
                        printf("\nTarea ya en proceso\n");
                    }
                    else {
                        if(isAssignmentInList(assignmentCompleted,id)) {
                            printf("\nLa tarea ya fue completada\n");
                        }
                        else {
                            addNode(assignmentCompleted,searchAssignmentByID(assignmentPending,id));
                            removeNode(assignmentPending,searchAssignmentByID(assignmentPending,id));
                        }
                    }
                    break;
                }
                break;
            case 2:
                if(isAssignmentInList(assignmentPending,id)) {
                    removeNode(assignmentPending,searchAssignmentByID(assignmentPending,id));
                    break;
                }
                if(isAssignmentInList(assignmentCompleted,id)) {
                    removeNode(assignmentCompleted,searchAssignmentByID(assignmentCompleted,id));
                    break;
                }
                if(isAssignmentInList(inProcessList,id)) {
                    removeNode(inProcessList,searchAssignmentByID(inProcessList,id));
                    break;
                }
                break;
            case 3:
                break;
        }
        printf("\n\nModificar otra tarea?\n1-Si\n2-No\n");
        scanf("%d",&option);
        switch(option) {
            case 1:
                break;
            case 2:
                printf("\n---DATOS DE CADA LISTA---\n");
                printf("\nTareas pendientes\n");
                showData(assignmentPending);
                printf("\nTareas completas\n");
                showData(assignmentCompleted);
                printf("\nTareas en proceso\n");
                showData(inProcessList);
                break;
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