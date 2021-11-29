/* STL사용한 테스트용*/
#include <bits/stdc++.h>
#define INF 987654321
#define MAXN 10001
using namespace std;

vector<pair<int, int>> adj[MAXN]; 
int n, m, q;

struct compare
{
	bool operator()(pair<int, int> a, pair<int, int> b)
	{
		if (a.first == b.first)
		{
			return a.second > b.second;
		}
		return a.first > b.first;
	}
};
void prim(int start)
{
	int dist = 0;
	vector<int> tree_order;
	vector<bool> visited(n + 1, false); 
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare>pq;
	pq.push({ 0,start });

	while (!pq.empty())
	{
		int curV = pq.top().second;
		int curC = pq.top().first;
		pq.pop();

		if (visited[curV]) continue;
		//cout << curV << "\n";
		if(!visited[curV])
		{
			visited[curV] = true;
			tree_order.push_back(curV);
			dist += curC;
		}

		for (auto u : adj[curV])
		{
			int nextV = u.first;
			int nextC = u.second;
			if (!visited[nextV])
			{
				pq.push({ nextC,nextV });
			}
			
		}
	}
	cout << dist << " ";
	for (auto u : tree_order)
	{
		cout << u << " ";
	}cout << "\n";
	
}
bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.first < b.first;
}
int main()
{
	
	cin >> n >> m >> q;
	for (int i = 0; i < m; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		adj[a].push_back({ b,w });
		adj[b].push_back({ a,w });
		
	}
	for (int i = 1; i <= n; i++)
	{
		sort(adj[i].begin(), adj[i].end(),cmp);
	}
	while (q--)
	{
		char c; int start;
		cin >> c >> start;
		prim(start);
	}
	
	
	return 0;
}