#include <iostream>
#include "GameplayState.h"
#include "DEFENITIONS.h"

namespace SaR
{
	GameplayState::GameplayState(GameDataRef data) : _data(data)
	{

	}

	void GameplayState::Init()
	{
		_data->assets.LoadTexture("Gameplay State Background", GAMEPLAY_BACKGROUND_FILEPATH);
		_data->assets.LoadTexture("Snake Head", SNAKEHEAD_FILEPATH);

		animal = new Animal( _data );

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
				animal->SpawnAnimal();
				std::cout << "animal spawned" << std::endl;
			}
			/*if (sf::Keyboard::isKeyPressed)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					animal->MoveAnimal("up", SNAKE_MOVEMENTSPEED);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					animal->MoveAnimal("down", SNAKE_MOVEMENTSPEED);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					animal->MoveAnimal("ledt", SNAKE_MOVEMENTSPEED);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					animal->MoveAnimal("right", SNAKE_MOVEMENTSPEED);
				}
			}*/
			
		}
	}

	void GameplayState::Update(float dt)
	{
		animal->MoveAnimal("down", dt);
	}

	void GameplayState::Draw(float dt)
	{
		_data->window.clear();
		_data->window.draw(_background);
		animal->DrawAnimals();
		_data->window.display();
	}
}