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
		
		void Spawn();
		void SetDirection(sf::Keyboard* key);
		void RandDirection(int range) {};
		bool SustainAlive();
		sf::Vector2f GetPosition();
		void Move(float dt);
		void Draw();

	private:
		GameDataRef _data;
		sf::Sprite snakeSprite;

		float movebyX = 1;
		float movebyY = 0;
	};
}