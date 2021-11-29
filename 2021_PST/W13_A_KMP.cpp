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

	int n = (int)s.size(), m = (int)p.size(), j =0; 
	for(int i = 0 ; i < n ; i++)
	{
		while(j>0 && s[i] != p[j]) j = pi[j-1]; 
		if(s[i] == p[j])
		{ 
			if(j==m-1)
			{ 
				ans.push_back(i-m+1); 
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
			for (int j = 0; j < n - i; j++)
			{
				temp += board[i + j][j];
			}
			T.push_back(temp);
			temp = "";
			for (int j = 0; j < n - i; j++)
			{
				temp += board[j][i + j];
			}
			T.push_back(temp);
		}


		temp2 += board[i][i];
	}
	T.push_back(temp2);

	for (int i=0;i<m;i++)
	{
		bool flag = false;
		string p; cin >> p;
		for (auto u : T)
		{
			if (kmp(u, p).size() > 0)
			{
				flag = true;
				break;
			}
		}
		cout << (flag ? "1" : "0") << "\n";
	}
	return 0;
}