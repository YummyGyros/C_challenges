#include <ncurses.h>

int main()
{
    initscr();
    WINDOW *win = newwin(15, 17, 2, 10);
    refresh();

    box(win, 0, 0);
    mvwprintw(win, 1, 1, "Hello,");
    mvwprintw(win, 2, 1, "World!");
    wrefresh(win);

    getch();
    endwin();
    return 0;
}
