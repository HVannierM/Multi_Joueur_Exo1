#pragma once
#include <SFML/Graphics.hpp>

class Ball{
protected:
	sf::CircleShape mShape;
	sf::Vector2f mDirection;
	int mRadius;
	int mSpeed;

public:
	Ball();
	int GetRadius() { return mRadius; }
	int GetPositionX() { return mShape.getPosition().x; }
	int GetPositionY() { return mShape.getPosition().y; }
	void SetPositionX(float _x) { return mShape.setPosition(_x, GetPositionY()); }
	void SetPositionY(float _y) { return mShape.setPosition(GetPositionX(), _y); }
	void SetPosition(float _x, float _y) { return mShape.setPosition(_x, _y); }
	sf::CircleShape Get() { return mShape; }

	void Move(float _Dt);

	void Check_Collision(int _width, int _height);

	void SetDirection(float _x, float _y) { mDirection = sf::Vector2f(_x, _y); }
};