//
// Created by Pingu on 05.10.23.
//

#ifndef TESTPROJECT_TUI_H
#define TESTPROJECT_TUI_H

#include "ToDoList.h"

void userMode(ToDoList *list);
void printHelpStatement();
void addNewItemMode(ToDoList *list);
void printAllItems(ToDoList *list);
void markAsCompleted(ToDoList *list, int itemPos);

#endif //TESTPROJECT_TUI_H
