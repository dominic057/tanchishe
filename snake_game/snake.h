#pragma once
#include "unit.h"
#include "food.h"
#include <vector>
using namespace std;

enum direction
{
	UP,DOWN,RIGHT,LEFT
};

class snake
{
public:
	snake(int x=20,int y=13,int length=4,direction dir= RIGHT,int speed=500,char pic= '*');
	~snake();
	void show_snake();
	void erase_snake();
	void move();
	void change_dir();
	void growup(food f);
	void mode_2();//穿墙模式
	bool food_eaten(food f);
	bool game_over();
	bool game_over2();//穿墙模式死亡规则
public:
	int m_hx;//蛇头坐标
	int m_hy;
	int m_lx;//蛇尾坐标
	int m_ly;
	int lenth;
	int m_speed;
	char m_Pic;
	direction m_dir;
	vector<unit> m_b;
};

