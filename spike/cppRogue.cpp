#include <stdlib.h>
#include <ctype.h>
#include <ncurses.h>
//#include <stack>
#include <array>
#include <panel.h>
#include <cstring>

static int playerx;
static int playery;
static WINDOW *my_wins[3];
static PANEL *my_panels[3];
//static stack<object> map [100][100];
char * intprtkey(int ch);
int playermove();
void writeChar(int y, int x, char c, int color);
void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, int color);

int main() {
	WINDOW *my_wins[3];
	PANEL *my_panels[3];
	int lines = 20, cols = 40, w = 2, z = 4, u;
	char playerSymbol = '@';
    int ch;
	int height,width;
	playerx = 6;
	playery = 6;

    /*  Initialize ncurses  */
    initscr();
	noecho();
	curs_set(0);
	keypad(my_wins[0], TRUE);
	
	my_wins[0] = newwin(20, 40, 0,0);
	my_wins[1] = newwin(10,20,0,30);
	my_wins[2] = newwin(10,20,10,30);
	for(u = 0; u<3; u++)
		box(my_wins[u],0,0);

	my_panels[0] = new_panel(my_wins[0]);
	my_panels[1] = new_panel(my_wins[1]);
	my_panels[2] = new_panel(my_wins[2]);
	top_panel(my_panels[0]);
	top_panel(my_panels[1]);
	top_panel(my_panels[2]);
	update_panels();
	wnoutrefresh(my_wins[0]);
	doupdate();
	refresh();
	
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

    /*  Print a prompt and refresh() the screen  */
	//wresize(mainwin,100,100);
	wattroff(my_wins[0],COLOR_PAIR(2));
	wattron(my_wins[0],COLOR_PAIR(7));
	for(int i = 1; i<11; i++){
		for(int j = 1; j<11; j++){
			mvwaddch(my_wins[0],i, j, '#');
		}
	}
	wattroff(my_wins[0],COLOR_PAIR(7));
	wattron(my_wins[0],COLOR_PAIR(3));
	mvwaddch(my_wins[0],playery,playerx, '@');
	wattroff(my_wins[0],COLOR_PAIR(3));
    update_panels();
	wnoutrefresh(my_wins[0]);
	doupdate();
	int c;
	while(1){
		c = playermove();
		if(c == 2)
			break;
		if(c==0){
			wmove(my_wins[0],15,0);
			wclrtobot(my_wins[0]);
			mvwprintw(my_wins[0],12,0, "BUMP");
		}
	}
	
	/*
	while((ch = getch()) != 'q'){
		//if(ch == 0){
			move(playery,playerx);
			refresh();
		//}
		//else{
		//	mvprintw(12,0, "You pressed: 0x%x (%s)", ch, intprtkey(ch));
		//	refresh();
		//}
	}
	
    /*  Loop until user presses 'q'  */
	/*Old testing while loop
    while ( (ch = getch()) != 'q' ) {
		/*  Delete the old response line, and print a new one  
		deleteln();
		mvprintw(7, 10, "You pressed: 0x%x (%s)", ch, intprtkey(ch));
		refresh();
    }
	*/
	
    /*  Clean up after ourselves  */
    //delwin(my_wins[0]);
	//delwin(my_wins[1]);
	//delwin(my_wins[2]);
    endwin();
    refresh();
    return EXIT_SUCCESS;
}

//Function to write char to certain coords, + color
void writeChar(int y, int x, char c, int color){
	wattron(my_wins[0],COLOR_PAIR(color));
	mvwaddch(my_wins[0],y,x,c);
	wattroff(my_wins[0],COLOR_PAIR(color));
	update_panels();
	wnoutrefresh(my_wins[0]);
	doupdate();
}

// Function to move player symbol 1 space
int playermove(){
	int direction = getch();
	/*DEBUGGING STUFF
	wmove(my_wins[0],12,0);
	wclrtobot(my_wins[0]);
	mvwprintw(my_wins[0],12,0, "(MOVE)You pressed: 0x%x (%s)", direction, intprtkey(direction));
	mvwprintw(my_wins[0],13,0, "%d", direction);
	mvwprintw(my_wins[0],14,0, "Playerx: %d    Playery: %d", playerx, playery);
	*/
	/*
	switch(direction){
		case 'A':
			if(playery <= 1)
				return 0;
			else{
				writeChar(playery,playerx,'#', 7);
				playery--;
				writeChar(playery,playerx,'@', 1);
				return 1;
			}
		case 'B':
			if(playery >= 11)
				return 0;
			else{
				writeChar(playery,playerx,'#', 7);
				playery++;
				writeChar(playery,playerx,'@', 1);
				return 1;
			}
		case 'C':
			if(playerx >= 11)
				return 0;
			else{
				writeChar(playery,playerx,'#', 7);
				playery++;
				writeChar(playery,playerx,'@', 1);
				return 1;
			}
		case 'D':
			if(playerx <= 1)
				return 0;
			else{
				writeChar(playery,playerx,'#', 7);
				playerx--;
				writeChar(playery,playerx,'@', 1);
				return 1;
			}
		
		default:
			//THIS SHOULD NEVER HAPPEN
			return 0;
	}
	*/
	switch(direction){
		//Up
		case 259:
			if(playery <= 1)
				return 0;
			else{
				writeChar(playery,playerx,'#', 7);
				playery--;
				writeChar(playery,playerx,'@', 1);
				return 1;
			}
		//Down
		case 258:
			if(playery >= 10)
				return 0;
			else{
				writeChar(playery,playerx,'#', 7);
				playery++;
				writeChar(playery,playerx,'@', 1);
				return 1;
			}
		//Left
		case 260:
			if(playerx <= 1)
				return 0;
			else{
				writeChar(playery,playerx,'#', 7);
				playerx--;
				writeChar(playery,playerx,'@', 1);
				return 1;
			}
		//Right
		case 261:
			if(playerx >= 10)
				return 0;
			else{
				writeChar(playery,playerx,'#', 7);
				playerx++;
				writeChar(playery,playerx,'@', 1);
				return 1;
			}
		
		default:
			//THIS SHOULD NEVER HAPPEN
			return 0;
	}
}

/*  Struct to hold keycode/keyname information  */

struct keydesc {
    int  code;
    char name[20];
};


/*  Returns a string describing a character passed to it  */

char * intprtkey(int ch) {

    /*  Define a selection of keys we will handle  */

    static struct keydesc keys[] = { 
					 { KEY_UP,        "Up arrow"        },
				     { KEY_DOWN,      "Down arrow"      },
				     { KEY_LEFT,      "Left arrow"      },
				     { KEY_RIGHT,     "Right arrow"     },
				     { KEY_HOME,      "Home"            },
				     { KEY_END,       "End"             },
				     { KEY_BACKSPACE, "Backspace"       },
				     { KEY_IC,        "Insert"          },
				     { KEY_DC,        "Delete"          },
				     { KEY_NPAGE,     "Page down"       },
				     { KEY_PPAGE,     "Page up"         },
				     { KEY_F(1),      "Function key 1"  },
				     { KEY_F(2),      "Function key 2"  },
				     { KEY_F(3),      "Function key 3"  },
				     { KEY_F(4),      "Function key 4"  },
				     { KEY_F(5),      "Function key 5"  },
				     { KEY_F(6),      "Function key 6"  },
				     { KEY_F(7),      "Function key 7"  },
				     { KEY_F(8),      "Function key 8"  },
				     { KEY_F(9),      "Function key 9"  },
				     { KEY_F(10),     "Function key 10" },
				     { KEY_F(11),     "Function key 11" },
				     { KEY_F(12),     "Function key 12" },
				     { -1,            "<unsupported>"   }
    };
    static char keych[2] = {0};
    
    if ( isprint(ch) && !(ch & KEY_CODE_YES)) {

	/*  If a printable character  */

	keych[0] = ch;
	return keych;
    }
    else {

	/*  Non-printable, so loop through our array of structs  */

	int n = 0;
	
	do {
	    if ( keys[n].code == ch )
		return keys[n].name;
	    n++;
	} while ( keys[n].code != -1 );

	return keys[n].name;
    }    
    
    return NULL;        /*  We shouldn't get here  */
}
