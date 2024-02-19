/*
** EPITECH PROJECT, 2024
** sokoban2
** File description:
** move.c
*/

#include "../my.h"
#include <ncurses.h>

static char **left(char *row, int i, int *pi, int *pj)
{
    for (int j = 0; row[j] != '\n'; j = j + 1) {
        if (row[j] == 'P') {
            *pi = i;
            *pj = j;
        }
    }
}

char **move_left(char **map, int nb_rows, char **saved_map)
{
    int pi = 0;
    int pj = 0;

    for (int i = 0; i != nb_rows; i = i + 1) {
        left(map[i], i, &pi, &pj);
    }
    left_management(map, pi, pj, saved_map);
    return map;
}

static char **right(char *row, int i, int *pi, int *pj)
{
    for (int j = 0; row[j] != '\n'; j = j + 1) {
        if (row[j] == 'P') {
            *pi = i;
            *pj = j;
        }
    }
}

char **move_right(char **map, int nb_rows, char **saved_map)
{
    int pi = 0;
    int pj = 0;

    for (int i = 0; i != nb_rows; i = i + 1) {
        right(map[i], i, &pi, &pj);
    }
    right_management(map, pi, pj, saved_map);
    return map;
}

static char **down(char *row, int i, int *pi, int *pj)
{
    for (int j = 0; row[j] != '\n'; j = j + 1) {
        if (row[j] == 'P') {
            *pi = i;
            *pj = j;
        }
    }
}

char **move_down(char **map, int nb_rows, char **saved_map)
{
    int pi = 0;
    int pj = 0;

    for (int i = 0; i != nb_rows; i = i + 1) {
        down(map[i], i, &pi, &pj);
    }
    down_management(map, pi, pj, saved_map);
    return map;
}

static char **get_up(char *row, int i, int *pi, int *pj)
{
    for (int j = 0; row[j] != '\n'; j = j + 1) {
        if (row[j] == 'P') {
            *pi = i;
            *pj = j;
        }
    }
}

char **move_up(char **map, int nb_rows, char **saved_map)
{
    int pi = 0;
    int pj = 0;

    for (int i = 0; i < nb_rows; i = i + 1) {
        get_up(map[i], i, &pi, &pj);
    }
    up_management(map, pi, pj, saved_map);
    return map;
}

char **deplacement(int input, char **map, int nb_rows, char **saved_map)
{
    switch (input) {
        case 65:
            map = move_up(map, nb_rows, saved_map);
            break;
        case 66:
            map = move_down(map, nb_rows, saved_map);
            break;
        case 68:
            map = move_left(map, nb_rows, saved_map);
            break;
        case 67:
            map = move_right(map, nb_rows, saved_map);
            break;
        default:
            break;
    }
    return map;
}
