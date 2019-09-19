#include<stdio.h>
#include<stdlib.h>

int n;


void fl(int a[n][n])
{
  int p[n][n],d[n][n],i,j,k,l;
  for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
        {
          d[i][j]=a[i][j];
          if(d[i][j]==0 || d[i][j]==999)
            p[i][j]=-1;
          else
            p[i][j]=i;
        }
    }

  printf("\n\n");
  for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
        {
          for(k=0;k<n;k++)
            {
              if(d[j][k]>d[j][i]+d[i][k])
                {
                  d[j][k]=d[j][i]+d[i][k];
                  p[j][k]=p[i][k];
                }
            }
        }
    }
  printf("Distance matrix is\n");
  for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
        {
          printf("%d   ",d[i][j]);
        }
      printf("\n");
    }
  for(i=0;i<n;i++)
        {
                for(j=0;j<n;j++)
                {
                        if(p[i][j]!=-1)
                        {
                          k=i;
                          l=j;
                          printf("path from %d to %d with cost %d : ",i,j,d[k][l]);
                          printf("%d   ",i);
                          while(p[k][l]!=k && p[k][l]!=-1)
                          {
                                printf("%d   ",p[k][l]);
                                l=p[k][l];
                          }
                                printf("%d   ",j);
                                printf("\n");
                        }

                }
        }



}

void input()
{
  int a[n][n],i,j;
  printf ("Enter the graph values in the form of matrix\n");
  printf("Enter 999 if infinity value is there\n");
  for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
        {
          scanf("%d",&a[i][j]);
          if(a[i][j]<0)
            {
              printf("Negative cycle exists");
              exit (0);
            }
        }
    }
  printf("\n\n");
  printf("Initial graph is as follows\n");
  for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
        {
          printf("%d     ",a[i][j]);
        }
      printf("\n");
    }
  fl(a);
}

int main()
{
  printf("Enter nodes  in the graph : ");
  scanf("%d",&n);
  input();
}
