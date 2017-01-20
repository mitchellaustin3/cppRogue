//Generic class for "Actors", anything that acts or moves
#include "actor.h"

Actor::Actor(){
	//Constructor
}
int Actor::currHP(){
	return hp;
}
int Actor::maxHP(){
	return maxhp;
}
bool Actor::isHostile(){
	return hostile;
}
int Actor::getAtt(){
	return att;
}

//Add logic to generate corpses eventually
void Actor::kill(std::vector<Thing *> map[10][10]){
	if(this->gety() == 0 || this->getx() == 0){
		delete this;
	}
	else{
		map[this->getx()][this->getx()].pop_back();
		delete this;
	}
}
