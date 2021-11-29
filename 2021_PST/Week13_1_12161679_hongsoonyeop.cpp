#include <bits/stdc++.h>
#define MAXN 3000
using namespace std;

int n, m;
char board[MAXN][MAXN];
bool visited[MAXN][MAXN];
int dy[3] = { 0,1,1 };
int dx[3] = { 1,1,0 };
set<string> s;
bool isRange(int y, int x)
{
	if (y >= 0 && y < n && x >= 0 && x < n) return true;
	return false;
}
void dfs(int y, int x, int dir,string curWord)
{
	visited[y][x] = true;
	curWord += board[y][x];
	s.insert(curWord);

	int ny = y + dy[dir];
	int nx = x + dx[dir];

	if (isRange(ny, nx))
	{
		dfs(ny, nx, dir, curWord);
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				dfs(i, j, k, "");
			}
		}
	}
	
	for (int i = 0; i < m; i++)
	{
		string tar; cin >> tar;
		if (s.find(tar) == s.end())
		{
			cout << "0\n";
		}
		else
		{
			cout << "1\n";
		}
	}

	return 0;
}