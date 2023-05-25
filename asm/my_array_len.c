/*
** EPITECH PROJECT, 2023
** my_array_len.c
** File description:
** return the lenght of an array
*/
#include <stddef.h>
#include <stdbool.h>

static bool array_compare_with_null(void **ptr, unsigned int i)
{
    return ptr[i] != NULL;
}

size_t my_array_len(void *ptr)
{
    size_t len = 0;

    for (unsigned int i = 0; array_compare_with_null(ptr, i); i ++) {
        len += 1;
    }
    return len;
}
