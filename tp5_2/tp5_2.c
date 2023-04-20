#include "assignments_functions.h"

int main(int argc,char** argv) {
    AssignmentNode* assignments = createList();
    AssignmentNode* completedAssignments = createList();
    AssignmentNode** pAssignments = &assignments;
    AssignmentNode** pCompleted = &completedAssignments;
    assignmentsInterface(pAssignments);
    moveAssignment(pCompleted,pAssignments);
    searchAssignmentByKeyword(assignments,"ola");
    searchAssignmentByID(assignments,2);
    showCompletedAssignments(*pCompleted);
    showPendingAssignments(*pAssignments);
    if(isAssignmentCompleted(completedAssignments,2)) {
        printf("\nTarea completada");
    }
    else {
        printf("\nTarea pendiente");
    }
    freeMemory(pAssignments);
    freeMemory(pCompleted);
    return 0;
}