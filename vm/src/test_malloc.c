/*
** EPITECH PROJECT, 2023
** test malloc and memdump
** File description:
** coreware
*/
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

int main(int ac, char **av)
{
    while(ac == 1) {
        char *ptr = malloc(sizeof(char) * strlen(ptr));
        free(ptr);
    }
    return 0;
}
