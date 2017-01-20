#include <panel.h>

int main()
{	WINDOW *my_wins[3];
	PANEL  *my_panels[3];
	int lines = 10, cols = 40, y = 2, x = 4, i;

	initscr();
	cbreak();
	noecho();
	
	if (has_colors())
    {
        start_color();

        /*
         * Simple color assignment, often all we need.  Color pair 0 cannot
         * be redefined.  This example uses the same value for the color
         * pair as for the foreground color, though of course that is not
         * necessary:
         */
        init_pair(1, COLOR_RED,     COLOR_BLACK);
        init_pair(2, COLOR_GREEN,   COLOR_BLACK);
        init_pair(3, COLOR_YELLOW,  COLOR_BLACK);
        init_pair(4, COLOR_BLUE,    COLOR_BLACK);
        init_pair(5, COLOR_CYAN,    COLOR_BLACK);
        init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
        init_pair(7, COLOR_WHITE,   COLOR_BLACK);
    }

	/* Create windows for the panels */
	my_wins[0] = newwin(lines, cols, y, x);
	my_wins[1] = newwin(lines, cols, y + 1, x + 5);
	my_wins[2] = newwin(lines, cols, y + 2, x + 10);

	/* 
	 * Create borders around the windows so that you can see the effect
	 * of panels
	 */
	for(i = 0; i < 3; ++i)
		box(my_wins[i], 0, 0);

	/* Attach a panel to each window */ 	/* Order is bottom up */
	my_panels[0] = new_panel(my_wins[0]); 	/* Push 0, order: stdscr-0 */
	my_panels[1] = new_panel(my_wins[1]); 	/* Push 1, order: stdscr-0-1 */
	my_panels[2] = new_panel(my_wins[2]); 	/* Push 2, order: stdscr-0-1-2 */
	const char *p, *pp, *ppp;
	p = (char*)"ONEONEONE";
	pp = (char*)"TWOTWOTWO";
	ppp = (char*)"THREETHREETHREE";
	
	wattron(panel_window(my_panels[0]), COLOR_PAIR(1));
	wprintw(panel_window(my_panels[0]), p);
	wattroff(panel_window(my_panels[0]), COLOR_PAIR(1));
	wattron(panel_window(my_panels[1]), COLOR_PAIR(2));
	wprintw(panel_window(my_panels[1]), pp);
	wattroff(panel_window(my_panels[1]), COLOR_PAIR(2));
	wattron(panel_window(my_panels[2]), COLOR_PAIR(3));
	wprintw(panel_window(my_panels[2]), ppp);
	wattroff(panel_window(my_panels[2]), COLOR_PAIR(3));

	/* Update the stacking order. 2nd panel will be on top */
	update_panels();

	/* Show it on the screen */
	doupdate();
	
	getch();
	endwin();
}