/*
** EPITECH PROJECT, 2024
** sokoban2
** File description:
** nb_row_cols.c
*/

#include "../my.h"
#include <ncurses.h>

int bigger_line(int line_1, int line_2)
{
    if (line_2 > line_1)
        line_1 = line_2;
    return (line_1);
}

int get_nb_cols(char *buffer)
{
    int i = 0;
    int line_1 = 0;
    int line_2 = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == '\n') {
            line_1 = bigger_line(line_1, line_2);
            line_2 = 0;
        } else {
            line_2 = line_2 + 1;
        }
        i = i + 1;
    }
    return bigger_line(line_1, line_2);
}

int get_nb_rows(char *buffer)
{
    int nb_rows = 0;

    for (int i = 0; buffer[i] != '\0'; i = i + 1) {
        if (buffer[i] == '\n')
            nb_rows = nb_rows + 1;
    }
    return (nb_rows);
}
