#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t, arr[100001];
vector<int> lis;

int main()
{
	cin >> t;
	while (t--)
	{
		int N; cin >> N;
		for (int i = 1; i <= N; i++) { cin >> arr[i]; cin.ignore(); }
		lis.push_back(0);
		for (int i = 1; i <= N; i++)
		{
			int temp = 0;
			temp = arr[i];
			if (arr[i] <= lis.back())
			{
				lis[lower_bound(lis.begin(), lis.end(), temp) - lis.begin()] = temp;
			}
			else
			{
				lis.push_back(temp);
			}

		}

		cout << lis.size() - 1 << "\n";


		lis.clear();
	}
	
	return 0;
}