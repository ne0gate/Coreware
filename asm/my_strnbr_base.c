/*
** EPITECH PROJECT, 2022
** libmy
** File description:
** putnbr into string depends on a given base
*/

#include <stdlib.h>
#include "format.h"

static void add(char *first, char c)
{
    unsigned int size = my_strlen(first);

    first[size] = c;
    first[size + 1] = '\0';
}

static void my_strnbr_base_part2_into_string(char *ret, int nbr,
    char const *base)
{
    int len = my_strlen(base);
    char nb;

    if (nbr >= len) {
        nb = nbr % len;
        my_strnbr_base_part2_into_string(ret, (nbr - nb) / len, base);
    } else {
        nb = nbr;
    };
    add(ret, base[(unsigned int) nb]);
}

//Malloc a string with the number given in the base given (without prefix)
char *my_strnbr_base(int nbr, char const *base)
{
    char *ret = malloc_empty(10);

    if (nbr < 0) {
        add(ret, '-');
        nbr = 0 - nbr;
    };
    if (nbr == 0) {
        add(ret, base[0]);
        add(ret, '\0');
        return ret;
    };
    my_strnbr_base_part2_into_string(ret, nbr, base);
    return ret;
}
