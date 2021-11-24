#include <bits/stdc++.h>
#define NEGINF -987654321
using namespace std;

int m;
int canuse[27];
int curuse[27];
string word[24];
int score[24];
bool chosen[24];
int max_score = NEGINF;
vector<int> subset;


void search(int k)
{

	if (k == m)
	{


		// subset에 포함된 단어들을 만들수있는지 확인
		int cur_score = 0;
		memset(curuse, 0, sizeof(curuse));
		for (auto i : subset)
		{
			for (int j = 0; j < word[i].size(); j++)
			{

				curuse[word[i][j] - 'a' + 1]++;
			}
		}



		for (int i = 1; i <= 26; i++)
		{
			if (canuse[i] - curuse[i] < 0)
			{

				return;
			}
		}

		for (auto u : subset)
		{
			cur_score += score[u];
		}

		max_score = max(max_score, cur_score);
		return;

	}
	else
	{
		for (int i = k + 1; i <= m; i++)
		{
			subset.push_back(i);
			search(i);
			subset.pop_back();
		}
	}



}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 1; i <= 26; i++)
	{
		cin >> canuse[i];
	}
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> word[i] >> score[i];
	}
	search(0);

	cout << max_score << "\n";
	return 0;
}