#include <bits/stdc++.h>
using namespace std;
#define NMAX 1025
int t, n, arr[NMAX][NMAX];

pair<int, int> operator +(pair<int, int> a, pair<int, int> b)
{
	return { a.first + b.first, a.second + b.second };
}

pair<int, int> makePaper(int x, int y, int size)
{
	if (size == 1)
	{
		if (arr[y][x] == 0) return { 0,1 };
		else return { 1,0 };
	}

	int temp = arr[y][x];
	for (int i = y; i < y + size; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			if (temp != arr[i][j])
			{

				return makePaper(x, y, (size / 2)) + makePaper(x + (size / 2), y, (size / 2)) + makePaper(x, y + (size / 2), (size / 2)) + makePaper(x + (size / 2), y + (size / 2), (size / 2));

			}
		}
	}

	if (arr[y][x])
	{
		return { 1,0 };
	}
	else
	{
		return { 0,1 };
	}
}

int main()
{
	cin >> t;
	while (t--)
	{
		int red = 0, blue = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				char c; cin >> c;
				if (c == 'R')
				{
					arr[i][j] = 0;
				}
				else
				{
					arr[i][j] = 1;
					blue++;
				}
			}
		}
		pair<int, int> res;
		res = makePaper(0, 0, n);
		red = n * n - blue;
		cout << res.second << " " << red << " " << res.first << " " << blue << "\n";
	}
	
	return 0;
}