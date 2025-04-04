#include "game.h"
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < rows;i++)
	{
		for (j = 0;j < cols;j++)
		{
			board[i][j] = set;
		}
	}
}

void DisInitBoard(char Disboard[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("--------------------------扫雷-----------------------\n");
	for (j = 0;j <= col;j++)
	{
		printf("%d ", j);
	}
	printf("\n");
	for (i = 1;i <= row;i++)
	{
		printf("%d ", i);
		for (j = 1;j <= col;j++)
		{
			printf("%c ", Disboard[i][j]);
		}
		printf("\n");
	}
	printf("--------------------------扫雷-----------------------\n");
}

void Dismine(char board[ROWS][COLS], int row, int col)
{
	int count = COUNT;
	while (count)
	{
		int x = rand() % row+1;
		int y = rand() % col+1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}
void Expandmine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)  //假如选中的坐标周围八个都不是雷，将周围八个全部都标记上非雷，也就是'0'
{
	int count = 0;
if (mine[x][y] == '0')
{
	for (int i = -1;i < 2;i++)
	{
		for (int j = -1;j < 2;j++)
		{
			if (mine[x + i][y + j] == '0')
			{
				count++;
			}
		}
	}
	if (count == 9)
	{
		for (int i = -1;i < 2;i++)
		{
			for (int j = -1;j < 2;j++)
			{
				if (x + i >= 0 && x + i <= ROW + 1 && y + j >= 0 && y + j <= COL + 1 && show[x + i][y + j] == '*')
				{
					show[x + i][y + j] = '0';
				}
			}
		}
	}
}

}

int get_mine_counnt(char mine[ROWS][COLS], int x , int y)
{
	int count = 0;				
	for (int i = -1;i < 2;i++)
	{
		for (int j = -1;j < 2;j++)
		{
			if (mine[x+i][y+j] == '1')
			{
				count++;
			}
		}
	}
	return count;			//算周围有几个雷
}
void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int win = 0;	//找到非雷的数量
	int  decide = 1;  //判断内部循环是否需要进行
	int symbolmine = 0;							//计算标记的雷是否正确，当雷全部被排除，直接游戏胜利
	while (win < row * col - COUNT)
	{
		int z = 0;
		printf("请选择输入数字，解雷—>1，标记雷—>2,取消标记—>3,请选择——>");
		scanf("%d", &z);
		if (z == 1)								//去解雷
		{
			decide = 1;
			while (decide)
			{
				decide = 0;
				printf("请输入坐标->");
				int x = 0;
				int y = 0;
				scanf("%d%d", &x, &y);
				if (show[x][y] != '*')
				{
					printf("该坐标已被占用,请重新输入坐标\n");
					decide = 1;
				}
				else
				{
					if (x >= 1 && x <= row && y >= 1 && y <= col)
					{
						if (mine[x][y] == '1')			//如果是雷
						{
							printf("你被炸死了，可以重新开始游戏或退出\n");
							printf("下图为该局答案\n");
							DisInitBoard(mine, ROW, COL);
							goto again;							//直接跳出所有循环，结束本局游戏
						}
						else						//如果不是雷
						{							//去判断在输入坐标周围有几个雷
							win++;
							//Expandmine(mine, show, x, y);
							int count = get_mine_counnt(mine, x, y);
							show[x][y] = count + '0';
							DisInitBoard(show, ROW, COL);
						}
					}
					else
					{
						printf("输入坐标超出范围，请重新输入\n");
						decide = 1;
					}
				}
			}
		}
		else if (z == 2)								//去标记雷
		{
			decide = 1;
			while (decide)
			{
				decide = 0;
				printf("请输入需要标记的坐标->");
				int x = 0;
				int y = 0;
				scanf("%d%d", &x, &y);
				if (show[x][y] == '#')
				{
					printf("该地方已被标记，请重新选择\n");
					decide = 1;
				}
				else
				{
					if (x >= 1 && x <= row && y >= 1 && y <= col)
					{
						show[x][y] = '#';
						DisInitBoard(show, ROW, COL);
						if (mine[x][y] == '1')
						{
							symbolmine++;
						}
					}
					else
					{
						printf("输入坐标超出范围，请重新输入\n");
						decide = 1;
					}
				}
			}
			if (symbolmine == COUNT)
			{
				goto  victory;								//当全部排干净的时候，直接goto语句，跳转到胜利
			}
		}
		else if (z == 3)
		{
			decide = 1;
			while (decide)
			{
				decide = 0;
				printf("请输入需要取消标记的坐标->");
				int x = 0;
				int y = 0;
				scanf("%d%d", &x, &y);
				if (show[x][y] != '#')
				{
					printf("该区域未被标记，请重新输入\n");
					decide = 1;
				}
				else
				{
					show[x][y] = '*';
					DisInitBoard(show, ROW, COL);
				}
			}
		}
		else
		{
			printf("超出数字范围，请重新选择\n");
		}
		if (win == row * col - COUNT)				//将所有无雷区域排除干净
		{
			victory:
			printf("恭喜你排雷成功\n");
			printf("此为答案\n");
			DisInitBoard(mine, ROW, COL);
			break;
		}
	}
again:;
}
