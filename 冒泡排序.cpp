#include <stdio.h>
int main()
{
	int L = 0;
	printf("请输入要判断几个数:");
	scanf("%d",&L);
	int arr[L];
	printf("请输入您要判断的数字,每两个数字之间那空格隔开:");
	for (int i = 0; i < L; i++)
	{
		scanf("%d", &arr[i]);
	}
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0;i <= sz - 1;i++)
	{
		for (int n = 0;n < sz - i - 1;n++)
		{
			if (arr[n] > arr[n + 1])
			{
				int a = arr[n];
				arr[n] = arr[n + 1];
				arr[n + 1] = a;
			}
		}
	}
	for (int i = 0; i < L-1; i++)
	{
		printf("%d < ", arr[i]);
	}
	printf("%d", arr[L-1]);
	return 0;
}
