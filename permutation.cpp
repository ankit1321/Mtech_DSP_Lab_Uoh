#include<bits/stdc++.h>
using namespace std;


int duplicate(int arr[],int size)
{
        int duplicate=0;
        for(int i=0;i<size;i++)
        {
                for(int j=0;j<size;j++)
                {
                        if(i!=j && arr[i]==arr[j])
                        {
                                duplicate=1;
                        }
                }
        }
        return duplicate;
}
void printArray(int arr[],int size)
{
        static int c=1;
        if(duplicate(arr,size)==0)
        {
                cout<<c++<<" ";
                for(int i=0;i<size;i++)
                {
                        printf("%d ",arr[i]);
                }
                printf("\n");
        }
        return;
}
int getsuccessor(int arr[],int r,int n)
{
        int p=r-1;
        while(arr[p]==n)
                p--;
                if(p<0)
                {
                        return 0;
                }
                arr[p]=arr[p]+1;
                for(int i=p+1;i<r;i++)
                {
                        arr[i]=1;
                }
        return 1;
}
void permutation(int n,int r)
{
        int arr[100];
        for(int i=0;i<r;i++)
        {
                arr[i]=1;
        }
        while(1)
        {
                printArray(arr,r);
                if(getsuccessor(arr,r,n)==0)
                        break;
        }
        return ;
}

int main()
{
        int n,r;
        printf("Enter the value n and r\n");
        scanf("%d",&n);
        int arr[n];
        for(int i=0;i<n;i++)
        {
                arr[i]=i+1;
        }
        scanf("%d",&r);
        permutation(n,r);
}