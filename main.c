#include <stdio.h>
#include <stdlib.h>
#include "ToDoList.h"
#include "TUI.h"

int main() {
    ToDoList *list = initEmptyList();

    userMode(list);

    // cleaning up:
    deleteList(list);

    return 0;
}
