#include<stdio.h>
#include<stdlib.h>
int max(int a,int b)
{
    if(a>b)
    return a;
    else return b;
}
int main()
{
int n,m;
printf("Enter the no. of objects :");
scanf("%d",&n);
printf("Enter the and knapsack capacity:");
scanf("%d",&m);

int w[n+1],p[n+1];
w[0]=0;
p[0]=0;
int k[n+1][m+1];
printf("Enter the weights of the objects:\n");
for(int i=1;i<=n;i++)
scanf("%d",&w[i]);
printf("Enter the profit of the objects:\n");
for(int i=1;i<=n;i++)
scanf("%d",&p[i]);
for(int i=0;i<=n;i++)
{
for(int j=0;j<=m;j++)
{
if(i==0||j==0)
k[i][j]=0;
else if(w[i]<=j)
k[i][j]=max(p[i]+k[i-1][j-w[i]],k[i-1][j]);
else
k[i][j]=k[i-1][j];
}
}
printf("Optimal solution : %d",k[n][m]);
int i=n;
int j=m;
printf("\nThe objects included are represented with ' 1 ' \n");
while(i>0 && j>=0)
{
if(k[i][j]==k[i-1][j])
{
printf("%d =0\n",i);
i--;
}
else
{
printf("%d =1\n",i);
j=j-w[i];
i--;
}
}
return 0;
}

/* output
Enter the no. of objects and knapsack capacity
4 5
enter the weights of the objects
2 1 3 2
enter the profit of the objects
12 15 25 10            
Optimal solution :40
The objects included are represented with ' 1 '
4 = 0
3 = 1
2 = 1
1 = 0
*/
