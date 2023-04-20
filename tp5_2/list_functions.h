#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tarea {
    int assignmentID;
    char* description;
    int duration;
};

typedef struct Tarea Assignment;

struct Nodo {
    Assignment assignment;
    struct Nodo* next;
};

typedef struct Nodo AssignmentNode;

AssignmentNode* createList() { return NULL; }

AssignmentNode* createNode(Assignment assignment) {
    AssignmentNode* node = (AssignmentNode*)malloc(sizeof(*node));
    node->assignment = assignment;
    node->next = NULL;
    return node;
}

void addNode(AssignmentNode** startingNode,Assignment assignment) {
    AssignmentNode* node = createNode(assignment);
    node->next = *startingNode;
    *startingNode = node;
}

void removeNode(AssignmentNode** startingNode,Assignment assignment) {
    AssignmentNode* tempNode = *startingNode;
    AssignmentNode* prevNode = *startingNode;
    while(tempNode != NULL && tempNode->assignment.assignmentID != assignment.assignmentID 
            && strcmp(tempNode->assignment.description,assignment.description) != 0 
            && tempNode->assignment.duration != assignment.duration) {
        prevNode = tempNode;
        tempNode = tempNode->next;
    }
    if(tempNode != NULL) {
        if(tempNode == *startingNode) {
            prevNode = tempNode->next;
            *startingNode = prevNode;
        }
        else {
            prevNode->next = tempNode->next;
        }
        free(tempNode);
    }
}