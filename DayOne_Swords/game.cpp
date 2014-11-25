#include "game.h"


game::game()
{
}

void game::interpret(actions a)
{
	if (end)
	{
		return;
	}
	switch (a)
	{
	case DOWN_LEFT:
		checkmove(-1,1);
		break;
	case DOWN:
		checkmove(0, 1);
		break;
	case DOWN_RIGHT:
		checkmove(1, 1);
		break;
	case LEFT:
		checkmove(-1, 0);
		break;
	case WAIT:
		opponent.seekPlayer();
		break;
	case RIGHT:
		checkmove(1, 0);
		break;
	case UP_LEFT:
		checkmove(-1, -1);
		break;
	case UP:
		checkmove(0, -1);
		break;
	case UP_RIGHT:
		checkmove(1, -1);
		break;
	}
	arena.clear();
	arena.placeFighter(player);
	arena.placeFighter(opponent);
	checkstate();
}

void game::checkmove(int x, int y)
{
	position p = player.getPosition() + position(x,y);
	if (p == opponent.getPosition())
	{
		if (player.attack(opponent))
		{
			battle_log.append("You hit your opponent.");
		}
		else
		{
			battle_log.append("You miss your opponent.");
		}
		opponent.seekPlayer();
	}
	else if (p >= position(0, 0) && p <= position(15, 15))
	{
		player.move(x, y);
		opponent.seekPlayer();
	}
}

void game::checkstate()
{
	if (player.isAlive() && opponent.isAlive())
	{
		return;
	}
	else if (!player.isAlive())
	{
		endText.setString("DEFEAT!");
		endText.setOrigin(28, 8);
		endText.setColor(sf::Color::Red);
		end = true;
	}
	else
	{
		endText.setString("VICTORY!");
		endText.setOrigin(32, 8);
		endText.setColor(sf::Color::Green);
		end = true;
	}
}

void game::setMapFont(std::string s)
{
	mapFont.loadFromFile(s);
	arena.clear();
	arena.placeFighter(player);
	arena.placeFighter(opponent);
}

void game::setLogFont(std::string s)
{
	logFont.loadFromFile(s);
	battle_log.append("You enter the arena.");
	endText.setFont(logFont);
	endText.setCharacterSize(16);
	endText.setPosition(400, 128);
}

game::~game()
{
}
