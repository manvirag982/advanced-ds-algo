// You are given number of nodes, N, and number of edges, M, of a undirected connected graph. After adding each edge, print the size of all the connected components (in increasing order).

// Input:
// First line contains two integers, N and M, number of nodes and number of edges.
// Next M lines contains two integers each, X and Y, denoting that there is an edge between X and Y.

// Output:
// For each edge, print the size of all the connected components (in increasing order) after adding that edge.

// Constraints:



// SAMPLE INPUT 
// 5 4
// 1 2
// 3 4
// 4 5
// 1 3
// SAMPLE OUTPUT 
// 1 1 1 2
// 1 2 2
// 2 3
// 5


#include<bits/stdc++.h>
using namespace std;
const int MAX =1e3;
int Rank[MAX+1];
int leader[MAX+1];
int n,e;
int Find(int u)
{
	while(leader[u]!=u)
	{
		u=leader[u];
	}
	return u;
}
void Union(int u,int v)
{
	   int leaderu=Find(u);
       int leaderv=Find(v);

        if(leaderv==leaderu)
        	return ;
         // cout<<leaderu<<endl;
       if(Rank[leaderv]>Rank[leaderu])
       swap(leaderu,leaderv);  

	   leader[leaderv]=leaderu;

	   Rank[leaderu]+=Rank[leaderv];
	   Rank[leaderv]=0;
	   
	   // cout<<Rank[v];
}
void print()
{
	multiset<int> p;

	for(int i=1;i<=n;i++)
	{
		if(Rank[i])
			p.insert(Rank[i]);
	}

	for(auto i=p.begin();i!=p.end();i++)
		cout<<*i<<" ";
	cout<<endl;
}
int main()
{
      for(int i=1;i<=MAX;i++)
      	Rank[i]=1;
      for(int i=1;i<=MAX;i++)
      	leader[i]=i;

       cin>>n>>e;

      for(int i=0;i<e;i++)
      {
      	 int u,v; cin>>u>>v;
      	 Union(u,v);
      	 print();

      }

    return 0;
}