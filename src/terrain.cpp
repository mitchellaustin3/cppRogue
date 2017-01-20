#include "terrain.h"

//Generic class for terrain
//This should never appear in game
Terrain::Terrain() : Thing('?',7, true){}
Terrain::Terrain(char c, int col) : Thing(c,col, true){}
Terrain::Terrain(char c, int col, bool p) : Thing(c,col, p){}

//Standard Wall
Wall::Wall() : Terrain('#',7, false){}

//Grass
Grass::Grass() : Terrain('.',2, true){}

