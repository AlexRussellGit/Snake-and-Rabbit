#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Game.h"
#include "DEFENITIONS.h"
#include "Animal.h"

namespace SaR
{
	class Snake 
	{
	public:
		Snake(GameDataRef data);
		
		void Spawn();
		void Move(std::string direction, float dt);
		void Draw();

	private:
		GameDataRef _data;
		std::vector<sf::Sprite> animalSprites;
	};
}