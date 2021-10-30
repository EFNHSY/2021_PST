#include <bits/stdc++.h>
#define MAX 21
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int t, n, q;
int board[MAX][MAX];
/*�н�����
int board[9][9] = {
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,1,0,-1,-1,-1,-1},
	{0,0,0,0,1,1,-1,-1,-1},
	{0,1,1,1,1,1,1,-1,-1},
	{0,1,0,1,-1,1,1,0,-1},
	{0,1,1,1,1,1,1,1,-1},
	{0,1,1,1,1,1,1,0,-1},
	{0,1,0,1,1,0,0,0,0},
	{0,0,0,0,-1,-1,-1,0,0} };
	*/
int temp[MAX][MAX];
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };
int dx[8] = { 1,1,0,-1,-1,-1,0,1 };

bool isRange(int y, int x)
{
	if (y >= 1 && y <= n && x >= 1  && x <= n) return true;
	return false;
}
int check(int y, int x,int dir,int type)
{
	int cnt = 0;
	int ny = y, nx = x;
	while (true)
	{
		ny += dy[dir], nx += dx[dir];
		if (!isRange(ny, nx))
		{
			for (int i = 0; i < cnt; i++)
			{
				ny -= dy[dir], nx -= dx[dir];
				board[ny][nx] = -type;
			}
			return 0;
		}
		else if (board[ny][nx] == 0)
		{
			for (int i = 0; i < cnt; i++)
			{
				ny -= dy[dir], nx -= dx[dir];
				board[ny][nx] = -type;
			}
			return 0;
		}
		else if (board[ny][nx] == type)
		{
			return cnt;
		}
		else
		{
			board[ny][nx] = type;
			cnt++;
		}
	}
}
void initialize()
{
	for (int i = 1; i < MAX; i++)
	{
		for (int j = 1; j < MAX; j++)
		{
			board[i][j] = 0;
		}
	}

	board[n / 2][n / 2] = board[n / 2 + 1][n / 2 + 1] = 1; // black
	board[n / 2 + 1][n / 2] = board[n / 2][n / 2 + 1] = -1; // white

	
	
}
void print(int turn)
{
	cout << "������ �� : " << turn << "\n";
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (board[i][j] == 1) cout << "o ";
			else if (board[i][j] == -1) cout << "x ";
			else cout << "  ";
		}cout << "\n";
	}
}
bool isFull()
{
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (board[i][j] == 0) sum++;
		}
	}
	if (sum == 0) return true;
	return false;
}
int canPlace(int turn)
{
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			temp[i][j] = board[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (board[i][j] == -turn)
			{
				
				for (int k = 0; k < 8; k++)
				{
					int ny = i + dy[k];
					int nx = j + dx[k];
					
					if (isRange(ny, nx) && (board[ny][nx] == 0))
					{
						for (int l = 0; l < 8; l++)
						{
							cnt += check(ny, nx, l, turn);
						}	
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			board[i][j] = temp[i][j];
		}
	}
	
	return cnt;
}
void play()
{
	int turn = 1; // black first
	while (q--)
	{
		
		/**/
		if (canPlace(turn) == 0) turn = -turn; // �ڽ��� ������ ���� �� �� �ִ� ��ġ�� �������� ������ ������ �Ѿ��.
		
		int r, c; cin >> r >> c;
		/* �� �� ���� ������ �Է� ���� �� ó�� */
		if (!isRange(r, c)) continue;
		if (board[r][c] != 0) continue; // �̹� �� �ڸ��� ���� ���� ���
		int cnt = 0;
		for (int i = 0; i < 8; i++)
		{	
			cnt += check(r, c, i, turn);
		}
		if (cnt == 0) continue; // ���� ������ �ƹ��͵� �ٲ��� �ʴ°��
		board[r][c] = turn;
		
		//print(turn);
		turn = -turn; // turn change
		
	}
}
int count()
{
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			sum += board[i][j];
		}
	}
	return sum;
}
int main()
{
	FASTIO;
	cin >> t;
	while (t--)
	{
		
		cin >> n >> q;
		
		initialize();

		
		play();
		int ans = count();
		
		//cout << "ans: ";
		if (ans > 0) cout << "2\n";
		else if (ans < 0) cout << "1\n";
		else cout << "0\n";
		
	}
	return 0;
}