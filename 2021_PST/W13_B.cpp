#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MAX 500000
using namespace std;

long long t, n, m;
long long arr[MAX];
long long cnt_read[MAX];

int main()
{
	FASTIO;
	cin >> t;
	while (t--)
	{
		set<int> s;
		cin >> n >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> arr[i];
		}
		for (int i = m - 1; i >= 0; i--)
		{
			s.insert(arr[i]);
			cnt_read[i] = (n - s.size());
		}
		for (int i = 0; i < m; i++)
		{
			cout << cnt_read[i] << "\n";
		}
	}

	return 0;
}