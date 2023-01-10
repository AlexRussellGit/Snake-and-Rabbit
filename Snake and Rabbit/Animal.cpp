#include "Animal.h"
#include "DEFENITIONS.h"

namespace SaR
{
	Animal::Animal(GameDataRef data) : _data(data)
	{

	}

	void Animal::SpawnAnimal()
	{
		sf::Sprite sprite(_data->assets.GetTexture("Snake Head"));
		sprite.setPosition((_data->window.getSize().x) / 2, (_data->window.getSize().y) / 2);
		animalSprites.push_back(sprite);
	}

	void Animal::MoveAnimal(std::string direction, float dt)
	{
		for (unsigned short int i = 0; i < animalSprites.size(); i++)
		{
			sf::Vector2f position = animalSprites.at(i).getPosition();
			float movement = SNAKE_MOVEMENTSPEED * dt;
			//animalSprites.at(i).move(movement, 0);
			if (direction == "right")
			{
				animalSprites.at(i).move(movement, 0);
			}
			if (direction == "left")
			{
				animalSprites.at(i).move((-movement), 0);
			}
			if (direction == "up")
			{
				animalSprites.at(i).move(0, movement);

			}
			if (direction == "down")
			{
				animalSprites.at(i).move(0, -movement);
			}
		}
	}

	void Animal::DrawAnimals()
	{
		for (unsigned short int i = 0; i < animalSprites.size(); i++)
		{
			_data->window.draw(animalSprites.at(i));
		}
	}
}