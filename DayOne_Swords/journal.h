#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "globals.h"

class journal
{
public:
	sf::Text display;
	void append(std::string);
	journal();
	~journal();
private:
	std::string& treatString(std::string&);
};

