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
    const auto position = mShape.getPosition();
    const float left = position.x - mRadius;
    const float right = position.x + mRadius;
    const float top = position.y - mRadius;
    const float bottom = position.y + mRadius;

    if (left < 0 || right > _width) {
        mDirection.x *= -1;
    }
    if (top < 0 || bottom > _height) {
        mDirection.y *= -1;
    }
}