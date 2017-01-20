//Include Guard
#ifndef MAP_H
#define MAP_H


//Dependencies
#include <vector>
#include <iostream>
#include <string>
#include "terrain.h"
#include "screendriver.h"
#include "thing.h"

class Map{
	public:
		Map();
		bool move(Thing* t, std::string d);
		std::vector<Thing*>* getMap();
		void changeTerrain(int x, int y, Thing* c);
		void addThing(int x, int y, Thing* t);
		bool removeThing(int x, int y);
		bool removeThing(int x, int y, int z);
		void printScreen(ScreenDriver sd);
	protected:
		std::vector<Thing *> map[10][10];
};

#endif