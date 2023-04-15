#include "assignments_functions.h"

int main(int argc,char** argv) {
    int numberAssignments;
    AssignmentNode* assignments = createList();
    AssignmentNode* completedAssignments = createList();
    AssignmentNode** pAssignments = &assignments;
    AssignmentNode** pCompleted = &completedAssignments;
    printf("Ingresar la cantidad de tareas a realizar: ");
    scanf("%d",&numberAssignments);
    assignmentsInterface(pAssignments,numberAssignments);
    moveAssignment(pCompleted,pAssignments);
    showCompletedAssignments(*pCompleted);
    showPendingAssignments(*pAssignments);
    freeMemory(pAssignments);
    freeMemory(pCompleted);
    return 0;
}