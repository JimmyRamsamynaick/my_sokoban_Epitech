/*
** EPITECH PROJECT, 2024
** sokoban2
** File description:
** descriptions.c
*/

#include "../my.h"
#include <ncurses.h>

void description(void)
{
    my_printf("HOW TO USE:\n");
    my_printf("    ./my_sokoban + map\n");
    my_printf("DESCRIPTION :\n");
    my_printf("    map file representing a map,\n");
    my_printf("who containing '#' for walls,\n");
    my_printf("    the 'P' is the player, 'X' is the boxes and\n");
    my_printf("'O' is the storage locations.\n");
}
