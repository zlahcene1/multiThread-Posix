/*
** EPITECH PROJECT, 2022
** PANORAMIX 2022
** File description:
** CATCH ARGUMENT AND CHECKÙ
*/

#include "headers.h"

bool is_a_num(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[0] == '0')
            return false;
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

bool great_number(char **argument, int size)
{
    for (int i = 1; i < size; i++) {
        if (!argument[i])
            return false;
        for (int idx = 0; argument[i][idx] != '\0'; idx++) {
            if (!is_a_num(argument[i]))
                return false;
            }
    }
    return true;
}
