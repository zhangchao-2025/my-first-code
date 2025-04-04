#include "game.h"
void headline()
{
	printf("-------------------------------------\n");
	printf("-----继续游戏->1    结束游戏->0------\n");
	printf("-------------------------------------\n");
}
void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	DisInitBoard(show, ROW, COL);
	Dismine(mine, ROW, COL);
	DisInitBoard(mine, ROW, COL);			//答案
	Findmine(mine, show, ROW, COL);
}
int main()
{
	srand((unsigned int)time(NULL));
	int num = 0;
	do
	{
		headline();
		printf("请选择->");
		scanf("%d", &num);
		switch (num)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输出数字超出范围，请重新输入\n");
		}
	} while (num);
	return 0;
}