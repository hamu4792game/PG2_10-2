#pragma once
#include <Novice.h>

class Key
{
private:

	// キー入力結果を受け取る箱
	//	プロトタイプ宣言と同じ
	static char keys[256];
	static char preKeys[256];

public:

	// キー入力を受け取る
	static void Input()
	{
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);
	}

	//	キーが押された時
	static bool IsTrigger(char keycord)
	{
		return preKeys[keycord] == 0 && keys[keycord] != 0;
	}

	//	キーが押されている時
	static bool IsPressed(char keycord)
	{
		return keys[keycord] != 0;
	}

};