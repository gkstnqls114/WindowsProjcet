#pragma once

#include "MyImage.h"
#include "Button.h"

class StageLobby
{
	MyImage image;

	MyImage Stage1_button;
	MyImage Stage2_button;
	MyImage Stage3_button;

public:
	StageLobby();
	~StageLobby();

	void Set();
	void Set(wstring Image_Name, wstring Button_Name1, wstring Button_Name2, wstring Button_Name3, int ix1, int iy1, int ix2, int iy2, int ix3, int iy3);
	void Update();
	void Draw(HDC hDC);

	//일단 혹시모를 나중을 위해 만들기만 했당
	void Mouse_Down(LPARAM lParam);
	void Mouse_Move(LPARAM lParam);
	void Keyboard_Down(WPARAM wParam);

	//boolean -> int로 바꿈
	int Check_Button(int mx, int my);

	//버튼의 가로 세로 크기 바꿉니당.
	void All_button_ori_resize(); //얘는 원상복구
	void State1_change_size(int width, int height);
	void State2_change_size(int width, int height);
	void State3_change_size(int width, int height);

	//이거 어찌 써야할지 모르겠다. 흑흑
	boolean Update_button1(int mx, int my);
	boolean Update_button2(int mx, int my);
	boolean Update_button3(int mx, int my);
};

