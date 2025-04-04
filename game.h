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
//初始化扫雷图表，一个输出，一个方位
void InitBoard(char Board[ROWS][COLS], int rows, int cols, char set);

//打印扫雷图表
void DisInitBoard(char Disboard[ROWS][COLS],int row , int col);

//埋雷，设置雷的数量
#define COUNT 10
void Dismine(char board[ROWS][COLS], int row, int col);

//排查雷，并标注非雷区域周围雷的数量
void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

//需扩展内容
//1.假如猜到某个坐标是雷，可以输入字符坐标进行标记




