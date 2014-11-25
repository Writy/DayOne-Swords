#include "globals.h"
#include "game.h"
#include "journal.h"


journal::journal()
{
	display.setFont(GAME.logFont);
}

std::string& journal::treatString(std::string& s)
{
	s.append("\n");
	return s;
}
void journal::append(std::string s)
{
	display.setCharacterSize(16);
	display.setColor(sf::Color::White);
	display.setString(display.getString() + treatString(s));
	display.setPosition(300,-(display.getLocalBounds().height - 250));
}

journal::~journal()
{
}
