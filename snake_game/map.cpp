#include <iostream>
#include <Windows.h>
#include <Mmsystem.h>
#pragma comment(lib,"winmm.lib")
#include <conio.h>
#include "map.h"
#include "food.h"
#include "snake.h"
using namespace std;

map::map()
{

}

map::~map()
{

}

void map::choose_mode()
{
	unit::gotoxy(width / 2 - 10, height / 2 - 7);
	cout<< "贪吃蛇游戏" << endl;
	unit::gotoxy(width / 2 - 10, height / 2 - 5);
	cout << "请选择模式：" << endl;
	unit::gotoxy(width / 2 - 10, height / 2 - 3);
	cout << "1.普通模式" << endl;
	unit::gotoxy(width / 2 - 10, height / 2 - 1);
	cout << "2.穿墙模式" << endl;
	system("pause>nul");
}

void map::print_map()
{
	system("cls");//清屏
	int i, j;
	for (i = 0; i < width; i++)
	{
		cout << "#";
	}
	cout << endl;
	for (i = 0; i < height - 2; i++)
	{
		for (j = 0; j < width; j++)
		{
			if (i == 13 && j >= width - 29)
			{
				cout << "#";
				continue;
			}
			if (j == 0 || j == width - 29 || j == width - 1)
			{
				cout << "#";
			}
			else
				cout << " ";
		}
		cout << endl;
	}
	for (i = 0; i < width; i++)
	{
		cout << "#";
	}
}

void map::print_score(int score)
{
	unit::gotoxy(width - 22 + 14, 6);
	cout << "  ";
	unit::gotoxy(width - 22 + 14, 4);
	cout << "  ";
	unit::gotoxy(width - 22, 7);
	unit::colour(7);
	cout << "当前玩家分数: " << score << endl;
}

void map::print_gameinfo()
{
	unit::gotoxy(width - 22, 18);
	cout << "贪吃蛇小游戏" << endl;
	unit::gotoxy(width - 22, 20);
	cout << "游戏操作说明：" << endl;
	unit::gotoxy(width - 22, 22);
	cout << "W: 上    S: 下" << endl;
	unit::gotoxy(width - 22, 24);
	cout << "A: 左    D: 右" << endl;
	unit::gotoxy(width - 22, 26);
	cout << "Q：退出游戏" << endl;
	unit::gotoxy(width - 22, 28);
	cout << "空格键：暂停游戏" << endl;
	unit::gotoxy(width - 22, 30);
	cout << "作者: 刘硕" << endl;
	unit::gotoxy(width - 22, 32);
	cout << "版本: 1.2" << endl;
}

void map::gameover(int score)
{
	unit::gotoxy(width / 2 - 20,height / 2 - 5);
	unit::colour(12);
	cout << "游戏结束！" << endl;
	unit::gotoxy(width / 2 - 20,height / 2 - 3);
	cout << "您的得分为：" << score << endl;
}

void map::run_game()
{
	food f;
	snake ss;
	char input_mode;
	choose_mode();
	PlaySound(TEXT("D:/录屏视频文件/按键音效.wav"), NULL, SND_FILENAME | SND_ASYNC);
	input_mode = _getch();
	print_map();
	score = 0;
	switch (input_mode)
	{
	case '1'://普通模式
		PlaySound(TEXT("D:/录屏视频文件/bgm.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);//循环播放bgm
		print_score(score);
		print_gameinfo();
		f.create_food();
		while (1)
		{
			ss.move();
			ss.growup(f);
			if (ss.food_eaten(f))
			{
				score = score + 10;
				print_score(score);
				f.create_food();//产生新食物
			}
			if (ss.game_over())//判断是否撞墙或碰到蛇身
			{
				PlaySound(TEXT("D:/录屏视频文件/死亡音效.wav"), NULL, SND_FILENAME | SND_ASYNC);
				gameover(score);
				system("pause>nul");//消去暂停后控制台显示“按任意键继续”
				exit(0);//退出游戏
			}
		}
		break;
	case '2'://穿墙模式
		PlaySound(TEXT("D:/录屏视频文件/bgm.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);//循环播放bgm
		print_score(score);
		print_gameinfo();
		f.create_food();
		while (1)
		{
			ss.move();
			ss.growup(f);
			if (ss.food_eaten(f))
			{
				score = score + 10;
				print_score(score);
				f.create_food();//产生新食物
			}
			ss.mode_2();
			if (ss.game_over2())//判断是否碰到蛇身
			{
				PlaySound(TEXT("D:/录屏视频文件/死亡音效.wav"), NULL, SND_FILENAME | SND_ASYNC);
				gameover(score);
				system("pause>nul");//消去暂停后控制台显示“按任意键继续”
				exit(0);//退出游戏
			}
		}
		break;
	}
}
