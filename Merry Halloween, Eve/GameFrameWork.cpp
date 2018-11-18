#include "GameFrameWork.h"

GameFrameWork::GameFrameWork()
{
}


GameFrameWork::~GameFrameWork()
{
}

void GameFrameWork::Create()
{
	scene = START_MENU;
	Start_Menu.Set(L"StartMenu.png", L"게임시작.png", 10, 500);
	Game_Over.Set(L"게임오버.png");
	Game_Over.set_position(0, 0);
	Stage_Lobby.Set();
	Stage_1.Set();
	Stage_2.Set();
	Stage_3.Set();
}

void GameFrameWork::Update()
{
	switch (scene)
	{
	case START_MENU:
		Start_Menu.Update();

		break;
	case STAGE_LOBBY:
		Stage_Lobby.Update();
		
		break;
	case STAGE_1:
		Stage_1.Update();
		switch (Stage_1.Check_Game_End())
		{
			case 1: // Game clear
				scene = STAGE_LOBBY;
				break;
			case 2: // Game over
				scene = GAME_OVER;
				break;
		}
		break;
	case STAGE_2:
		Stage_2.Update();
		switch (Stage_2.Check_Game_End())
		{
		case 1: // Game clear
			scene = STAGE_LOBBY;
			break;
		case 2: // Game over
			scene = GAME_OVER;
			break;
		}
		break;
	case STAGE_3:
		Stage_3.Update();
		switch (Stage_3.Check_Game_End())
		{
		case 1: // Game clear
			scene = STAGE_LOBBY;
			break;
		case 2: // Game over
			scene = GAME_OVER;
			break;
		}
		break;
	}
}

void GameFrameWork::Rander(HDC hDC)
{
	switch (scene)
	{
	case START_MENU:
		Start_Menu.Draw(hDC);
		break;

	case STAGE_LOBBY:
		//Rectangle(hDC, 0, 0, 1200, 800);
		Stage_Lobby.Draw(hDC);
		break;

	case STAGE_1:
		Stage_1.Draw(hDC);
		break;

	case STAGE_2:
		Stage_2.Draw(hDC);
		break;

	case STAGE_3:
		Stage_3.Draw(hDC);
		break;

	case GAME_OVER:
		Game_Over.Draw(hDC);
		break;
	}
}

void GameFrameWork::Mouse_Down(LPARAM lParam)
{
	int mx = 1, my = -1;

	mx = LOWORD(lParam);
	my = HIWORD(lParam);

	//클릭하면 넘어갑니다.
	switch (scene)
	{
	case START_MENU:
		if (Start_Menu.Check_Button(mx, my) == 1)
		{
			//스테이지로비로
			scene = STAGE_LOBBY;
		}
		else if (Start_Menu.Check_Button(mx, my) == 2)
		{
			//게임 설명
		}
		else if (Start_Menu.Check_Button(mx, my) == 3)
		{
			//게임종료
			PostQuitMessage(0);
		}

		break;
	case STAGE_LOBBY:
		if (Stage_Lobby.Check_Button(mx, my) == 1)
		{
			scene = STAGE_1;
			Stage_1.ReSet();
		}
		if (Stage_Lobby.Check_Button(mx, my) == 2)
		{
			scene = STAGE_2;
			Stage_2.ReSet();
		}
		if (Stage_Lobby.Check_Button(mx, my) == 3)
		{
			scene = STAGE_3;
			Stage_3.ReSet();
		}

		break;
	case STAGE_1:
		Stage_1.Mouse_Down(lParam);
		break;
	case STAGE_2:
		Stage_2.Mouse_Down(lParam);
		break;
	case STAGE_3:
		Stage_3.Mouse_Down(lParam);
		break;
	case GAME_OVER:
		scene = STAGE_LOBBY;
		break;
	}
}

void GameFrameWork::Exit(HWND hWnd, LPARAM lParam)
{
	int mx = 1, my = -1;

	mx = LOWORD(lParam);
	my = HIWORD(lParam);

	switch (scene)
	{
	case START_MENU:
		if (Start_Menu.Check_Button(mx, my) == 3)
		{
			//게임종료
			DestroyWindow(hWnd);
		}

		break;
	}
}

void GameFrameWork::Mouse_Move(LPARAM lParam)
{
	int mx = 1, my = -1;

	mx = LOWORD(lParam);
	my = HIWORD(lParam);

	switch (scene)
	{
	case START_MENU:
		//원상복구
		Start_Menu.All_button_ori_resize();

		if (Start_Menu.Check_Button(mx, my) == 1)
		{
			Start_Menu.Start_chagne_size(490, 170);
		}
		else if (Start_Menu.Check_Button(mx, my) == 2)
		{
			Start_Menu.Explain_change_size(490, 170);
		}
		else if (Start_Menu.Check_Button(mx, my) == 3)
		{
			Start_Menu.End_change_size(490, 170);
		}


		break;
	case STAGE_LOBBY:
		Stage_Lobby.All_button_ori_resize();

		if (Stage_Lobby.Check_Button(mx, my) == 1)
		{
			Stage_Lobby.State1_change_size(320, 320);
		}

		if (Stage_Lobby.Check_Button(mx, my) == 2)
		{
			Stage_Lobby.State2_change_size(320, 320);
		}

		if (Stage_Lobby.Check_Button(mx, my) == 3)
		{
			Stage_Lobby.State3_change_size(320, 320);
		}

		break;
	case STAGE_1:
		Stage_1.Mouse_Move(lParam);
		break;
	case STAGE_2:
		Stage_2.Mouse_Move(lParam);
		break;
	case STAGE_3:
		Stage_3.Mouse_Move(lParam);
		break;
	}
}

void GameFrameWork::Keyboard_Down(WPARAM wParam)
{
	switch (scene)
	{
	case START_MENU:

		break;
	case STAGE_LOBBY:
		break;

	case STAGE_1:
		Stage_1.Keyboard_Down(wParam);
		break;

	case STAGE_2:
		Stage_2.Keyboard_Down(wParam);
		break;

	case STAGE_3:
		Stage_3.Keyboard_Down(wParam);
		break;

	case GAME_OVER:
		scene = STAGE_LOBBY;
		break;
	}
}

void GameFrameWork::Destroy()
{
	
}