/*
** EPITECH PROJECT, 2023
** str_to_command_array
** File description:
** str_to_command_array
*/

#include <stdlib.h>
#include <stdio.h>

static int is_not_a_separator(char c, char separator)
{
    if (c != separator && c != '\0' && c != ';') {
        return 1;
    }
    return 0;
}

static int count_word_number_minishell(char const *str, char separator)
{
    int	a = 0;
    int	b = 0;
    while (str[a] != '\0') {
        if ((is_not_a_separator(str[a], separator) == 1 && \
is_not_a_separator(str[a + 1], separator)) == 0 || \
(is_not_a_separator(str[a], separator) == 0 && is_not_a_separator(str[a + 1], \
separator)) == 1) {
            b = b + 1;
        }
        a = a + 1;
    }
    return (b);
}

static int len_of_word_minishell(char const *str, int i, char separator)
{
    int a = i;
    while (str[i] != '\0') {
        if (is_not_a_separator(str[i], separator) != 1 || (str[i] == ' ' && \
is_not_a_separator(str[i], separator) != 1)) {
            return (i - a);
        }
        i++;
    }
    return (i - a);
}

static int space_correction_minishell(char const *str, int i, char separator)
{
    while ((str[i] != '\0' && is_not_a_separator(str[i], separator) != 1) || \
str[i] == ' ') {
        i++;
    }
    return i;
}

char **my_str_to_word_array_minishell(char const *str, char separator)
{
    int y = count_word_number_minishell(str, separator);
    char **result = malloc(sizeof(char *) * (y + 1));
    int a = space_correction_minishell(str, 0, separator), b = 0, c = 0;
    while (b < y){
        c = 0;
        result[b] = malloc(sizeof(char) * (len_of_word_minishell(str, a, \
separator) + 1));
        while (str[a] != '\0' && is_not_a_separator(str[a], separator) != 0) {
            result[b][c] = str[a];
            c = c + 1;
            a = a + 1;
        }
        result[b][c] = '\0';
        a = space_correction_minishell(str, a, separator);
        b = b + 1;
    }
    result[b] = NULL;
    return result;
}
