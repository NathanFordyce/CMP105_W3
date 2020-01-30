#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	circ1.setRadius(20);
	circ1.setOrigin(20,20);
	circ1.setPosition(300, 300);
	circ1.setFillColor(sf::Color::Green);
	circ1.setOutlineColor(sf::Color::White);
	circ1.setOutlineThickness(2.f);

	speed = 200.f;
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Right))
	{
		input->setKeyUp(sf::Keyboard::Right);
		direction = 0;
	}
	else if (input->isKeyDown(sf::Keyboard::Left))
	{
		input->setKeyUp(sf::Keyboard::Left);
		direction = 1;
	}
	else if (input->isKeyDown(sf::Keyboard::Up))
	{
		input->setKeyUp(sf::Keyboard::Up);
		direction = 2;
	}
	else if (input->isKeyDown(sf::Keyboard::Down))
	{
		input->setKeyUp(sf::Keyboard::Down);
		direction = 3;
	}
}

// Update game objects
void Level::update(float dt)
{
	distance = speed * dt;


	if (direction == 0 || direction == 1)
	{
		if ((direction == 0) && (coord.x < window->getSize().x - 20))
		{
			coord.x += distance;
		}
		else if ((direction == 0) && (coord.x > window->getSize().x - 20))
		{
			direction = 1;
		}
		else if ((direction == 1) && (coord.x < 20))
		{
			direction = 0;
		}
		else
		{
			coord.x -= distance;
		}

		if (counter == 1)
		{
			circ1.setPosition(coord.x, coord.y);
		}
		else
		{
			counter++;
		}
	}

	if (direction == 2 || direction == 3)
	{
		if ((direction == 2) && (coord.y > window->getSize().y - 20))
		{
			coord.y += distance;
		}
		else if ((direction == 2) && (coord.y < window->getSize().y - 20))
		{
			direction = 3;
		}
		else if ((direction == 3) && (coord.y < 20))
		{
			direction = 2;
		}
		else
		{
			coord.y -= distance;
		}

		circ1.setPosition(coord.x, coord.y);
	}
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(circ1);

	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}