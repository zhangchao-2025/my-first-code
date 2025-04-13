#include <stdio.h>
int arr[20];
void num(int number)
{
	int i = 0;
	if (number != 0)
	{
		while (number >= arr[i])
		{
			i++;
		}
		i--;
		number = number - arr[i];
		printf("2");
		if (i != 1)
		{
			printf("(");
		}
		if (i == 0 || i == 2)
		{
			printf("%d)", i);
		}
		if (i >= 3)
		{
			num(i);
			printf(")");
		}
		if (number != 0)
		{
			printf("+");
			num(number);
		}
	}
	return;
}
int main()
{
	arr[0] = 1;
	for (int i = 0;i < 20;i++)
	{
		arr[i + 1] = arr[i] * 2;
	}
	int number = 0;
	scanf("%d", &number);
	num(number);
	return 0;
}
