#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>& adj, vector<int>& visited, int src)
{
  visited[src]=1;
  queue<int>q;
  q.push(src);
  int i,sz,fron,sz1,neigh,j;
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
        if(visited[neigh]==0)
        {
          visited[neigh]=1;
          q.push(neigh);
        }
      }
    }
  }
}

int number_of_components(vector<vector<int> > &adj,int n) {
  int res = 0;
  vector<int>visited(n,0);
  for(int i=0;i<n;i++)
  {
    if(visited[i]==0)
    {
      res++;
      bfs(adj,visited,i);
    }
  }
  return res;
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
  std::cout << number_of_components(adj,n);
}
