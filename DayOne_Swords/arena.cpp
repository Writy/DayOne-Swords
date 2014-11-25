#include "globals.h"
#include "game.h"
#include "arena.h"

arena::arena()
{
	for (int i = 0; i < 16; i++){
		for (int j = 0; j < 16; j++){
			this->arena_display[position(i, j)] = sf::Text("", GAME.mapFont, 16);
			this->arena_display[position(i, j)].setPosition(i * 16, j * 16);
		}
	}
}

void arena::clear()
{
	for (display::iterator it = this->arena_display.begin(); it != this->arena_display.end(); ++it){
		it->second.setString(".");
		it->second.setColor(sf::Color::White);
	}
}

void arena::placeFighter(fighter f)
{
	this->arena_display[f.getPosition()].setString(f.getCharacter());
	this->arena_display[f.getPosition()].setColor(f.getColor());
}

arena::~arena()
{
}
