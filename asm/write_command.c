/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-damian.gil
** File description:
** write_command
*/

#include <stdbool.h>
#include <errno.h>
#include <stdio.h>
#include "format.h"
#include "op.h"

//Loop to know how to call errno_error_test
bool asm_loop(const char *const *file_lines, FILE *file)
{
    unsigned int line_of_op_tab = 0;
    char **arg = NULL;

    for (unsigned int i = 0; file_lines[i] != NULL; i++) {
        line_of_op_tab = find_op_tab_line(file_lines[i]);
        if (!execute(line_of_op_tab, arg, file)) {
            errno_error_test(i);
            return false;
        }
    }
    return true;
}

//verify and print what's found on the line
bool execute(unsigned int line_of_op_tab, char **arg, FILE *file)
{
    op_t op = op_tab[line_of_op_tab];
    bool test = true;

    fwrite(&op.code, sizeof(op.code), 1, file);
    for (unsigned int i = 0; i < (unsigned int) op.nbr_args; i++) {
        errno = 0;
        test = false;
        if (op.type[i] & T_REG && is_reg(arg[i])) {
            test = true;
            write_reg(arg[i], file);
        }
        if (op.type[i] & T_DIR && is_dir(arg[i])) {
            test = true;
            write_dir(arg[i], file);
        }
        if (op.type[i] & T_IND && is_ind(arg[i])) {
            test = true;
            write_ind(arg[i], file);
        }
        if (op.type[i] & T_LAB && is_lab_arg(arg[i])) {
            test = true;
            write_lab(arg[i], file);
        }
        if (!test)
            return false;
    }
    return true;
}
