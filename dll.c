#include<stdio.h>
#include<stdlib.h>
typedef struct dll{
  int data;
  struct dll *next,*prev;
}dll;

dll *insert(dll *root)
{
  dll *temp2;
  dll *temp=malloc(sizeof(dll));
  int pos;
  printf("Enter the data to be inserted");
  scanf("%d",&temp->data);
  temp->prev=temp->next=NULL;
  if(root==NULL)
      root=temp;
  else
    {
      temp2=root;
      printf("Enter position u want to insert");
      scanf("%d",&pos);
      if(pos==0)
        {
          temp->next=temp2;
          temp2->prev=temp;
          return temp;
        }
      for(int i=1;i<pos;i++)
        temp2=temp2->next;
      if(temp2->next==NULL){
        temp2->next=temp;
        temp->prev=temp2;
        return root;
      }
      else
        {
          temp->next=temp2->next;
          temp2->next=temp;
          temp->prev=temp2;
          temp->next->prev=temp;
          return root;
        }


    }
  return root;
}


void display(dll *root)
{
  if(root==NULL)
    printf("List is empty\n");
  else
    {
      while(1)
        {
          printf("%d ->",root->data);
          if(root->next==NULL)
            {
              printf("\b\b  ");
              printf("\n");
              break;
            }
          root=root->next;
        }
    }
}


dll *delete(dll *root){
  int n;
  dll *temp,*tmp;
  display(root);
  printf("Enter the element u want to delete");
  scanf("%d",&n);
  if(n==root->data)
    {
      if(root->next==NULL && root->prev==NULL)
          {
            root=NULL;
            return root;
          }
      else
        {
      root=root->next;
      root->prev=NULL;
      return root;
      }
    }
  tmp=root;
  while(1)
    {
      if(n==tmp->data)
      {
        if(tmp->next==NULL && tmp->prev==NULL)
          {
            root=NULL;
            return root;
          }

        else if(tmp->next==NULL)
          {
            printf("Element %d deleted\n",tmp->data);
            temp=tmp;
            tmp=tmp->prev;
            tmp->next=NULL;
            temp->prev=NULL;
            free(temp);

            /*  while(1)
              {
                if(tmp->prev==NULL)
                  return tmp;
                else{
                  tmp=tmp->prev;
                }
                }*/
            return root;

          }
                else
          {
            printf("Element %d deleted\n",tmp->data);
            //tmp=temp;
            tmp->prev->next=tmp->next;
            tmp->next->prev=tmp->next;
            tmp->next=NULL;
            tmp->prev=NULL;
            free(tmp);
            return root;
            }
      }
      else if(tmp->next==NULL)
        {
          printf("Element not found\n");
          return root;
        }
      else
        tmp=tmp->next;
    }
}

dll *reverse(dll *root){
  dll *temp1=NULL,*temp2=NULL;

        temp1=root;

        while(temp1->next!=NULL)
                temp1=temp1->next;

        root=temp1;

        while(temp1!=NULL)
        {
                temp2=temp1->next;
                temp1->next=temp1->prev;
                temp1->prev=temp2;

                temp1=temp1->next;
        }

        display(root);
        return root;
}

void search(dll *root)
{
  int n;
  printf("Enter element u want to search");
  scanf("%d",&n);
  while(1)
    {
      if(root->data==n)
        {
          printf("Element Found\n");
          break;
        }
      else if(root->next==NULL)
        {
          printf("Element not found");
          break;
        }
        else
          root=root->next;
    }
}

int main()
{
  dll *root=NULL;
  int ch;
  printf("DLL OPerations\n");
  printf("1.Create\n2.Insert\n3.Delete\n4.Display\n5.Reverse\n6.search\n7.Exit\n");
  while(1)
    {
      printf("Enter ur choice");
      scanf("%d",&ch);
      switch(ch){
      case 1:printf("Enter no. of nodes u want to create in DLL");
        scanf("%d",&ch);
        for(int i=0;i<ch;i++)
          root=insert(root);
        break;
      case 2:root=insert(root);
        break;
      case 3:root=delete(root);
        break;
      case 4:display(root);
        break;
      case 5:root=reverse(root);
        break;
      case 6:search(root);
        break;
      case 7:exit(0);
      }
    }

}
