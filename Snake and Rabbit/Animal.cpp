#include "Animal.h"
#include "DEFENITIONS.h"

namespace SaR
{
	Animal::Animal(GameDataRef data) : _data(data)
	{

	}

	void Animal::Spawn()
	{
		sf::Sprite sprite(_data->assets.GetTexture("Animal Head"));
		sprite.setPosition((_data->window.getSize().x) / 2, (_data->window.getSize().y) / 2);
		animalSprites.push_back(sprite);
	}

	void Animal::Direction(sf::Keyboard *key)
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

	void Animal::Move(float dt)
	{
		for (unsigned short int i = 0; i < animalSprites.size(); i++)
		{
			sf::Vector2f position = animalSprites.at(i).getPosition();
			float movementDistance = SNAKE_MOVEMENTSPEED * dt;
			float x = movebyX * movementDistance;
			float y = movebyY * movementDistance;
			animalSprites.at(i).move(x, y);
		}
	}

	void Animal::Draw()
	{
		for (unsigned short int i = 0; i < animalSprites.size(); i++)
		{
			_data->window.draw(animalSprites.at(i));
		}
	}
}