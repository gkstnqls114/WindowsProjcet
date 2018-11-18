#pragma once

#include <Windows.h>
#include <atlimage.h>
#include <string>

using namespace std;

class MyImage
{
	CImage image;

	//�̹����� ��ġ�ϴ� ���� ��ǥ
	int x;
	int y;

	int width;
	int height;

	int sprite_left;
	int sprite_top;
	int sprite_width;
	int sprite_height;
	
	//ȸ���� ���� ���̴� POINT ������
	POINT Point_Rotate[3]{ { 0, 0 },{ 0, 0 },{ 0, 0 } };
	POINT Point_ori[3]{ { 0, 0 },{ 0, 0 },{ 0, 0 } }; //���� ��ǥ

	//ȸ�� �߽�
	int Rotate_center_x;
	int Rotate_center_y;

	//�׸� ũ�� ����
	double proportion_x{ 1 };
	double proportion_y{ 1 };

	//��ȯ����
	int angle{ 0 };

public:
	MyImage();
	~MyImage();


	//�׳� �׸� �׸��� �Լ�
	//ũ�� �����Ϸ��� ��������ϴ�!!
	void Draw(HDC hDC)
	{
		image.Draw(hDC, x, y, width, height);
	}

	void Draw(HDC hDC, int ix, int iy)
	{
		image.Draw(hDC, ix, iy, width, height);
	}

	//��������Ʈ �׸��� �Լ�
	void Sprite_Draw(HDC hDC)
	{
		image.Draw(hDC, x, y, sprite_width, sprite_height,
			sprite_left, sprite_top, sprite_width, sprite_height);
	}

	void Rotate_Draw(HDC hDC);


	boolean Check(int mx, int my);

	//ȸ��
	//Rotatedraw������ �ؾ���
	void Rotate();


	//�̹��� �ε�
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
	//���󺹱� ��Ų�� 
	void oriWidth() { width = image.GetWidth(); }
	void oriHeight() { height = image.GetHeight(); }

	//��������Ʈ ����
	void move_Sprite_left(const int num) { sprite_left += num; }
	void move_Sprite_top(const int num) { sprite_top += num; }
	void set_Sprite_left(const int num) { sprite_left = num; }
	void set_Sprite_top(const int num) { sprite_top = num; }
	void set_Sprite_width(const int num) { sprite_width = num; }
	void set_Sprite_height(const int num) { sprite_height = num; }

	//ȸ�������� �ϴ� ����
	void set_angle(int num) { angle = num; }
	void set_Rotate_center_x(int num) { Rotate_center_x = num; }
	void set_Rotate_center_y(int num) { Rotate_center_y = num; }
	void set_proportion_x(double num) { proportion_x = num; }
	void set_proportion_y(double num) { proportion_y = num; }

	
	//�׸��׸� ��ǥ�̵�
	void move_x(const int num) { x += num; }
	void move_y(const int num) { y += num; }
	void set_x(const int num) { x = num; }
	void set_y(const int num) { y = num; }
	void set_position(const int ix, const int iy) { x = ix, y = iy; }
	 

};

