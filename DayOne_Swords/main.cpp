#ifdef SFML_STATIC
#pragma comment(lib, "glew.lib")
#pragma comment(lib, "freetype.lib")
#pragma comment(lib, "jpeg.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "gdi32.lib")  
#endif // SFML_STATIC

#include "globals.h"
#include "game.h"

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(800, 256), "Day One", sf::Style::Default, settings);

	GAME.setMapFont("fonts/cootue.ttf");
	GAME.setLogFont("fonts/mono.ttf");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4))
				{
					GAME.interpret(actions::LEFT);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Z) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8))
				{
					GAME.interpret(actions::UP);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6))
				{
					GAME.interpret(actions::RIGHT);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2))
				{
					GAME.interpret(actions::DOWN);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1))
				{
					GAME.interpret(actions::DOWN_LEFT);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3))
				{
					GAME.interpret(actions::DOWN_RIGHT);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad7))
				{
					GAME.interpret(actions::UP_LEFT);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad9))
				{
					GAME.interpret(actions::UP_RIGHT);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad5))
				{
					GAME.interpret(actions::WAIT);
				}
			}
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear();
		if (GAME.end)
		{
			window.draw(GAME.endText);
		}
		else
		{
			for (display::iterator it = GAME.arena.arena_display.begin(); it != GAME.arena.arena_display.end(); ++it){
				window.draw(it->second);
			}
			window.draw(GAME.battle_log.display);
		}
		window.display();
	}

	return 0;
}