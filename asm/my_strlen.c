/*
** EPITECH PROJECT, 2022
** libmy
** File description:
** return lenth of string
*/

#include <sys/types.h>

size_t my_strlen(char const *str)
{
    size_t i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}
