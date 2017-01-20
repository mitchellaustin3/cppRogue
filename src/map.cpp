//Class defining the map
#include "map.h"



Map::Map(){

	for(int i = 0; i<10; i++){
		for(int j = 0; j<10; j++){
			if(j == 0 || j == 9)
				map[j][i].push_back(new Wall);
			else if(i == 0 || i == 9)
				map[j][i].push_back(new Wall);
			else
				map[j][i].push_back(new Grass);
		}
	}
}
//Pass a pointer to a thing, and string with direction ("up" or "downleft", etc)
//X and Y of thing are set when added to map
//Will return false w/ no change if Thing is not on map
//Will return false if trying to move into non-passable tile
bool Map::move(Thing* t, std::string d){
	int x = t->getx();
	int y = t->gety();
	if(y == 0 || x == 0)
		return false;
	if(d == "up"){
		if(map[x][y-1].back()->isPassable()){
			map[x][y-1].push_back(t);
			map[x][y].pop_back();
			t->sety(y-1);
			return true;
		}
		else
			return false; //Tried to move into something not passable (TODO: Handle running into actors)
	}
	else if( d == "down"){
		if(map[x][y+1].back()->isPassable()){
			map[x][y+1].push_back(t);
			map[x][y].pop_back();
			t->sety(y+1);
			return true;
		}
		else
			return false;
	}
	else if( d == "left"){
		if(map[x-1][y].back()->isPassable()){
			map[x-1][y].push_back(t);
			map[x][y].pop_back();
			t->setx(x-1);
			return true;
		}
		else
			return false;
	}
	else if( d == "right"){
		if(map[x+1][y].back()->isPassable()){
			map[x+1][y].push_back(t);
			map[x][y].pop_back();
			t->setx(x+1);
			return true;
		}
		else
			return false;
	}
	else if(d == "upleft"){
		if(map[x-1][y-1].back()->isPassable()){
			map[x-1][y-1].push_back(t);
			map[x][y].pop_back();
			t->setx(x-1);
			t->sety(y-1);
			return true;
		}
		else
			return false;
	}
	else if (d == "upright"){
	if(map[x+1][y-1].back()->isPassable()){
			map[x+1][y-1].push_back(t);
			map[x][y].pop_back();
			t->setx(x+1);
			t->sety(y-1);
			return true;
		}
		else
			return false;
	}
	else if (d == "downleft"){
	if(map[x-1][y+1].back()->isPassable()){
			map[x-1][y+1].push_back(t);
			map[x][y].pop_back();
			t->setx(x-1);
			t->sety(y+1);
			return true;
		}
		else
			return false;
	}
	else if( d == "downright"){
	if(map[x+1][y+1].back()->isPassable()){
			map[x+1][y+1].push_back(t);
			map[x][y].pop_back();
			t->setx(x+1);
			t->sety(y+1);
			return true;
		}
		else
			return false;
	}
	else
		return false;
}
std::vector<Thing*>* Map::getMap(){
	return *map;
}
void Map::changeTerrain(int x, int y, Thing* c){
	map[x][y].front() = c;
}
void Map::addThing(int x, int y, Thing* t){
	t->setx(x);
	t->sety(y);
	map[x][y].push_back(t);
}
bool Map::removeThing(int x, int y){
	if(map[x][y].size() > 1){
		map[x][y].pop_back();
		return true;
	}
	return false;
}
bool Map::removeThing(int x, int y, int z){
	if(map[x][y].size() > 2){
		map[x][y].erase(map[x][y].begin()+z);
		return true;
	}
	return false;
}
void Map::printScreen(ScreenDriver sd){
	for(int i = 0; i<10; i++){
		for(int j=0; j<10; j++){
			sd.printChar(i,j,map[i][j].back()->getChar(),map[i][j].back()->getColor());
		}
	}
}
