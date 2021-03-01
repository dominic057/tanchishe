#include "unit.h"
#include <Windows.h>
#include <iostream>
using namespace std;

unit::unit(int x, int y, char pic)//构造函数赋值
{
	m_x = x;
	m_y = y;
	m_pic = pic;
}

unit::~unit()
{

}

void unit::show()//显示光标
{
	gotoxy(m_x, m_y);
	cout << m_pic << endl;
}

void unit::erase()//擦除光标
{
	gotoxy(m_x, m_y);
	m_pic = ' ';
	cout << m_pic << endl;
}

void unit::colour(int x)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, x);
}

void unit::gotoxy(int x, int y)
{
	COORD position = { x,y };
	//HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); //获取句柄
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position); //移动光标
}