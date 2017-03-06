#include "stdafx.h"
//#include "const.h"

#ifndef BOARD_H
#define BOARD_H


class Board{
private:
	int m_xl, m_yt, m_xr, m_yb;
public:
	Board(int xl, int yt);

	int getXl();
	int getYt();
	int getXr();
	int getYb();

	HDC & draw(HDC & memDC);

	int up();
};

#endif