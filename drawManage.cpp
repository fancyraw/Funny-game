
#include "drawManage.h"
#include "const.h"
#include "boardQueue.h"
#include "role.h"
#include "board.h"

//int randX()
//{
//	//srand((unsigned)time(NULL));
//	//return rand() % g_tClient.cx;
//	return (int)(g_tClient.cx - 0)*rand() / (RAND_MAX + 1.0);
//};
//int randCreate()
//{
//	//srand((unsigned)time(NULL));
//	return rand() % 10;
//}

DrawManage::DrawManage()
{
	pCBoardQueue = new BoardQueue();
	lastboard = NULL;
	pRole = new Role();
	
}
DrawManage::~DrawManage()
{
	delete pCBoardQueue;
	delete pRole;
	pCBoardQueue = NULL;
	pRole = NULL;
}

void DrawManage::drawAll()
{
	Board *tmpboard;
	WCHAR buf[100];
	WCHAR buf1[100];
		
	drawBackground();
	drawBoards();

	pRole->down = true;
	for (int i = 0; i < pCBoardQueue->getCount(); i++)
	{		
		tmpboard = pCBoardQueue->arrBoard[(pCBoardQueue->getTop() + i) % pCBoardQueue->getMax()];
		if (abs(tmpboard->getYt() - (pRole->getYt() + 35)) < 5)
		{
			if (tmpboard->getXl() < pRole->getXl() + 40 && tmpboard->getXr() > pRole->getXl())
			{
				pRole->down = false; 		
				break;
			}
		}
	}
	if (pRole->down == true)
		pRole->setD();
	else
		pRole->setU();
	pRole->drawRole();

	wsprintf(buf, L"分数： %d", pRole->getPoint());
	wsprintf(buf1, L"你的分数为：%d\n点击Menu重新开始", pRole->getPoint());
	TextOut(g_hdcMem, 10, 10, buf, lstrlen(buf));
	if (pRole->getYt() <= -50 || pRole->getYt() >= g_tClient.cy + 10)
	{
		KillTimer(g_hWnd, 1);
		MessageBox(g_hWnd, buf1, L"你输了", MB_OK);
	}
		
}
void DrawManage::drawBackground(){

Rectangle(g_hdcMem, 0, 0, g_tClient.cx, g_tClient.cy);
hPen = CreatePen(PS_SOLID, 1, RGB(255, 204, 153));
hBrush = CreateSolidBrush(RGB(235, 255, 255));
rt.left = 0;
rt.right = g_tClient.cx;
rt.top = 0;
rt.bottom = g_tClient.cy;
SelectObject(g_hdcMem, hBrush);
FillRect(g_hdcMem, &rt, NULL);
SelectObject(g_hdcMem, hPen);
for (int i = 0; i<g_tClient.cy; i += 15) {
	MoveToEx(g_hdcMem, 0, i, NULL);
	LineTo(g_hdcMem, g_tClient.cx, i);
}
for (int i = 0; i<g_tClient.cx; i += 15) {
	MoveToEx(g_hdcMem, i, 0, NULL);
	LineTo(g_hdcMem, i, g_tClient.cy);
}
DeleteObject(hBrush);
DeleteObject(hPen);



} 
void DrawManage::drawBoards()
{
	int tmpX, tmpY;
	Board *tmpboard;
	

	if (!pCBoardQueue->full())//&& randCreate() == 1)
	{
		tmpX = (g_tClient.cx - 0)*rand() / (RAND_MAX + 1.0);
	    tmpY = g_tClient.cy;
		 if (lastboard)
		 {
			 if (abs(lastboard->getXl() - tmpX)<100) {
				 tmpX = lastboard->getXl()>tmpX ? tmpX - 100 : tmpX + 100;
			 }
			 tmpY = lastboard->getYb() + 50 +(rand()%10)/10;
		 }
		 tmpboard = new Board(tmpX, tmpY);
		// print(123);
	 pCBoardQueue->addBoard(tmpboard);
	 lastboard = tmpboard;

	}
	pCBoardQueue->drawBoards(g_hdcMem);
	pCBoardQueue->boardsUp();
	pCBoardQueue->removeTopBoard();

}

void DrawManage::rolemove(direc moveTo)
{
	static  int l_flag = 1, r_flag = 1, d_flag = 1;
	
	switch (moveTo)
	{
	case left:
		//print(123);
		pRole->setL();
		if (pRole->down == true)
		{
			
			pRole->flag = d_flag++ % 4 + 11;
		}		
		else		
			 pRole->flag = l_flag++ % 6 + 1;
		break;
	case right:
		pRole->setR();
		if (pRole->down == true)
		{
			pRole->flag = d_flag++ % 4 + 11;
		}			 
		else	
			pRole->flag = r_flag++ % 4 + 7;
		break;
	case junmp:
		pRole->setJ();
		break;
	default: break;
	}
		
}

void DrawManage::rebegin()
{
	delete pCBoardQueue;
	delete pRole;
	pCBoardQueue = NULL;
	pRole = NULL;
	pCBoardQueue = new BoardQueue();
	pRole = new Role();
	lastboard = NULL;
	SetTimer(g_hWnd, 1, 100, NULL);
}