#include<stdio.h>
#include<stdlib.h>
int parent[30];

int find(int i)
{
while (parent[i]!=i)
       i = parent[i];
return i;
}
void unionv(int i, int j)
{
int a = find(i);
int b = find(j);
    parent[a] = b;
}
void kruskals(int a[][30], int n)
{
int mincost = 0,c = 0,i,j;
for(i=0;i<n;i++)
        parent[i] = i;
while(c<n-1)
{
       int min = 10000,it = -1,jt = -1;
       for(i=0;i<n;i++)
{
        for(j=0;j<n;j++)
{
               if(find(i)!=find(j) && a[i][j]<min)
{
                    min = a[i][j];
                    it = i;                                                                
                    jt = j;
                }
            }
        }
  unionv(it,jt);
c++;
        printf("( %d ,%d)\t %d \n",it+1,jt+1,min);
        mincost += min;
    }
    printf("\nMinimum cost = %d",mincost);
}
int main()
{
int a[30][30],n,i,j;
printf("Enter the number of vertices\n");
scanf("%d",&n);
printf("Enter the weight matrix of the graph (Enter 9999 for infinity(i.e. if there is no edge))\n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
scanf("%d",&a[i][j]);
}
printf("\nThe Minimum Spanning Tree is :\n");
printf("Edges\tWeight\n");
kruskals(a,n);
return 0;
} 
