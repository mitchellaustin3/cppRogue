#ifndef SCREEN_H
#define SCREEN_H

#include <ncurses.h>
#include <string>

class ScreenDriver{
	public:
		ScreenDriver();
		void clearScreen();
		void printChar(int x, int y, char c, int color);
		void cleanUp();
		void debugPrint(std::string s);
		void clearDebug();
};
#endif