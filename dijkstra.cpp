#include<bits/stdc++.h>
using namespace std;

long long distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  //write your code her
  long long n = adj.size(),ans=0,current_v,current_d,sz,i,neigh,weight;
  vector<long long>dist(n,INT_MAX);
  vector<long long>spt(n,0);
  dist[s]=0;
  priority_queue<pair<long long, long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>>pq;
  pq.push(make_pair(0,s));
  while(!pq.empty())
  {
    pair<long long, long long>fron = pq.top();
    pq.pop();
    current_v = fron.second;
    current_d = fron.first;
    if(spt[current_v]==0)
    {
      spt[current_v]=1;
      ans=ans + dist[current_v];
    }
    sz=adj[current_v].size();
    for(i=0;i<sz;i++)
    {
      neigh = adj[current_v][i];
      weight = cost[current_v][i];
      if((dist[neigh] == INT_MAX) || ((dist[current_v]!=INT_MAX) && (dist[neigh]>dist[current_v] + weight)))
      {
        dist[neigh] = dist[current_v] + weight;
        pq.push(make_pair(dist[neigh],neigh));
      }
    }
  }
  if(dist[t]==INT_MAX)
    return -1;
  return dist[t];
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
