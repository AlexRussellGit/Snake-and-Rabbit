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

		void Spawn();
		void Direction(sf::Keyboard *key);
		void Move(float dt);
		void Draw();

	private:
		GameDataRef _data;
		std::vector<sf::Sprite> animalSprites;

		float movebyX = 1;
		float movebyY = 0;
	};
}