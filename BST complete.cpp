#include<iostream>
using namespace std;
int val,sw,f=0;
struct node
{
	int data;
	node *left;
	node *right;
}*tree,*ptr,*nodeptr,*parptr,*cur,*suc,*psuc,*par;
node *insertelement(node *tree,int val)
{
	ptr->data=val;
	ptr->left=NULL;
	ptr->right=NULL;
	if(tree==NULL)
	{
		tree=ptr;
		tree->left=NULL;
		tree->right=NULL;
	}
	else
	{
		parptr=NULL;
		nodeptr=tree;
		while(nodeptr!=NULL)
		{
			parptr=nodeptr;
			if(val<nodeptr->data)
			{
				nodeptr=nodeptr->left;
			}
			else
			{
				nodeptr=nodeptr->right;
			}
		}
		if(val<parptr->data)
		{
			parptr->left=ptr;
		}
		else
		{
			parptr->right=ptr;
		}
	}
	return (tree);
}
void preorder(node *tree)
{
	while(tree!=NULL)
	{
		cout<<tree->data<<"\t";
		preorder(tree->left);
		preorder(tree->right);
	}
}

void inorder(node *tree)
{
	while(tree!=NULL)
	{
		inorder(tree->left);
		cout<<tree->data<<"\t";
		inorder(tree->right);
	}
}
void postorder(node *tree)
{
	while(tree!=NULL)
	{
		postorder(tree->left);
		postorder(tree->right);
		cout<<tree->data<<"\t";
	}
}
node *findsmallest(node *tree)
{
	if((tree==NULL)||((tree->left)==NULL))
	{
		return tree;
	}
	else
	{
		return findsmallest(tree->left);
	}
}
node *findlargest(node *tree)
{
	if((tree==NULL)||((tree->right)==NULL))
	{
		return tree;
	}
	else
	{
		return findlargest(tree->right);
	}
}
int totalnodes(node *tree)
{
	if(tree==NULL)
	{
		return 0;
	}
	else
	{
		return (totalnodes(tree->left)+totalnodes(tree->right)+1);
	}
}
node *deletion(node *tree,int val)
{
	if(tree->left==NULL)
	{
		cout<<"Tree is empty!\n";
		return (tree);
	}
	par=tree;
	cur=tree->left;
	while(cur!=NULL && val!=cur->data)
	{
		par=cur;
		cur=(val<cur->data)?cur->left:cur->right;
	}
	if(cur==NULL)
	{
		cout<<"Value not present!\n";
		return (tree);
	}
	if(cur->left==NULL)
	{
		ptr=cur->right;
	}
	else if(cur->right==NULL)
	{
		ptr=cur->left;
	}
	else
	{
		psuc=cur;
		cur=cur->left;
		while(suc->left!=NULL)
		{
			psuc=suc;
			suc=suc->left;
		}
		if(cur==psuc)
		{
			suc->left=cur->right;
		}
		else
		{
			suc->left=cur->left;
			psuc->left=suc->right;
			suc->right=cur->right;
		}
		ptr=suc;
	}
	if(par->left==cur)
	{
		par->left=ptr;
	}
	else
	{
		par->right=ptr;
	}
	delete(cur);
	return (tree);
}
int main()
{	
	while(f==0)
	{
		cout<<"Enter you option!\n1.Insertion.\n2.Preorder Traversal.\n3.Inorder Traversal.\n4.Postorder Traversal.\n5.Find the smallest Element.\n6.Find the largest Element.\n7.Deletion.\n8.Count the total number of nodes.\n9.Exit.\n";
		cin>>sw;
		switch(sw)
		{
			case 1:
				cout<<"Enter the value!\n";
				cin>>val;
				tree=insertelement(tree,val);
				break;
			case 2:
				cout<<"Preorder Traversal!\n";
				preorder(tree);
				break;
			case 3:
				cout<<"Inorder Traversal!\n";
				inorder(tree);
				break;
			case 4:
				cout<<"Postorder Traversal!\n";
				postorder(tree);
				break;
			case 5:
				ptr=findsmallest(tree);
				cout<<"Smallest element: "<<ptr->data;
				break;
			case 6:
				ptr=findlargest(tree);
				cout<<"Largest element: "<<ptr->data;
				break;
			case 7:
				cout<<"Enter element to be deleted!\n";
				cin>>val;
				tree=deletion(tree,val);
				break;
			case 8:
				cout<<"Total Number of Nodes are: ";
				totalnodes(tree);
				break;
			case 9:
				f=1;
		}
	}
}
