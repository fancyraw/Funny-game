#include "stdafx.h"

#ifndef CONST_H
#define CONST_H

//���崰�ڴ�С
#define WINDOW_HEIGHT 640
#define WINDOW_WIDTH 480
#define MAX_BOARD 10

//ȫ�ֱ���
extern SIZE g_tClient;
extern HINSTANCE g_hInst;								// ��ǰʵ��
extern HWND g_hWnd;
extern HDC g_hdcMem;
enum direc{ left, right, junmp};

#endif