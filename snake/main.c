#include <ncurses.h>
#include <stdio.h>
#include <unistd.h>

#include "snake.h"


int put_ret_error(char *error_msg)
{
    dprintf(2, "error: %s\n", error_msg);
    return 84;
}

void init_ncurses()
{
    initscr();
    keypad(stdscr, TRUE);
    noecho();
}

int main()
{
    snake_s *s = create_snake();

    // init_ncurses();
    if (s == NULL)
        return put_ret_error("invalid snake alloc");
    dump_snake(s);
    for (int i = 0; i < 1; i++) {
        usleep(100000);
        update_snake(s);
        dump_snake(s);
        //clear();
        //mvprintw(0, i, "8===D");
        //refresh();
    }
    destroy_snake(s);
    //refresh();
    //endwin();
    return 0;
}
