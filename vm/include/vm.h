/*
** EPITECH PROJECT, 2023
** coreware
** File description:
** vm test 2
*/

#ifndef VM_H_
    #define VM_H_

    #define MEMORY_SIZE (6144)

typedef struct {
    int memory[MEMORY_SIZE];
    int registers[8];
    int program_counter;
} VirtualMachine;

#endif
