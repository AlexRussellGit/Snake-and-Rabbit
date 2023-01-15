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
		sf::Sprite sprite(_data->assets.GetTexture("Rabbit"));
		sprite.setPosition((_data->window.getSize().x) / 2, (_data->window.getSize().y) / 2);
		rabbitSprites.push_back(sprite);
	}

	void Rabbit::RandDirection(int range)
	{
		int changeDirection = rand() % 100;

		if (changeDirection < (int)(range * 0.8))
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
		else if (changeDirection < range) // 99
		{
			movebyX = movebyX - (2 * movebyX);
			movebyY = movebyY - (2 * movebyY);
		}

	}

	void Rabbit::Move(float dt)
	{
		RandDirection(3);
		for (unsigned short int i = 0; i < rabbitSprites.size(); i++)
		{
			sf::Vector2f position = rabbitSprites.at(i).getPosition();
			float movementDistance = SNAKE_MOVEMENTSPEED * dt;
			float x = movebyX * movementDistance;
			float y = movebyY * movementDistance;
			rabbitSprites.at(i).move(x, y);
		}
	}

	void Rabbit::Draw()
	{
		for (unsigned short int i = 0; i < rabbitSprites.size(); i++)
		{
			_data->window.draw(rabbitSprites.at(i));
		}
	}
}