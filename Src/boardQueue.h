#include "const.h"
//#include "board.h"

#ifndef BOARDQUEUE_H
#define BOARDQUEUE_H
class Board;

class BoardQueue{
private:
	
	int top;
	int rear;
	int max;
	int count;
public:
	Board *arrBoard[MAX_BOARD];
	BoardQueue();
	~BoardQueue();

	int getCount();

	int getTop();

	int getMax();

	int empty();

	int full();

	bool addBoard(Board *b);

	bool removeTopBoard();

	void drawBoards(HDC & memDC);

	void boardsUp();
};


#endif