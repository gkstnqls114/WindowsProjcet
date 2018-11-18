#include "GameFrameWork.h"

HINSTANCE g_hinst;
LPCTSTR lpszClass = L"Window Class Name"; //유니코드 L 추가
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

GameFrameWork gameFrameWork;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdshow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASSEX WndClass;
	g_hinst = hInstance;
	WndClass.cbSize = sizeof(WndClass);
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	WndClass.lpfnWndProc = (WNDPROC)WndProc;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hInstance = hInstance;
	WndClass.hIcon = LoadCursor(NULL, IDI_APPLICATION);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.lpszMenuName = NULL;
	WndClass.lpszClassName = lpszClass;
	WndClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	RegisterClassEx(&WndClass);
	hWnd = CreateWindow(lpszClass, L"WinPro", WS_OVERLAPPEDWINDOW, 0, 0, WIDTH + 16, HEIGHT + 39, NULL, (HMENU)NULL, hInstance, NULL);
	//유니코드 L 추가
	ShowWindow(hWnd, nCmdshow);
	UpdateWindow(hWnd);
	while (GetMessage(&Message, 0, 0, 0))
	{
		//영태센빠이가 peek이 더 좋다고 함 근데 언젠가 수정...
		//PeekMessage(&Message, hWnd, )

		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hDC, hMemDC, hImageDC;
	HBITMAP hBitmap, oldBitmap;
	RECT rect;

	switch (iMessage)
	{
	case WM_CREATE:
		gameFrameWork.Create();
		SetTimer(hWnd, 1, 17, NULL);
		break;

	case WM_TIMER:
		gameFrameWork.Update();
		InvalidateRect(hWnd, NULL, FALSE);	
		break;

	case WM_PAINT:
		hDC = BeginPaint(hWnd, &ps);
		GetClientRect(hWnd, &rect);
		hMemDC = CreateCompatibleDC(hDC);
		hBitmap = CreateCompatibleBitmap(hDC, rect.right, rect.bottom);
		oldBitmap = (HBITMAP)SelectObject(hMemDC, hBitmap);
		FillRect(hMemDC, &rect, (HBRUSH)GetStockObject(WHITE_BRUSH));

		gameFrameWork.Rander(hMemDC);

		BitBlt(hDC, 0, 0, rect.right, rect.bottom, hMemDC, 0, 0, SRCCOPY);
		SelectObject(hMemDC, oldBitmap);
		DeleteObject(SelectObject(hMemDC, oldBitmap));
		DeleteObject(hBitmap);
		DeleteDC(hMemDC);
		EndPaint(hWnd, &ps);

		break;

	case WM_LBUTTONDOWN:
		gameFrameWork.Mouse_Down(lParam);

		//종료어떻게 할지 몰라서 일단 이렇게 해놓았다!
		gameFrameWork.Exit(hWnd, lParam);

		//InvalidateRect(hWnd, NULL, FALSE);
		break;

	case WM_MOUSEMOVE:
		gameFrameWork.Mouse_Move(lParam);
		break;

	case WM_KEYDOWN:
		gameFrameWork.Keyboard_Down(wParam);
		break;

	case WM_DESTROY:
		gameFrameWork.Destroy();
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}