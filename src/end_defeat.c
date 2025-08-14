/*
** EPITECH PROJECT, 2024
** sokoban2
** File description:
** end_defeat.c
*/

#include "../my.h"
#include <ncurses.h>
#include <unistd.h>

static int get_nb(char *line)
{
    int count = 0;

    for (int j = 0; line[j] != '\n'; j = j + 1) {
        if (line[j] == 'X')
            count = count + 1;
    }
    return count;
}

int get_nb_x(char **map, int nb_rows)
{
    int nb_x = 0;

    for (int i = 0; i != nb_rows; i = i + 1) {
        nb_x = nb_x + get_nb(map[i]);
    }
    return nb_x;
}

int check_stuck(char **map, int i, int j)
{
    // Check if box is stuck in corner (blocked by two adjacent walls/boxes)
    if ((map[i][j - 1] == '#' || map[i][j - 1] == 'X') &&
            (map[i - 1][j] == '#' || map[i - 1][j] == 'X'))
        return 1;
    if ((map[i][j - 1] == '#' || map[i][j - 1] == 'X') &&
        (map[i + 1][j] == '#' || map[i + 1][j] == 'X'))
        return 1;
    if ((map[i][j + 1] == '#' || map[i][j + 1] == 'X') &&
        (map[i - 1][j] == '#' || map[i - 1][j] == 'X'))
        return 1;
    if ((map[i][j + 1] == '#' || map[i][j + 1] == 'X') &&
        (map[i + 1][j] == '#' || map[i + 1][j] == 'X'))
        return 1;

    return 0;
}





static int end_defeat(char **map, int i, int *nb_x_stuck)
{
    for (int j = 0; map[i][j] != '\n' && map[i][j] != '\0'; j = j + 1) {
        if (map[i][j] == 'X' && check_stuck(map, i, j) == 1)
            (*nb_x_stuck)++;
    }
    return 0;
}

int check_end_defeat(char *buffer, char **map)
{
    int nb_rows = get_nb_rows(buffer);
    int nb_x = get_nb_x(map, nb_rows);
    int nb_x_stuck = 0;

    for (int i = 0; i != nb_rows; i = i + 1) {
        end_defeat(map, i, &nb_x_stuck);
    }
    if (nb_x_stuck >= nb_x && nb_x > 0) {
        usleep(500000);
        return 1;
    }
    return 0;
}
