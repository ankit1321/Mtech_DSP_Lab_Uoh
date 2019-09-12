#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int data;
  struct node *next;
}node;
node *head=NULL;

node* insert(int n1)
{
  node *t,*p;
  t=(node*)malloc(sizeof(node));
  t->data=n1;
  t->next=t;
  if(head==NULL)
    head=t;
  else
    {
      p=head;
      while(1)
        {
          if(p->next==head)
            {
              p->next=t;
              t->next=head;
              return head;
            }
          p=p->next;
        }
    }
  return head;
}

void display()
{
  node *p;
  p=head;
  while(1)
    {
      printf("%d -> ",p->data);
      if(p->next==head)
        {
          printf("Last node pointing to first node\n");
          break;
        }
      p=p->next;
    }
}

int jos(int n,int k)
{
	if(n==1)
		return 1;
	else
		return (jos(n-1)+k-1)%n+1;  
}

int main()
{
  int n,k,i;
  printf("Enter no. of people in circle: ");
  scanf("%d",&n);
  printf("Enter the value of k");
  scanf("%d",&k);
  k++;
  for(i=1;i<=n;i++)
    {
      head=insert(i);
    }
  display();
  printf("last man who survived is %d\n",jos(n,k));
  return 0;
}
