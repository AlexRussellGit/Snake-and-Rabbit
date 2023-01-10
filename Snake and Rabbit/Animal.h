#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Game.h"
#include "DEFENITIONS.h"

namespace SaR
{
	class Animal
	{
	public:
		Animal(GameDataRef data);
		void SpawnAnimal();
		void MoveAnimal(std::string direction, float dt);
		void DrawAnimals();

	private:
		GameDataRef _data;
		std::vector<sf::Sprite> animalSprites;
	};
}