#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>& adj,int& x,int& y,unordered_map<int,int>& visited)
{
  if(x==y)
    return true;
  visited[x]=1;
  int i,sz=adj[x].size(),neigh;
  for(i=0;i<sz;i++)
  {
    neigh = adj[x][i];
    if(neigh == y)
      return true;
    if(visited.find(neigh) == visited.end())
    {
      return dfs(adj,neigh,y,visited);
    }
  }
  return false;
}
int reach(vector<vector<int> > &adj, int x, int y) {
  unordered_map<int,int>visited;
  // bool v = dfs(adj,x,y,visited);
  // if(v== true)
  //   return 1;
  // return 0;
  visited[x]=1;
  queue<int>q;
  q.push(x);
  int i,sz,fron,sz1,j,neigh;
  while(!q.empty())
  {
    sz=q.size();
    for(i=0;i<sz;i++)
    {
      fron=q.front();
      q.pop();
      if(fron == y)
      {
        return 1;
      }
      sz1 = adj[fron].size();
      for(j=0;j<sz1;j++)
      {
        neigh = adj[fron][j];
        if(visited.find(neigh) == visited.end())
        {
          visited[neigh]=1;
          q.push(neigh);
        }
      }
    }
  }
  return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1);
}
