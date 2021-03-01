#include "unit.h"
#include <Windows.h>
#include <iostream>
using namespace std;

unit::unit(int x, int y, char pic)//���캯����ֵ
{
	m_x = x;
	m_y = y;
	m_pic = pic;
}

unit::~unit()
{

}

void unit::show()//��ʾ���
{
	gotoxy(m_x, m_y);
	cout << m_pic << endl;
}

void unit::erase()//�������
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
	//HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ���
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position); //�ƶ����
}