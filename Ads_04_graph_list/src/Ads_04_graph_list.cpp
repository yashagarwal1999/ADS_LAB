//============================================================================
// Name        : Ads_04_graph_list.cpp
// Author      : yash
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;
class vertex
{
	int time;
	char name;

public:
	vertex(int t,char n)
{
		time=t;
		name=n;
}
	friend class graph;
};
class graph
{
	vector<vector<vertex> >v;

public:
	graph()
{

v.resize(26);
}
void addedge()
{
	int t;

	char a,b;
	cout<<"Enter city 1 and city 2"<<endl;
	cin>>a>>b;
	cout<<"Enter time"<<endl;
	cin>>t;
	vertex m(t,b);

	v[a-'a'].push_back(m);



}
void deletedge(char a,char b)
{
	int i;
	for(i=0;i<v[a-'a'].size();i++)
	{
		if(v[a-'a'][i].name==b)
		{
			v[a-'a'].erase(v[a-'a'].begin()+i);
			break;
		}
	}
}
int outdeg(char a)
{
	return v[a-'a'].size();
}
int indeg(char a){
	int i,j,count=0;
	for(i=0;i<26;i++)
	{
		for(j=0;j<v[i].size();j++){
			if(v[i][j].name==a)

			{
				count++;
			}
		}
	}
		return count;

}
int deg(char a)
{
	int in=indeg(a);
	return v[a-'a'].size()+in;
}
void dfs()
{
	cout<<"Enter start"<<endl;
	char f;
	cin>>f;
	bool visi[26];
	memset(visi,false,sizeof(visi));
	stack<int>s;

	s.push(f-'a');
	visi[f-'a']=true;

	while(!s.empty())
	{
		int temp=s.top();

		s.pop();
		cout<<(char)(temp+'a')<<" ";
		//cout<<(char)(temp+'a')<<endl;
		//cout<<"size"<<v[temp].size()<<endl;
		for(int i=0;i<v[temp].size();i++){
			if(!visi[v[temp][i].name-'a'])
			{

				visi[v[temp][i].name-'a']=true;
				s.push(v[temp][i].name-'a');
			}
		}
	}

}
void deletevertex(char a)
{
	int i,j;
	for(i=0;i<26;i++)
	{
		for(j=0;j<v[i].size();j++)
		{
			if(v[i][j].name==a)
			{
				v[i].erase(v[i].begin()+j);
			}
		}
	}

}
void bfs()
{
	queue<int>q;
	bool visi[26];
		memset(visi,false,sizeof(visi));
		q.push(0);
		visi[0]=true;
		cout<<"a ";
			while(!q.empty())
			{
				int temp=q.front();
				q.pop();
				//cout<<(char)(temp+'a')<<endl;
				//cout<<"size"<<v[temp].size()<<endl;
				for(int i=0;i<v[temp].size();i++){
					if(!visi[v[temp][i].name-'a'])
					{
						cout<<v[temp][i].name<<" ";
						visi[v[temp][i].name-'a']=true;
						q.push(v[temp][i].name-'a');
					}
				}
			}


}

};
int main() {
graph g;
int n,opt;
while(1){
	cout<<"1. Add Edge 2.Deleet edge  3.Indegree 4.Outdegree 5.dfs 6.bfs 7.delete vertex"<<endl;
	cin>>opt;
	char a,b;
	switch(opt)
	{
	case 1:
	{
		g.addedge();
		break;
	}
	case 2:
	{
		cout<<"Enter the flight start and end cities "<<endl;
		cin>>a>>b;
		g.deletedge(a,b);
		break;
	}
	case 3:
	{
		cout<<"Enter the city name "<<endl;
		cin>>a;
		cout<<g.indeg(a)<<endl;
		break;
	}
	case 4:
	{
		cout<<"Enter the city name "<<endl;
				cin>>a;
				cout<<g.outdeg(a)<<endl;
				break;
	}
	case 5:
	{
		cout<<"The dfs sequence is"<<endl;
		g.dfs();
		break;
	}
	case 6:
		{
			cout<<"The bfs sequence is"<<endl;
			g.bfs();
			break;
		}
	case 7:
	{
		cout<<"Enter the vertex"<<endl;
		cin>>a;
		g.deletevertex(a);
		break;
	}
	}
}
	return 0;
}
