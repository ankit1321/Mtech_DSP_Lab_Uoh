#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

int max(int value1,int value2)
{
	return ((value1>value2)?value1:value2);
}

class BSTnode
{
	public:
		int data;
		BSTnode *left,*right;
		BSTnode(int x)
		{
			data=x;
			left=right=NULL;
		}
};

class BST
{
	BSTnode *root;
	BSTnode *delet1(BSTnode *T,int);
	void inorder1(BSTnode *T);
	void preorder1(BSTnode *T);
	void postorder1(BSTnode *T);
	int height1(BSTnode *T);
	int print0(BSTnode *T);
	void display1(BSTnode *t,int level);

	public:
		BST()
		{
			root=NULL;
		}
		BSTnode *find(int x);
		void insert(int x);
		void delet(int x)
		{
			root=delet1(root,x);
		}
		void create();
		void inorder()
		{
			inorder1(root);
		}
		void preorder()
		{
			preorder1(root);
		}
		void postorder()
		{
			postorder1(root);
		}
		void non_rec_inorder();
		void non_rec_preorder();
		void non_rec_postorder();
		int height()
		{
			return(height1(root));
		}
		int print_leaf_nodes()
		{
			return(print0(root));
		}
		void level_wise();
		void display()
		{
		    display1(root,1);
		}
    };


class stack
{
	BSTnode *data[30];
	int top;

	public:
		stack()
		{
			top=-1;
		}
		int empty()
		{
			if(top==-1)
				return 1;
			return 0;
		}
		void push(BSTnode *p)
		{
			data[++top]=p;
		}
		BSTnode *pop()
		{
			return(data[top--]);
		}
};

class Q
{
	BSTnode *data[30];
	int R,F;

	public:
		Q()
		{
			R=F=-1;
		}
		void init()
		{
			R=F=-1;
		}
		int empty()
		{
			if(R==-1)
				return 1;
			return 0;
		}
		void insert(BSTnode *p)
		{
			if(empty())
				R=F=0;
			else
				R=R+1;
			data[R]=p;
		}
		BSTnode *Delete()
		{
			BSTnode *p=data[F];
			if(R==F)
				R=F=-1;
			else
				F=F+1;
			return(p);
		}
};
BSTnode *BST::delet1(BSTnode *T,int x)
{
	BSTnode *temp;
	if(T==NULL)
	{
		cout<<"\nElement not found:";
		return(T);
	}
	if(x<T->data)
	{
		T->left=delet1(T->left,x);
		return(T) ;
	}
	if(x>T->data)
	{
		T->right=delet1(T->right,x);
		return(T);
	}
	if(T->left==NULL && T->right==NULL)
	{
		temp=T;
		delete temp;
		return(NULL);
	}
	if(T->left==NULL)
	{
		temp=T;
		T=T->right;
		delete temp;
		return(T);
	}
	if(T->right==NULL)
	{
		temp=T;
		T=T->left;
		delete temp;
		return(T);
	}
	temp=T->right;
	while(temp->left!=NULL)
		temp=temp->left;
	T->data=temp->data;
	T->right=delet1(T->right,temp->data);
	return(T);
}
void BST::display1(BSTnode *T,int level)
{
    int i;
	if ( T!=NULL )
	{
		display1(T->right, level+1);
		printf("\n");
		for (i = 0; i < level; i++)
			printf("    ");
		printf("%d", T->data);
		display1(T->left, level+1);
	}
}
void BST::inorder1(BSTnode *T)
{
	if(T!=NULL)
	{
		inorder1(T->left);
		cout<<" "<<T->data;
		inorder1(T->right);
	}
}
void BST::preorder1(BSTnode *T)
{
	if(T!=NULL)
	{
		cout<<" "<<T->data;
		preorder1(T->left);
		preorder1(T->right);
	}
}
void BST::postorder1(BSTnode *T)
{
	if(T!=NULL)
	{
		postorder1(T->left);
		postorder1(T->right);
		cout<<" "<<T->data;
	}
}
int BST::height1(BSTnode *T)
{
	if(T==NULL)
		return(0);
	if(T->left==NULL && T->right==NULL)
		return(0);
	return(max(height1(T->left),height1(T->right))+1);
}
int BST::print0(BSTnode *T)
{
	if(T==NULL)
		return(0);
	if(T->left==NULL && T->right==NULL)
	{
		cout<<" "<<T->data;
		return(1);
	}
	return(print0(T->left)+print0(T->right));
}
void BST::insert(int x)
{
	BSTnode *p,*q,*r;
	r=new BSTnode(x);
	if(root==NULL)
	{
		root=r;
		return;
	}
	p=root;
	while(p!=NULL)
	{
		q=p;
		if(x>p->data)
			p=p->right;
		else
			p=p->left;
	}
	if(x>q->data)
		q->right=r;
	else
		q->left=r;
}
void BST::create()
{
	int n,x,i;
	root=NULL;
	cout<<"\nEnter no. of nodes:";
	cin>>n;
	cout<<"\nEnter tree value:";
	for(i=0;i<n;i++)
	{
		cin>>x;
		insert(x);
	}
}
BSTnode *BST::find(int x)
{
	BSTnode *T=root;
	while(T!=NULL)
	{
		if(x==T->data)
			return(T);
		if(x>root->data)
			T=T->right;
		else
			T=T->left;
	}
	return(NULL);
}
void BST::non_rec_inorder()
{
	stack s;
	BSTnode *T=root;
	cout<<"\n";
	while(T!=NULL)
	{
		s.push(T);
		T=T->left;
	}
	while(!s.empty())
	{
		T=s.pop();
		cout<<" "<<T->data;
		T=T->right;
		while(T!=NULL)
		{
			s.push(T);
			T=T->left;
		}
	}
}
void BST::non_rec_preorder()
{
	stack s;
	BSTnode *T=root;
	cout<<"\n";
	while(T!=NULL)
	{
		cout<<" "<<T->data;
		s.push(T);
		T=T->left;
	}
	while(!s.empty())
	{
		T=s.pop();
		T=T->right;
		while(T!=NULL)
		{
			cout<<" "<<T->data;
			s.push(T);
			T=T->left;
		}
	}
}
void BST::non_rec_postorder()
{
	stack s,s1;
	BSTnode *T=root;
	cout<<"\n";
	while(T!=NULL)
	{
		s.push(T);
		s1.push(NULL);
		T=T->left;
	}
	while(!s.empty())
	{
		T=s.pop();
		if(s1.pop()==NULL)
		{
			s.push(T);
			s1.push((BSTnode*)1) ;
			T=T->right;
			while(T!=NULL)
			{
				s.push(T) ;
				s1.push(NULL);
				T=T->left;
			}
		}
		else
			cout<<" "<<T->data;
	}
}
void BST::level_wise()
{
	Q q1,q2;
	BSTnode *p1;
	BSTnode *T=root;
	if(T==NULL)
		return;
	q1.insert(T);
	cout<<"\n"<<T->data;
	while(!q1.empty())
	{
		cout<<"\n";
		q2.init();
		while(!q1.empty())
		{
			p1=q1.Delete();
			if(p1->left!=NULL)
			{
				q2.insert(p1->left);
				cout<<" "<<p1->left->data;
			}
			if(p1->right!=NULL)
			{
				q2.insert(p1->right);
				cout<<" "<<p1->right->data;
			}
		}
		q1=q2;
	}
}

main()
{
	BST bst;
	BSTnode *p;
	int x,op;
    cout<<"1.Create\n2.Insert\n3.Delete\n4.Search\n5.Preorder(recursive)\n6.Inorder(recursive)\n7.Postorder(recursive)\n8.Preorder(non-recursive)";
    cout<<"\n9.Inorder(non-recursive)\n10.Postorder(non-recursive)\n11.Level wise traversal\n12.Print leaf nodes\n13.Height\n14.Display\n15.Quit\n ";
	do
	{
		cout<<"\nEnter your choice:";
		cin>>op;

		switch(op)
		{
			case 1: bst.create();
				break;
            case 2:cout<<"\nEnter the node to be inserted: " ;
                cin>>x;
                bst.insert(x);
				break;
			case 3:	cout<<"\nEnter the key to be deleted: " ;
				cin>>x;
				bst.delet(x);
				break;
			case 4:	cout<<"Enter the key to be searched: ";
				cin>>x;
				p=bst.find(x);
				if(p==NULL)
					cout<<"\nNot found....";
				else
					cout<<"\nFound..."  ;
				break;
			case 5:	bst.preorder();
				break;
			case 6: bst.inorder();
				break;
			case 7:	bst.postorder();
				break;
			case 8:	bst.non_rec_preorder();
				break;
			case 9:	bst.non_rec_inorder();
				break;
			case 10:	bst.non_rec_postorder();
				break;
			case 11:bst.level_wise();
				break;
			case 12:int xx;
				xx=bst.print_leaf_nodes();
				cout<<"\nNo of leaf nodes= "<<xx;
				break;
			case 13:cout<<"\nHeight= "<<bst.height();
				break;
            case 14:bst.display();
                break;
		}
	}while(op!=15);
}


