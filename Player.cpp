#include "Player.h"
#include <Novice.h>

Player::Player()
{
	Pos_.x = 50;
	Pos_.y = 600;
	Speed_ = 0;
	radius_ = 16;
	Charge = 0;
	MoveFlag = 0;
}

void Player::Move(char* keys, char* preKeys)
{
	if (keys[DIK_SPACE] && MoveFlag == 0 && Charge < 30)
	{
		Charge += 1;
	}

	if (keys[DIK_SPACE] == 0 && preKeys[DIK_SPACE])
	{
		Speed_ = Charge;
		MoveFlag = 1;
	}

	if (MoveFlag == 1)
	{
		Pos_.x += Speed_;
	}

	if (Speed_ < 0 && MoveFlag == 1)
	{
		MoveFlag = 0;
		Charge = 0;
		Speed_ = 0;
	}

	Speed_ -= 1;//‰¼‚ÌŒ¸‘¬
}

void Player::Draw()
{
	Novice::DrawEllipse(Pos_.x, Pos_.y, radius_, radius_, 0.0f, WHITE, kFillModeSolid);
	Novice::ScreenPrintf(0, 0, "moveflag = %d", MoveFlag);
	Novice::ScreenPrintf(0, 20, "charge = %f", Charge);
}