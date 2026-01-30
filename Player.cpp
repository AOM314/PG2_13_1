#include "Player.h"

void Player::Init(int x_, int y_) {
	x = x_;

	y = y_;

	speed = 6;
}

void Player::Update(char* keys) {


	if (keys[DIK_W])
		y -= speed;

	if (keys[DIK_S])
		y += speed;

	if (keys[DIK_A])
		x -= speed;

	if (keys[DIK_D])
		x += speed;


}


void Player::Draw() { Novice::DrawEllipse(x, y, 30, 30, 0.0f, GREEN, kFillModeSolid); }
