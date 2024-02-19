/*
** EPITECH PROJECT, 2024
** sokoban2
** File description:
** manage_errors.c
*/

#include "../my.h"
#include <ncurses.h>
#include <errno.h>
#include <fcntl.h>

int arguments_error(int argc)
{
    if (argc != 2) {
        my_printf("Error: arguments are missing ! \n");
        return 84;
    }
    return 0;
}

int file_error(char const *filepath)
{
    if (open(filepath, O_RDONLY) == -1) {
        if (errno == ENOENT) {
            my_printf("Error: no such file or direcotry !\n");
            return 84;
        }
    }
    return 0;
}

int open_or_read_or_close_error(char const *filepath)
{
    if (open_or_read_file(filepath) == NULL)
        return 84;
    return 0;
}

int invalid_map_error(char const *filepath)
{
    char *buffer;
    int p = 0;

    buffer = open_or_read_file(filepath);
    for (int i = 0; buffer[i] != '\0'; i = i + 1) {
        if (buffer[i] != ' ' && buffer[i] != '\n' && buffer[i] != '#' &&
        buffer[i] != 'X' && buffer[i] != 'P' && buffer[i] != 'O') {
            my_printf("Error: invalid map\n");
            return 84;
        }
        if (buffer[i] == 'P') {
                p = 1;
        }
    }
    if (p == 0) {
        my_printf("Error : the P is missing");
        return 84;
    }
    return 0;
}

int error_management(int argc, char **argv)
{
    if (arguments_error(argc) == -1)
        return 84;
    if (file_error(argv[1]) == -1)
        return 84;
    if (open_or_read_or_close_error(argv[1]) == -1)
        return 84;
    if (invalid_map_error(argv[1]) == -1)
        return 84;
    return 0;
}
