#include <bits/stdc++.h>
#define MAX 3000
using namespace std;
int n, m;
char board[MAX][MAX];
bool visited[26];

struct Trie 
{ 
	Trie* ch[26]; 
	bool end; 
	Trie() 
	{ 
		end = false; 
		for (int i = 0; i < 26; i++) 
			ch[i] = NULL; }
	~Trie(){
		for (int i = 0; i < 26; i++) 
			if (ch[i]) delete ch[i]; 
	} 
	void insert(const char* s)
	{ 
		if (!*s)
		{ 
			this->end = true; return; 
		} 
		int now = *s - 'A'; 
		if (!ch[now]) ch[now] = new Trie; 
		ch[now]->insert(s + 1); 
	}
	bool find(const char* s) 
	{ 
		if (!*s)
		{ 
			if (end) return true; return false;
		} 
		int now = *s - 'A';
		if (!ch[now]) return false;
		return ch[now]->find(s + 1); 
	} 
};



int dy[3] = { 0,1,1 };
int dx[3] = { 1,1,0 };

bool isRange(int y, int x)
{
	if (y >= 0 && y < n && x >= 0 && x < n) return true;
	return false;
}
void dfs(int y, int x, int dir,string curWord)
{
	curWord += board[y][x];

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
		for (int j = 0; j < n; j++)
			cin >> board[i][j];

	Trie* root = new Trie;
	for (int i = 0; i < m; i++)
	{
		string temp; cin >> temp;
		root->insert(temp.c_str());
	}
	
	
	return 0;
}