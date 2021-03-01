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
	cout<< "̰������Ϸ" << endl;
	unit::gotoxy(width / 2 - 10, height / 2 - 5);
	cout << "��ѡ��ģʽ��" << endl;
	unit::gotoxy(width / 2 - 10, height / 2 - 3);
	cout << "1.��ͨģʽ" << endl;
	unit::gotoxy(width / 2 - 10, height / 2 - 1);
	cout << "2.��ǽģʽ" << endl;
	system("pause>nul");
}

void map::print_map()
{
	system("cls");//����
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
	cout << "��ǰ��ҷ���: " << score << endl;
}

void map::print_gameinfo()
{
	unit::gotoxy(width - 22, 18);
	cout << "̰����С��Ϸ" << endl;
	unit::gotoxy(width - 22, 20);
	cout << "��Ϸ����˵����" << endl;
	unit::gotoxy(width - 22, 22);
	cout << "W: ��    S: ��" << endl;
	unit::gotoxy(width - 22, 24);
	cout << "A: ��    D: ��" << endl;
	unit::gotoxy(width - 22, 26);
	cout << "Q���˳���Ϸ" << endl;
	unit::gotoxy(width - 22, 28);
	cout << "�ո������ͣ��Ϸ" << endl;
	unit::gotoxy(width - 22, 30);
	cout << "����: ��˶" << endl;
	unit::gotoxy(width - 22, 32);
	cout << "�汾: 1.2" << endl;
}

void map::gameover(int score)
{
	unit::gotoxy(width / 2 - 20,height / 2 - 5);
	unit::colour(12);
	cout << "��Ϸ������" << endl;
	unit::gotoxy(width / 2 - 20,height / 2 - 3);
	cout << "���ĵ÷�Ϊ��" << score << endl;
}

void map::run_game()
{
	food f;
	snake ss;
	char input_mode;
	choose_mode();
	PlaySound(TEXT("D:/¼����Ƶ�ļ�/������Ч.wav"), NULL, SND_FILENAME | SND_ASYNC);
	input_mode = _getch();
	print_map();
	score = 0;
	switch (input_mode)
	{
	case '1'://��ͨģʽ
		PlaySound(TEXT("D:/¼����Ƶ�ļ�/bgm.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);//ѭ������bgm
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
				f.create_food();//������ʳ��
			}
			if (ss.game_over())//�ж��Ƿ�ײǽ����������
			{
				PlaySound(TEXT("D:/¼����Ƶ�ļ�/������Ч.wav"), NULL, SND_FILENAME | SND_ASYNC);
				gameover(score);
				system("pause>nul");//��ȥ��ͣ�����̨��ʾ���������������
				exit(0);//�˳���Ϸ
			}
		}
		break;
	case '2'://��ǽģʽ
		PlaySound(TEXT("D:/¼����Ƶ�ļ�/bgm.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);//ѭ������bgm
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
				f.create_food();//������ʳ��
			}
			ss.mode_2();
			if (ss.game_over2())//�ж��Ƿ���������
			{
				PlaySound(TEXT("D:/¼����Ƶ�ļ�/������Ч.wav"), NULL, SND_FILENAME | SND_ASYNC);
				gameover(score);
				system("pause>nul");//��ȥ��ͣ�����̨��ʾ���������������
				exit(0);//�˳���Ϸ
			}
		}
		break;
	}
}
