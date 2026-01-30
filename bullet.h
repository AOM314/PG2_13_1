#pragma once
#include <Novice.h>

class Bullet {
public:

	int x;
	int y;
	int vy;

	bool isAlive;

	void Fire(int x_, int y_);
	void Update();
	void Draw();

};
