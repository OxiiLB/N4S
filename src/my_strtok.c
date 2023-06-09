/*
** EPITECH PROJECT, 2023
** my_strtok
** File description:
** function that split an str into a word array
** but takes in argument separators
*/

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

static bool is_in_separators(char *separators, char c)
{
    for (int i = 0; separators[i] != '\0'; i++) {
        if (separators[i] == c)
            return true;
    }
    return false;
}

static char **malloc_words(char const *str, char *separators)
{
    int i = 0;
    int j = 0;
    int count = 0;
    for (i = 0; str[i] != '\0'; i += 1) {
        if (is_in_separators(separators, str[i]) == true)
            continue;
        count += 1;
        for (j = i + 1; str[j] != '\0' &&
        is_in_separators(separators, str[j]) == false; j += 1);
        i = j - 1;
    }
    char **res = malloc(sizeof(char *) * (count + 1));
    if (res == NULL)
        return NULL;
    return res;
}

char **my_strtok(char const *str, char *separators)
{
    int j = 0;
    int k = 0;
    char **res = malloc_words(str, separators);
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (is_in_separators(separators, str[i]) == true)
            continue;
        for (j = i + 1; str[j] != '\0' &&
        is_in_separators(separators, str[j]) == false; j += 1);
        res[k] = malloc(sizeof(char) * (j - i + 1));
        if (res[k] == NULL)
            return NULL;
        strncpy(res[k], str + i, j - i);
        res[k][j - i] = '\0';
        k += 1;
        i = j - 1;
    }
    res[k] = NULL;
    return res;
}
