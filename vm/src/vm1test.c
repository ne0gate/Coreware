/*
** EPITECH PROJECT, 2023
** coreware
** File description:
** test vm 2
*/

#include "../include/vm.h"
#include <stdio.h>
#include <stdlib.h>

void load_champion(VirtualMachine *vm, int *champion, int address, int size)
{
    for (int i = 0; i < size; i++) {
        vm->memory[address + i] = champion[i];
    }
}


void execute_instruction(VirtualMachine *vm)
{
    int instruction = vm->memory[vm->program_counter];
    int opcode = (instruction >> 24) & 0xFF;
    int operand1 = (instruction >> 16) & 0xFF;
    int operand2 = (instruction >> 8) & 0xFF;
    int operand3 = instruction & 0xFF;

    switch (opcode) {
        case 0x01:
            vm->registers[operand1] = vm->registers[operand2] + vm->registers[operand3];
            break;
        case 0x02:
            vm->registers[operand1] = vm->registers[operand2] - vm->registers[operand3];
            break;
        case 0x03:
            vm->registers[operand1] = vm->registers[operand2] - vm->registers[operand3];
            break;
        case 0x05:
            vm->registers[operand1] = vm->registers[operand2] - vm->registers[operand3];
            break;
        case 0x06:
            vm->registers[operand1] = vm->registers[operand2] - vm->registers[operand3];
            break;
        case 0x07:
            vm->registers[operand1] = vm->registers[operand2] - vm->registers[operand3];
            break;
        case 0x08:
            vm->registers[operand1] = vm->registers[operand2] - vm->registers[operand3];
            break;
        case 0x09:
            vm->registers[operand1] = vm->registers[operand2] - vm->registers[operand3];
            break;
    }
    vm->program_counter++;
}

int main(void)
{
    VirtualMachine vm;
    vm.program_counter = 0;

    int champion[] = {0x01020304, 0x02030405, 0x03040506};
    int champion2[] = {0x04050607, 0x05060708, 0x06070809};
    int champion_size = sizeof(champion) / sizeof(champion[0]);
    int champion_size2 = sizeof(champion2) / sizeof(champion2[0]);

    load_champion(&vm, champion, 0, champion_size);
    load_champion(&vm, champion2, 0, champion_size2);

    while (vm.program_counter < MEMORY_SIZE) {
        execute_instruction(&vm);
    }

    printf("Result: %d\n", vm.registers[0]);

    return 0;
}
