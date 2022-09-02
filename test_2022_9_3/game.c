#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

//		所在的文件	→	game.c

//		初始化

void Init_board(char arr[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			arr[i][j] = set;
		}
	}
}


//		打印

void show_board(char arr[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	int a = 0;
	for (a = 0; a <= col; a++)
	{
		printf("%d ", a);
	}
	printf("\n");

	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%C ", arr[i][j]);
		}
		printf("\n");
	}
}


//		布置雷

void set_mine(char mine[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;

	int x = 0;
	int y = 0;

	while (count)
	{
		x = rand() % row + 1;
		y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';	//	布置雷
			count--;
		}
	}	
}


int get_mine_count(char mine[ROWS][COLS], int x, int y)		//	遍历坐标周围的8个位置
{
	return
		mine[x - 1][y] +
			mine[x - 1][y - 1] +
				mine[x][y - 1] +
					mine[x + 1][y - 1] +
						mine[x + 1][y] +
							mine[x + 2][y + 1] +
								mine[x][y + 1] +
									mine[x - 1][y + 1] -
														8 * '0';
}


//	排查雷
void find_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	printf("请输入要排查的坐标");
	int x = 0;
	int y = 0;
	int win = 0;

	while (win<row*col-EASY_COUNT)
	{
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("游戏结束,被雷炸死\n");
				show_board(mine, ROW, COL);
				break;
			}
			else
			{
				int count = get_mine_count(mine, x, y);
				show[x][y] = count + '0';
					show_board(show, ROW, COL);
					win++;
			}
		}
		else
		{
			printf("输入坐标非法,请重新输入\n");
		}
	}

	//	判断是否成功
	if (win == row * col - EASY_COUNT)
	{
		printf("恭喜你,扫雷成功!\n");
		show_board(mine, ROW, COL);

	}
}
