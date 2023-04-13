#include <stdio.h>
#include <stdlib.h>
#include "assignments_functions.h"

int main(int argc,char** argv) {
    int numberAssignments;
    printf("Ingresar la cantidad de tareas a realizar: ");
    scanf("%d",&numberAssignments);
    Assignment** assignments = malloc(numberAssignments*sizeof(*assignments));
    Assignment** assignmentsCompleted = malloc(numberAssignments*sizeof(*assignmentsCompleted));
    initializeAssignments(assignments,assignmentsCompleted,numberAssignments);
    assignmentsInterface(assignments,numberAssignments);
    searchAssignmentByKeyword(assignments,numberAssignments,"ola");
    searchAssignmentByID(assignments,numberAssignments,2);
    moveAssignment(assignmentsCompleted,assignments,numberAssignments);
    showCompletedAssignments(assignmentsCompleted,numberAssignments);
    showPendingAssignments(assignments,numberAssignments);
    freeMemory(assignments,numberAssignments);
    freeMemory(assignmentsCompleted,numberAssignments);
    return 0;
}