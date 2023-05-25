/*
** EPITECH PROJECT, 2022
** libmy
** File description:
** Rm 2d array
*/

#include <unistd.h>
#include "format.h"
#include <stdlib.h>

void rm_2d_array(char **map)
{
    size_t len = my_array_len(map);

    if (map == NULL)
        return;
    for (unsigned int i = 0; i < len; i++) {
        free(map[i]);
    }
    free(map);
}
