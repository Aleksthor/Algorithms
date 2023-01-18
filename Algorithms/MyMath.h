#pragma once
#include <math.h>

struct Vec2
{
	Vec2()
		: x(0), y(0)
	{

	}
	Vec2(int _x, int _y)
		: x(_x), y(_y)
	{

	}

	int x;
	int y;

	static int Length(Vec2 A, Vec2 B)
	{
		return sqrt((B.x - A.x)*(B.x - A.x) + (B.y-A.y) * (B.y-A.y));
	}
};


