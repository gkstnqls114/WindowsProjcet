#include "Button.h"



Button::Button()
{
}


Button::~Button()
{
}

void Button::Set(wstring Image_Name, int ix, int iy)
{
	image.set(Image_Name);
	x = ix;
	y = iy;
	width = image.getWidth();
	height = image.getHeight();
}

void Button::Draw(HDC hDC)
{
	image.Draw(hDC, x, y);
}

boolean Button::Check(int mx, int my)
{
	return false;
}
