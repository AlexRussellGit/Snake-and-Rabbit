#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

namespace SaR
{
	class MenuState : public State
	{
	public:
		MenuState(GameDataRef data);
		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);
	private:
		GameDataRef _data;
		sf::Sprite _background;
		sf::Sprite _title;
		sf::Sprite _playButton;

	};
}