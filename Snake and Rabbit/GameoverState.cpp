#include <sstream>
#include "GameoverState.h"
#include "DEFENITIONS.h"
#include <iostream>

namespace SaR
{
	GameoverState::GameoverState(GameDataRef data) : _data(data)
	{

	}

	void GameoverState::Init()
	{
		_data->assets.LoadTexture("Gameover State Background", GAMEOVER_BACKGROUND_FILEPATH);
		_background.setTexture(this->_data->assets.GetTexture("Gameover State Background"));
	}

	void GameoverState::HandleInput()
	{
		sf::Event event;
		while (_data->window.pollEvent(event)) {
			if (sf::Event::Closed == event.type) {
				_data->window.close();
			}
		}
	}

	void GameoverState::Update(float dt)
	{

	}

	void GameoverState::Draw(float dt)
	{
		_data->window.clear();
		_data->window.draw(_background);
		_data->window.display();
	}
}