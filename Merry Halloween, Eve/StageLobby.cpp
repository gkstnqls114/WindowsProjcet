#include "StageLobby.h"



StageLobby::StageLobby()
{
}


StageLobby::~StageLobby()
{
}

void StageLobby::Set()
{
	//그림 로드
	image.Set(L"스테이지 로비.png");
	Stage1_button.Set(L"1스테이지.png");
	Stage2_button.Set(L"2스테이지.png");
	Stage3_button.Set(L"3스테이지.png");
	//그림 위치 지정
	image.set_position(0, 0);
	Stage1_button.set_position(10, 400);
	Stage2_button.set_position(400, 400);
	Stage3_button.set_position(800, 400);
}

void StageLobby::Set(wstring Image_Name, wstring Button_Name1, wstring Button_Name2, wstring Button_Name3, int ix1, int iy1, int ix2, int iy2, int ix3, int iy3)
{
	//image.Set(Image_Name);

}

void StageLobby::Update()
{
}

void StageLobby::Draw(HDC hDC)
{
	image.Draw(hDC);
	Stage1_button.Draw(hDC);
	Stage2_button.Draw(hDC);
	Stage3_button.Draw(hDC);
}

void StageLobby::Mouse_Down(LPARAM lParam)
{

}

void StageLobby::Mouse_Move(LPARAM lParam)
{

}

void StageLobby::Keyboard_Down(WPARAM wParam)
{

}

void StageLobby::All_button_ori_resize()
{
	Stage1_button.oriHeight();
	Stage1_button.oriWidth();

	Stage2_button.oriHeight();
	Stage2_button.oriWidth();

	Stage3_button.oriHeight();
	Stage3_button.oriWidth();
}

int StageLobby::Check_Button(int mx, int my)
{
	if (Stage1_button.Check(mx, my))
	{
		return 1;
	}
	else if (Stage2_button.Check(mx, my))
	{
		return 2;
	}
	else if (Stage3_button.Check(mx, my))
	{
		return 3;
	}
	else
	{
		return 0;
	}
}

void StageLobby::State1_change_size(int width, int height)
{
	Stage1_button.setWidth(width);
	Stage1_button.setHeight(height);
}

void StageLobby::State2_change_size(int width, int height)
{
	Stage2_button.setWidth(width);
	Stage2_button.setHeight(height);
}

void StageLobby::State3_change_size(int width, int height)
{
	Stage3_button.setWidth(width);
	Stage3_button.setHeight(height);
}

boolean StageLobby::Update_button1(int mx, int my)
{
	return false;
}

boolean StageLobby::Update_button2(int mx, int my)
{

	return false;
}

boolean StageLobby::Update_button3(int mx, int my)
{
	return false;
}
