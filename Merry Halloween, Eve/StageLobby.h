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

	//�ϴ� Ȥ�ø� ������ ���� ����⸸ �ߴ�
	void Mouse_Down(LPARAM lParam);
	void Mouse_Move(LPARAM lParam);
	void Keyboard_Down(WPARAM wParam);

	//boolean -> int�� �ٲ�
	int Check_Button(int mx, int my);

	//��ư�� ���� ���� ũ�� �ٲߴϴ�.
	void All_button_ori_resize(); //��� ���󺹱�
	void State1_change_size(int width, int height);
	void State2_change_size(int width, int height);
	void State3_change_size(int width, int height);

	//�̰� ���� ������� �𸣰ڴ�. ����
	boolean Update_button1(int mx, int my);
	boolean Update_button2(int mx, int my);
	boolean Update_button3(int mx, int my);
};

