/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-damian.gil
** File description:
** fill_line
*/

#include <stdio.h>
#include <sys/types.h>
#include "format.h"

bool fill_lines(file_info_t *sfile, FILE *rfile)
{
    char *str = NULL;
    size_t m = 0;
    sfile->lines = malloc_empty(sizeof(char *) * 1);

    if (sfile->lines == NULL)
        return false;
    for (ssize_t n = 0; n != -1; n = getline(&str, &m, rfile)) {
        if (n == 0)
            continue;
        if (str[n - 1] == '\n')
            str[n - 1] = '\0';
        str[my_strlen_until(str, '#') - 1] = '\0';
        if (my_strlen(str) < 3)
            continue;
        if (!my_strncmp(str, ".name:", 6)) {
            my_strcpy(sfile->name, &str[6]);
            continue;
        }
        if (!my_strncmp(str, ".comment:", 9)) {
            my_strcpy(sfile->comment, &str[9]);
            continue;
        }
        if (!pointer_add_to_list((void ***) &sfile->lines, (void **) &str)) {
            rm_2d_array(sfile->lines);
            return false;
        }
    }
    return true;
}
