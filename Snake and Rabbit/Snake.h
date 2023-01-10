#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Game.h"
#include "DEFENITIONS.h"
#include "Animal.h"

namespace SaR
{
	class Snake : public Animal
	{
	public:
		Snake(GameDataRef data);
		void SpawnAnimal();
		void MoveAnimal(std::string direction, float dt);
		void DrawAnimals();

	private:
		GameDataRef _data;
		std::vector<sf::Sprite> animalSprites;
	};
}