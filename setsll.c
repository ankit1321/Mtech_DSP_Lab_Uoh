#include<stdio.h>
#include<stdlib.h>



struct node
{
        int data;
        struct node *next;
};


void insert(struct node** href,int data)
{
        struct node *temp= (*href);

        if(!search(temp,data))

        {
                struct node *newnode = (struct node*)malloc(sizeof(struct node));
                newnode->data=data;
                newnode->next=(*href);
                (*href)=newnode;
        }
        else
                return;
}

int search(struct node *head, int data)
{
        struct node *t=head;
        while(t!=NULL)
        {
                if(t->data == data)
                        return 1;

          t=t->next;

        }
        return 0;
}


struct node* unin(struct node *h1,struct node *h2)
{
        struct node *uni=NULL;
        struct node *t1=h1;
        struct node *t2=h2;
        while(t1!=NULL)
        {
                insert(&uni,t1->data);
                t1=t1->next;
        }

        while(t2!=NULL)
        {
                if(!search(uni,t2->data))
                {       insert(&uni,t2->data);
                        t2=t2->next;
                }
                else
                        t2=t2->next;
        }
        return uni;
}

struct node* intersection(struct node *h1,struct node *h2)
{
        struct node *ints =NULL;
        struct node *t1=h1;
        struct node *t2=h2;

        while(t1!=NULL)
        {
                if(search(t2,t1->data))
                {
                        insert(&ints,t1->data);
                        t1=t1->next;

                }
                else
                        t1=t1->next;
        }
        return ints;
}

void delete(struct node *head,int data)
{
        struct node *temp=head;
        struct node *t=NULL;
        struct node *prev=NULL;
        while(search(head,data))
        {

                prev->next=temp->next;
                free(temp);

        }
        //else
        //{
                //printf("element to be deleted is not present.\n");
        //}

}

void printlist(struct node *head)
{
        struct node *t=head;
        if(t == NULL)
                return;
        while(t!=NULL)
        {
                printf("%d",t->data);

                t=t->next;
                if(t!=NULL)
                        printf("-->");
        }
        printf("\n");
}

void ordered(struct node *head)
{
        int flag,i;
        struct node *t1;
        struct node *t2=NULL;
        if(head==NULL)
                return;
        do{
                flag=0;
                t1=head;
                while(t1->next!=t2)
                {
                        if(t1->data > t1->next->data)
                        {
                                swap(t1,t1->next);
                                flag=1;
                        }
                        t1=t1->next;
                }

        }while(flag);
}

void swap(struct node *a,struct node *b)
{
        int temp= a->data;
        a->data=b->data;
        b->data=temp;
}


int main()
{
        struct node *list1=NULL;
        struct node *list2=NULL;
        struct node *uni=NULL;
        struct node *inter= NULL;
        int n1,n2,ele,i,item;
        printf("enter the number of elements you want to create in list1:\n");
        scanf("%d",&n1);
        printf("enter elements in list1:\n");
        for(i=1;i<=n1;i++)
        {
                scanf("%d",&ele);
                insert(&list1,ele);
        }

        printf("enter the number of elements you want to create in list2:\n");
        scanf("%d",&n2);
        printf("enter elements in list2:\n");
        for(i=1;i<=n2;i++)
        {
                scanf("%d",&ele);
                insert(&list2,ele);
        }
        printf("elements of list1 are: ");
        printlist(list1);
        printf("ordered set:\n");
        ordered(list1);
        printlist(list1);
        printf("\n");
        printf("elements of list2 are: ");
        printlist(list2);
        printf("ordered set:\n");
        ordered(list2);
        printlist(list2);
        printf("\n");
        //printf("delete element from list1: ");
        //scanf("%d",&item);
        //delete(list1,item);
        //printlist(list1);
        printf("union of lists is:\n");
        uni = unin(list1,list2);
        //printlist(uni);
        ordered(uni);
        printlist(uni);
                printf("intersection of lists is:\n");
        inter=intersection(list1,list2);
        //printlist(inter);
        ordered(inter);
        printlist(inter);

}


