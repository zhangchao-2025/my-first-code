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
	printf("���ַ�Χ0-100\n");
	while(1)
	{
		againe:
		printf("����������:");
		scanf("%d",&guess);
		if (guess > b || guess < a)
		{
			printf("������Χ����Χ��%d-%d,����������\n",a,b);
			goto againe;
		} 
		if (guess > number)
		{
			printf("(%d)�µ�����ƫ����\n",time);
			time++;
			c = 1;
		}
		else if (guess < number)
		{
			printf("(%d)�µ�����ƫС��\n",time);
			time++;
			c = 2;
		}
		else
		{
			printf("��ϲ��¶��ˣ�һ������%d��\n",time);
			break;
		}
		if (c == 1)
		{
			b = guess;
			printf("���ַ�Χ%d-%d\n",a,b);
		}
		if ( c == 2)
		{
			a = guess;
			printf("���ַ�Χ%d-%d\n",a,b);
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
		printf("------------ ��ʼ -> 1 , ���� -> 0 ------------\n");
		printf("-----------------------------------------------\n");
		printf("����ѡ���Ƿ������Ϸ:");
		scanf("%d",&play);
		switch(play)
		{
			case 1:
				player();
				break;
			case 0:
				break; 
			default:
				printf("���������룬�����ʽ����:\n");
		}
	}
	while(play);
	return 0;
 } 
