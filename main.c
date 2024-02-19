/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** main.c
*/

#include "my.h"
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

char **create_map(char *buffer)
{
    int rows = get_nb_rows(buffer);
    int cols = get_nb_cols(buffer);
    char **map;

    map = malloc_2d_arrays(rows, cols);
    fill_tab(map, buffer, rows);
    return map;
}

int end_case(char *buffer, char **map, char **saved_map)
{
    int end = -1;
    int nb_rows = get_nb_rows(buffer);

    end = my_screen(buffer, map, saved_map, nb_rows);
    return end;
}

int main(int argc, char **argv)
{
    char *buffer;
    char **map;
    char **saved_map;
    int end = 0;
    int input;

    if (argc == 2 && my_strcmp(argv[1], "-h") == 0)
        description();
    else if (error_management(argc, argv) == 84) {
        return 84;
    } else {
        buffer = open_or_read_file(argv[1]);
        map = create_map(buffer);
        saved_map = create_map(buffer);
        end = end_case(buffer, map, saved_map);
        free(buffer);
        free(map);
        free(saved_map);
        return end;
    }
}
