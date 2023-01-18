#pragma once
#include "Variety/Vec2/Vec2.h"

class Bullet
{
public:
	Bullet();

private:
	Vec2 pos;
	Vec2 rad;
	Vec2 speed;
	bool isShot;

public:
	//	
	bool getBullet();
	void setBullet(bool flag);
	void setPos(Vec2 pos);

public:
	void Update();
	void Draw();

};
