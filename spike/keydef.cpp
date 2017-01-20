#include <ncurses.h>

int main(void) {

    int key = 0;

    initscr();
    noecho();
    keypad(stdscr, TRUE);
	
	
	//UP 259, 56
	//DOWN 258, 50
	//LEFT 260, 52
	//RIGHT 261, 54
	//UPLEFT 55
	//UPRIGHT 57
	//DOWNLEFT 49
	//DOWNRIGHT 51
	
	

    do {

        key = getch();
        clear();
        mvprintw(0, 0, "Key = %d\n", key);
		mvprintw(1, 0, "Key = %d\n", key);
        refresh();

    } while (key != 27); 

    clear();
    refresh();
    endwin();
    return 0;

}
