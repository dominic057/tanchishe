#include <iostream>
#include <conio.h>
#include "snake.h"
#include "food.h"
#include "map.h"

snake::snake(int x , int y , int length, direction dir , int speed, char pic )
{
	CONSOLE_CURSOR_INFO cursor_info = { 1,0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);//���ع��
	m_hx = x;
	m_hy = y;
	lenth = length;
	m_dir = dir;
	m_speed = speed;
	m_Pic = pic;

	for (int i = 0; i < lenth; i++)
	{
		unit m_unit(0, 0, '@');
		m_b.push_back(m_unit);//��ʼ����
		switch (dir)
		{
		case UP:
			break;
		case DOWN:
			break;
		case LEFT:
			break;
		case RIGHT://�趨��ʼ���������ƶ�
			m_b[i].m_x = m_hx - i;
			m_b[i].m_y = m_hy;
			break;
		default:
			break;
		}
	}
}

snake::~snake()
{

}

void snake::show_snake()
{
	for (int i = 0; i < lenth; i++)
	{
		unit::colour(6);//������Ϊ��ɫ
		m_b[i].show();
	}
}

void snake::erase_snake()
{
	m_lx = m_b[lenth - 1].m_x;//����β���걣������
	m_ly = m_b[lenth - 1].m_y;
	unit::gotoxy(m_lx, m_ly);
	cout << " ";//������βͼ�μ���
}

void snake::move()
{
	show_snake();
	Sleep(m_speed);
	change_dir();//�ú����ڲ�������֮ǰ ������ͣ��Ϸʱ������һ��
	erase_snake();//������β
	for (int i =lenth-1; i>0; i--)
	{
		m_b[i].m_x = m_b[i-1].m_x; //ÿһ��������������ǰһ���������
		m_b[i].m_y = m_b[i-1].m_y;
	}
	switch (m_dir)//���������ƶ����֮����ͷ�����û����̷�����ı�
	{
	case RIGHT:
		m_b[0].m_x++;;
		break;
	case LEFT:
		m_b[0].m_x--;;
		break;
	case UP:
		m_b[0].m_y--;
		break;
	case DOWN:
		m_b[0].m_y++;
		break;
	}
}

void snake::change_dir()
{
	if (_kbhit() != 0)//����⵽��������
	{
		char in_put;
		while (!_kbhit() == 0)
		{
			in_put = _getch();
		}
		switch(in_put)
		{
		case 'w':
			if (m_dir != DOWN)//��������ͷ
				m_dir = UP;
			break;
		case 's':
			if (m_dir != UP)//��������ͷ
				m_dir = DOWN;
			break;
		case 'a':
			if (m_dir != RIGHT)//��������ͷ
				m_dir = LEFT;
			break;
		case 'd':
			if (m_dir != LEFT)//��������ͷ
				m_dir = RIGHT;
			break;
		case ' ':
			system("pause>nul");//��ȥ��ͣ�����̨��ʾ���������������
			break;
		case 'q':
			int x = ::MessageBox(NULL, TEXT("���Ҫ�˳���Ϸ��"), TEXT("������ʾ"), 1);//������Ϣ��ѯ��
			if (x == 1)
			{
				exit(0);
			}
			break;
		}
	}
}

bool snake::food_eaten(food f)
{
	if (m_b[0].m_x == f.m_x && m_b[0].m_y == f.m_y)//����ͷ������ʳ�������غ�
	{
		f.erase();//����ԭ��ʳ��
		return true;
	}
	else
	{
		return FALSE;
	}
}

void snake::growup(food f)
{
	if (food_eaten(f))//���Ե�ʳ��
	{
		unit n_l;
		m_lx = m_b[lenth - 1].m_x;//����β���걣������
		m_ly = m_b[lenth - 1].m_y;
		n_l.m_x = m_lx;
		n_l.m_y = m_ly;
		n_l.m_pic = '@';
		lenth++;//����������
		if (m_speed > 40)//�ٶȲ���̫�� ���ֵΪ20
		{
			m_speed = m_speed * 0.85;//�ٶȼӿ�
		}
		m_b.push_back(n_l);//ѹ������ʵ��������
	}
}

bool snake::game_over()
{
	bool is_gameover=false;
	if (m_b[0].m_x < 0||m_b[0].m_x == map::width - 29 || m_b[0].m_y < 0|| m_b[0].m_y == map::height)//��ͷ������߿��غ�
	{
		is_gameover = true;
	}
	for (int i = 1; i < lenth; i++)//�ж��Ƿ���������
	{
		if (m_b[i].m_x == m_b[0].m_x && m_b[i].m_y == m_b[0].m_y)
		{
			is_gameover = true;
		}
	}
	return is_gameover;
}
bool snake::game_over2()
{
	bool is_gameover = false;
	for (int i = 1; i < lenth; i++)//�ж��Ƿ���������
	{
		if (m_b[i].m_x == m_b[0].m_x && m_b[i].m_y == m_b[0].m_y)
		{
			is_gameover = true;
		}
	}
	return is_gameover;
}

void snake::mode_2()//��ǽģʽ
{
	//bool crash_wall;
	if (m_b[0].m_x == 0)//��ͷ������߿���ұ߿����
		   {
			   m_b[0].m_x = map::width - 30;
		   }
	else if (m_b[0].m_x == map::width - 29)//��ͷ�����ұ߿����߿����
		   {
			   m_b[0].m_x = 1;
		   }
	else if (m_b[0].m_y == 0)//��ͷ�����ϱ߿���±߿����
		   {
			   m_b[0].m_y = map::height-2;
		   }
	else if (m_b[0].m_y == map::height-1)//��ͷ�����±߿���ϱ߿����
		   {
		m_b[0].m_y = 1;
		   }
}