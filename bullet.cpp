#include "Bullet.h"

void Bullet::Fire(int x_, int y_) {
	x = x_;
	y = y_;
	vy = -12;

	isAlive = true;
}

void Bullet::Update() {

	if (!isAlive)
		return;

	y += vy;
	if (y < 0) {

		isAlive = false;
	
	}
}

void Bullet::Draw() {
	if (isAlive) {

		Novice::DrawEllipse(x, y, 5, 5, 0.0f, WHITE, kFillModeSolid);
	
	}
}
