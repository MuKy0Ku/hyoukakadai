#pragma once
#include"Struct.h"

class Player
{
public:

	Player();

	void Move(char* keys, char* preKeys);

	void Draw();

private:
	Vector2 Pos_;
	float Speed_;
	int radius_;
	float Charge;
	int MoveFlag;
};

