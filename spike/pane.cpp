#include <ncurses.h>
#include <panel.h>
void printShitOnPanels(PANEL *my_panels[]);

static int mlines,lines, cols;
int main(){
	WINDOW *my_wins[3];
	PANEL  *my_panels[3];
	//Dimensions of main window
	int mlines = 20, mcols = 70;
	int lines = 10, cols = 15, i;

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
	
	my_wins[0] = newwin(mlines, mcols, 0,0);
	my_wins[1] = newwin(lines, cols, 0, mcols-cols);
	my_wins[2] = newwin(lines, cols, lines, mcols-cols);
	
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

	printShitOnPanels(my_panels);
	/* Update the stacking order. 2nd panel will be on top */
	update_panels();

	/* Show it on the screen */
	doupdate();
	
	getch();
	endwin();
}

void printShitOnPanels(PANEL *my_panels[]){
	const char *p, *pp, *ppp;
	p = (char*)"ONE";
	pp = (char*)"TWO";
	ppp = (char*)"THR";
	
	wattron(panel_window(my_panels[0]), COLOR_PAIR(1));
	int xmax, ymax;
	
	
	//wprintw(panel_window(my_panels[0]), p);
	getmaxyx(panel_window(my_panels[0]), ymax, xmax);
	mvwprintw(panel_window(my_panels[0]), ymax/2, xmax/2-cols, p);
	wattroff(panel_window(my_panels[0]), COLOR_PAIR(1));
	wattron(panel_window(my_panels[1]), COLOR_PAIR(2));
	//wprintw(panel_window(my_panels[1]), pp);
	getmaxyx(panel_window(my_panels[1]), ymax, xmax);
	mvwprintw(panel_window(my_panels[1]), (mlines-lines)+ymax/2, 4, pp);
	wattroff(panel_window(my_panels[1]), COLOR_PAIR(2));
	wattron(panel_window(my_panels[2]), COLOR_PAIR(3));
	//wprintw(panel_window(my_panels[2]), ppp);
	getmaxyx(panel_window(my_panels[2]), ymax, xmax);
	mvwprintw(panel_window(my_panels[2]), (mlines-lines)+ymax/2, 4, ppp);
	wattroff(panel_window(my_panels[2]), COLOR_PAIR(3));
}