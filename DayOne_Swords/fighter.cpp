#include "globals.h"
#include "game.h"
#include "fighter.h"

position& operator += (position& left, const position& right){
	left.first += right.first;
	left.second += right.second;
	return left;
}

position operator + (const position& left, const position& right){
	return position(left.first + right.first, left.second + right.second);
}

position operator - (const position& left, const position& right){
	return position(left.first - right.first, left.second - right.second);
}

bool operator >= (const position& left, const position& right)
{
	return (left.first >= right.first && left.second >= right.second);
}

bool operator <= (const position& left, const position& right){
	return (left.first <= right.first && left.second <= right.second);
}

position operator * (const position& left, const position& right){
	position p = right - left;
	p.first = (p.first != 0) ? p.first / abs(p.first) : 0;
	p.second = (p.second != 0) ? p.second / abs(p.second) : 0;
	return p;
}

fighter::fighter()
{
}

fighter::fighter(std::string s, position p)
{
	this->setCharacter(s);
	this->setPosition(p);
}

void fighter::move(int x, int y)
{
	this->pos += position(x, y);
}

void fighter::move(position p)
{
	this->pos += p;
}

bool fighter::attack(fighter& f)
{
	int damages = 0;
	if (rand() % 2)
	{
		damages = rand() % 3 + 1;
		f.getBeaten(damages);
	}
	return (damages > 0);
}

void fighter::getBeaten(int d)
{
	hp -= d;
	if (hp < 0){ hp = 0; }
}

void fighter::setCharacter(std::string s)
{
	this->character = s;
}

void fighter::setPosition(position p)
{
	this->pos = p;
}

std::string fighter::getCharacter()
{
	return this->character;
}

position fighter::getPosition()
{
	return this->pos;
}

sf::Color fighter::getColor()
{
	return sf::Color(250, 25 * this->hp, 25 * this->hp, 255);
}

bool fighter::isAlive()
{
	return (hp > 0);
}

void fighter::seekPlayer()
{
	position direction = pos * GAME.player.getPosition();
	if (pos + direction == GAME.player.getPosition())
	{
		if (attack(GAME.player))
		{
			GAME.battle_log.append("Your opponent hits you.");
		}
		else
		{
			GAME.battle_log.append("Your opponent misses you.");
		}
	}
	else
	{
		move(direction);
	}
}

fighter::~fighter()
{
}
