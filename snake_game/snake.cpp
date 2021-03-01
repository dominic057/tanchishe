#include <iostream>
#include <conio.h>
#include "snake.h"
#include "food.h"
#include "map.h"

snake::snake(int x , int y , int length, direction dir , int speed, char pic )
{
	CONSOLE_CURSOR_INFO cursor_info = { 1,0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);//隐藏光标
	m_hx = x;
	m_hy = y;
	lenth = length;
	m_dir = dir;
	m_speed = speed;
	m_Pic = pic;

	for (int i = 0; i < lenth; i++)
	{
		unit m_unit(0, 0, '@');
		m_b.push_back(m_unit);//初始化蛇
		switch (dir)
		{
		case UP:
			break;
		case DOWN:
			break;
		case LEFT:
			break;
		case RIGHT://设定初始方向向右移动
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
		unit::colour(6);//设置蛇为黄色
		m_b[i].show();
	}
}

void snake::erase_snake()
{
	m_lx = m_b[lenth - 1].m_x;//把蛇尾坐标保存下来
	m_ly = m_b[lenth - 1].m_y;
	unit::gotoxy(m_lx, m_ly);
	cout << " ";//覆盖蛇尾图形即可
}

void snake::move()
{
	show_snake();
	Sleep(m_speed);
	change_dir();//该函数在擦除函数之前 避免暂停游戏时蛇身少一个
	erase_snake();//擦除蛇尾
	for (int i =lenth-1; i>0; i--)
	{
		m_b[i].m_x = m_b[i-1].m_x; //每一个点的坐标等于它前一个点的坐标
		m_b[i].m_y = m_b[i-1].m_y;
	}
	switch (m_dir)//身体坐标移动完毕之后，蛇头根据用户键盘方向而改变
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
	if (_kbhit() != 0)//若检测到键盘输入
	{
		char in_put;
		while (!_kbhit() == 0)
		{
			in_put = _getch();
		}
		switch(in_put)
		{
		case 'w':
			if (m_dir != DOWN)//不能缩蛇头
				m_dir = UP;
			break;
		case 's':
			if (m_dir != UP)//不能缩蛇头
				m_dir = DOWN;
			break;
		case 'a':
			if (m_dir != RIGHT)//不能缩蛇头
				m_dir = LEFT;
			break;
		case 'd':
			if (m_dir != LEFT)//不能缩蛇头
				m_dir = RIGHT;
			break;
		case ' ':
			system("pause>nul");//消去暂停后控制台显示“按任意键继续”
			break;
		case 'q':
			int x = ::MessageBox(NULL, TEXT("真的要退出游戏吗？"), TEXT("操作提示"), 1);//弹出消息框询问
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
	if (m_b[0].m_x == f.m_x && m_b[0].m_y == f.m_y)//若蛇头坐标与食物坐标重合
	{
		f.erase();//擦除原有食物
		return true;
	}
	else
	{
		return FALSE;
	}
}

void snake::growup(food f)
{
	if (food_eaten(f))//若吃到食物
	{
		unit n_l;
		m_lx = m_b[lenth - 1].m_x;//把蛇尾坐标保存下来
		m_ly = m_b[lenth - 1].m_y;
		n_l.m_x = m_lx;
		n_l.m_y = m_ly;
		n_l.m_pic = '@';
		lenth++;//蛇身长度增加
		if (m_speed > 40)//速度不能太快 最大值为20
		{
			m_speed = m_speed * 0.85;//速度加快
		}
		m_b.push_back(n_l);//压入数组实现蛇身长大
	}
}

bool snake::game_over()
{
	bool is_gameover=false;
	if (m_b[0].m_x < 0||m_b[0].m_x == map::width - 29 || m_b[0].m_y < 0|| m_b[0].m_y == map::height)//蛇头坐标与边框重合
	{
		is_gameover = true;
	}
	for (int i = 1; i < lenth; i++)//判断是否碰到蛇身
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
	for (int i = 1; i < lenth; i++)//判断是否碰到蛇身
	{
		if (m_b[i].m_x == m_b[0].m_x && m_b[i].m_y == m_b[0].m_y)
		{
			is_gameover = true;
		}
	}
	return is_gameover;
}

void snake::mode_2()//穿墙模式
{
	//bool crash_wall;
	if (m_b[0].m_x == 0)//蛇头碰到左边框从右边框出现
		   {
			   m_b[0].m_x = map::width - 30;
		   }
	else if (m_b[0].m_x == map::width - 29)//蛇头碰到右边框从左边框出现
		   {
			   m_b[0].m_x = 1;
		   }
	else if (m_b[0].m_y == 0)//蛇头碰到上边框从下边框出现
		   {
			   m_b[0].m_y = map::height-2;
		   }
	else if (m_b[0].m_y == map::height-1)//蛇头碰到下边框从上边框出现
		   {
		m_b[0].m_y = 1;
		   }
}