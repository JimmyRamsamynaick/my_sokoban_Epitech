/*
** EPITECH PROJECT, 2024
** sokoban2
** File description:
** end_victory.c
*/

#include "../my.h"
#include <ncurses.h>
#include <unistd.h>

static int saved_nb_o(char *row, int i, int *nb_o)
{
    for (int j = 0; row[j] != '\n'; j = j + 1) {
        if (row[j] == 'O') {
            (*nb_o)++;
        }
    }
}

int get_nb_o(char **saved_map, int nb_rows)
{
    int nb_o = 0;

    for (int i = 0; i != nb_rows; i = i + 1) {
        saved_nb_o(saved_map[i], i, &nb_o);
    }
    return nb_o;
}

static int check_end_victory(char *row, int i, int *cmt)
{
    for (int j = 0; row[j] != '\n'; j = j + 1) {
        if (row[j] == 'O' && row[j] == 'X')
            (*cmt)++;
    }
}

int check_end_game_victory(char **map, char **saved_map, int nb_rows)
{
    int cmt = 0;
    int nb_o = get_nb_o(map, nb_rows);

    for (int i = 0; i != nb_rows; i = i + 1) {
        check_end_victory(saved_map[i], i, &cmt);
        if (cmt == nb_o * 2) {
            usleep(500000);
            return 0;
        }
    }
    return 1;
}
