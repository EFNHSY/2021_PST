#include <bits/stdc++.h>
#define MAX 3000
using namespace std;

int n, m;
char board[MAX][MAX];
vector<string> T;
vector<int> getPi(string p) {
	int m = (int)p.size(), j = 0;
	vector<int> pi(m, 0);

	for (int i = 1; i < m; i++) {
		while (j > 0 && p[i] != p[j]) j = pi[j - 1];
		if (p[i] == p[j]) pi[i] = ++j;
	}
	return pi;
}vector<int> kmp(string s, string p)
{
	vector<int> ans;
	auto pi = getPi(p);

	int n = (int)s.size(), m = (int)p.size(), j = 0;
	for (int i = 0; i < n; i++)
	{
		// mismatch
		while (j > 0 && s[i] != p[j]) j = pi[j - 1];
		// match
		if (s[i] == p[j])
		{
			if (j == m - 1)
			{
				ans.push_back(i - m + 1);
				j = pi[j];
			}
			else
			{
				j++;
			}
		}
		
		
	}
	return ans;
}
int main()
{
	string T, P;
	getline(cin, T);
	getline(cin, P);
	vector<int> ans = kmp(T, P);
	cout << ans.size() << "\n";
	for (auto u : ans)
	{
		cout << u+1 << "\n";
	}
	return 0;
}