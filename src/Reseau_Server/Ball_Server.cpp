#include "pch.h"
#include "Ball_Server.h"

Ball::Ball() {
	mShape.setRadius(50);
	mShape.setOrigin(mShape.getRadius(), mShape.getRadius());
}