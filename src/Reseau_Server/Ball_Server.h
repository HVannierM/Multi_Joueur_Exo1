#pragma once
#include <SFML/Graphics.hpp>

class Ball {
protected:
	sf::CircleShape mShape;

public:
	Ball();
	void SetPosition(float _x, float _y) { return mShape.setPosition(_x, _y); }
	sf::CircleShape Get() { return mShape; }
};