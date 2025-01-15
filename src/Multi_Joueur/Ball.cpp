#include "pch.h"
#include "Ball.h"

Ball::Ball(){
	mRadius = 50;
	mSpeed = 200;
	mDirection = sf::Vector2f(1.0f, 0.5f);
	mShape.setRadius(mRadius);
	mShape.setFillColor(sf::Color::Red);
	mShape.setPosition(400, 400);
	mShape.setOrigin(mRadius, mRadius);
}
void Ball::Move(float Dt) {
	mShape.move(mDirection.x * mSpeed * Dt, mDirection.y * mSpeed * Dt);
}

void Ball::Check_Collision(int _width, int _height) {
	if (mShape.getPosition().x - mRadius < 0 || mShape.getPosition().x + mRadius > _width) {
		mDirection.x *= -1;
	}
	if (mShape.getPosition().y - mRadius < 0 || mShape.getPosition().y + mRadius > _height) {
		mDirection.y *= -1;
	}

}