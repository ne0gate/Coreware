/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-damian.gil
** File description:
** format
*/

#include <errno.h>
#include <stdbool.h>
#include "../includes/op.h"
#include "../includes/format.h"

static bool str_is_label(char *str)
{
    unsigned int j = 0;

    for (unsigned int i = 0; str[j] != '\0'; i++) {
        if (LABEL_CHARS[i] == str[j]) {
            j++;
            i = 0;
        }
        if (LABEL_CHARS[i] == '\0')
            return false;
    }
    return true;
}

static bool str_is_digit(char *str)
{
    for (unsigned int i = 0; str[i] != '\0'; i++)
        if (str[i] < '0' || str[i] > '9')
            return false;
    return true;
}

bool is_dir(char *arg)
{
    if (arg[0] != DIRECT_CHAR || !str_is_digit(&arg[1])) {
        errno = WRONG_ARG;
        return false;
    }
    return true;
}

//Test if a string is a register
bool is_reg(char *arg)
{
    if (arg[0] != 'r' || !str_is_digit(&arg[1])) {
        errno = WRONG_ARG;
        return false;
    }
    if (my_getnbr(&arg[1]) < 1 || my_getnbr(&arg[1]) > REG_NUMBER) {
        errno = UNKNOWN_REGISTER;
        return false;
    }
    return true;
}

//Test if a string is a indirect number
bool is_ind(char *arg)
{
    if (!str_is_digit(&arg[1])) {
        errno = WRONG_ARG;
        return false;
    }
    return true;
}

//Test if a string is a label
bool is_lab_arg(char *arg)
{
    if (arg[0] == DIRECT_CHAR)
        arg++;
    if (arg[0] != LABEL_CHAR || !str_is_label(&arg[1])) {
        errno = WRONG_ARG;
        return false;
    }
    return true;
}
