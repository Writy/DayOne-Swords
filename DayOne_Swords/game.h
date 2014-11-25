#pragma once
#include "arena.h"

enum actions{
	DOWN_LEFT = 1,
	DOWN,
	DOWN_RIGHT,
	LEFT,
	WAIT,
	RIGHT,
	UP_LEFT,
	UP,
	UP_RIGHT
};

class game
{
public:
	game();
	void interpret(actions);
	arena arena;
	void setMapFont(std::string);
	void setLogFont(std::string);
	bool end;
	sf::Text endText;
	sf::Font mapFont;
	sf::Font logFont;
	fighter player;
	journal battle_log;
	~game();
private:
	void checkmove(int,int);
	void checkstate();
	fighter opponent = fighter("G", position(rand() % 10, rand() % 10));
};

