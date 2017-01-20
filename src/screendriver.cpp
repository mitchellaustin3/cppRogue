//Class for controlling screen (via ncurses)
#include "screendriver.h"

ScreenDriver::ScreenDriver(){
	mainwin = initscr();			/* Start curses mode 		  */	
	if (has_colors()){
		start_color();
		init_pair(1, COLOR_RED,     COLOR_BLACK);
		init_pair(2, COLOR_GREEN,   COLOR_BLACK);
		init_pair(3, COLOR_YELLOW,  COLOR_BLACK);
		init_pair(4, COLOR_BLUE,    COLOR_BLACK);
		init_pair(5, COLOR_CYAN,    COLOR_BLACK);
		init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
		init_pair(7, COLOR_WHITE,   COLOR_BLACK);
	}		
	refresh();	
}
void ScreenDriver::clearScreen(){
	wclear(mainwin);
}
void ScreenDriver::printChar(int x, int y, char c, int color){
	attrset(COLOR_PAIR(color));
	mvaddch(y,x,c);
	standout();
	refresh();
}
	
void ScreenDriver::cleanUp(){
	endwin();
}
	
void ScreenDriver::debugPrint(std::string s){
	const char* c = s.c_str();
	wmove(mainwin, 10,0);
	wclrtoeol(mainwin);
	mvwaddstr(mainwin, 10, 0, c);
	wrefresh(mainwin);
}
void ScreenDriver::clearDebug(){
	wmove(mainwin, 10,0);
	wclrtoeol(mainwin);
	wrefresh(mainwin);
}