#include "Devil.h"

#define PI 3.14

Devil::Devil()
{
}


Devil::~Devil()
{
}

void Devil::Set()
{
	//�̹��� �ε�
	image.Set(L"�翪��_�ִϸ��̼�.png", 2);

	//���Ʒ� ��������Ʈ �̹��� ũ�� �ٸ��Ƿ� �������� ��������
	image.set_Sprite_height(150);
	image.set_Sprite_width(150);

	//�̹��� ��ġ����
	image.set_position(500, 620);
	t = 0;
	x_vector = 0;
	y_vector = 0;
	degree = 0;
	power = 0;
	item = -1;
}

void Devil::Reset()
{
	image.set_position(500, 620);

	image.set_Sprite_height(150);
	image.set_Sprite_width(150);
	image.set_Sprite_top(0);
	image.set_Sprite_left(0);

	t = 0;
	x_vector = 0;
	y_vector = 0;
	degree = 0;
	power = 0;
	item = -2;
	m_bThrow = false;
}

void Devil::Update()
{
	Char_ani_count += 1;

	if (!m_bThrow)
	{
		if (Char_ani_count > 12)
		{
			image.move_Sprite_left(image.get_Sprite_width());
			Char_ani_count = 0;
		}

		if (image.get_Sprite_left() > 150)
			image.set_Sprite_left(0);
	}
	else
	{
		//�ð� ����
		//t += 1;

		//�ִϸ��̼�
		if (Char_ani_count > 2)
		{
			image.move_Sprite_left(image.get_Sprite_width());
			Char_ani_count = 0;
		}

		if (image.get_Sprite_left() > 200)
		{
			image.set_Sprite_left(0);
		}

		Move();

		t += 1;
	}
	
}

void Devil::Draw(HDC hDC)
{
	image.Sprite_Draw(hDC);
}

void Devil::Throw()
{
	m_bThrow = true;

	//���ư��� �׸����� ����ϱ� ����
	image.set_Sprite_height(150);
	image.set_Sprite_width(200);
	image.set_Sprite_top(150);
	image.set_Sprite_left(0);

	Char_ani_count = 0;
}

void Devil::Move()
{
	x_vector = power * cos(degree * (PI / 180));
	//x += x_vector; ��ſ�..
	image.move_x(x_vector);

	y_vector = -power * sin(degree * (PI / 180)) + g * t;
	//y += y_vector; ��ſ�..
	image.move_y(y_vector);
	
}