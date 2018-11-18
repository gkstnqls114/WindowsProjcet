#pragma once

#include <Windows.h>
#include <atlimage.h>
#include <string>

using namespace std;

class MyImage
{
	CImage image;

	//이미지가 위치하는 곳
	// 즉 이미지 자체의 left_top
	int x;
	int y;

	int width;
	int height;

	int sprite_left;
	int sprite_top;
	int sprite_width;
	int sprite_height;

public:
	MyImage();
	~MyImage();


	void Draw(HDC hDC)
	{
		image.Draw(hDC, x, y, width, height);
	}

	void Draw(HDC hDC, int x, int y)
	{
		image.Draw(hDC, x, y, width, height);
	}



	boolean Check(int mx, int my);


	/////////////////////////////////////////Get
	int getWidth(){ return width; }
	int getHeight() { return height; }

	
	/////////////////////////////////////////Set
	void setWidth(int num) { width = num; }
	void setHeight(int num) { height = num; }

	//원상복구 시킨다 
	void oriWidth() { width = image.GetWidth(); }
	void oriHeight() { height = image.GetHeight(); }

	//void move_x(int num) { x += num; }
	//void move_y(int num) { y += num; }

	void set(const wstring& path)
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
	}
	void set(const wstring& path, int sprite_num)
	{
		image.Load(path.c_str());
		x = 0;
		y = 0;
		width = image.GetWidth() / sprite_num;
		height = image.GetHeight();
		sprite_top = 0;
		sprite_width = width;
		sprite_height = height;
	}
};

