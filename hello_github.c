#include <stdio.h>
int main()
{
    int n,k,i,s=0;//��n��ʼ�Σ�����k�죬����s����
    scanf("%d %d",&n,&k);
    for (i=1;i<=k;i++)//Ҫ��k�죬������ѭ��
    {
        if(n!=6 && n!=7) s+=250;//���������ĩ���250
        if(n==7) n=1;//�������7����ô��ֵΪ1
        else n++;//����n+1
    }
    printf("%d",s);//������˶��ٹ���
    return 0;
}
