#include "thing.h"
Thing::Thing(char y, int col, bool p){
	c = y;
	color = col;
	passable = p;
}
Thing::Thing(char y, int col){
	c = y;
	color = col;
	passable = true;
}
Thing::Thing(){
	c = '?';
	color = 1;
	passable = true;
}
char Thing::getChar(){
	return c;
}
int Thing::getColor(){
	return color;
}
bool Thing::isPassable(){
	return passable;
}
int Thing::gety(){
	return y;
}
int Thing::getx(){
	return x;
}
void Thing::sety(int newy){
	y = newy;
}
void Thing::setx(int newx){
	x = newx;
}