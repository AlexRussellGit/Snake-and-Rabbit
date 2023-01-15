#include <iostream>
#include "GameplayState.h"
#include "DEFENITIONS.h"

#define SNAKE_TEST true
#define RABBIT_TEST false

namespace SaR
{
	GameplayState::GameplayState(GameDataRef data) : _data(data)
	{

	}

	void GameplayState::Init()
	{
		_data->assets.LoadTexture("Gameplay State Background", GAMEPLAY_BACKGROUND_FILEPATH);
#if (RABBIT_TEST)
		_data->assets.LoadTexture("Rabbit", RABBIT_FILEPATH);
		aRabbit = new Rabbit(_data);
#endif
#if (SNAKE_TEST)
		_data->assets.LoadTexture("Snake Head", SNAKEHEAD_FILEPATH);
		aSnake = new Snake(_data);
#endif
		_background.setTexture(this->_data->assets.GetTexture("Gameplay State Background"));
	}

	void GameplayState::HandleInput()
	{
		sf::Event event;
		while (_data->window.pollEvent(event)) {
			if (sf::Event::Closed == event.type) {
				_data->window.close();
			}
			if (_data->input.IsSpriteClicked(_background, sf::Mouse::Left, _data->window))
			{
#if (RABBIT_TEST)
				aRabbit->Spawn();
#endif
#if (SNAKE_TEST)
				aSnake->Spawn();
#endif
				std::cout << "animals spawned" << std::endl;
			}
#if (SNAKE_TEST)
			aSnake->SetDirection(key);	
#endif
		}
	}

	void GameplayState::Update(float dt)
	{
#if (RABBIT_TEST)
		aRabbit->Move(dt);
#endif
#if (SNAKE_TEST)
		if (!(aSnake->SustainAlive()))
		{
			_data->machine.AddState(StateRef(new GameoverState(_data)), true);
		}
		aSnake->Move(dt);
#endif
	}

	void GameplayState::Draw(float dt)
	{
		_data->window.clear();
		_data->window.draw(_background);
#if (RABBIT_TEST)
		aRabbit->Draw();
#endif
#if (SNAKE_TEST)
		aSnake->Draw();
#endif
		_data->window.display();
	}
}