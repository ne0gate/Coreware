/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-damian.gil
** File description:
** asm
*/

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/stat.h>
#include "format.h"

int main(int ac, char const *const *av)
{
    FILE *file = NULL;

    if (ac != 3) {
        write(2, "\e[30m\e[47mWrong number of arguments !\e[0m\n", 42);
        return 84;
    }
    fopen(av[1], "r");
    if (file == NULL) {
        write(2, "Fopen failed\n", 13);
        return false;
    }
    if (!main_asm(file, av[2]))
        return 84;
    return 0;
}

bool main_asm(FILE *rfile, char const *wfilepath)
{
    file_info_t sfile = {0};
    FILE *wfile = NULL;

    if (!fill_lines(&sfile, rfile)) {
        fclose_protected(rfile);
        return false;
    }
    fclose_protected(rfile);
    if (!asm_loop((const char *const *) sfile.lines, NULL)) {
        return false;
    }
    wfile = fopen(wfilepath, "w");
    if (wfile == NULL) {
        write(2, "Fopen failed\n", 13);
        return false;
    }
    asm_loop((const char *const *) sfile.lines, wfile);
    return true;
}
