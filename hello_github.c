#include <stdio.h>
int main()
{
    int n,k,i,s=0;//周n开始游，过了k天，游了s公里
    scanf("%d %d",&n,&k);
    for (i=1;i<=k;i++)//要游k天，所以用循环
    {
        if(n!=6 && n!=7) s+=250;//如果不是周末则加250
        if(n==7) n=1;//如果是周7，那么赋值为1
        else n++;//否则n+1
    }
    printf("%d",s);//输出游了多少公里
    return 0;
}
