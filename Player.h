#pragma once
#include <Novice.h>

class Player {
public:

	int x;
	int y;
	int speed;

	void Init(int x_, int y_);
	void Update(char* keys);
	void Draw();


};
