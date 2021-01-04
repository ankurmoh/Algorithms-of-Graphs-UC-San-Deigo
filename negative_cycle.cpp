#include<bits/stdc++.h>
using namespace std;

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost,int source, vector<long long>& dist)
{
  int n = adj.size(),i,j,k,src,dest,wt;
  dist[source]=0;
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      for(k=0;k<adj[j].size();k++)
      {
        src = j;
        dest = adj[j][k];
        wt = cost[j][k];
        if((dist[src]!=INT_MAX) && (dist[dest] > dist[src] + wt))
        {
          dist[dest] = dist[src] + wt;
          if(i==n-1)
            return 1;
        }
      }
    }
  }
  // for(j=0;j<n;j++)
  // {
  //   vector<int>temp = adj[j];
  //   for(k=0;k<temp.size();k++)
  //   {
  //     src = j;
  //     dest = temp[k];
  //     wt = cost[j][k];
  //     if((dist[src]!=INT_MAX) && (dist[src] + wt < dist[dest]))
  //     {
  //       return 1;
  //     }
  //   }
  // }
  return 0;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  vector<long long>dist(n,INT_MAX);
  for(int i=0;i<n;i++)
  {
    if(dist[i]==INT_MAX)
    {
      int res = negative_cycle(adj, cost,i,dist);
      if(res == 1)
      {
        cout<<1;
        return 0;
      }
    }
  }
  cout<<0;
  // std::cout << negative_cycle(adj, cost);
}
