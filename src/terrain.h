#ifndef TERRAIN_H
#define TERRAIN_H

class Thing;
class Terrain : public Thing{
	public:
		Terrain();
		Terrain(char c, int col);
		Terrain(char c, int col, bool p);
};

class Wall : public Terrain{
	public:
		Wall();
};
class Grass : public Terrain{
	public:
		Grass();
};

#endif