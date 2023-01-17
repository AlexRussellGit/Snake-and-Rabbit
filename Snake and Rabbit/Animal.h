#pragma once

namespace SaR
{
	class Animal
	{
	public:
		virtual void Spawn() = 0;
		virtual void SetDirection(sf::Keyboard *key) = 0;
		virtual void RandDirection(int range) = 0;
		virtual bool SustainAlive() = 0;
		virtual sf::Vector2f GetPosition() = 0;
		virtual void Move(float dt) = 0;
		virtual void Draw() = 0;
	};
}