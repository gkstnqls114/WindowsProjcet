#include "MyImage.h"



MyImage::MyImage()
{
}


MyImage::~MyImage()
{

}

void MyImage::Rotate_Draw(HDC hDC)
{
	//회전을 다른 DC에 그립니다.
	HDC RotateDC = CreateCompatibleDC(hDC);
	HBITMAP RotateBitmap = CreateCompatibleBitmap(hDC, 800 + 16, 1200 + 39);
	HBRUSH RotateBrush = CreateSolidBrush(RGB(255, 0, 255));

	SelectObject(RotateDC, RotateBitmap);
	SelectObject(RotateDC, RotateBrush);

	Rectangle(RotateDC, -1, -1, 800 + 16, 1200 + 39);
	////////////여기까지 초기화

	//////////////이제 그림그린다~~


	image.PlgBlt(RotateDC, Point_Rotate, NULL);


	TransparentBlt(hDC, x, y, sprite_width, sprite_height, RotateDC, 0, 0, sprite_width, sprite_height, RGB(255, 0, 255));

	//BitBlt(hDC, x, y, sprite_width, sprite_height, RotateDC, 0, 0, SRCCOPY);


	///////////
	DeleteDC(RotateDC);
	DeleteObject(RotateBitmap);
	DeleteObject(RotateBrush);
}

boolean MyImage::Check(int mx, int my)
{
	if (x <= mx && mx <= x + width && y <= my && my <= y + height)
		return 1;
	else
		return 0;
	
}

void MyImage::Rotate()
{
	Point_Rotate[0].x =
		(Point_ori[0].x - Rotate_center_x) * proportion_x * cos(angle * 3.14 / 180)
		+ (Point_ori[0].y - Rotate_center_y) * proportion_y  * sin(angle* 3.14 / 180)
		+ Rotate_center_x;

	Point_Rotate[0].y =
		-(Point_ori[0].x - Rotate_center_x) * proportion_x * sin(angle * 3.14 / 180)
		+ (Point_ori[0].y - Rotate_center_y) * proportion_y  * cos(angle * 3.14 / 180)
		+ Rotate_center_y;

	Point_Rotate[1].x =
		(Point_ori[1].x - Rotate_center_x) * proportion_x * cos(angle * 3.14 / 180)
		+ (Point_ori[1].y - Rotate_center_y) * proportion_y  * sin(angle* 3.14 / 180)
		+ Rotate_center_x;

	Point_Rotate[1].y =
		-(Point_ori[1].x - Rotate_center_x) * proportion_x * sin(angle * 3.14 / 180)
		+ (Point_ori[1].y - Rotate_center_y) * proportion_y  * cos(angle * 3.14 / 180)
		+ Rotate_center_y;

	Point_Rotate[2].x =
		(Point_ori[2].x - Rotate_center_x) * proportion_x * cos(angle * 3.14 / 180)
		+ (Point_ori[2].y - Rotate_center_y) * proportion_y  * sin(angle* 3.14 / 180)
		+ Rotate_center_x;

	Point_Rotate[2].y =
		-(Point_ori[2].x - Rotate_center_x) * proportion_x * sin(angle * 3.14 / 180)
		+ (Point_ori[2].y - Rotate_center_y) * proportion_y * cos(angle * 3.14 / 180)
		+ Rotate_center_y;
}

void MyImage::Set(const wstring & path)
{
	image.Load(path.c_str());
	x = 0;
	y = 0;
	width = image.GetWidth();
	height = image.GetHeight();
	sprite_left = 0;
	sprite_top = 0;
	sprite_width = width;
	sprite_height = height;
	
	Point_ori[0].x = 0;
	Point_ori[0].y = 0;
	Point_ori[1].x = width;
	Point_ori[1].y = 0;
	Point_ori[2].x = 0;
	Point_ori[2].y = height;

	Point_Rotate[0].x = Point_ori[0].x;
	Point_Rotate[0].y = Point_ori[0].y;
	Point_Rotate[1].x = Point_ori[1].x;
	Point_Rotate[1].y = Point_ori[1].y;
	Point_Rotate[2].x = Point_ori[2].x;
	Point_Rotate[2].y = Point_ori[2].y;

	//기본적으로 회전중심을 넓이의 중심으로
	Rotate_center_x = width / 2;
	Rotate_center_y = height / 2;

}

void MyImage::Set(const wstring & path, int sprite_num)
{

	image.Load(path.c_str());
	x = 0;
	y = 0;
	width = image.GetWidth();
	height = image.GetHeight();
	sprite_top = 0;
	sprite_width = width / sprite_num;
	sprite_height = height;

	Point_ori[0].x = 0;
	Point_ori[0].y = 0;
	Point_ori[1].x = sprite_width;
	Point_ori[1].y = 0;
	Point_ori[2].x = 0;
	Point_ori[2].y = sprite_height;

	Point_Rotate[0].x = Point_ori[0].x;
	Point_Rotate[0].y = Point_ori[0].y;
	Point_Rotate[1].x = Point_ori[1].x;
	Point_Rotate[1].y = Point_ori[1].y;
	Point_Rotate[2].x = Point_ori[2].x;
	Point_Rotate[2].y = Point_ori[2].y;

	//기본적으로 회전중심을 넓이의 중심으로
	Rotate_center_x = sprite_width / 2;
	Rotate_center_y = sprite_height / 2;

}
