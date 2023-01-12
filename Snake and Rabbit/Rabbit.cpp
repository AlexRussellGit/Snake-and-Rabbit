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
		sf::Sprite sprite(_data->assets.GetTexture("Snake Head"));
		sprite.setPosition((_data->window.getSize().x) / 2, (_data->window.getSize().y) / 2);
		rabbitSprites.push_back(sprite);
	}

	void Rabbit::RandDirection()
	{
		//srand(time(0));
		//int binar_arr[] = {-1, 1};

		/*srand(time(NULL));
		std::cout << rand() << std::endl;*/

		//int changeDirection = rand() % 100;
		
		int changeDirection = rand() % 100;

		/*if (changeDirection < 50)
		{
			movebyX = (int)(movebyX - (2 * movebyX));
			movebyY = (int)(movebyY - (2 * movebyY));
		}*/

		if (changeDirection >= 69 && changeDirection < 99)
		{
			if (movebyY == 0)
			{
				if (changeDirection >= 69 && changeDirection < changeDirection < 82)
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
				if (changeDirection >= 69 && changeDirection < changeDirection < 82)
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
		else if (changeDirection == 99) // 99
		{
			movebyX = movebyX - (2 * movebyX);
			movebyY = movebyY - (2 * movebyY);
		}

	}

	void Rabbit::Move(float dt)
	{
		RandDirection();
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