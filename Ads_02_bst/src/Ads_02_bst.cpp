//============================================================================
// Name        : Ads_02_bst.cpp
// Author      : yash
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
class node
{
	string data,mean;
	node *left,*right;
public:
	node()
{
		left=NULL;
		right=NULL;

}
	node(string d,string e)
	{
		data=d;
		mean=e;
		left=NULL;
			right=NULL;

	}
	friend class bst;
};
class bst
{
	node* root;
public:
	bst()
{
		root=NULL;
}
	void newnode(string d,string e)
	{
		node* temp=new node(d,e);
		if(root==NULL)
		{
			root=temp;
			return;
		}
		insert(temp,root);

	}
	void insert(node* t,node* root)
	{

		if(root==NULL)
		{

		return;
		}

		else if(root->data>t->data)
		{
			if(root->left==NULL)
			{
				root->left=t;
				return;
			}
			insert(t,root->left);
		}
		else if(root->data<t->data)
			{
			if(root->right==NULL)
			{
				root->right=t;
				return;
			}
			insert(t,root->right);
			}



	}
	void preorder(node* t)
	{
		if(t==NULL)
		{
			return;
		}
		cout<<t->data<<" ";
		preorder(t->left);
		preorder(t->right);
	}
	void pre()
	{
		preorder(root);
	}
	void in()
	{
		inorder(root);
	}
	void inorder(node* t)
	{
		if(t==NULL)
		{
			return;

		}
		inorder(t->left);
		cout<<t->data<<" ";
		inorder(t->right);
	}
	string s(string a)
	{
		return search(a,root);

	}

	string search(string a,node* r)
	{
if(r==NULL)
{
	return "NOT FOUND";
}
if(r->data>a)
{
	return search(a,r->left);
}
else if(r->data<a)
{
	return search(a,r->right);
}
else
{
	return r->mean;
}
	}
	node* succesor(node* t,string a)
	{
		node* temp=t;
		while(temp->left!=NULL)
		{
			temp=temp->left;
		}
		return temp;
	}
	void deleten(string a)
	{
		node* t=deletenode(root,a);
	}
	node* deletenode(node* t,string a)
	{
if(t==NULL)
{
	return t;
}
if(t->data<a)
{
	t->right=deletenode(t->right,a);
}
else if(t->data>a)
{
	t->left=deletenode(t->left,a);
}
else
{
	if(t->left==NULL)
	{node* temp=t->right;
	delete(t);
	return temp;
	}
	else if(t->right==NULL)
	{node* temp=t->left;
	delete(t);
	return temp;}

		node* s=succesor(t,a);
		t->data=s->data;
		t->mean=s->mean;
		t->right=deletenode(root->right,s->data);
		delete(t);



}
return root;
	}


};
int main() {
	int opt;
	bst b;
	string d,e,f;
	while(1)
	{
		cout<<"1.Add a new node 2.delete a node 3.inorder 4.preorder 5.search"<<endl;
		cin>>opt;
		switch(opt)
		{
		case 1:
		{
			cout<<"Enter the string to be inserted "<<endl;
			cin>>d;
			cout<<"Enter the meaning to be inserted "<<endl;
			getline(cin,f);
			//cin.ignore('\n',1000);
			getline(cin,e);

			b.newnode(d,e);
			break;

		}
		case 2:
		{
			cout<<"Enter the string to be deleted"<<endl;
			string a;
			cin>>a;
			b.deleten(a);
			break;

		}
		case 3:
		{
			cout<<"The inorder is "<<endl;
						b.in();
						cout<<endl;
						break;
		}
		case 4:
		{
			cout<<"The preorder is "<<endl;
			b.pre();
			cout<<endl;
			break;
		}
		case 5:
		{
			cout<<"Enter the word to be searched"<<endl;
			cin>>e;
			cout<<b.s(e)<<endl;
			break;
		}
		}
	}
	return 0;
}
