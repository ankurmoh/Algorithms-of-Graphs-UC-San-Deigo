#include<bits/stdc++.h>
using namespace std;

stack<int>st;

vector<vector<int>> reverse_g(vector<vector<int>>& adj)
{
  vector<vector<int>>adj_r(adj.size());
  int i,n=adj.size(),j,sz;
  for(i=0;i<n;i++)
  {
    vector<int>temp = adj[i];
    if(temp.size()==0)
      continue;
    for(j=0;j<temp.size();j++)
    {
      adj_r[temp[j]].push_back(i);
    }
  }
  return adj_r;
}
void dfs(vector<int>& visited,int src,vector<vector<int>>& adj)
{
  visited[src]=1;
  int i,sz=adj[src].size(),neigh;
  for(i=0;i<sz;i++)
  {
    neigh=adj[src][i];
    if(!visited[neigh])
    {
      dfs(visited,neigh,adj);
    }
  }
  st.push(src);
}

void dfs_util(vector<int>& visited,int src,vector<vector<int>>& adj_r)
{
  visited[src]=1;
  int i,sz=adj_r[src].size(),neigh;
  for(i=0;i<sz;i++)
  {
    neigh=adj_r[src][i];
    if(!visited[neigh])
    {
      dfs(visited,neigh,adj_r);
    }
  }
}

int number_of_strongly_connected_components(vector<vector<int> > adj) {
  int result = 0,i,src;

  vector<int>visited(adj.size(),0);
  for(i=0;i<adj.size();i++)
  {
    if(visited[i]==0)
    {
      dfs(visited,i,adj);
    }
  }
  vector<vector<int>> adj_r = reverse_g(adj);
  for(i=0;i<adj.size();i++)
  {
    visited[i]=0;
  }
  while(!st.empty())
  {
    src = st.top();
    st.pop();
    if(!visited[src])
    {
      result++;
      dfs_util(visited,src,adj_r);
    }
  }
  return result;
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
  std::cout << number_of_strongly_connected_components(adj);
}
