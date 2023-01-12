#pragma once

namespace SaR
{
	class Animal
	{
	public:
		virtual void Spawn() = 0;
		virtual void SetDirection(sf::Keyboard *key) = 0;
		virtual void RandDirection() = 0;
		virtual void Move(float dt) = 0;
		virtual void Draw() = 0;
	};
}