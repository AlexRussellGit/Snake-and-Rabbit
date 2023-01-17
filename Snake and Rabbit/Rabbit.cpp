#include "Rabbit.h"
#include "Animal.h"
#include "DEFENITIONS.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>  

namespace SaR
{

	Rabbit::Rabbit(GameDataRef data) : _data(data)
	{

	}

	void Rabbit::Spawn()
	{
		rabbitSprite.setTexture(_data->assets.GetTexture("Rabbit"));
		rabbitSprite.setPosition( rand() % (int)(_data->window.getSize().x - rabbitSprite.getGlobalBounds().width ), rand() % (int)(_data->window.getSize().y - rabbitSprite.getGlobalBounds().height));
	}

	void Rabbit::RandDirection(int range)
	{
		int changeDirection = rand() % 100;

		if (changeDirection <= (int)(range * 0.8) && !(range > 100))
		{
			if (movebyY == 0)
			{
				if (changeDirection < (int)(range * 0.4))
				{
					movebyY = movebyY - movebyX;
					movebyX = 0;
				}
				else
				{
					movebyY = movebyY + movebyX;
					movebyX = 0;
				}
			}
			else if(movebyX == 0)
			{
				if (changeDirection < (int)(range * 0.4))
				{
					movebyX = movebyX - movebyY;
					movebyY = 0;
				}
				else
				{
					movebyX = movebyX + movebyY;
					movebyY = 0;
				}
			}
		}
		else if (changeDirection < range || range > 100) 
		{
			movebyX = movebyX - (2 * movebyX);
			movebyY = movebyY - (2 * movebyY);
		}

	}

	sf::Vector2f Rabbit::GetPosition()
	{
		return rabbitSprite.getPosition();
	}

	void Rabbit::Move(float dt)
	{
		if (rabbitSprite.getPosition().x <= 0 ||
			rabbitSprite.getPosition().x >= _data->window.getSize().x - rabbitSprite.getGlobalBounds().width ||
			rabbitSprite.getPosition().y <= 0 ||
			rabbitSprite.getPosition().y >= _data->window.getSize().y - rabbitSprite.getGlobalBounds().height)
		{
			RandDirection(101);
		}
		else
		{
			RandDirection(5);
		}
		float movementDistance = SNAKE_MOVEMENTSPEED * dt;
		float x = movebyX * movementDistance;
		float y = movebyY * movementDistance;
		rabbitSprite.move(x, y);
	}

	void Rabbit::Draw()
	{
			_data->window.draw(rabbitSprite);
	}
}