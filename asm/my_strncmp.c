/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** compare n char in strings
*/

#include <stddef.h>
#include "format.h"

int my_strncmp(const char* s1, const char* s2, int n)
{
    while (n > 0 && (*s1) != '\0' && (*s2) != '\0') {
        if (*s1 != *s2)
            return *s1 - *s2;
        s1++;
        s2++;
        n--;
    }
    if (n == 0)
        return 0;
    return *s1 - *s2;
}
