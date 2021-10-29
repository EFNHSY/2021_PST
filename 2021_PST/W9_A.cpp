#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll t, x, n, m;

ll myPow(ll a, ll b)
{
	if (b == 0) return 1;
	if (b == 1) return a % m;

	if (b % 2 == 0)
	{
		ll temp = myPow(a, b / 2) % m;
		return (temp * temp) % m;
	}
	else
	{
		return ((myPow(a, b - 1)%m)*(a%m))%m;
	}
}

ll func(ll k)
{
	if (k == 0) return 0;
	if (k == 1) return (x % m);
	if (k % 2 == 0)
	{
		return ((func(k / 2) % m) * ((myPow(x, k / 2) + 1) % m)) % m;
	}
	else
	{
		return (((func(k / 2) % m) * ((myPow(x, k / 2) + 1) % m)) % m + myPow(x, k) % m) % m;
	}
}

int main()
{
	cin >> t;
	while (t--)
	{
		cin >> x >> n >> m;
		cout << func(n) << "\n";
	}
	
	

	return 0;
}