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
	void print_gameinfo();//��ӡ������Ϣ
	void gameover(int score);
	void run_game();
public:
	static const int height = 40;//��ͼ�ߴ��40
	static const int width = 80;//��80
	int score;
};

