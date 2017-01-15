#include <stdlib.h>
#include <ctype.h>
#include <ncurses.h>
//#include <stack>
#include <array>

static int playerx;
static int playery;
//static stack<object> map [100][100];
char * intprtkey(int ch);
int playermove();
void writeChar(int y, int x, char c, int color);

int main(void) {
	char playerSymbol = '@';
    WINDOW* mainwin;
    int ch;
	int height,width;
	playerx = 5;
	playery = 5;

    /*  Initialize ncurses  */
    if ( (mainwin = initscr()) == NULL ) {
		fprintf(stderr, "Error initializing ncurses.\n");
		exit(EXIT_FAILURE);
    }

    noecho();                  /*  Turn off key echoing                 */
    keypad(mainwin, TRUE);     /*  Enable the keypad for non-char keys  */
	
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
	wresize(mainwin,100,100);
	attron(COLOR_PAIR(2));
    hline('-', 12);
	mvhline(11,0,'-', 12);
	mvvline(1,0,'|', 10);
	mvvline(1,11,'|', 10);
	attroff(COLOR_PAIR(2));
	attron(COLOR_PAIR(7));
	for(int i = 1; i<11; i++){
		for(int j = 1; j<11; j++){
			mvaddch(i, j, '#');
		}
	}
	attroff(COLOR_PAIR(7));
	attron(COLOR_PAIR(1));
	mvaddch(playery,playerx, '@');
	attroff(COLOR_PAIR(1));
    refresh();
	int c;
	while(1){
		c = playermove();
		if(c == 2)
			break;
		if(c==0){
			move(12,0);
			clrtobot();
			mvprintw(12,0, "BUMP");
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
    delwin(mainwin);
    endwin();
    refresh();
    return EXIT_SUCCESS;
}

//Function to write char to certain coords, + color
void writeChar(int y, int x, char c, int color){
	attron(COLOR_PAIR(color));
	mvaddch(y,x,c);
	attroff(COLOR_PAIR(color));
	refresh();
}

// Function to move player symbol 1 space
int playermove(){
	int direction = getch();
	move(12,0);
	clrtobot();
	mvprintw(12,0, "(MOVE)You pressed: 0x%x (%s)", direction, intprtkey(direction));
	mvprintw(13,0, "%d", direction);
	mvprintw(14,0, "Playerx: %d    Playery: %d", playerx, playery);
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
