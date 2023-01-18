#include "Bullet/Bullet.h"
#include "Variety/Screen/Screen.h"
#include <Novice.h>

Bullet::Bullet() {
	pos = { -100.0f,0.0f };
	rad = { 10.0f,10.0f };
	speed = { 10.0f,10.0f };
	isShot = false;
}

bool Bullet::getBullet() {
	return isShot;
}

void Bullet::setBullet(bool flag) {
	this->isShot = flag;
}

void Bullet::setPos(Vec2 pos) {
	this->pos = pos;
}

void Bullet::Update() {
	if (isShot)
	{
		pos.y += speed.y;
	}

	if (pos.y >= world_pos_y)
	{
		pos = { -100.0f,0.0f };
		isShot = false;
	}
}

void Bullet::Draw() {

	if (isShot)
	{
		Novice::DrawEllipse(static_cast<int>(Screen_Change(pos).x), static_cast<int>(Screen_Change(pos).y),
			static_cast<int>(rad.x), static_cast<int>(rad.y), 0.0f, 0xff0000ff, kFillModeSolid);
	}
}