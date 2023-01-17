#include <iostream>
#include "GameplayState.h"
#include "DEFENITIONS.h"

#define SNAKE_TEST true
#define RABBIT_TEST true

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
		aRabbit->Spawn();
#endif
#if (SNAKE_TEST)
		_data->assets.LoadTexture("Snake Head", SNAKEHEAD_FILEPATH);
		aSnake = new Snake(_data);
		aSnake->Spawn();
#endif
		_background.setTexture(this->_data->assets.GetTexture("Gameplay State Background"));
		std::cout << "animals spawned" << std::endl;
	}

	void GameplayState::HandleInput()
	{
		sf::Event event;
		while (_data->window.pollEvent(event)) {
			if (sf::Event::Closed == event.type) {
				_data->window.close();
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
#if (SNAKE_TEST && RABBIT_TEST)

		if (AnimalCollusion(aSnake, aRabbit))
		{
			std::cout << "true" << std::endl;
		}
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

	bool GameplayState::AnimalCollusion(Animal *animal1, Animal *animal2)
	{
		if (animal1->GetPosition().x >= animal2->GetPosition().x - 48 && 
			animal1->GetPosition().x <= animal2->GetPosition().x + 48 &&
			animal1->GetPosition().y >= animal2->GetPosition().y - 48 &&
			animal1->GetPosition().y <= animal2->GetPosition().y + 48)
		{
			animal2->Spawn();
			return true;
		}
		return false;
	}

}
