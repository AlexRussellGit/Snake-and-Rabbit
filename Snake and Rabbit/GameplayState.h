#pragma once

#include <SFML/Graphics.hpp>
#include "GameoverState.h"
#include "State.h"
#include "Game.h"
#include "Animal.h"
#include "Snake.h"
#include "Rabbit.h"

namespace SaR
{
	class GameplayState : public State
	{
	public:
		GameplayState(GameDataRef data);
		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);
	private:
		GameDataRef _data;
		sf::Clock _clock;
		sf::Sprite _background;
		
		sf::Keyboard* key;
		Animal* aRabbit;
		Animal* aSnake;
	};
}