#include "stdafx.h"
#include "const.h"

#ifndef DRAWMANAGE_H
#define DRAWMANAGE_H

class BoardQueue;
class Role;
class Board;
extern direc moveTo;

class DrawManage
{
private:
    BoardQueue *pCBoardQueue;
	Role *pRole;
	Board *lastboard;
private:
	HBRUSH hBrush;
	HPEN hPen;
	RECT rt;
private:
	void drawBackground();
	void drawBoards();
public:
	DrawManage();
	~DrawManage();
	
	void drawAll();
	void rolemove(direc moveTo);
	void rebegin();
};

#endif