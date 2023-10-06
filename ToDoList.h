//
// Created by Pingu on 04.10.23.
//

#ifndef TESTPROJECT_TODOLIST_H
#define TESTPROJECT_TODOLIST_H

#include <stdio.h>

typedef struct {
    int ID;
    char *content;
    u_int8_t completed;
} ToDo;

typedef struct linkedListNode {
    ToDo *data;
    struct linkedListNode *nextElement;
};

typedef struct {
    struct linkedListNode *listStart;
} ToDoList;

ToDoList *initEmptyList();

// create methods:
void addToDoListElementAfterNode(struct linkedListNode * listNode, ToDo * itemToAdd);
void appendToEndOfList(ToDoList *list, ToDo *itemToAdd);

// getters:
ToDo *getItemAtPos(ToDoList *list, int pos);

// delete methods
int deleteList(ToDoList *theList);
int deleteNodeAtPos(ToDoList *theList, int pos);

#endif //TESTPROJECT_TODOLIST_H
