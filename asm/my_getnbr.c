/*
** EPITECH PROJECT, 2022
** libmy
** File description:
** return number found in string (base 10)
*/

static int return_nb(long int nb, int const *neg);
#include "format.h"

static int coding_style_is_shit(int *test, long int *nb)
{
    if (*test == 6) {
        *test = 0;
        if (*nb == 0)
            return 42;
    };
    return 0;
}

static void inside_add_nb(long int *nb, char const *str, int const i, int *neg)
{
    int gre = 0;

    if (*nb != 0) {
        while (*neg > 1) {
            *neg = *neg - 2;
        };
    };
    *nb = return_nb(((*nb * 10) + (str[i] - 48)), &gre);
}

static int add_nb(long int *nb, char const *str, int const i, int *neg)
{
    if (str[i] < 58 && str[i] > 47) {
        inside_add_nb(nb, str, i, neg);
    } else if (str[i] == '-') {
        *neg = *neg + 1;
        return 4;
    } else {
        *neg = 0;
        return 4;
    };
    return 6;
}

static int return_nb(long int nb, int const *neg)
{
    int i = -2147483648;
    int j = 2147483647;

    if ((*neg < 0) || (nb < i) || (nb > j))
        return 0;
    if (*neg == 0)
        return nb;
    if (*neg == 1)
        return (0 - nb);
    return nb;
}

int my_getnbr(char const *str)
{
    int len = my_strlen(str);
    int i = 0;
    long int nb = 0;
    int neg = 0;
    int test = -2;

    while (i < len) {
        test = add_nb(&nb, str, i, &neg) + (test * 3);
        if (coding_style_is_shit(&test, &nb) == 42)
            return 0;
        i++;
        if ((test == 4) && (nb != 0))
            return return_nb(nb, &neg);
    };
    return return_nb(nb, &neg);
}
