/*
** EPITECH PROJECT, 2024
** sokoban2
** File description:
** array.c
*/

#include "../my.h"
#include <ncurses.h>

int array(char **array, int nb_rows)
{
    for (int i = 0; i != nb_rows; i = i + 1) {
        printw(array[i]);
    }
    return 0;
}
