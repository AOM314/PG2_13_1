#include "Enemy.h"

bool Enemy::isAllDead = false;


void Enemy::Init(int x_, int y_, int vx_) {
	
	x = x_;
	y = y_;
	vx = vx_;

	isAlive = true;
	
	isAllDead = false;


}


void Enemy::Update() {

	if (!isAlive || isAllDead)
		return;

	x += vx;

	if (x < 20 || x > 1260) {
		vx *= -1;
	}
}


void Enemy::OnHit() {

	//　倒された位置を保存

	deadX = x;
	deadY = y;
	deadVx = vx;

	isAllDead = true;
}


void Enemy::Respawn() {

	x = deadX; 
	y = deadY;
	vx = deadVx;

	isAlive = true;
	isAllDead = false;

}

void Enemy::Draw() {

	if (isAlive) {

		Novice::DrawEllipse(x, y, 20, 20, 0.0f, RED, kFillModeSolid);

	}

}
