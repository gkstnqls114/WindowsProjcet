#pragma once

#include "StartMenu.h"
#include "StageLobby.h"
#include "Stage1.h"
#include "Stage2.h"
#include "Stage3.h"

#define WIDTH 1200
#define HEIGHT 800

#define START_MENU 0
#define STAGE_LOBBY 1
#define STAGE_1 101
#define STAGE_2 102
#define STAGE_3 103
#define GAME_OVER -1

class GameFrameWork
{
	int scene;
	StartMenu Start_Menu;
	StageLobby Stage_Lobby;
	Stage1 Stage_1;
	Stage2 Stage_2;
	Stage3 Stage_3;
	MyImage Game_Over;
	//Scene Stage[3];

public:
	GameFrameWork();
	~GameFrameWork();

	void Create();
	void Rander(HDC hDC);
	void Update();

	void Exit(HWND hWnd, LPARAM lParam);
	void Mouse_Down(LPARAM lParam);
	void Mouse_Move(LPARAM lParam);
	void Keyboard_Down(WPARAM wParam);

	void Destroy();

};

