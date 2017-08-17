#include "stdafx.h"

#ifndef CONST_H
#define CONST_H

//定义窗口大小
#define WINDOW_HEIGHT 640
#define WINDOW_WIDTH 480
#define MAX_BOARD 10

//全局变量
extern SIZE g_tClient;
extern HINSTANCE g_hInst;								// 当前实例
extern HWND g_hWnd;
extern HDC g_hdcMem;
enum direc{ left, right, junmp};

#endif