#include <bits/stdc++.h>
#define MAX 101
#define INF 987654321
using namespace std;

int t, n, dp[MAX][MAX], arr[MAX][MAX];

int main()
{
	cin >> t;
	while (t--)
	{
		
		for (int i = 0; i < MAX; i++)
		{
			for (int j = 0; j < MAX; j++)
			{
				arr[i][j] = dp[i][j] = INF;
			}
		}
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				cin >> arr[i][j];
				
			}
		}

		dp[1][1] = arr[1][1];
		for (int i = 2; i <= n; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + arr[i][j];
			}
		}

		
		int ans = INF;
		for (int i = 1; i <= n; i++)
		{
			ans = (ans > dp[n][i] ? dp[n][i] : ans);
		}
		cout << ans << "\n";
	}
	return 0;
}