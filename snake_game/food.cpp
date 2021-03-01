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
	srand((int)time(0));//随机在地图范围内产生食物
	m_x = rand() % (map::width - 30)+1;
	m_y = rand() % (map::height - 2)+1;
	gotoxy(m_x, m_y);
	unit::colour(12);//设置食物为红色
	cout << m_pic << endl;
}
