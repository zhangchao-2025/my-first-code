#include <stdio.h>
int main()
{
	int L = 0;
	printf("������Ҫ�жϼ�����:");
	scanf("%d",&L);
	int arr[L];
	printf("��������Ҫ�жϵ�����,ÿ��������֮���ǿո����:");
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
