#include <ncurses.h>

#include <ncurses.h>

int main()
{
    int ch;

    initscr();			/* Start curses mode 		*/
    //raw();				/* Line buffering disabled	*/
    keypad(stdscr, TRUE);		/* We get F1, F2 etc..		*/
    noecho();			/* Don't echo() while we do getch */
    printw("Type any character to see it in bold\n");
    while ((ch = getch()) != 'q') {
        if(ch == KEY_F(1))
            printw("F1 Key pressed\n");
        else {
            printw("The pressed key is ");
            attron(A_BOLD);
            printw("%c\n", ch);
            attroff(A_BOLD);
        }
        refresh();			/* Print it on to the real screen */
    }
    endwin();
    return 0;
}
