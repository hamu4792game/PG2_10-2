#pragma once
#include "Variety/Vec2/Vec2.h"
#include "Bullet/Bullet.h"

class Player
{
public:
	Player();
	~Player();

private:
	const int MAX_BULLET;
	Bullet* bullet;

	Vec2 pos;
	Vec2 rad;
	Vec2 speed;

public:
	void Update();
	void Draw();
};
