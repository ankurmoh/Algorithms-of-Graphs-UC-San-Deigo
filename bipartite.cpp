#include<bits/stdc++.h>
using namespace std;

bool bfs(vector<vector<int>>& adj,int src,vector<int>& color)
{
  color[src]=0;
  queue<int>q;
  q.push(src);
  int i,fron,sz,sz1,neigh,j;
  while(!q.empty())
  {
    sz=q.size();
    for(i=0;i<sz;i++)
    {
      fron=q.front();
      q.pop();
      sz1=adj[fron].size();
      for(j=0;j<sz1;j++)
      {
        neigh = adj[fron][j];
        if(color[neigh]==-1)
        {
          color[neigh] = 1 - color[fron];
          q.push(neigh);
        }
        else if(color[neigh] == 1 - color[fron])
        {
          continue;
        }
        else if(color[neigh] == color[fron])
        {
          return true;
        }
      }
    }
  }
  return false;
}

int bipartite(vector<vector<int> > &adj) {
  int i,n=adj.size();
  vector<int>color(n,-1);
  for(i=0;i<n;i++)
  {
    if(color[i]==-1)
    {
      if(bfs(adj,i,color))
      {
        return 0;
      }
    }
  }
  return 1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj);
}
