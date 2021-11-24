#include <bits/stdc++.h>
#define MAX 10000
using namespace std;

int t;
bool visited[MAX];
int dist[MAX];
int dx[2] = { 1,-1 };
bool isRange(int x)
{
	if (x >= 0 && x < MAX) return true;
	return false;
}
void bfs(int x)
{
	queue<int> q; 
	q.push(x);
	visited[x] = true;
	dist[x] = 0;

	while (!q.empty())
	{
		int x = q.front(); q.pop();
		
		for (int i = 0; i < 2; i++)
		{
			int nx = x + dx[i];

			if (isRange(nx))
			{
				if (!visited[nx])
				{
					visited[nx] = true;
					dist[nx] = dist[x] + 1;
					q.push(nx);
				}
			}
		}
		int temp= 0,i=3;
		int xx = x;
		while (x)
		{
			temp += (x % 10) * pow(10, i--);
			x /= 10;
		}
		
		if (isRange(temp))
		{
			if (!visited[temp])
			{
				visited[temp] = true;
				dist[temp] = dist[xx] + 1;
				q.push(temp);
			}
		}
	}
}
int main()
{
	cin >> t;
	while (t--)
	{
		for (int i = 0; i < MAX; i++)
		{
			visited[i] = false;
			dist[i] = 0;
		}
		int s, e;
		cin >> s >> e;

		bfs(s);

		cout << dist[e] << "\n";

	}

	return 0;
}