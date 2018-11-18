#pragma once
#include "MyImage.h"

class Button
{
	MyImage image;
	int x, y;
	int width;
	int height;

public:
	Button();
	~Button();

	void Set(wstring Image_Name, int ix, int iy);

	void Draw(HDC hDC);

};

