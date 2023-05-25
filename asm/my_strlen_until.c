/*
** EPITECH PROJECT, 2022
** libmy
** File description:
** return lenth of string (stop at a given char or \0)
*/

int my_strlen_until(char const *str, char c)
{
    int i = 0;

    while (str[i] != '\0' && str[i] != c) {
        i++;
    };
    return i;
}
