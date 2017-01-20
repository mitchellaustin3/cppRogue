#ifndef THING_H
#define THING_H

class Thing{
	public:
		Thing(char y, int col, bool p);
		Thing(char y, int col);
		Thing();
		char getChar();
		int getColor();
		bool isPassable();
		int getx();
		int gety();
		void setx(int newx);
		void sety(int newy);
	protected:
		char c;
		int color;
		bool passable;
		int x, y;
};

#endif