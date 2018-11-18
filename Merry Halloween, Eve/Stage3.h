#pragma once

#include "Devil.h"

class Stage3
{
	///////////////////////////맵

	MyImage map_back;

	RECT map_rect;
	RECT map_player_rect;
	RECT map_devil_rect;
	RECT map_manstion_rect;
	RECT map_object_rect[7];

	LONG map_devil_move_x{ 0 };
	LONG map_devil_move_y{ 0 };

	///////////////////////////맵

	//배경
	MyImage Background;
	MyImage m_Floor;
	MyImage m_Mansion;

	//캐릭터
	MyImage m_Player;
	MyImage m_Arrow;

	Devil m_Devil;

	//장착할 수 있는 아이템
	MyImage m_Item[3];
	MyImage Select_Image;
	MyImage Item_UI;

	//충돌 해야하는 오브젝트
	MyImage m_Object[7];
	boolean Object_State[7] = { 0 };

	MyImage m_Heart;
	int Heart_Num = 11;

	int m_angle{ 0 };
	int m_power{ 100 };
	//잠시 임시로 쓰일 텍스트
	WCHAR check_angle_str[100];
	WCHAR check_power_str[100];

	//던지는 것 체크
	bool m_bAngle = false; //첫번째 스페이스바 누름
	bool m_bPower = false; //두번째 스페이스바 누름
	bool m_bThrow = false; //날아감!
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

	//카메라 이동합니다
	//모두 - 붙여서 이동
	void Camera_Move_X();
	void Camera_Move_Y();

	void Camera_Move_X(int num);
	void Camera_Move_Y(int num);

	//다시 원상복귀 시키기
	void ReData();
	//재시작
	void ReSet();

	void Mouse_Down(LPARAM lParam);
	void Mouse_Move(LPARAM lParam);
	void Keyboard_Down(WPARAM wParam);

	int Check_Game_End();
};

