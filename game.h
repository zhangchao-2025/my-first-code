#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
//��ʼ��ɨ��ͼ��һ�������һ����λ
void InitBoard(char Board[ROWS][COLS], int rows, int cols, char set);

//��ӡɨ��ͼ��
void DisInitBoard(char Disboard[ROWS][COLS],int row , int col);

//���ף������׵�����
#define COUNT 10
void Dismine(char board[ROWS][COLS], int row, int col);

//�Ų��ף�����ע����������Χ�׵�����
void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

//����չ����
//1.����µ�ĳ���������ף����������ַ�������б��




