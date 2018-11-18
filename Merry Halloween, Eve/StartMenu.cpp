#include "StartMenu.h"



StartMenu::StartMenu()
{
}

StartMenu::~StartMenu()
{
}

void StartMenu::Set(wstring Image_Name, wstring Button_Name, int ix, int iy)
{
	image.Set(Image_Name);
	
	//그림 로드합니다.
	Start_button.Set(Button_Name);

	//어차피 고정된 그림이므로 변수 추가 안하고 직접 작성~~
	//Explain_button.Set(L"게임설명.png");
	End_button.Set(L"게임종료.png");

	//버튼의 위치 지정
	Start_button.set_position(20, 500);
	//Explain_button.set_position(20, 500);
	End_button.set_position(20, 650);
	
}

void StartMenu::Draw(HDC hDC)
{
	image.Draw(hDC);
	Start_button.Draw(hDC);
	//Explain_button.Draw(hDC);
	End_button.Draw(hDC);
}

void StartMenu::Update()
{
}

void StartMenu::All_button_ori_resize()
{
	Start_button.oriHeight();
	Start_button.oriWidth();

	//Explain_button.oriHeight();
	//Explain_button.oriWidth();

	End_button.oriHeight();
	End_button.oriWidth();
}

int StartMenu::Check_Button(int mx, int my)
{
	if (Start_button.Check(mx, my))
	{
		return 1;
	}
	else if (/*Explain_button.Check(mx, my)*/false)
	{
		return 2;
	}
	else if (End_button.Check(mx, my))
	{
		return 3;
	}
	else
	{
		return 0;
	}

}
