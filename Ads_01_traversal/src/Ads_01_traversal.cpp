//============================================================================
// Name        : Ads_01_traversal.cpp
// Author      : yash
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;
int x=0;
class node
{
	int data;
	node *left,*right;

public:
node()
{
	left=NULL;
	right=NULL;
}
	node(char d)
{
		data=d;
		left=NULL;
		right=NULL;
}
	friend class tree;

	friend class queue;
};
class Queue
{
	node* s;
	int n,front,rear;
public:
	Queue(int n)
{
		this->n=n;
		s=new node[n];
		front=-1;
		rear=-1;
}
	void enqueue(node q)
			{
		s[++rear]=q;

			}
	node pop()
	{
		return s[++front];
	}
	bool empty()
	{
		if(front==-1 && rear==-1)
		{
			return true;
		}
		return false;
	}


};

class tree
{
 	node* root;
	int count,ht,leaf;
public:
	tree(int n)
{
		root=NULL;
		count=n;
		leaf=0;
ht=0;
}
	void insert()
	{
		int d;
		cout<<"Enter the element to be insert"<<endl;
		cin>>d;
		node *temp=root;
		if(root==NULL)
		{
		root=new node(d);

		return;
		}
		int side;
		node *temp1=new node(d);
		while(1)
		{
			cout<<"1.insert at left 2.insert at right of"<<temp->data<<endl;
			cin>>side;
			if(side==1)
			{
				if(temp->left==NULL)
				{
					temp->left=temp1;

					return;
				}
				temp=temp->left;
			}
			else
			{
				if(temp->right==NULL)
				{
					temp->right=temp1;

					return;
				}
				temp=temp->right;
			}
		}

	}
	void preoder(node* r)
	{
if(r==NULL)
{
	return;
}
cout<<r->data<<" ";
preoder(r->left);
preoder(r->right);
	}


	void pre()
	{
		preoder(root);
	}
	void postorder(node* r)
	{
		if(r==NULL)
		{
			return;
		}
		postorder(r->left);
		postorder(r->right);
		cout<<r->data<<" ";
	}
	int height()
	{

		return ht;

	}
	void pos()
	{
		postorder(root);
	}
	void print()
	{
		ht=(log2(count+1))-1;
node *arr[ht];

arr[0]=root;
for(int i=0;i<ht-2;i++)
{
	if(arr[i]!=NULL)
	{
	cout<<arr[i]->data<<" ";
	arr[i+1]=arr[i]->left;



}
}
	}
	void preorderN()
	{
		stack<node>s;
		node temp=*root;
s.push(temp);
		int n=count;
		int i;
		for(i=0;i<n;i++)
		{

			temp=s.top();
			s.pop();
			cout<<temp.data<<" ";
			if(temp.right)
			{
				s.push(*temp.right);
			}
			if(temp.left)
			{
				s.push(*temp.left);
			}
		}

	}
	void postorderN()
	{
		stack<node>s1,s2;
		int i;
		cout<<"Postorder without recursion "<<endl;
		node temp1;
		s1.push(*root);
		for(i=0;i<count;i++)
		{

temp1=s1.top();
s1.pop();
s2.push(temp1);
if(temp1.left!=NULL)
{
	s1.push(*temp1.left);
}
if(temp1.right!=NULL)
{
	s1.push(*temp1.right);
}

		}
		for(i=0;i<count;i++)
		{
			temp1=s2.top();
			s2.pop();
			cout<<temp1.data<<" ";
		}
		cout<<endl;

	}
	void mirror(node* temp1)
	{
		//cout<<x++<<endl;
		if(temp1==NULL)
		{

					//cout<<temp1->data<< " "<<temp2->data<<" "<<endl;
			return;
		}
		else{
		mirror(temp1->left);
		mirror(temp1->right);
		swap(temp1->left,temp1->right);
		//cout<<"after swap"<<temp1->data<< " "<<temp2->data<<" "<<x++<<endl;
		}

	}
	void m()
	{
		mirror(root);
	}
	void mirrorN()
	{
		//int i;
		//
		//queue q(count);
		stack<node>q;
q.push(*root);

int i=0;
if(root==NULL)
{return;}
while(i<count)
{
	node temp;
	temp=q.top();

	//cout<<temp.data<<endl;
	//q.pop();
	swap(temp.left,temp.right);
	q.pop();
	if(temp.left)
	{
		q.push(*temp.left);
	}
	if(temp.right)
	{
		q.push(*temp.right);
	}
	i++;
}


	}
	int l()
	{
		leaf=0;
		leafcount(root);
		return leaf/2;
	}
	void leafcount(node* r)
	{
		if(r==NULL)
		{
			leaf++;
			return;
		}
		leafcount(r->left);
		leafcount(r->right);

	}
	int leafcountN()
	{
		int i,freq=0;
		queue<node> q;
		q.push(*root);
		node temp;
		for(i=0;i<count;i++)
		{
			temp=q.front();
			q.pop();
			if(temp.left==NULL && temp.right==NULL)
			{
				freq++;
			}
			if(temp.left)
			{
				q.push(*temp.left);
			}
			if(temp.right)
				{
				q.push(*temp.right);
				}
		}
		return freq;
	}
	int Ht()
	{
		int level=-1;
		queue<node>q;
		q.push(*root);
		if(root==NULL)
		{
			return 0;
		}
		int count=0;
		while(1)
		{
			count=q.size();
			level++;
			if(count==0)
			{
				return level-1;
			}
			while(count>0)
			{
			node temp=q.front();
			q.pop();
			if(temp.left)
			{
				q.push(*temp.left);
			}
			if(temp.right)
			{
				q.push(*temp.right);
			}
			count--;

		}

		}
		return level-1;


	}
	int RHT()
	{
		int i=HTR(root);
		return i-1;
	}
int HTR(node* r)
{
	if(r==NULL)
	{
		return 0;
	}
	int h1=HTR(r->left);
	int h2=HTR(r->right);
	if(h1>h2)
	{
		return 1+h1 ;
	}
	else
	{
		return h2+1;
	}
}
void e()
{
	erase(root);
	//cout<<count<<endl;
}
void erase(node* r)
{
	if(r==NULL)
	{
		return;
	}
	erase(r->left);
	erase(r->right);
	delete r;
	count--;

}
node newnode(int d)
{
	node* temp=new node(d);
	return temp;
}
tree operator =(tree& t)
{
	tree temp;
	queue<node>q;
	node c=temp.root;
	q.push(*t.root);
	if(t.root==NULL)
		{
		temp.root=NULL;
		return temp;
		}
	int count=0;
	while(1)
	{
		count=q.size();
		while(count>0)
		{
			node a=q.front();
			q.pop();
			node b=newnode(a.data);
			if(c==NULL)
			{
				temp.root=a;
			}
			if(a.left)
			{
				q.push(*a.left);
			}
			if(a.right)
			{
				q.push(*a.right);
			}
			count--;


		}
	}
}
};

int main() {
cout<<"Enter the number of nodes"<<endl;
int n,i,opt;
cin>>n;
tree t(n);
tree t2(n);
for(i=0;i<n;i++)
{
t.insert();
}
while(1){
	cout<<"\n 1.Preorder using recursion \n 2.Postorder Using recursion\n ";
		cout<<"3.Preoder iterative\n 4.postorder iterative\n 5.mirror\n 6.mirror Non recursive\n ";
		cout<<"7.number of leaves and internal nodes\n 8.number of leaves and internal nodes\n 9.copy to another tree\n ";
		cout<<"10. height\n 11.Height recursively\n 12.erase recursive\n 13.erase\n  14.exit\n"<<endl;
	cin>>opt;
	switch(opt)
	{
	case 1:
	{
		t.pre();
		break;
	}
	case 2:
	{
		t.pos();
		break;
	}
	case 3:
	{
		t.preorderN();
		break;
	}
	case 4:
	{
		t.postorderN();
		break;
	}
	case 5:
	{
		t.m();
		//cout<<x<<endl;
		break;
	}
	case 6:
	{
		t.mirrorN();
		break;
	}
	case 7:
		{
			int leaf=t.l();
			cout<<"Number of leaves is "<<leaf<<"and number of internal nodes is "<<n-leaf<<endl;
			break;
		}
	case 8:
	{
		int leaf=t.leafcountN();
		cout<<"Number of leaves is "<<leaf<<"and number of internal nodes is "<<n-leaf<<endl;
					break;
	}
	case 9:
	{
		t2=t;
		cout<<"Tree copied"<<endl;
		break;
	}
	case 10:
	{
		cout<<"The height of tree is "<<t.Ht()<<endl;
		break;
	}
	case 11:
		{
			cout<<"The height of tree recursively is "<<t.RHT()<<endl;
			break;
		}
	case 12:
	{
		t.e();
		break;
	}
	case 13:
	{
		break;
	}
	case 14:
		{
			return 0;
		}
	}
	}

	return 0;
}
