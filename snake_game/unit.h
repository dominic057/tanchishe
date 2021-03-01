#pragma once
#include <Windows.h>
class unit
{
public:
	unit(int x = 0, int y = 0, char pic = '*');
	virtual ~unit();
	void show();
	void erase();
	static void colour(int c);
	static void gotoxy(int x, int y);
public:
	int m_x;
	int m_y;
	char m_pic;
};