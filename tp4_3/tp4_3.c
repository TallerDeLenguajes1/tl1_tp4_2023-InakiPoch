#include "assignments_functions.h"

int main(int argc,char** argv) {
    AssignmentNode* assignments = createList();
    AssignmentNode* completedAssignments = createList();
    AssignmentNode** pAssignments = &assignments;
    AssignmentNode** pCompleted = &completedAssignments;
    assignmentsInterface(pAssignments);
    moveAssignment(pCompleted,pAssignments);
    showCompletedAssignments(*pCompleted);
    showPendingAssignments(*pAssignments);
    freeMemory(pAssignments);
    freeMemory(pCompleted);
    return 0;
}