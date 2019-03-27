#include<bits/stdc++.h>
using namespace std;
string key="abcdefghijklmnopqestuvwxyz";
int it=0;
#define MAX 100
class node
{
string key,val;
bool flag;
public:
	node()
{
key="";
val="";
		flag=false;
}
	node(string k,string v,bool f)
	{
		key=k;
		flag=f;
		val=v;
	}
friend class hash;
};
class hash
{
node arr[MAX];
public:
int encode(string k)
{
it=0;
		int n=k.length();
		int sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=(k[i] ^ key[it]);
		it=(it+1)%26;
	}
//cout<<sum<<endl;
	int k1=sum%MAX;
return k1;
}
void hashh(string k,string v)
	{
		int k1=encode(k);
	cout<<"1.with replacement 2.Without replacement"<<endl;
	int x;
	cin>>x;
	if(x==1)
	{
with(k,v,k1);

	}
	else
	{
				without(k,v,k1);
	}


	}


	void with(string k,string v,int x)
	{
		node* t=new node(k,v,true);

		arr[x]=*t;
	}

void without(string k,string v,int x)
	{
		node* t=new node(k,v,true);
		if(arr[x].flag==false && arr[x].key=="")
{
arr[x]=*t;
return;
}
else
{
int m=encode(arr[x].key);
if(x!=m)
{
node q=arr[x];
arr[x]=*t;
without(q.key,q.val,m);
}
else
{
while(arr[x].key!="")
{
x++;
}
t->flag=false;
arr[x]=*t;
}

}
}
int find(string k)
{
int x=encode(k);
if(arr[x].key==k)
{
return x;
}
for(int i=0;i<MAX;i++)
{
if(arr[i].key==k)
{
return i;
}
}
return -1;
}

string Ret(int x)
{
string a=arr[x].val;
return a;
}

void del(string k)
{
int m=find(k);
if(m==-1)
{
cout<<"key not present"<<endl;
}
else
{
node t;
arr[m]=t;
cout<<"Deleted successfully"<<endl;
}
}
void print()
{
	cout<<"Position\t"<<"KEY\t\t"<<"Value\t"<<endl;
	for(int i=0;i<MAX;i++)
	{
		if(arr[i].key!="")
		{
			cout<<"   "<<i<<"\t\t"<<arr[i].key<<"\t\t"<<arr[i].val<<endl;
		}
	}
}
};



int main()
{
hash h;
	int opt,n;
	string k,v;
	while(1)
	{
		cout<<"1.Insert key 2.Delete key 3.find key 4.print map 5.exit"<<endl;
			cin>>opt;
			switch(opt)
			{
			case 1:
			{
				cout<<"enter key and val"<<endl;
				cin>>k>>v;
				h.hashh(k,v);
				break;
			}
			case 2:

			{

				cout<<"enter key"<<endl;
								cin>>k;
								h.del(k);
								break;
			}
			case 3:
			{
				cout<<"enter key"<<endl;
				cin>>k;
				int m=h.find(k);
if(m==-1)
{
cout<<"The string is not present"<<endl;
}
else
{
cout<<"The value at key "<<k<<" is "<<h.Ret(m)<<endl;
}
				break;

			}
			case 4:
			{
				h.print();
				break;
			}
			case 5:
			{
				return 0;
			}
			}
	}
	return 0;
}
