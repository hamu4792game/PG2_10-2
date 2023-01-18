#include "Variety/Screen/Screen.h"
#include <Novice.h>
#include "Variety/Key/Key.h"


//フルスクリーン切り替え-----------------------------------------------------------------------------
#pragma region FULL_screen
void Full_screen(int key) {
	static bool screenmode = false;

	if (Key::IsTrigger(key))
	{
		if (screenmode == false)
		{
			screenmode = true;
		}
		else
		{
			screenmode = false;
		}
	}

	if (screenmode == false)
	{
		Novice::SetWindowMode(kWindowed);
	}
	else if (screenmode == true)
	{
		Novice::SetWindowMode(kFullscreen);
	}
}
#pragma endregion


Vec2 Screen_Change(Vec2 pos) {
	Vec2 result;
	result.x = pos.x;
	result.y = (pos.y - world_pos_y) * -1;
	return result;
}