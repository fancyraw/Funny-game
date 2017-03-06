/*******************************************
*	
*
*	Coptright (c)  2016, UESTC
*	All rights reserved.
*	
*	文件名：逗逼游戏
*   
*	当前版本：1.0
*	作者：张肖肖
*	创建日期：2016年11月2日
*
*
**********************************************/

// Win32Project.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "resource.h"
#include "drawManage.h"

#define MAX_LOADSTRING 100


// 全局变量:
SIZE g_tClient;
HINSTANCE g_hInst;								// 当前实例
HWND g_hWnd;
HDC  g_hdcMem;
TCHAR szTitle[MAX_LOADSTRING];					// 标题栏文本
TCHAR szWindowClass[MAX_LOADSTRING];			// 主窗口类名

// 此代码模块中包含的函数的前向声明: 
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	Help(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO:  在此放置代码。
	MSG msg;
	HACCEL hAccelTable;

	srand(time(NULL));

	// 初始化全局字符串
	LoadString(hInstance, IDS_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDS_STRING105, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 执行应用程序初始化: 
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDS_STRING105));

	// 主消息循环: 
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  函数:  MyRegisterClass()
//
//  目的:  注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
	wcex.hCursor = LoadCursor(hInstance, MAKEINTRESOURCE(IDC_CURSOR1));
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName = MAKEINTRESOURCE(IDC_WIN32PROJECT);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_ICON1));

	return RegisterClassEx(&wcex);
}

//
//   函数:  InitInstance(HINSTANCE, int)
//
//   目的:  保存实例句柄并创建主窗口
//
//   注释: 
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   g_hInst = hInstance; // 将实例句柄存储在全局变量中

   SIZE tScreen;
   tScreen.cx = (GetSystemMetrics(SM_CXSCREEN));
   tScreen.cy = (GetSystemMetrics(SM_CYSCREEN));

   g_hWnd = hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
	   tScreen.cx / 3, tScreen.cy / 6, WINDOW_WIDTH, WINDOW_HEIGHT, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  函数:  WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目的:    处理主窗口的消息。
//
//  WM_COMMAND	- 处理应用程序菜单
//  WM_PAINT	- 绘制主窗口
//  WM_DESTROY	- 发送退出消息并返回
//
//


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	HBITMAP hBitmap;
	UINT_PTR iTimerID;
	
	static DrawManage *pCDrawManage = new DrawManage;
    direc moveTo;

	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// 分析菜单选择: 
		switch (wmId)
		{
		case ID_MENU_BEGIN:
		{
							 /* delete pCDrawManage;
							  pCDrawManage = NULL;
							  pCDrawManage = new DrawManage;*/
							  pCDrawManage->rebegin();

		}
			
			break;
		case ID_HELP:
			DialogBox(g_hInst, MAKEINTRESOURCE(IDD_HELP), hWnd, Help);
			break;
		case ID_ABOUT:
			DialogBox(g_hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_CREATE :
		SetTimer(hWnd, 1, 100, NULL);
		return 0;
	case WM_SIZE:
		g_tClient.cx = LOWORD(lParam);
		g_tClient.cy = HIWORD(lParam);
		return 0;
	case WM_TIMER:
	{
			
		hdc = GetDC(hWnd);//获取设备指针

		g_hdcMem = CreateCompatibleDC(hdc); //建立内存设备内容
		hBitmap = CreateCompatibleBitmap(hdc, g_tClient.cx, g_tClient.cy);
		SelectObject(g_hdcMem, hBitmap);//将一个GDI位图对象选进内存设备内容
				
		pCDrawManage->drawAll();
				
		BitBlt(hdc, 0, 0, g_tClient.cx, g_tClient.cy, g_hdcMem, 0, 0, SRCCOPY);//从内存设备内容到显示区域设备内容

		DeleteObject(hBitmap);
		DeleteDC(g_hdcMem);
		ReleaseDC(hWnd, hdc);
					 					
			return 0;
	}
	case WM_CHAR:

		switch (wParam) {
		case 'a':
			moveTo = left;
			pCDrawManage->rolemove(moveTo);
			break;
		case 'd':
			moveTo = right;
			pCDrawManage->rolemove(moveTo);
			break;
		case 'w':
			moveTo = junmp;
			pCDrawManage->rolemove(moveTo);
			break;
		case 's':
			
			break;
		}
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO:  在此添加任意绘图代码...

		//SelectObject(hdc, hBrush = CreateHatchBrush(HS_CROSS, RGB(204,232,207)));
		//SelectObject(hdc, GetStockObject(NULL_PEN));
		//Rectangle(hdc, 0, 0, g_tClient.cx, g_tClient.cy);
		//DeleteObject(SelectObject(hdc, GetStockObject(BLACK_PEN)));


		/*SelectObject(hdcMem, hBrush = (HBRUSH)GetStockObject(BLACK_BRUSH));
		SelectObject(hdcMem, GetStockObject(NULL_PEN));
		Rectangle(hdcMem, 0, 0, rand() % g_tClient.cx, g_tClient.cy / 2);
		DeleteObject(SelectObject(hdcMem, GetStockObject(BLACK_PEN)));*/

		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		KillTimer(hWnd, 1);
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// “关于”框的消息处理程序。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
INT_PTR CALLBACK Help(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
