#pragma once

#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include<time.h>

//		���ڵ��ļ�	��	game.h

#define ROW 9

#define COL 9

#define ROWS ROW+2

#define COLS COL+2

#define EASY_COUNT 10

//		��ʼ��

void Init_board(char arr[ROWS][COLS], int rows, int cols,char set);

//		��ӡ

void show_board(char arr[ROWS][COLS], int row, int col);

//		������

void set_mine(char mine[ROWS][COLS], int row, int col);

//		�Ų���

void find_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);