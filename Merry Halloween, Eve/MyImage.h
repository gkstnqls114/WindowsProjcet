#pragma once

#include <Windows.h>
#include <atlimage.h>
#include <string>

using namespace std;

class MyImage
{
	CImage image;

	//이미지가 위치하는 곳의 좌표
	int x;
	int y;

	int width;
	int height;

	int sprite_left;
	int sprite_top;
	int sprite_width;
	int sprite_height;
	
	//회전을 위해 쓰이는 POINT 세가지
	POINT Point_Rotate[3]{ { 0, 0 },{ 0, 0 },{ 0, 0 } };
	POINT Point_ori[3]{ { 0, 0 },{ 0, 0 },{ 0, 0 } }; //원래 좌표

	//회전 중심
	int Rotate_center_x;
	int Rotate_center_y;

	//그림 크기 비율
	double proportion_x{ 1 };
	double proportion_y{ 1 };

	//변환각도
	int angle{ 0 };

public:
	MyImage();
	~MyImage();


	//그냥 그림 그리는 함수
	//크기 조절하려고 만들었슴니당!!
	void Draw(HDC hDC)
	{
		image.Draw(hDC, x, y, width, height);
	}

	void Draw(HDC hDC, int ix, int iy)
	{
		image.Draw(hDC, ix, iy, width, height);
	}

	//스프라이트 그리는 함수
	void Sprite_Draw(HDC hDC)
	{
		image.Draw(hDC, x, y, sprite_width, sprite_height,
			sprite_left, sprite_top, sprite_width, sprite_height);
	}

	void Rotate_Draw(HDC hDC);


	boolean Check(int mx, int my);

	//회전
	//Rotatedraw이전에 해야함
	void Rotate();


	//이미지 로드
	void Set(const wstring& path);
	void Set(const wstring& path, int sprite_num);


	/////////////////////////////////////////Get
	int get_X() { return x; }
	int get_Y() { return y; }
	int getWidth() { return width; }
	int getHeight() { return height; }
	int get_Sprite_width() { return sprite_width; }
	int get_Sprite_height() { return sprite_height; }
	int get_Sprite_left() { return sprite_left; }
	int get_Sprite_top() { return sprite_top; }

	/////////////////////////////////////////Set
	void setWidth(const int num) { width = num; }
	void setHeight(const int num) { height = num; }
	//원상복구 시킨다 
	void oriWidth() { width = image.GetWidth(); }
	void oriHeight() { height = image.GetHeight(); }

	//스프라이트 조정
	void move_Sprite_left(const int num) { sprite_left += num; }
	void move_Sprite_top(const int num) { sprite_top += num; }
	void set_Sprite_left(const int num) { sprite_left = num; }
	void set_Sprite_top(const int num) { sprite_top = num; }
	void set_Sprite_width(const int num) { sprite_width = num; }
	void set_Sprite_height(const int num) { sprite_height = num; }

	//회전때문에 하는 조정
	void set_angle(int num) { angle = num; }
	void set_Rotate_center_x(int num) { Rotate_center_x = num; }
	void set_Rotate_center_y(int num) { Rotate_center_y = num; }
	void set_proportion_x(double num) { proportion_x = num; }
	void set_proportion_y(double num) { proportion_y = num; }

	
	//그림그릴 좌표이동
	void move_x(const int num) { x += num; }
	void move_y(const int num) { y += num; }
	void set_x(const int num) { x = num; }
	void set_y(const int num) { y = num; }
	void set_position(const int ix, const int iy) { x = ix, y = iy; }
	 

};

