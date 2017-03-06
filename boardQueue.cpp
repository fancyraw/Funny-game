
#include "boardQueue.h"
#include "board.h"

BoardQueue::BoardQueue() :top(0), rear(0), count(0)
{ 
	max = MAX_BOARD; 
	/*for (int i = 0; i < count; i++)
	{
		arrBoard[(top + i) % max] = NULL;
	}*/
	//arrBoard = new Board *[MAX_BOARD];
}

BoardQueue::~BoardQueue()
{
	for (int i = 0; i < count; i++)\
	{
		delete arrBoard[(top + i) % max];
		arrBoard[(top + i) % max] = NULL;
	}

}
int BoardQueue::getCount(){
	return count;
}

int BoardQueue::getTop() {
	return top;
}

int BoardQueue::getMax() {
	return max;
}

int BoardQueue::empty() {
	return !count;
}
int BoardQueue::full(){
	return !(max - count);
}

bool BoardQueue::addBoard(Board *b){
	if (count < max)
	{
		arrBoard[rear] = b;
		rear = (rear + 1) % max;
		count++;
		//print(count);
		return true;
	}
	else return false;
}
bool BoardQueue::removeTopBoard() {
	if (count>0)
	{
		Board *tmpboard;
		for (int i = 0; i < getCount(); i++)
		{
			tmpboard = arrBoard[(getTop() + i) % getMax()];
			if (!empty() && tmpboard->up() == 0)
			{
				delete arrBoard[top];
				top = (top + 1) % max;
				count -= 1;
				return true;
			}
		}
	}
	else return false;
}
void BoardQueue::drawBoards(HDC & memDC)
{
	Board *tmpboard;
	for (int i = 0; i < getCount(); i++)
	{
		tmpboard = arrBoard[(getTop() + i) % getMax()];
		memDC = tmpboard->draw(memDC);
	}
	
}
void BoardQueue::boardsUp()
{
	Board *tmpboard;
	for (int i = 0; i < getCount(); i++)
	{
		tmpboard = arrBoard[(getTop() + i) % getMax()];
		tmpboard->up();
	}
}




