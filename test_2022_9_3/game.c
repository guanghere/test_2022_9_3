#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

//		���ڵ��ļ�	��	game.c

//		��ʼ��

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


//		��ӡ

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


//		������

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
			mine[x][y] = '1';	//	������
			count--;
		}
	}	
}


int get_mine_count(char mine[ROWS][COLS], int x, int y)		//	����������Χ��8��λ��
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


//	�Ų���
void find_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	printf("������Ҫ�Ų������");
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
				printf("��Ϸ����,����ը��\n");
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
			printf("��������Ƿ�,����������\n");
		}
	}

	//	�ж��Ƿ�ɹ�
	if (win == row * col - EASY_COUNT)
	{
		printf("��ϲ��,ɨ�׳ɹ�!\n");
		show_board(mine, ROW, COL);

	}
}