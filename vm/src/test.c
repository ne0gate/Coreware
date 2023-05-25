#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define MEM_SIZE 1024

typedef enum {
    NOP = 0,
    ADD = 1,
    SUB = 2,
    MOV = 3,
    JMP = 4,
    JZ = 5,
    JNZ = 6,
    PRINT = 7,
    HALT = 8
} OpCode;

int main(int ac, char **av) {
    if (ac < 2) {
        printf("Usage: %s <program_file>\n", av[0]);
        return 1;
    }

    FILE *program_file = fopen(av[1], "rb");
    if (program_file == NULL) {
        printf("Failed to open program file %s\n", av[1]);
        return 1;
    }

    int mem[MEM_SIZE] = {0};
    int reg[4] = {0};
    int ip = 0;

    fread(mem, sizeof(int), MEM_SIZE, program_file);
    fclose(program_file);

    int running = 1;
    while (running) {

        int instr = mem[ip];
        OpCode op = instr & 0x7;
        int arg1 = (instr >> 3) & 0x7;
        int arg2 = (instr >> 6) & 0x3FF;

        switch (op) {
            case NOP:
                break;
            case ADD:
                reg[arg1] += mem[arg2];
                break;
            case SUB:
                reg[arg1] -= mem[arg2];
                break;
            case MOV:
                reg[arg1] = arg2;
                break;
            case JMP:
                ip = arg2;
                break;
            case JZ:
                if (reg[arg1] == 0) {
                    ip = arg2;
                }
                break;
            case JNZ:
                if (reg[arg1] != 0) {
                    ip = arg2;
                }
                break;
            case PRINT:
                printf("%d\n", mem[arg2]);
                break;
            case HALT:
                running = 0;
                break;
            default:
                printf("Unknown opcode: %d\n", op);
                running = 0;
                break;
        }

        ip++;
    }

    return 0;
}
