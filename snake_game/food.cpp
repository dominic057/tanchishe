#include "food.h"
#include "map.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

food::food()
{

}

food::~food()
{

}

void food::create_food()
{
	srand((int)time(0));//����ڵ�ͼ��Χ�ڲ���ʳ��
	m_x = rand() % (map::width - 30)+1;
	m_y = rand() % (map::height - 2)+1;
	gotoxy(m_x, m_y);
	unit::colour(12);//����ʳ��Ϊ��ɫ
	cout << m_pic << endl;
}
