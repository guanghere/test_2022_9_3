#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

//		���ڵ��ļ�	��	test.c

void menu()
{
	printf("**********************\n");
	printf("******  1.play  ******\n");
	printf("******  0.over  ******\n");
	printf("**********************\n");

}
void game()
{
	//		���ڵ��ļ�	��	test.c

	//	��Ϸ��ʵ��

	char mine[ROWS][COLS] = { 0 };	//	���� 1

	char show[ROWS][COLS] = { 0 };	//	���� 2

	//	��ʼ������

	Init_board(mine, ROWS, COLS,'0');	//	���� 1

	Init_board(show, ROWS, COLS,'*');	//	���� 2

	//	��ӡ����

	//	show_board(mine, ROW, COL);

	//	������

		set_mine(mine, ROW, COL);

		show_board(show, ROW, COL);

	//	show_board(show, ROW, COL);

	//	�Ų���

	find_mine(mine, show, ROW, COL);
}



int main()
{

	int input = 0;

	srand((unsigned int)time(NULL));

	do
	{
		menu();
		printf("��ѡ�� 1 ������Ϸ  0 �˳���Ϸ \n");
		scanf("%d", &input);

		switch(input)
		{
		case 1:
			game();
			printf("ɨ����Ϸ\n");
			break;
		case 0:
			printf("�˳���Ϸ��\n");
			break;

		default :
			printf("�������,������ѡ��!\n");
		}
	} while (input);

	return 0;
}