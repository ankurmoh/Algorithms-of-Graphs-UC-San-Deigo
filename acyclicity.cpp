#include<bits/stdc++.h>
using namespace std;

bool dfs(int src,vector<vector<int>>& adj,vector<int>& color)
{
  color[src]=1;
  int i,sz=adj[src].size(),neigh;
  for(i=0;i<sz;i++)
  {
    neigh = adj[src][i];
    if(color[neigh]==1)
      return true;
    if((color[neigh]==0) && (dfs(neigh,adj,color)))
      return true;
  }
  color[src]=2;
  return false;
}


int acyclic(vector<vector<int> > &adj,int n) {
  vector<int>color(n,0);
  int i;
  for(i=0;i<n;i++)
  {
    if(color[i]==0)
    {
      if(dfs(i,adj,color))
        return 1;
    }
  }
  //write your code here
  return 0;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj,n);
}
