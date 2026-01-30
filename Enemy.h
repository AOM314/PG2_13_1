#pragma once
#include <Novice.h>

class Enemy {
public:
	int x, y;
	int vx;
	bool isAlive;


	static bool isAllDead;


	void Init(int x_, int y_, int vx_);
	
	void Update();
	
	void Draw();
	

	//保存
	void OnHit(); 
	
	void Respawn();


private:
	
	int deadX; 
	int deadY;
	int deadVx;

};
