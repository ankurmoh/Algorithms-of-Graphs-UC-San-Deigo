#include<bits/stdc++.h>
using namespace std;

int Find(int i, vector<int>& parent)
{
  if(i!=parent[i])
  {
    parent[i] = Find(parent[i], parent);
  }
  return parent[i];
}

void Union(int u, int v, vector<int>& parent, vector<int>& rank)
{
  int r1 = Find(u, parent);
  int r2 = Find(v, parent);
  if (r1 != r2)
  {
    if (rank[r1] > rank[r2])
    {
      parent[r2] = r1;
    }
    else
    {
      parent[r1] = r2;
      if (rank[r1] == rank[r2])
      {
        rank[r2]++;
      }
    }
  }
}

double minimum_distance(vector<int> x, vector<int> y)
{
  double result = 0.0;
  int n = x.size();
  vector<int>rank(n,0);
  vector<int>parent(n);

  for(int i=0;i<n;i++)
  {
    parent[i]=i;
  }

  vector<pair<int, pair<int, double>>>edges;
  for(int i=0;i<n;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      double dist = sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
      edges.push_back(make_pair(i, make_pair(j, dist)));
    }
  }

sort(edges.begin(), edges.end(), [](const pair<int, pair<int,double>>& a, const pair<int, pair<int,double>>& b)
{
    return a.second.second<b.second.second;
});

  for (int i = 0; i < edges.size(); i++)
  {
    int u = edges[i].first;
    int v = edges[i].second.first;
    if (Find(u, parent) != Find(v, parent))
    {
      result += edges[i].second.second;
      Union(u, v, parent, rank);
    }
  }

  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
