#pragma once

#include "MyImage.h"

class Devil
{
	MyImage image;

	//int x, y;
	int degree;
	int power;

	int x_vector{ 0 };
	int y_vector{ 0 };

	double g{ 1 };
	int t{ 0 };

	int item = -2;

	int Char_ani_count{ 0 };

	//현재 던져지는 중인지 아닌지 정의
	bool m_bThrow = false;

public:
	Devil();
	~Devil();

	void Set();
	void Reset();
	void Update();
	void Draw(HDC hDC);

	//던져졌을때 변수설정
	void Throw();
	void Move();


	/////////////////////Get
	int get_x() { return image.get_X(); }
	int get_y() { return image.get_Y(); }
	int get_x_vector() { return x_vector; }
	int get_y_vector() { return y_vector; }
	int get_item() { return item; }
	int get_width() { return image.get_Sprite_width(); }
	int get_height() { return image.get_Sprite_height(); }

	//////////////////////Set
	void move_x(int num) { image.move_x(num); }
	void move_y(int num) { image.move_y(num); }

	void set_degree(int num) { degree = num; }
	void set_power(int num) { power = num; }
	void set_Throw_true() { m_bThrow = true; }
	void set_Throw_false() { m_bThrow = false; }
	void set_ani_count_0() { Char_ani_count = 0; }
	void set_item(int num) { item = num; }
	void set_x_vector(int num) { x_vector = num; }
	void set_y_vector(int num) { y_vector = num; }
	void set_t(int num) { t = num; }

};

