//Class defining the map
#include "thing.h"
#include <vector>
#include <iostream>


using std::cout;
using std::endl;
using std::vector;
class Map{



public:
	Map(){
		cout << "Map created" << endl;
	}
	
protected:
	
};

int main(int argc, char *argv[]){
		cout << "doot" << endl;
		vector<Thing> map[10][10];
		for(int i = 0; i<10; i++){
			for(int j = 0; j<10; j++){
				Thing t(j);
				map[j][i].push_back(t);
			}
		}
		for(int x = 0; x<10; x++){
			for(int y = 0; y<10; y++){
				cout << map[y][x].back().getThing();
			}
			cout << endl;
		}
		
		return 0;
}