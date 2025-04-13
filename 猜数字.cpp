#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void player()
{
	int a = 0;
	int b = 100;
	int c = 0;
	int number = rand() % 100 + 1;
	int time=1;
	int guess = 0;
	printf("数字范围0-100\n");
	while(1)
	{
		againe:
		printf("请输入数字:");
		scanf("%d",&guess);
		if (guess > b || guess < a)
		{
			printf("超出范围，范围在%d-%d,请重新输入\n",a,b);
			goto againe;
		} 
		if (guess > number)
		{
			printf("(%d)猜的数字偏大了\n",time);
			time++;
			c = 1;
		}
		else if (guess < number)
		{
			printf("(%d)猜的数字偏小了\n",time);
			time++;
			c = 2;
		}
		else
		{
			printf("恭喜你猜对了，一共猜了%d次\n",time);
			break;
		}
		if (c == 1)
		{
			b = guess;
			printf("数字范围%d-%d\n",a,b);
		}
		if ( c == 2)
		{
			a = guess;
			printf("数字范围%d-%d\n",a,b);
		}
	}
}
int main()
{
	srand(time(NULL));
	int play = 0;
	do
	{
		printf("-----------------------------------------------\n");
		printf("------------ 开始 -> 1 , 结束 -> 0 ------------\n");
		printf("-----------------------------------------------\n");
		printf("请您选择是否继续游戏:");
		scanf("%d",&play);
		switch(play)
		{
			case 1:
				player();
				break;
			case 0:
				break; 
			default:
				printf("请重新输入，输入格式不对:\n");
		}
	}
	while(play);
	return 0;
 } 
