#include <bits/stdc++.h>
#define MAX 3000
using namespace std;

char board[MAX][MAX];
int n, m;
set<string> s[26][3000];
int dy[3] = { 0,1,1 };
int dx[3] = { 1,1,0 };
vector<string> word;

bool isRange(int y, int x)
{
	if (y >= 0 && y < n && x >= 0 && x < n) return true;
	return false;
}
void dfs(int y, int x, int dir)
{
	
}
int main()
{
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];

	

	

	return 0;
}