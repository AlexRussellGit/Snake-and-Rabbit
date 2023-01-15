#include "Snake.h"
#include "Animal.h"
#include "DEFENITIONS.h"

namespace SaR
{

	Snake::Snake(GameDataRef data) : _data(data)
	{

	}

	void Snake::Spawn()
	{
		snakeSprite.setTexture(_data->assets.GetTexture("Snake Head"));
		snakeSprite.setPosition((_data->window.getSize().x) / 2, (_data->window.getSize().y) / 2);
	}

	void Snake::SetDirection(sf::Keyboard* key)
	{
		if (key->isKeyPressed)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && (movebyX != 0 && movebyY != -1))
			{
				movebyX = 0;
				movebyY = 1;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && (movebyX != 0 && movebyY != 1))
			{
				movebyX = 0;
				movebyY = -1;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && (movebyX != 1 && movebyY != 0))
			{
				movebyX = -1;
				movebyY = 0;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && (movebyX != -1 && movebyY != 0))
			{
				movebyX = 1;
				movebyY = 0;
			}
		}
	}

	bool Snake::SustainAlive()
	{
		if (snakeSprite.getPosition().x >= 0 && snakeSprite.getPosition().x <= (_data->window.getSize().x - (snakeSprite.getGlobalBounds().width)) && snakeSprite.getPosition().y >= 0 && snakeSprite.getPosition().y <= (_data->window.getSize().y - (snakeSprite.getGlobalBounds().height)))
			return true;
		return false;
	}

	void Snake::Move(float dt)
	{
		sf::Vector2f position = snakeSprite.getPosition();
		float movementDistance = SNAKE_MOVEMENTSPEED * dt;
		float x = movebyX * movementDistance;
		float y = movebyY * movementDistance;
		snakeSprite.move(x, y);
	}

	void Snake::Draw()
	{
		_data->window.draw(snakeSprite);
	}
}