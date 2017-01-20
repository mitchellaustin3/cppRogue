//Game driver class

//#include "thing.cpp"
//#include "terrain.cpp"
//#include "screendriver.cpp"
#include "map.h"

#include <string>
static ScreenDriver sd;
static Map m;
static int playerx, playery;
static Thing player;
void getInput();




//Function to loop and handle input characters
//Breaks on 'q'
//No actual game logic in here, just passing input to appropriate functions

void getInput(){
	
	//Int codes for inputs in ncurses (multiple values for numpad + regular keys)
	//UP 259, 56
	//DOWN 258, 50
	//LEFT 260, 52
	//RIGHT 261, 54
	//UPLEFT 55
	//UPRIGHT 57
	//DOWNLEFT 49
	//DOWNRIGHT 51
	//Numpad 5 53
	//q 113
	
	int c;
	c = getch();
	while(c != 113){
		switch(c){
			case 'A':
			case 56:
				m.move(&player, "up");
				break;
			case 'B':
			case 50:
				m.move(&player, "down");
				break;
			case 'C':
			case 54:
				m.move(&player, "right");
				break;
			case 'D':
			case 52:
				m.move(&player, "left");
				break;
			case 55:
				m.move(&player, "upleft");
				break;
			case 57:
				m.move(&player, "upright");
				break;
			case 49:
				m.move(&player, "downleft");
				break;
			case 51:
				m.move(&player, "downright");
				break;
			case 53:
				sd.debugPrint("WAIT");
				break;
			case '\033':		//Garbage characters when entering arrow keys, ignore
			case '[': 
				break;
			default:
				std::string s = "UNRECOGNIZED INPUT: ";
				s+=c;
				if(c == KEY_ENTER || c == '\n' || c == '\r')
					s = "Enter";
				sd.debugPrint(s);
				break;
		}
		m.printScreen(sd);
		c = getch();
		sd.clearDebug();
	}
	return;
}

int main(){
	
	player = Thing( '@', 2);
	playery = 5;
	playerx = 5;
	m.addThing(playerx,playery, &player);
	m.printScreen(sd);
	getInput();
	sd.cleanUp();
	
	return 0;
}