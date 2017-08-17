
#pragma comment( lib, "msimg32.lib" )
#include "resource.h"

#ifndef ROLE_H
#define ROLE_H


class Role
{
private:
	int xl, yt;
	int width, height;
	int point;
	int life;
	
public:
	//enum{ l1=1, l2=2, l3=3, l4=4, l5=5, l6=6, r1=7, r2=8, r3=9, r4=10, d1=11, d2=12, d3=13, d4=14 }flag;
	int flag;
	bool down;
	Role();

	int getXl();
	int getYt();
	int setL();
	int setR();
	int setU();
	int setD();
	int setJ();

	int getWidth();
	int getHeight();

    int getflag();
	int getPoint();
	int getLife();
public:
	void drawl(int i);
	void drawr(int i);
	void drawd(int i);
	void drawRole();
};


#endif