#include "Stage1.h"



Stage1::Stage1()
{
}


Stage1::~Stage1()
{

}

void Stage1::Set()
{
	//�̹��� �ε�
	Background.Set(L"�ӽ� ���.png");
	m_Player.Set(L"���� �ִϸ��̼� 1.png", 7);
	m_Arrow.Set(L"ȭ��ǥ.png");
	m_Mansion.Set(L"�Ǽ�.png");
	m_Floor.Set(L"�ܵ�.png");
	
	m_Item[0].Set(L"ȣ��.png");
	m_Item[1].Set(L"����.png");
	m_Item[2].Set(L"�ذ�.png");

	Select_Image.Set(L"����.png");
	Item_UI.Set(L"������.png");

	m_Object[0].Set(L"ȣ�ں�ũ.png");
	m_Object[1].Set(L"�����ũ.png");
	m_Object[2].Set(L"�ذ��ũ.png");

	m_Heart.Set(L"��Ʈ.png");

	//Devil class �ȿ� �̹� �ҷ��Ȱ� ���ÿ� ��ġ��������
	m_Devil.Set();
	
	m_Item[0].set_x(10);
	m_Item[0].set_y(10);
	m_Item[1].set_x(130);
	m_Item[1].set_y(10);
	m_Item[2].set_x(250);
	m_Item[2].set_y(10);
	
	m_Object[0].set_x(1800);
	m_Object[0].set_y(-100);
	m_Object[1].set_x(2000);
	m_Object[1].set_y(-200);
	m_Object[2].set_x(2200);
	m_Object[2].set_y(100);


	//ȸ�� �߽ɼ���
	m_Arrow.set_Rotate_center_x(50);
	m_Arrow.set_Rotate_center_y(550);

	//�̹��� ��ġ����
	//���̰� 1200 ���� 800
	Background.set_position(0, 800 - Background.getHeight());
	m_Player.set_position(50, 170);
	m_Arrow.set_position(550, 120);
	m_Mansion.set_position(2000, -400);
	m_Floor.set_position(0, 700);

	m_power = 100;

	///////////////////////////////////�ʶ����� ���μ�����

	map_back.Set(L"��.png");
	map_back.set_position(1200 - map_back.getWidth(), 0);
	
	//�� �ʱ���ġ
	map_rect.left = map_back.get_X();
	map_rect.right = map_back.get_X() + map_back.getWidth();
	map_rect.top = 0;
	map_rect.bottom = map_back.getHeight();

	//�� �� ĳ���� �ʱ���ġ
	map_player_rect.left = m_Player.get_X() / 10 + map_rect.left;
	map_player_rect.right = map_player_rect.left + m_Player.get_Sprite_width() /10;
	map_player_rect.top = m_Player.get_Y() / 10 + (map_rect.bottom - 80);
	map_player_rect.bottom = map_player_rect.top + m_Player.get_Sprite_height() / 10;
	
	//�Ǽ� �ʱ���ġ
	map_manstion_rect.left = m_Mansion.get_X() / 10 + map_rect.left;
	map_manstion_rect.right = map_manstion_rect.left + m_Mansion.getWidth() / 10;
	map_manstion_rect.top = map_rect.bottom - m_Mansion.getHeight() / 10;
	map_manstion_rect.bottom = map_rect.bottom;
	
	//�Ǹ� �ʱ�ȭ ��ġ
	map_devil_rect.left = m_Devil.get_x() / 10 + map_rect.left;
	map_devil_rect.right = map_devil_rect.left + m_Devil.get_width() / 10;
	map_devil_rect.top = m_Devil.get_y() / 10 + (map_rect.bottom - 80);
	map_devil_rect.bottom = map_devil_rect.top + m_Devil.get_height() / 10;

	//������Ʈ ��ġ
	map_object_rect[0].left = m_Object[0].get_X() / 10 + map_rect.left;
	map_object_rect[0].right = map_object_rect[0].left + (m_Object[0].getWidth() / 10);
	map_object_rect[0].top = map_rect.bottom - 80 + (m_Object[0].get_Y() / 10);
	map_object_rect[0].bottom = map_object_rect[0].top + (m_Object[0].getHeight() / 10);

	map_object_rect[1].left = m_Object[1].get_X() / 10 + map_rect.left;
	map_object_rect[1].right = map_object_rect[1].left + m_Object[1].getWidth() / 10;
	map_object_rect[1].top = map_rect.bottom - 80 +  (m_Object[1].get_Y() / 10);
	map_object_rect[1].bottom = map_object_rect[1].top + m_Object[1].getHeight() / 10;

	map_object_rect[2].left = m_Object[2].get_X() / 10 + map_rect.left;
	map_object_rect[2].right = map_object_rect[2].left + m_Object[2].getWidth() / 10;
	map_object_rect[2].top = map_rect.bottom - 80 +  m_Object[2].get_Y() / 10;
	map_object_rect[2].bottom = map_object_rect[2].top + m_Object[2].getHeight() / 10;


	///////////////////////////////////�ʶ����� ���μ�����\

}

void Stage1::Update()
{
	Player_ani_count += 1;

	if (!m_bAngle)
	{
		if (m_angle >= 80)
		{
			m_down = true;
		}
		else if (m_angle <= 10)
		{
			m_down = false;
		}

		if (!m_down)
		{
			m_angle += 1;
		}
		else
		{
			m_angle -= 1;
		}

		
		//ȸ���� �̹��� �����ְ� ȸ����Ű��
		m_Arrow.set_angle(m_angle);
		
		wsprintf(check_angle_str, L"����: %d", m_angle);
	}
	else if (!m_bPower)
	{
		if (m_power >= 100)
		{
			m_down = true;
		}
		else if (m_power <= 30)
		{
			m_down = false;
		}

		if (!m_down)
		{
			m_power += 1;
		}
		else
		{
			m_power -= 1;
		}

		//ũ����� ���ϱ�
		m_Arrow.set_proportion_x(double(m_power) / double(100));

		wsprintf(check_power_str, L"�Ŀ�: %d", m_power);
	}

	m_Arrow.Rotate();


	if (!m_bThrow)
	{
		//������ ��

		if (m_bPower)
		{
			//ĳ���� �ִϸ��̼� (�����̱�)
			if (Player_ani_count > 2)
			{
				m_Player.move_Sprite_left(m_Player.get_Sprite_width());
				Player_ani_count = 0;
			}

			//������ �����ְ� ������
			if (m_Player.get_Sprite_left() > 3000)
			{
				m_bThrow = true;
				m_Devil.Throw();
			}
			else if (m_Player.get_Sprite_left() > 3600)
			{
				m_Player.set_Sprite_left(0);
			}
		}
		else
		{
			//ĳ���� �ִϸ��̼� (���)
			if (Player_ani_count > 30)
			{
				m_Player.move_Sprite_left(m_Player.get_Sprite_width());
				Player_ani_count = 0;
			}

			if (m_Player.get_Sprite_left() > 600)
			{
				m_Player.set_Sprite_left(0);
			}
		}

	}


	m_Devil.Update();
	
	//�̴ϸ��̵�
	map_devil_move_x = LONG(m_Devil.get_x_vector()) / LONG(10);
	map_devil_rect.left += map_devil_move_x;
	map_devil_rect.right += map_devil_move_x;

	//�̴ϸ��̵�
	map_devil_move_y = LONG(m_Devil.get_y_vector()) / LONG(10);
	map_devil_rect.top += map_devil_move_y;
	map_devil_rect.bottom += map_devil_move_y;


	Camera_Move_X();
	Camera_Move_Y();

	//������ �浹üũ
	for (int i = 0; i < 3; i++)
	{
  		if (m_Object[i].Check(m_Devil.get_x() + m_Devil.get_width() / 2
			, m_Devil.get_y() + m_Devil.get_height() / 2)
			&& m_Devil.get_item() == i)
			Object_State[i] = 1;
		if (m_Object[i].Check(m_Devil.get_x()
			, m_Devil.get_y())
			&& m_Devil.get_item() == i)
			Object_State[i] = 1;
		if (m_Object[i].Check(m_Devil.get_x() + m_Devil.get_width()
			, m_Devil.get_y() + m_Devil.get_height())
			&& m_Devil.get_item() == i)
			Object_State[i] = 1;
	}

	//�翪�� �浹üũ
	if (m_Devil.get_y() + 150 > 800)
	{
		//�̴ϸ��̵�
		map_devil_move_x = double(m_Devil.get_x_vector()) / double(10);
		map_devil_rect.left += map_devil_move_x;
		map_devil_rect.right += map_devil_move_x;

		////�̴ϸ��̵�
		map_devil_move_y = double(m_Devil.get_y_vector()) / double(10);
		map_devil_rect.top += map_devil_move_y;
		map_devil_rect.bottom += map_devil_move_y;

		m_bThrow_finish = true;
		m_bThrow = false;

		//�Ǹ� �������� �ʰ�
		m_Devil.set_Throw_false();
		m_Devil.set_x_vector(0);
		m_Devil.set_y_vector(0);
		m_Devil.set_power(0);
		m_Devil.set_degree(0);
		m_Devil.set_t(0);
		//m_bThrow = false;
	}

	if (m_Devil.get_x() > 1200)
	{
		//�̴ϸ��̵�
		map_devil_move_x = double(m_Devil.get_x_vector()) / double(10);
		map_devil_rect.left += map_devil_move_x;
		map_devil_rect.right += map_devil_move_x;

		////�̴ϸ��̵�
		map_devil_move_y = double(m_Devil.get_y_vector()) / double(10);
		map_devil_rect.top += map_devil_move_y;
		map_devil_rect.bottom += map_devil_move_y;

		m_bThrow_finish = true;
		m_bThrow = false;


		//�Ǹ� �������� �ʰ�
		m_Devil.set_Throw_false();
		m_Devil.set_x_vector(0);
		m_Devil.set_y_vector(0);
		m_Devil.set_power(0);
		m_Devil.set_degree(0);
		m_Devil.set_t(0);
	}
}

void Stage1::Draw(HDC hDC)
{
	Background.Draw(hDC);
	m_Floor.Draw(hDC);
	m_Player.Sprite_Draw(hDC);

	if (!m_bPower && !m_bView)
	{
		m_Arrow.Rotate_Draw(hDC);
	}

	m_Mansion.Draw(hDC);
	m_Devil.Draw(hDC);

	
	///////////////////////////////////�ʶ����� ���μ�����
	
	if (!m_bView)
	{
		map_back.Draw(hDC);

		SelectObject(hDC, (HBRUSH)GetStockObject(GRAY_BRUSH));

		//�÷��̾�
		Rectangle(hDC, map_player_rect.left, map_player_rect.top
			, map_player_rect.right, map_player_rect.bottom);

		//�Ǽ�
		Rectangle(hDC, map_manstion_rect.left, map_manstion_rect.top
			, map_manstion_rect.right, map_manstion_rect.bottom);

		//�Ǹ�
		Rectangle(hDC, map_devil_rect.left, map_devil_rect.top
			, map_devil_rect.right, map_devil_rect.bottom);

		//������Ʈ
		for (int x = 0; x < 3; ++x)
		{
			if (!Object_State[x])
			{
				SelectObject(hDC, (HBRUSH)GetStockObject(WHITE_BRUSH));
			}
			else
			{
				SelectObject(hDC, (HBRUSH)GetStockObject(BLACK_BRUSH));
			}
			Rectangle(hDC, map_object_rect[x].left, map_object_rect[x].top
				, map_object_rect[x].right, map_object_rect[x].bottom);
		}


		FrameRect(hDC, &map_rect, (HBRUSH)GetStockObject(BLACK_BRUSH));
	}

	///////////////////////////////////�ʶ����� ���μ�����
	
	for (int i = 0; i < 3; i++)
	{
		if (!Object_State[i])
		{
			m_Object[i].Draw(hDC);
		}
		else
		{
			//if (!m_bView)
			//{
				m_Item[i].Draw(hDC, m_Object[i].get_X(), m_Object[i].get_Y());
			//}
		}
		if (!m_bView)
		{
			Item_UI.Draw(hDC, 120 * i, 0);
			m_Item[i].Draw(hDC);
		}
	}
	
	if (!m_bView)
	{
		//�ӽ÷� ������ ���� ���� Ȯ��
		Select_Image.Draw(hDC, 5 + m_Devil.get_item() * 120, 0);

		for (int i = Heart_Num; i > 0; i--)
			m_Heart.Draw(hDC, 1200 - 50 * i, 750);

	}
	
	TextOut(hDC, 0, 760, check_angle_str, wcslen(check_angle_str));
	TextOut(hDC, 0, 780, check_power_str, wcslen(check_power_str));
}

void Stage1::Camera_Move_X()
{
	//���⼭ 1200�� Ŭ���̾�Ʈ ����
	
	//����ó��
	//���� ��� ũ�� �Ѿ�� �������� �ʴ´�.
	if (Background.get_X() - m_Devil.get_x_vector()
		<= -Background.getWidth() + 1200)
		return;
		
	//�翪���� ȭ���� ��� ���̶�� ȭ�� �������� �ʴ´�.
	if (m_Devil.get_x() < 1200 / 2)
		return;
	

	//���ư��� ������ �ݴ�������� �̵��ؾ߹Ƿ� ���̳ʽ� �ٿ���
	Background.move_x(-m_Devil.get_x_vector());
	m_Player.move_x(-m_Devil.get_x_vector());
	m_Floor.move_x(-m_Devil.get_x_vector());
	m_Mansion.move_x(-m_Devil.get_x_vector());

	for (int i = 0; i < 3; i++)
		m_Object[i].move_x(-m_Devil.get_x_vector());

	m_Devil.move_x(-m_Devil.get_x_vector());

}

void Stage1::Camera_Move_Y()
{
	//���⼭ 800�� Ŭ���̾�Ʈ ����
	//����ó��

	// ����� �Ʒ��� �������� �������� �ʴ´�.
	if (Background.get_Y() - m_Devil.get_y_vector() > 0)
		return;

	if (Background.get_Y() - m_Devil.get_y_vector()
		<= -Background.getHeight() + 800)
		return;



	//���ư��� ������ �ݴ�������� �̵��ؾ߹Ƿ� ���̳ʽ� �ٿ���
	Background.move_y(-m_Devil.get_y_vector());
	m_Player.move_y(-m_Devil.get_y_vector());
	m_Floor.move_y(-m_Devil.get_y_vector());
	m_Mansion.move_y(-m_Devil.get_y_vector());

	for (int i = 0; i < 3; i++)
		m_Object[i].move_y(-m_Devil.get_y_vector());

	m_Devil.move_y(-m_Devil.get_y_vector());

}

void Stage1::Camera_Move_X(int num)
{
	//���⼭ 1200�� Ŭ���̾�Ʈ ����

	//����ó��
	//���� ��� ũ�� �Ѿ�� �������� �ʴ´�.
	if (Background.get_X() - num
		< -Background.getWidth() + 1200)
		return;


	if (Background.get_X() - num > 0)
		return;
	

	//���ư��� ������ �ݴ�������� �̵��ؾ߹Ƿ� ���̳ʽ� �ٿ���
	Background.move_x(-num);
	m_Player.move_x(-num);
	m_Floor.move_x(-num);
	m_Mansion.move_x(-num);

	for (int i = 0; i < 3; i++)
		m_Object[i].move_x(-num);

	m_Devil.move_x(-num);
}

void Stage1::Camera_Move_Y(int num)
{
	//���⼭ 800�� Ŭ���̾�Ʈ ����
	//����ó��

	// ����� �Ʒ��� �������� �������� �ʴ´�.
	if (Background.get_Y() - num > 0)
		return;

	if (Background.get_Y() - num
		< -Background.getHeight() + 800)
		return;



	//���ư��� ������ �ݴ�������� �̵��ؾ߹Ƿ� ���̳ʽ� �ٿ���
	Background.move_y(-num);
	m_Player.move_y(-num);
	m_Floor.move_y(-num);
	m_Mansion.move_y(-num);

	for (int i = 0; i < 3; i++)
		m_Object[i].move_y(-num);

	m_Devil.move_y(-num);
}

void Stage1::ReData()
{
	m_bAngle = false;
	m_bPower = false;
	m_bThrow = false;
	m_Devil.Reset();

	Background.set_position(0, 800 - Background.getHeight());
	m_Player.set_position(50, 170);
	m_Arrow.set_position(550, 120);
	m_Mansion.set_position(2000, -400);
	m_Floor.set_position(0, 700);

	m_Object[0].set_position(1800, -100);
	m_Object[1].set_position(2000, -200);
	m_Object[2].set_position(2200, 100);


	//�Ǹ� �ʱ�ȭ ��ġ
	map_devil_rect.left = m_Devil.get_x() / 10 + map_rect.left;
	map_devil_rect.right = map_devil_rect.left + m_Devil.get_width() / 10;
	map_devil_rect.top = m_Devil.get_y() / 10 + (map_rect.bottom - 80);
	map_devil_rect.bottom = map_devil_rect.top + m_Devil.get_height() / 10;
	//Heart_Num--;
}

void Stage1::Mouse_Down(LPARAM lParam)
{
	if (m_bView) return;
	if (m_bThrow) return;

	int mx = 1, my = -1;

	mx = LOWORD(lParam);
	my = HIWORD(lParam);


	for (int i = 0; i < 3; i++)
		if (m_Item[i].Check(mx, my))
			m_Devil.set_item(i);
}

void Stage1::Mouse_Move(LPARAM lParam)
{

	if (m_bView) return;
	if (m_bThrow) return;

	int mx = 1, my = -1;

	mx = LOWORD(lParam);
	my = HIWORD(lParam);

	for (int i = 0; i < 3; i++)
	{
		m_Item[i].oriWidth();
		m_Item[i].oriHeight();
	}

	for (int i = 0; i < 3; i++)
	{
		if (m_Item[i].Check(mx, my))
		{
			m_Item[i].setWidth(120);
			m_Item[i].setHeight(120);
		}
	}
}

void Stage1::Keyboard_Down(WPARAM wParam)
{
	switch (wParam)
	{
	case VK_SPACE:
		if (m_bView) break;
		//�ϴ� �����̽� ������ ���ư��°ɷ�~!!
		if (!m_bAngle)
		{
 			m_bAngle = true;
			m_Devil.set_degree(m_angle);
			m_down = false;
			break;
		}

		if (!m_bPower)
		{
			m_bPower = true;
 			m_Devil.set_power(m_power);
			m_Player.set_Sprite_left(0);
			m_down = false;
			break;
		}
		
		if (m_bThrow_finish)
		{
			ReData();
			m_bThrow_finish = false;
			//�������ϴ�
			Heart_Num--;
		}
		break;

	case VK_ESCAPE:
		//��� ��ġ ���½�Ų��.
		//ReData();

		break;

	case VK_RIGHT:
		if (!m_bView) break;
		
		Camera_Move_X(100);
		break;

	case VK_LEFT:
		if (!m_bView) break;
		Camera_Move_X(-100);
		break;

	case VK_DOWN:
		if (!m_bView) break;
		Camera_Move_Y(100);
		break;

	case VK_UP:
		if (!m_bView) break;
		Camera_Move_Y(-100);
		break;

	case VK_F1:
		if (m_bThrow) break;
		if (m_bAngle) break;
		if (m_bPower) break;

		if (m_bView)
		{
			m_bView = false;
			ReData();
		}
		else
		{
			m_bView = true;
		}
		break;
	}
}

void Stage1::ReSet()
{
	ReData();

	Heart_Num = 7;
	for (int i = 0; i < 3; i++)
		Object_State[i] = 0;

}

int Stage1::Check_Game_End()
{
	if (Heart_Num == 0)
		return 2;
	else if (Object_State[0] == 1 && Object_State[1] == 1 && Object_State[2] == 1)
		return 1;
}
