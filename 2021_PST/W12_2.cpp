#include <bits/stdc++.h>
#define MAX 500000
using namespace std;

int t, n;
pair<int, int> arr[MAX];

bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.first > b.first;
}
int main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i].first >> arr[i].second;
		}
		sort(arr, arr + n, cmp);
		int n_hubo = 1, min_dist=arr[0].second;
		for (int i = 1; i < n; i++)
		{
			if (arr[i].second < min_dist)
			{
				min_dist = arr[i].second;
				n_hubo++;
			}
			
		}
		cout << n_hubo << "\n";

	}
	return 0;
}