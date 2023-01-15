#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Game.h"
#include "DEFENITIONS.h"
#include "Animal.h"

namespace SaR
{
	class Rabbit : public Animal
	{
	public:
		Rabbit(GameDataRef data);

		void Spawn();
		void SetDirection(sf::Keyboard* key) {};
		void RandDirection(int range);
		bool SustainAlive() { return true; };
		void Move(float dt);
		void Draw();

	private:
		GameDataRef _data;
		std::vector<sf::Sprite> rabbitSprites;

		float movebyX = -1;
		float movebyY = 0;
	};
}