#pragma once

#include "Devil.h"

class Stage3
{
	///////////////////////////��

	MyImage map_back;

	RECT map_rect;
	RECT map_player_rect;
	RECT map_devil_rect;
	RECT map_manstion_rect;
	RECT map_object_rect[7];

	LONG map_devil_move_x{ 0 };
	LONG map_devil_move_y{ 0 };

	///////////////////////////��

	//���
	MyImage Background;
	MyImage m_Floor;
	MyImage m_Mansion;

	//ĳ����
	MyImage m_Player;
	MyImage m_Arrow;

	Devil m_Devil;

	//������ �� �ִ� ������
	MyImage m_Item[3];
	MyImage Select_Image;
	MyImage Item_UI;

	//�浹 �ؾ��ϴ� ������Ʈ
	MyImage m_Object[7];
	boolean Object_State[7] = { 0 };

	MyImage m_Heart;
	int Heart_Num = 11;

	int m_angle{ 0 };
	int m_power{ 100 };
	//��� �ӽ÷� ���� �ؽ�Ʈ
	WCHAR check_angle_str[100];
	WCHAR check_power_str[100];

	//������ �� üũ
	bool m_bAngle = false; //ù��° �����̽��� ����
	bool m_bPower = false; //�ι�° �����̽��� ����
	bool m_bThrow = false; //���ư�!
	bool m_down = false;

	bool m_bView = false;
	bool m_bThrow_finish = false;

	int Player_ani_count = 0;

public:
	Stage3();
	~Stage3();

	void Set();
	void Update();
	void Draw(HDC hDC);

	//ī�޶� �̵��մϴ�
	//��� - �ٿ��� �̵�
	void Camera_Move_X();
	void Camera_Move_Y();

	void Camera_Move_X(int num);
	void Camera_Move_Y(int num);

	//�ٽ� ���󺹱� ��Ű��
	void ReData();
	//�����
	void ReSet();

	void Mouse_Down(LPARAM lParam);
	void Mouse_Move(LPARAM lParam);
	void Keyboard_Down(WPARAM wParam);

	int Check_Game_End();
};

