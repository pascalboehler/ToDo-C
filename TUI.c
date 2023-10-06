//
// Created by Pingu on 05.10.23.
//

#include "TUI.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void userMode(ToDoList *newList) {

    while (0 == 0) {

        printf("> ");
        char buffer[20];
        if(fgets(buffer, sizeof buffer, stdin) != NULL) {
            /* Now inspect and further parse the string in line. */
            // ToDo: Split the string and invoke the corresponding cmd

            /* Split up the typed in command into cmd part and argument part and add it to args*/
            char *args[2];
            char *token = strtok(buffer, " ");
            args[0] = &token[0];
            token = strtok(NULL, " ");
            args[1] = &token[0];


            char command = args[0][0];

            switch(command) {
                case '+':
                case 'a':
                    addNewItemMode(newList);
                    break;
                case 'p':
                    printAllItems(newList);
                    break;
                case 'd':
                    if (args[1] == NULL) {
                        printf("Argument position missing; d [n]\n");
                        break;
                    }
                    deleteNodeAtPos(newList, (int) strtol(args[1], 0, 10));
                    break;
                case 'x':
                case 'q':
                    return;
                case 'c':
                    // FIXME: Not beautiful, make better
                    markAsCompleted(newList, (int) strtol(args[1], 0, 10));
                    break;
                case 'h':
                case '?':
                    printHelpStatement();
                    break;
                case '\n':
                    break;
                default:
                    printf("Command not found!\n");
                    printHelpStatement();
                    break;
            }
        }
    }
}

void markAsCompleted(ToDoList *list, int itemPos) {
    struct linkedListNode *curr = list->listStart;
    int i = 0;
    while (i < itemPos && curr != NULL) {
        curr = curr->nextElement;
        i++;
    }
    if (curr == NULL) {
        printf("Item does not exist. Aborting\n");
        return;
    }
    printf("%s\n", curr->data->content);

    curr->data->completed = !curr->data->completed;

}

void printAllItems(ToDoList *list) {

    if (list == NULL | list->listStart == NULL) {
        printf("== Empty list ==\n");
        return;
    }

    if (list->listStart->data == NULL) {
        printf("== Empty list ==\n");
        return;
    }


    struct linkedListNode *curr = list->listStart;

    int counter = 0;
    while (curr != NULL) {
        printf("ToDoItem %i:\t%s", counter, curr->data->content);
        if (curr->data->completed == 1) {
            printf("\tCOMPLETED\n");
        } else {
            printf("\n");
        }
        curr = curr->nextElement;
        counter++;
    }
}

void addNewItemMode(ToDoList *list) {
    printf("Adding new item\n");
    printf("ToDo Item Name: ");

    char *buffer = malloc(sizeof (char[60]));
    if(fgets(buffer, sizeof(char[60]), stdin) != NULL) {
        ToDo *newItem = malloc(sizeof(ToDo));
        //printf("%s\n", buffer);
        // strip all \n from the buffer
        for (int i = 0; i < sizeof(buffer); i++) {
            if(buffer[i] == '\n')
                buffer[i] = ' ';
        }

        // FIXME: This is not memory save!!

        newItem->ID = 254;
        newItem->completed = 0;
        newItem->content = buffer;

        //printf("%s\n", newItem->content);
        appendToEndOfList(list, newItem);
    }
    printf("Created element successfully\n");
}

void printHelpStatement() {
    printf("ToDo-C - a memory stored TUI App\n");
    printf("================================\n");
    printf("       Available commands       \n");
    printf("================================\n");
    printf("a, +   Add a new item\n");
    printf("p      Print all items\n");
    printf("c (x)  Complete item x\n");
    printf("d (x)  Delete entry from pos x\n");
    printf("x,q    Exit the program\n");
    printf("h, ?   Shows this help message\n");
    printf("================================\n");
}