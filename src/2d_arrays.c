/*
** EPITECH PROJECT, 2024
** sokoban2
** File description:
** 2d_arrays.c
*/

#include "../my.h"
#include <ncurses.h>
#include <stdlib.h>

char **malloc_2d_arrays(int rows, int cols)
{
    char **array;

    array = malloc(sizeof(char *) * rows);
    for (int i = 0; i < rows; i = i + 1) {
        array[i] = malloc(sizeof(char) * cols + 1);
    }
    return array;
}
