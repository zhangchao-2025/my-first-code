#include "game.h"
void headline()
{
	printf("-------------------------------------\n");
	printf("-----������Ϸ->1    ������Ϸ->0------\n");
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
	DisInitBoard(mine, ROW, COL);			//��
	Findmine(mine, show, ROW, COL);
}
int main()
{
	srand((unsigned int)time(NULL));
	int num = 0;
	do
	{
		headline();
		printf("��ѡ��->");
		scanf("%d", &num);
		switch (num)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("������ֳ�����Χ������������\n");
		}
	} while (num);
	return 0;
}