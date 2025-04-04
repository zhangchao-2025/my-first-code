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
	printf("--------------------------ɨ��-----------------------\n");
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
	printf("--------------------------ɨ��-----------------------\n");
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
void Expandmine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)  //����ѡ�е�������Χ�˸��������ף�����Χ�˸�ȫ��������Ϸ��ף�Ҳ����'0'
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
	return count;			//����Χ�м�����
}
void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int win = 0;	//�ҵ����׵�����
	int  decide = 1;  //�ж��ڲ�ѭ���Ƿ���Ҫ����
	int symbolmine = 0;							//�����ǵ����Ƿ���ȷ������ȫ�����ų���ֱ����Ϸʤ��
	while (win < row * col - COUNT)
	{
		int z = 0;
		printf("��ѡ���������֣����ס�>1������ס�>2,ȡ����ǡ�>3,��ѡ�񡪡�>");
		scanf("%d", &z);
		if (z == 1)								//ȥ����
		{
			decide = 1;
			while (decide)
			{
				decide = 0;
				printf("����������->");
				int x = 0;
				int y = 0;
				scanf("%d%d", &x, &y);
				if (show[x][y] != '*')
				{
					printf("�������ѱ�ռ��,��������������\n");
					decide = 1;
				}
				else
				{
					if (x >= 1 && x <= row && y >= 1 && y <= col)
					{
						if (mine[x][y] == '1')			//�������
						{
							printf("�㱻ը���ˣ��������¿�ʼ��Ϸ���˳�\n");
							printf("��ͼΪ�þִ�\n");
							DisInitBoard(mine, ROW, COL);
							goto again;							//ֱ����������ѭ��������������Ϸ
						}
						else						//���������
						{							//ȥ�ж�������������Χ�м�����
							win++;
							//Expandmine(mine, show, x, y);
							int count = get_mine_counnt(mine, x, y);
							show[x][y] = count + '0';
							DisInitBoard(show, ROW, COL);
						}
					}
					else
					{
						printf("�������곬����Χ������������\n");
						decide = 1;
					}
				}
			}
		}
		else if (z == 2)								//ȥ�����
		{
			decide = 1;
			while (decide)
			{
				decide = 0;
				printf("��������Ҫ��ǵ�����->");
				int x = 0;
				int y = 0;
				scanf("%d%d", &x, &y);
				if (show[x][y] == '#')
				{
					printf("�õط��ѱ���ǣ�������ѡ��\n");
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
						printf("�������곬����Χ������������\n");
						decide = 1;
					}
				}
			}
			if (symbolmine == COUNT)
			{
				goto  victory;								//��ȫ���Ÿɾ���ʱ��ֱ��goto��䣬��ת��ʤ��
			}
		}
		else if (z == 3)
		{
			decide = 1;
			while (decide)
			{
				decide = 0;
				printf("��������Ҫȡ����ǵ�����->");
				int x = 0;
				int y = 0;
				scanf("%d%d", &x, &y);
				if (show[x][y] != '#')
				{
					printf("������δ����ǣ�����������\n");
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
			printf("�������ַ�Χ��������ѡ��\n");
		}
		if (win == row * col - COUNT)				//���������������ų��ɾ�
		{
			victory:
			printf("��ϲ�����׳ɹ�\n");
			printf("��Ϊ��\n");
			DisInitBoard(mine, ROW, COL);
			break;
		}
	}
again:;
}
