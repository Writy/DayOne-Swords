#pragma once
#include "journal.h"

typedef std::pair<int, int> position;

position& operator += (position& left, const position& right);

position operator + (const position& left, const position& right);

position operator - (const position& left, const position& right);

bool operator >= (const position& left, const position& right);

bool operator <= (const position& left, const position& right);

position operator * (const position& left, const position& right);

class fighter
{
public:
	fighter();
	fighter(std::string,position);
	~fighter();
	void move(int, int);
	void move(position);
	void getBeaten(int);
	void setCharacter(std::string);
	void setPosition(position);
	std::string getCharacter();
	position getPosition();
	bool attack(fighter&);
	sf::Color getColor();
	bool isAlive();
	void seekPlayer();
private:
	position pos = position(12,12);
	std::string character = "@";
	int hp = 10;
};

