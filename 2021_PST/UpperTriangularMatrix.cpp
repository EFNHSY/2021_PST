#include <bits/stdc++.h>
using namespace std;

int n;

void findPivot(vector<vector<int>>& arr, int a, int b)
{

	for (int i = a + 1; i < n; i++)
	{
		if (arr[i][b] != 0)
		{
			for (int j = 0; j < n; j++)
			{
				swap(arr[b][j], arr[i][j]);
			}
			break;
		}

	}
}
int main()
{
	
	for (int i = 1; i <= 10; i++)
	{
		cout << "# Testcase : " << i << "\n";

		cout << "정수를 입력: ";
		cin >> n;

		// n*n 벡터 선언
		vector<vector<int>> arr(n, vector<int>(n, 0));

		//	input 
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
			}
		}

		// upper triangular matrix 적용
		for (int i = 0; i < n; i++)
		{
			if (arr[i][i] == 0)
			{
				findPivot(arr, i, i);
			}
			int pivot = arr[i][i];
			for (int j = i + 1; j < n; j++)
			{
				int temp = arr[j][i];

				int c1 = temp, c2 = pivot;
				for (int k = 0; k < n; k++)
				{
					arr[j][k] = arr[i][k] * c1 - arr[j][k] * pivot;
				}
			}
		}

		// output
		for (int i = 0; i < n; i++)
		{

			for (int j = 0; j < n; j++)
			{
				cout << arr[i][j] << " ";
			}cout << "\n";
		}
	}
	
	return 0;
}