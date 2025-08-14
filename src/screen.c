/*
** EPITECH PROJECT, 2024
** sokoban2
** File description:
** screen.c
*/

#include "../my.h"
#include <ncurses.h>
#include <unistd.h>

void init_screen(void)
{
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
}

void close_screen(char *buffer, char **map)
{
    refresh();
    endwin();
}

int quit_game(int input)
{
    return (input == 'q' || input == 'Q');
}

static int proce_game(char *buffer, char **map, char **saved_map, int nb_rows)
{
    int input = getch();

    if (quit_game(input))
        return 2;
    deplacement(input, map, nb_rows, saved_map);
    if (input == 32)
        reset_game(map, saved_map, nb_rows);
    return end_management(buffer, map, saved_map, nb_rows);
}

int my_screen(char *buffer, char **map, char **saved_map, int nb_rows)
{
    int end_game = -1;

    init_screen();
    while (1) {
        clear();
        display(map, buffer);
        refresh();
        end_game = proce_game(buffer, map, saved_map, nb_rows);
        if (end_game == 1 || end_game == 0 || end_game == 2) {
            clear();
            if (end_game == 1) {
                mvprintw(LINES / 2, COLS / 2 - 4, "GAME OVER");
                refresh();
                usleep(2000000);
            }
            if (end_game == 0) {
                mvprintw(LINES / 2, COLS / 2 - 3, "YOU WIN");
                refresh();
                usleep(2000000);
            }
            break;
        }
    }
    close_screen(buffer, map);
    return (end_game);
}
