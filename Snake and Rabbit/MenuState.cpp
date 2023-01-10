#include <sstream>
#include "MenuState.h"
#include "GameplayState.h"
#include "DEFENITIONS.h"
#include <iostream>

namespace SaR
{
	MenuState::MenuState(GameDataRef data) : _data(data)
	{

	}

	void MenuState::Init()
	{
		_data->assets.LoadTexture("Menu State Background", MAIN_MENU_BACKGROUND_FILEPATH);
		_data->assets.LoadTexture("Game Title", GAME_TITLE_FILEPATH);
		_data->assets.LoadTexture("Play Button", PLAY_BUTTON_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Menu State Background"));
		_title.setTexture(this->_data->assets.GetTexture("Game Title"));
		_playButton.setTexture(this->_data->assets.GetTexture("Play Button"));

		_title.setPosition((SCREEN_WIDTH / 2), 0);
		_playButton.setPosition((7 * SCREEN_WIDTH / 9) - (_playButton.getGlobalBounds().width / 2), (5 * SCREEN_HEIGHT / 6));
	}

	void MenuState::HandleInput()
	{
		sf::Event event;
		while (_data->window.pollEvent(event)) {
			if (sf::Event::Closed == event.type) {
				_data->window.close();
			}
			if (_data->input.IsSpriteClicked(_playButton, sf::Mouse::Left, _data->window))
			{
				_data->machine.AddState(StateRef(new GameplayState(_data)), true);
			}
		}
	}

	void MenuState::Update(float dt)
	{

	}

	void MenuState::Draw(float dt)
	{
		_data->window.clear();
		_data->window.draw(_background);
		_data->window.draw(_title);
		_data->window.draw(_playButton);
		_data->window.display();
	}
}