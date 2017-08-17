#include "stdafx.h"
#include "role.h"
#include "const.h"

Role::Role() :xl(WINDOW_WIDTH / 2), yt(0), width(40), height(40){
	life = 1;
	point = 0;
	flag = 11;
	down = true;
}

int Role::getXl() {
	return xl;
}
int Role::getYt() {
	return yt;
}
int Role::setL() {
	if (xl >= 0)
	xl -= 5;	
	return xl;
}

int Role::setR() {
	if (xl <= g_tClient.cx -40)
	xl += 5;
	return xl;
}
int Role::setU() {
	yt -= 2;
	return yt;
}
int Role::setD() {
	point++;
	yt += 5;
	return yt;
}
int Role::setJ() {
	if (!down)
	{
		point++;
        yt -= 35;
	}
	return yt;
}
int Role::getWidth() {
	return width;
}
int Role::getHeight(){
	return height;
}


int Role::getLife(){
	return life;
}
int Role::getPoint(){
	return point;
}


void Role::drawl(int i)
{
	HBITMAP tmpBitmap = NULL;
	HDC hdcMem = CreateCompatibleDC(g_hdcMem);
	switch (i)
	{
	case 1:   tmpBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAPl1)); break;
	case 2:   tmpBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAPl2)); break;
	case 3:   tmpBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAPl3)); break;
	case 4:   tmpBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAPl4)); break;
	case 5:   tmpBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAPl5)); break;
	case 6:   tmpBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAPl6)); break;
	default: break;
	}
	SelectObject(hdcMem, tmpBitmap);
	// BitBlt(hdc, 50, 50, 120, 120, memDC, 0 ,0 ,SRCCOPY);
	TransparentBlt(g_hdcMem, xl, yt, 40, 40, hdcMem, 0, 0, width, height, RGB(0, 0, 255));
	//SelectObject(hdc, tmpBitmap);
	DeleteObject(tmpBitmap);
	DeleteDC(hdcMem);
}
void Role::drawr(int i)
{
	HBITMAP tmpBitmap = NULL;
	HDC hdcMem = CreateCompatibleDC(g_hdcMem);
	switch (i)
	{
	case 1:   tmpBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAPr1)); break;
	case 2:   tmpBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAPr2)); break;
	case 3:   tmpBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAPr3)); break;
	case 4:   tmpBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAPr4)); break;
	default: break;
	}
	SelectObject(hdcMem, tmpBitmap);
	// BitBlt(hdc, 50, 50, 120, 120, memDC, 0 ,0 ,SRCCOPY);
	TransparentBlt(g_hdcMem, xl, yt, 40, 40, hdcMem, 0, 0, width, height, RGB(0, 0, 255));
	//SelectObject(hdc, tmpBitmap);
	DeleteObject(tmpBitmap);
	DeleteDC(hdcMem);
}
void Role::drawd(int i)
{
	HBITMAP tmpBitmap = NULL;
	HDC hdcMem = CreateCompatibleDC(g_hdcMem);
	switch (i)
	{
	case 1:   tmpBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAPd1)); break;
	case 2:   tmpBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAPd2)); break;
	case 3:   tmpBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAPd3)); break;
	case 4:   tmpBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAPd4)); break;
	default: break;
	}
	SelectObject(hdcMem, tmpBitmap);
	// BitBlt(hdc, 50, 50, 120, 120, memDC, 0 ,0 ,SRCCOPY);
	TransparentBlt(g_hdcMem, xl, yt, 40, 40, hdcMem, 0, 0, width, height, RGB(0, 0, 255));
	//SelectObject(hdc, tmpBitmap);
	DeleteObject(tmpBitmap);
	DeleteDC(hdcMem);
}


void Role::drawRole()
{
	switch (flag)
	{
	case 1: drawl(1);  break;
	case 2: drawl(2);  break;
	case 3: drawl(3);  break;
	case 4: drawl(4);  break;
	case 5: drawl(5);  break;
	case 6: drawl(6);  break;

	case 7: drawr(1);  break;
	case 8: drawr(2);  break;
	case 9: drawr(3);  break;
	case 10: drawr(4); break;

	case 11: drawd(1);  break;
	case 12: drawd(2);  break;
	case 13: drawd(3);  break;
	case 14: drawd(4);  break;
	default:break;
	}

}