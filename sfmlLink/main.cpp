#include "stdafx.h"
#include "Game.h"
#include "Player.h"

int main()
{
	RenderWindow gameWindow(VideoMode(1920,1080), "Game Window", Style::Close | Style::Resize);
	

	Texture defaultTexture;
	defaultTexture.loadFromFile("playerTexture/Idle.png");
	
	player p1(&defaultTexture, Vector2u(6, 2), 0.1f, 400.0f);

	float deltaTime = 0.0f;
	Clock deltaClock;

	while (gameWindow.isOpen())
	{
		deltaTime = deltaClock.restart().asSeconds();


		Event gameEvent;

		while (gameWindow.pollEvent(gameEvent))
		{
			switch (gameEvent.type)
			{
			case Event::Closed:
				gameWindow.close();
				break;
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			gameWindow.close();
			break;
		}


		p1.update(deltaTime);
	

		gameWindow.clear(Color::Black);

		p1.draw(gameWindow);

		gameWindow.display();

	}

	int a = 10;
	
	return 0;
}