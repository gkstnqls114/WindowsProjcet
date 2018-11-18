#pragma once

#include "MyImage.h"
#include "Button.h"

class StartMenu
{
	MyImage image; //배경이미지

	MyImage Start_button; //게임시작
	//MyImage Explain_button; //게임설명
	MyImage End_button; //게임종료

public:
	StartMenu();
	~StartMenu();

	void Set(wstring Image_Name, wstring Button_Name, int ix, int iy);
	void Draw(HDC hDC);
	void Update();


	//버튼 사이즈 조정
	void All_button_ori_resize();
	
	void Start_chagne_size(int change_width, int change_height)
	{
		Start_button.setWidth(change_width);
		Start_button.setHeight(change_height);
	}
	void Explain_change_size(int change_width, int change_height)
	{
	//	Explain_button.setWidth(change_width);
		//Explain_button.setHeight(change_height);
	}
	void End_change_size(int change_width, int change_height)
	{
		End_button.setWidth(change_width);
		End_button.setHeight(change_height);
	}

	//boolean -> int로 반환값 수정
	int Check_Button(int mx, int my);
};

