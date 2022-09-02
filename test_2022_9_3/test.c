#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

//		所在的文件	→	test.c

void menu()
{
	printf("**********************\n");
	printf("******  1.play  ******\n");
	printf("******  0.over  ******\n");
	printf("**********************\n");

}
void game()
{
	//		所在的文件	→	test.c

	//	游戏的实现

	char mine[ROWS][COLS] = { 0 };	//	雷盘 1

	char show[ROWS][COLS] = { 0 };	//	雷盘 2

	//	初始化雷盘

	Init_board(mine, ROWS, COLS,'0');	//	雷盘 1

	Init_board(show, ROWS, COLS,'*');	//	雷盘 2

	//	打印雷盘

	//	show_board(mine, ROW, COL);

	//	布置雷

		set_mine(mine, ROW, COL);

		show_board(show, ROW, COL);

	//	show_board(show, ROW, COL);

	//	排查雷

	find_mine(mine, show, ROW, COL);
}



int main()
{

	int input = 0;

	srand((unsigned int)time(NULL));

	do
	{
		menu();
		printf("请选择 1 进入游戏  0 退出游戏 \n");
		scanf("%d", &input);

		switch(input)
		{
		case 1:
			game();
			printf("扫雷游戏\n");
			break;
		case 0:
			printf("退出游戏！\n");
			break;

		default :
			printf("输入错误,请重新选择!\n");
		}
	} while (input);

	return 0;
}