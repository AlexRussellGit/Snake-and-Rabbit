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
		sf::Sprite sprite(_data->assets.GetTexture("Snake Head"));
		sprite.setPosition((_data->window.getSize().x) / 2, (_data->window.getSize().y) / 2);
		snakeSprites.push_back(sprite);
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

	void Snake::Move(float dt)
	{
		for (unsigned short int i = 0; i < snakeSprites.size(); i++)
		{
			sf::Vector2f position = snakeSprites.at(i).getPosition();
			float movementDistance = SNAKE_MOVEMENTSPEED * dt;
			float x = movebyX * movementDistance;
			float y = movebyY * movementDistance;
			snakeSprites.at(i).move(x, y);
		}
	}

	void Snake::Draw()
	{
		for (unsigned short int i = 0; i < snakeSprites.size(); i++)
		{
			_data->window.draw(snakeSprites.at(i));
		}
	}
}