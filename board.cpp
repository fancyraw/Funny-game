
#include "board.h"


Board::Board(int xl, int yt) :m_xl(xl), m_yt(yt), m_xr(xl + 100), m_yb(yt + 10){};

int Board::getXl(){
	return m_xl;
}
int Board::getYt() {
	return m_yt;
}
int Board::getXr(){
	return m_xr;
}
int Board::getYb() {
	return m_yb;
}

HDC & Board::draw(HDC & memDC) {
	HBRUSH hBrush;
	HPEN bPen;
	hBrush = CreateHatchBrush(HS_BDIAGONAL, RGB(120, 220, 120));
	bPen = CreatePen(PS_INSIDEFRAME, 1, RGB(120, 120, 120));
	SelectObject(memDC, hBrush);
	SelectObject(memDC, bPen);
	RoundRect(memDC, m_xl, m_yt, m_xr, m_yb, 10, 10);



	DeleteObject(hBrush);
	DeleteObject(bPen);
	return memDC;
}

int Board::up() {
	if (m_yb>-5) {
		m_yb -= 1;
		m_yt -= 1;
		return 1;
	}
	else return 0;
}
