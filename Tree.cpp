
#include <iostream>
#include <string.h>
using namespace std;
class Node
{
public:
		char name[15];
		long int cell;
		Node *left,*right;

};
class Directory
{
public:
	Node *root,*temp;
	void create();
	void insert(Node *, Node *);
	void display(Node *);
	Node * del(Node*,char []);
	Node * min(Node*);
	int search(Node*,char []);
};
void Directory::create()
{
	Node *temp;
	int ch;
	do
	{
		temp=new Node;
		cout<<"Enter Name";
		cin>>temp->name;
		cout<<"Enter cell_no";
		cin>>temp->cell;
		temp->left=temp->right=NULL;
		if(root==NULL)
		{
			root=temp;
		}
		else
		{
			insert(root,temp);
		}
		cout<<"Press 1 to continue";
		cin>>ch;

	}while(ch==1);

}
void Directory::insert(Node* root,Node* temp)
{
	if(strcmp(temp->name,root->name)<0)
	{
		if(root->left==NULL)
		{
			root->left=temp;
		}
		else
		{
			insert(root->left,temp);
		}
	}
	else
	{
		if(root->right==NULL)
		{
			root->right=temp;
		}
		else
		{
			insert(root->right,temp);

		}
	}
}
void Directory::display(Node* root)
{
	Node* temp=root;
	//cout<<"\nRecord\n";
	if(temp!=NULL)
	{
		display(temp->left);
		cout<<"\n Name:"<<temp->name;
		cout<<"\n Cell :"<<temp->cell;
		display(temp->right);
	}
}
int Directory::search(Node* root,char k[15])
{
	int c=0;
	while(root!=NULL)
	{
		c++;
		if(strcmp(k,root->name)==0)
		{
			cout<<"\n record found at :"<<c;
			return 1;

		}
		else if(strcmp(k,root->name)<0)
		{
			root=root->left;
		}
		else
		{
			root=root->right;
		}
	}
}
Node* Directory::min(Node *q)
{
	while(q->left!=NULL)
	{
		q=q->left;

	}
	return 	q;
}
Node* Directory::del(Node *root,char k[15])
{
	Node *temp;
	if(root==NULL)
	{
		cout<<"Tree is empty";
		return root;

	}
	if(strcmp(k,root->name)<0)
	{
		root->left=del(root->left,k);
		return root;
	}
	if(strcmp(k,root->name)>0)
	{
		root->right=del(root->right,k);
		return root;
	}
	if((root->right==NULL)&&(root->left==NULL))
	{
		temp=root;
		delete temp;
		return NULL;

	}
	if(root->right==NULL)
	{
		temp=root;
		root=root->left;
		delete temp;
		return root;
	}
	else if(root->left==NULL)
	{
		temp=root;
		root=root->right;
		delete temp;
		return root;
	}
	temp=min(root->right);
	strcpy(root->name,temp->name);
	root->right=del(root->right,temp->name);
	return root;

}
int main() {
	int ch;
	char k[15];
	Directory d;
	int c=0;
	d.root=NULL;
	do
	{
		cout<<"\n1-Create\n2-Display\n3-Delete\n4-Search";
		cout<<"\nEnter your choice";
		cin>>ch;
		switch(ch)
		{
			case 1:
			d.create();
			break;

			case 2:
			d.display(d.root);
			break;

			case 3:
				cout<<"Enter name to delete";
				cin>>k;
				d.del(d.root,k);
				break;

			case 4:
				cout<<"Enter name to search";
				cin>>k;
				d.search(d.root,k);
				break;


		}
		cout<<"\nEnter 1 to continue";
		cin>>c;
	}while(c==1);
	return 0;
}
