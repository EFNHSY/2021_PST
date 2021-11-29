
#include <bits/stdc++.h>
#define INF 987654321
#define MAXN 10010
using namespace std;

vector<pair<int, int>> adj[MAXN]; // adjcaent list
int n, m, q;

#include <bits/stdc++.h>
#define INF 987654321
#define MAXN 10010
using namespace std;

vector<pair<int, int>> adj[MAXN]; // adjcaent list
int n, m, q;

struct item
{
	int priority; // cost가 낮을 수록 우선순위가 높음
	int value; // 다음에 방문할 노드
};

// Store the element of a priority queue
item pr[100000];

// Pointer to the last index
int size__ = -1;

// Function to insert a new element
// into priority queue
void enqueue(int value, int priority)
{
	// Increase the size__
	size__++;

	// Insert the element
	pr[size__].value = value;
	pr[size__].priority = priority;
}

// Function to check the top element
int peek()
{
	int highestPriority = INT_MIN;
	int ind = -1;

	// Check for the element with
	// highest priority
	for (int i = 0; i <= size__; i++) {

		// If priority is same choose
		// the element with the
		// highest value
		if (highestPriority
			== pr[i].priority
			&& ind > -1
			&& pr[ind].value
			< pr[i].value) {
			highestPriority = pr[i].priority;
			ind = i;
		}
		else if (highestPriority
			< pr[i].priority) {
			highestPriority = pr[i].priority;
			ind = i;
		}
	}

	// Return position of the element
	return ind;
}

// Function to remove the element with
// the highest priority
void dequeue()
{
	// Find the position of the element
	// with highest priority
	int ind = peek();

	// Shift the element one index before
	// from the position of the element
	// with highest priortity is found
	for (int i = ind; i < size__; i++) {
		pr[i] = pr[i + 1];
	}

	// Decrease the size__ of the
	// priority queue by one
	size__--;
}

void prim(int start)
{
	int dist = 0;
	vector<int> tree_order;
	vector<bool> visited(n + 1, false);
	enqueue(0, start);

	while (true)
	{
		
		int idx = myTop();
		if (idx < 0) break;
		int curV = myPQ[idx].node_num;
		int curC = myPQ[idx].key;
		myPop();
	
		if (!visited[curV])
		{
			visited[curV] = true;
			tree_order.push_back(curV);
			dist += curC;
		}

		for (auto u : adj[curV])
		{
			int nextV = u.first;
			int nextC = u.second;
			if (!visited[nextV])
			{
				enqueue(nextC, nextV);
			}

		}
		if (p_last_idx < 0) break;
	}
	cout << dist << " ";
	for (auto u : tree_order)
	{
		cout << u << " ";
	}cout << "\n";

}
void init()
{
	p_last_idx = -1;
	for (int i = 0; i < MAXN; i++)
	{
		myPQ[i].key = myPQ[i].node_num = 0;
	}
}
bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.first < b.first;
}
int main()
{

	cin >> n >> m >> q;
	for (int i = 0; i < m; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		adj[a].push_back({ b,w });
		adj[b].push_back({ a,w });

	}
	for (int i = 1; i <= n; i++)
	{
		sort(adj[i].begin(), adj[i].end(), cmp);
	}
	while (q--)
	{
		init();
		char c; int start;
		cin >> c >> start;
		prim(start);
	}


	return 0;
}
void prim(int start)
{
	int dist = 0;
	vector<int> tree_order;
	vector<bool> visited(n + 1, false);
	myInsert(0, start);

	while (true)
	{

		int idx = myTop();
		if (idx < 0) break;
		int curV = myPQ[idx].node_num;
		int curC = myPQ[idx].key;
		myPop();

		if (!visited[curV])
		{
			visited[curV] = true;
			tree_order.push_back(curV);
			dist += curC;
		}

		for (auto u : adj[curV])
		{
			int nextV = u.first;
			int nextC = u.second;
			if (!visited[nextV])
			{
				myInsert(nextC, nextV);
			}

		}
		if (p_last_idx < 0) break;
	}
	cout << dist << " ";
	for (auto u : tree_order)
	{
		cout << u << " ";
	}cout << "\n";

}
void init()
{
	p_last_idx = -1;
	for (int i = 0; i < MAXN; i++)
	{
		myPQ[i].key = myPQ[i].node_num = 0;
	}
}
bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.first < b.first;
}
int main()
{

	cin >> n >> m >> q;
	for (int i = 0; i < m; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		adj[a].push_back({ b,w });
		adj[b].push_back({ a,w });

	}
	for (int i = 1; i <= n; i++)
	{
		sort(adj[i].begin(), adj[i].end(), cmp);
	}
	while (q--)
	{
		init();
		char c; int start;
		cin >> c >> start;
		prim(start);
	}


	return 0;
}