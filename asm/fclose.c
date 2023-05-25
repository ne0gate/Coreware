/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-damian.gil
** File description:
** fclose
*/

#include <stdio.h>

//fclose but test if not NULL before closing
int fclose_protected(FILE *flux)
{
    if (flux == NULL)
        return 0;
    return fclose(flux);
}
