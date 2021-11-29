#include <bits/stdc++.h>
#define MAX 3000
using namespace std;

int n, m;
char board[MAX][MAX];
vector<string> T;

struct Trie
{
	Trie* go[26];
	Trie* fail;
	bool output;
	const char* finished_output;

	Trie()
	{
		fill(go, go + 26, nullptr);
		output = false;
	}
	~Trie()
	{
		for (int i = 0; i < 26; i++)
			if (go[i]) delete go[i];
	}

	void insert(const char* key)
	{
		if (*key == '\0')
		{
			output = true;
			finished_output = key;
			return;
		}
		int next = *key - 'A';
		if (!go[next])
		{
			go[next] = new Trie();
		}
		go[next]->insert(key + 1);
	}


};
const char* find_aho(Trie* root,const char* s) {
	int i;
	Trie* current = root;

	for (i = 0; s[i]; i++) {
		int next = s[i] - 'a';
		while (current != root && !current->go[next])
			current = current->fail;
		if (current->go[next])
			current = current->go[next];
		if (current->output)
			return current->finished_output;
	}

	return "";
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	string temp2 = "";
	for (int i = 0; i < n; i++)
	{
		string temp = "";
		
		for (int j = 0; j < n; j++)
		{
			temp += board[i][j];
		}
		T.push_back(temp);
		
		temp = "";
		for (int j = 0; j < n; j++)
		{
			temp += board[j][i];
		}
		T.push_back(temp);

		if (i > 0)
		{
			temp = "";
			for (int j = 0; j < n-i; j++)
			{
				temp += board[i+j][j];
			}
			T.push_back(temp);
			temp = "";
			for (int j = 0; j < n-i; j++)
			{
				temp += board[j][i+j];
			}
			T.push_back(temp);
		}
		
		
		temp2 += board[i][i];
	}
	T.push_back(temp2);

	Trie* root = new Trie();
	for (int i = 0; i < m; i++)
	{
		string temp; cin >> temp;
		root->insert(temp.c_str());
	}


	queue<Trie*> q;
	root->fail = root;
	while (!q.empty())
	{
		Trie* cur = q.front();
		q.pop();

		for (int i = 0; i < 26; i++)
		{
			Trie* next = cur->go[i];
			if (!next) continue;

			if (cur == root)
			{
				next->fail = root;
			}
			else
			{
				Trie* dest = cur->fail;

				while (dest != root && !dest->go[i])
				{
					dest = dest->fail;
				}
				if (dest->go[i]) dest = dest->go[i];
				next->fail = dest;
			}
			if (next->fail->output) next->output = true;

			q.push(next);
		}
	}

	for (auto u : T)
	{
		cout << find_aho(root, u.c_str()) << "\n";
	}
	delete root;

	return 0;
}