/*
** EPITECH PROJECT, 2024
** sokoban2
** File description:
** fill_tab.c
*/

#include "../my.h"
#include <ncurses.h>

char **fill_tab(char **tab, char *buffer, int rows)
{
    int i = 0;
    int j = 0;
    int idx = 0;

    while (buffer[idx] != '\0' && i < rows) {
        if (buffer[idx] == '\n') {
            tab[i][j] = buffer[idx];
            i = i + 1;
            j = 0;
        } else {
            tab[i][j] = buffer[idx];
            j = j + 1;
        }
        idx = idx + 1;
    }
    return tab;
}
