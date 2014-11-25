#pragma once
#include "fighter.h"

typedef std::map<position, sf::Text> display;

class arena
{
public:
	display arena_display;

	arena();
	void clear();
	void placeFighter(fighter);
	~arena();
private:
};

