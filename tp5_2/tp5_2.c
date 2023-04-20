#include "assignments_functions.h"

int main(int argc,char** argv) {
    AssignmentNode* assignments = createList();
    AssignmentNode* completedAssignments = createList();
    AssignmentNode* inProcessAssignments = createList();
    AssignmentNode** pAssignments = &assignments;
    AssignmentNode** pCompleted = &completedAssignments;
    AssignmentNode** pInProcess = &inProcessAssignments;
    assignmentsInterface(pAssignments);
    moveAssignment(pCompleted,pAssignments,pInProcess);
    freeMemory(pAssignments);
    freeMemory(pCompleted);
    freeMemory(pInProcess);
    return 0;
}