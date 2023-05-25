/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** malloc void *
** with 0 everywhere
** Return NULL on failure
** works like calloc
*/

#include <stdlib.h>
#include <stdio.h>

static void set_buf(char *ptr, size_t size)
{
    for (size_t i = 0; i < size; i++)
        ptr[i] = 0;
}

void *malloc_empty(size_t size)
{
    void *ptr;

    if (size < 1)
        return NULL;
    ptr = malloc(size);
    if (ptr == NULL)
        return NULL;
    set_buf(ptr, size);
    return ptr;
}
