#pragma once
#include "food.h"
#include "snake.h"
class map
{
public:
	map();
	~map();
	void choose_mode();
	void print_map();
	void print_score(int score);
	void print_gameinfo();//打印操作信息
	void gameover(int score);
	void run_game();
public:
	static const int height = 40;//地图尺寸高40
	static const int width = 80;//宽80
	int score;
};

