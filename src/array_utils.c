/*
** EPITECH PROJECT, 2023
** array_utils
** File description:
** array_utils
*/

#include "n4s.h"
#include <stdlib.h>

void print_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        fprintf(stderr, "%s\n", tab[i]);
    }
}

int len_tab(char **tab)
{
    int len = 0;

    for (int i = 0; tab[i] != NULL; i++) {
        len++;
    }
    return len;
}
