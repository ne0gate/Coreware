/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-damian.gil
** File description:
** ernno
*/

#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "format.h"

// Write the error found
static bool write_error_str1_at_str2(char *str, unsigned int line)
{
    char *line_str = my_strnbr_base(line, "0123456789");
    bool rand = get_randint(0, 1);

    if (rand)
        write(2, "\e[41m\e[37m", 10);
    else
        write(2, "\e[31m\e[47m", 10);
    write(2, str, my_strlen(str));
    if (line_str) {
        write(2, " at line ", 9);
        write(2, line_str, my_strlen(line_str));
    }
    write(2, " !", 2);
    for (unsigned int i = 0; i < get_randint(0, 500); i++)
        write(2, " ", 1);
    write(2, "\e[0m\n", 5);
    free(line_str);
    return true;
}

//Test if an error was found on errno
bool errno_error_test(unsigned int line)
{
    switch (errno) {
        case 0:
            return false;
        case WRONG_ARG:
            return write_error_str1_at_str2("A wrong argument was found", line);
        case UNKNOWN_REGISTER:
            return write_error_str1_at_str2("A register number was not in the"
                " possible set of digits", line);
        case NO_COMMENT:
            return write_error_str1_at_str2("Need .comment", line);
        case NO_NAME:
            return write_error_str1_at_str2("Need .name", line);
        default:
            return write_error_str1_at_str2("An unknown error occured", line);
    }
}
