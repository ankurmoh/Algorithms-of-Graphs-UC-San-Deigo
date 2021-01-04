#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int> > &adj, int src, stack<int>& st,vector<int>& visited) {
  //write your code here
  visited[src]=1;
  int i,sz=adj[src].size(),neigh;
  for(i=0;i<sz;i++)
  {
    neigh = adj[src][i];
    if(!visited[neigh])
    {
      dfs(adj,neigh,st,visited);
    }
  }
  st.push(src);
}

vector<int> toposort(vector<vector<int> > adj) {
  stack<int>st;
  vector<int> order;
  vector<int> visited(adj.size(), 0);
  for(int i=0;i<adj.size();i++)
  {
    if(!visited[i])
    {
      dfs(adj,i,st,visited);
    }
  }
  while(!st.empty())
  {
    order.push_back(st.top());
    st.pop();
  }
  return order;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  vector<int> order = toposort(adj);
  for (size_t i = 0; i < order.size(); i++) {
    std::cout << order[i] + 1 << " ";
  }
}
