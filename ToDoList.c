//
// Created by Pingu on 04.10.23.
//

#include "ToDoList.h"
#include <stdlib.h>

ToDoList *initEmptyList() {
    struct linkedListNode *firstNode = (struct linkedListNode*) malloc(sizeof (struct linkedListNode));
    //printf("Not implemented");
    ToDoList *newList = (ToDoList *) malloc(sizeof(ToDoList));

    firstNode->data = NULL;
    newList->listStart = firstNode;

    return newList;
}

/** Method to append a new ToDoItem after the specified node. Uses the arguments: listNode (pos 1) && itemToAdd (pos 2) */
void addToDoListElementAfterNode(struct linkedListNode * listNode, ToDo *itemToAdd) {

    // check if this node is empty ==> if so, add the data there
    if (listNode->data == NULL) {
        listNode->data = itemToAdd;
        return;
    }

    struct linkedListNode *newNode = (struct linkedListNode *) malloc(sizeof(struct linkedListNode));

    newNode->data = itemToAdd;
    newNode->nextElement = listNode->nextElement;;

    listNode->nextElement = newNode;
}

/** Method to append a new ToDoItem at the end of a list */
void appendToEndOfList(ToDoList *list, ToDo *itemToAdd) {
    // find the end of the list:
    struct linkedListNode * curr = list->listStart;

    if (curr == NULL) {
        struct linkedListNode *newNode = (struct linkedListNode *) malloc(sizeof(struct linkedListNode));
        newNode->data = itemToAdd;
        newNode->nextElement = NULL;
        list->listStart = newNode;
        return;
    }

    while (curr->data != NULL && curr->nextElement != NULL)
        curr = curr->nextElement;

    // append element
    if (curr->data == NULL) {
        curr->data = itemToAdd;
    } else {
        struct linkedListNode *newNode = (struct linkedListNode *) malloc(sizeof(struct linkedListNode));
        newNode->data = itemToAdd;
        newNode->nextElement = NULL;
        curr->nextElement = newNode;
    }
}

/** Method to request a specific ToDoItem from a Nth position in the list ==> returns null if not found */
ToDo *getItemAtPos(ToDoList *list, int pos) {
    int i = 0;

    struct linkedListNode *curr = list->listStart;
    while (curr != NULL && i < pos) {
        curr = curr->nextElement;
        i++;
    }

    if (i == pos && curr != NULL) {
        return curr->data;
    } else {
        return NULL;
    }
}

/** Method to clear the entire list and deallocate the memory */
int deleteList(ToDoList *theList) {
    struct linkedListNode * currElement = theList->listStart;
    struct linkedListNode * nextElement = NULL;
    while(currElement != NULL) {
        nextElement = currElement->nextElement;
        if (currElement->data != NULL) {
            free(currElement->data->content);
            free(currElement->data);
        }
        free(currElement);
        currElement = nextElement;
    }

    free(theList);

    return 0;
}

int deleteNodeAtPos(ToDoList *list, int pos) {
    // ToDo: Implement delete methods

    if (list == NULL | list->listStart == NULL | list->listStart->data == NULL)
        return -1;

    printf("%i\n", pos);

    int i = 0;

    struct linkedListNode *prev = NULL;
    struct linkedListNode *curr = list->listStart;

    while (i < pos && curr != NULL) {
        prev = curr;
        curr = curr->nextElement;
        i++;
    }


    if (curr == NULL)
        return -1;

    if (prev == NULL)
        list->listStart = curr->nextElement;
    else
        prev->nextElement = curr->nextElement; // dereference it


    free(curr->data->content);
    free(curr->data);
    free(curr);

    return 0;
}