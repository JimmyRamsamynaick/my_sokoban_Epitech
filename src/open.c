/*
** EPITECH PROJECT, 2024
** sokoban2
** File description:
** open.c
*/

#include "../my.h"
#include <ncurses.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

long file_size(char const *filepath)
{
    struct stat s;

    stat(filepath, &s);
    return (s.st_size);
}

char *open_or_read_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buffer;
    int size = file_size(filepath);
    ssize_t bytesRead;

    buffer = malloc(sizeof(char) * (size + 1));
    if (fd == -1) {
        my_printf("Error !\n");
        return NULL;
    }
    bytesRead = read(fd, buffer, size);
    if (bytesRead == -1) {
        close(fd);
        return NULL;
    }
    close(fd);
    buffer[bytesRead];
    return buffer;
}
