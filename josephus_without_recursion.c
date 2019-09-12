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
  node *t1,*t2;
  int j;
  t1=head;
  t2=NULL;
  while(t1!=t2)
    {
      // if(k==1)
      //return n;
      for(j=0;j<k;j++)
        {
          t2=t1;
          t1=t1->next;
        }
      t2->next=t1->next;
      t1->next=NULL;
      free(t1);
      t1=t2->next;
    }
  return t2->data;
}

int main()
{
  int n,k,i;
  printf("Enter no. of people in circle: ");
  scanf("%d",&n);
  printf("Enter the value of k");
  scanf("%d",&k);
  for(i=1;i<=n;i++)
    {
      head=insert(i);
    }
  display();
  printf("last man who survived is %d\n",jos(n,k));
  return 0;
}
