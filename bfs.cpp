#include<bits/stdc++.h>
using namespace std;

int distance(vector<vector<int> > &adj, int s, int t) {
  vector<int>dist(adj.size(),INT_MAX);
  dist[s]=0;
  queue<int>q;
  q.push(s);
  int i,sz,fron,j,sz1,neigh;
  while(!q.empty())
  {
    sz=q.size();
    for(i=0;i<sz;i++)
    {
      fron = q.front();
      q.pop();
      sz1=adj[fron].size();
      for(j=0;j<sz1;j++)
      {
        neigh = adj[fron][j];
        if(dist[neigh]==INT_MAX)
        {
          dist[neigh] = 1 + dist[fron];
          q.push(neigh);
        }
      }
    }
  }
  if(dist[t] == INT_MAX)
  {
    return -1;
  }
  return dist[t];
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
