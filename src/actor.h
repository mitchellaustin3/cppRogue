//Include Guard
#ifndef ACTOR_H
#define ACTOR_H

//Forward Declarations
//class Map;

//Dependencies
#include <vector>

class Actor : public Thing{
	public:
		Actor();
		int currHP();
		int maxHP();
		bool isHostile();
		int getAtt();
		void kill(std::vector<Thing *> map[10][10]);
	protected:
		int maxhp, hp, att;
		bool hostile;
};
#endif