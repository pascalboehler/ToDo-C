cmake_minimum_required(VERSION 3.26)
project(testproject C)

set(CMAKE_C_STANDARD 23)

add_executable(testproject main.c
        ToDoList.h
        ToDoList.c
        TUI.c
        TUI.h)
