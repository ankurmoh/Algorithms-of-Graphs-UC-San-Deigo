#include<bits/stdc++.h>
using namespace std;

void shortest_paths(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, vector<long long> &distance, vector<int> &reachable, vector<int> &shortest) {
  reachable[s]=1;
  distance[s]=0;
  int i,j,k,n=adj.size(),fron,neigh,sz;
  queue<int>q;
  vector<int>visited(n,0);
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      for(k=0;k<adj[j].size();k++)
      {
        int src = j;
        int dest = adj[j][k];
        int wt = cost[j][k];
        if((distance[src]!=LLONG_MAX) && (distance[src] + wt < distance[dest]))
        {
          distance[dest] = distance[src] + wt;
          reachable[dest] = 1;
          if(i==n-1)
          {
            q.push(dest);
            visited[dest]=1;
          }
        }
      }
    }
  }
  while(!q.empty())
  {
    fron = q.front();
    q.pop();
    shortest[fron] = 0;
    sz = adj[fron].size();
    for(i=0;i<sz;i++)
    {
      neigh = adj[fron][i];
      if(!visited[neigh])
      {
        visited[neigh]=1;
        q.push(neigh);
      }
    }
  }
}

int main() {
  int n, m, s;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cin >> s;
  s--;
  vector<long long> distance(n, LLONG_MAX);
  vector<int> reachable(n, 0);
  vector<int> shortest(n, 1);
  shortest_paths(adj, cost, s, distance, reachable, shortest);
  for (int i = 0; i < n; i++) {
    if (!reachable[i]) {
      std::cout << "*\n";
    } else if (!shortest[i]) {
      std::cout << "-\n";
    } else {
      std::cout << distance[i] << "\n";
    }
  }
}
