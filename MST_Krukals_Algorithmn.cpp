//https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/tutorial/
time-complexity==ElogV;

#include<bits./stdc++.h>
#define ll long long int
vector<ll,pair<ll,ll>p(MAXN);
vector<int>ID(MAXN);
void initialise()
{
 for(int i=0;i<n;i++)
 p[i].first=INF;
 id[i]=i;
 
}


int find(vector<int>ID,int A)
{
 int i=A;
 while(i!=ID[i])
 {
  ID[i]=ID[ID[i]];
  i=ID[i];
 }
 return i;
}

void union(int A,int B)
{
 int rootA=find(A);
 int rootB=find(B);
 
 if(rootA!=rootB)
 {
  id[rootA]=id[rootB];
 }
}

ll calculate(p)///p is sorted according to weight
{
  for(int i=0;i<edges;i++)
  {
   int A=p[i].second.first;
   int B=p[i].second.second;
   int rootA=find(A);
   int rootB-find(B);
   
   if(rootA!=rootB)
   {
    cost+=p[i].first;
    union(rootA,rootB);
   }
  }
  return cost;
}
