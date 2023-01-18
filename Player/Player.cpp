#include "Player/Player.h"
#include "Variety/Key/Key.h"
#include "Variety/Screen/Screen.h"

Player::Player() : MAX_BULLET(10) {
	bullet = new Bullet[MAX_BULLET];

	pos = { 0.0f,0.0f };
	rad = { 20.0f,20.0f };
	speed = { 5.0f,5.0f };
}

Player::~Player() {
	delete[] bullet;
}

void Player::Update() {
	//	à⁄ìÆ
	if (Key::IsPressed(DIK_W) || Key::IsPressed(DIK_UP))
	{
		pos.y += speed.y;
	}
	if (Key::IsPressed(DIK_S) || Key::IsPressed(DIK_DOWN))
	{
		pos.y -= speed.y;
	}
	if (Key::IsPressed(DIK_A) || Key::IsPressed(DIK_LEFT))
	{
		pos.x -= speed.x;
	}
	if (Key::IsPressed(DIK_D) || Key::IsPressed(DIK_RIGHT))
	{
		pos.x += speed.x;
	}

	//	êßå¿
	if (pos.x - rad.x <= 0)
	{
		pos.x = 0 + rad.x;
	}
	else if (pos.x + rad.x >= 1280)
	{
		pos.x = 1280 - rad.x;
	}
	if (pos.y + rad.y >= world_pos_y)
	{
		pos.y = world_pos_y - rad.y;
	}
	else if (pos.y - rad.y <= world_pos_y - 720)
	{
		pos.y = (world_pos_y - 720) + rad.y;
	}

	//	ÉtÉâÉOÇóßÇƒÇÈ
	if (Key::IsTrigger(DIK_SPACE))
	{
		for (int i = 0; i < MAX_BULLET; i++)
		{
			if (!bullet[i].getBullet())
			{
				bullet[i].setBullet(true);
				bullet[i].setPos(pos);
				break;
			}
		}
	}
	
	for (int i = 0; i < MAX_BULLET; i++)
	{
		if (bullet[i].getBullet())
		{
			bullet[i].Update();
		}
	}

}

void Player::Draw() {
	for (int i = 0; i < MAX_BULLET; i++)
	{
		bullet[i].Draw();
	}
	Novice::DrawEllipse(static_cast<int>(Screen_Change(pos).x), static_cast<int>(Screen_Change(pos).y),
		static_cast<int>(rad.x), static_cast<int>(rad.y), 0.0f, 0xffffffff, kFillModeSolid);
}