
#include <bits/stdc++.h>
#define INF 987654321
#define MAXN 10001
#define MAXM 100002
using namespace std;

vector<pair<int, int>> adj[MAXN]; // adjcaent list
int n, m, q;

struct item
{
	int key; // cost가 낮을 수록 우선순위가 높음
	int node_num; // 다음에 방문할 노드
};


struct myHeap
{
	item minHeap[MAXM]; // dense한 그래프일경우 queue 에 최대 m개가 들어올수 있다.
	int size;

public:
	myHeap()
	{
		for (int i = 0; i < MAXM; i++)
		{
			minHeap[i].key = minHeap[i].node_num = INF;
		}
		size = 0;
	}
	void swap(item& i1, item& i2)
	{
		item temp;
		temp = i1;
		i1 = i2;
		i2 = temp;
		return;
	}
	void push(int key_,int node_num_)
	{
		if (size >= MAXM)
		{
			// heap 에 더 이상 추가될수 없는 상태 
			return;
		}
		
		int idx = ++size;;
		while (idx > 1 && key_ <= minHeap[idx/2].key)
		{
			if (key_ == minHeap[idx / 2].key)
			{
				if (node_num_ <= minHeap[idx / 2].node_num)
				{
					minHeap[idx] = minHeap[idx / 2];
					idx /= 2;
				}
				else {
					break;
				}
			}
			else
			{
				minHeap[idx] = minHeap[idx / 2];
				idx /= 2;
			}
		}
		minHeap[idx].key = key_;
		minHeap[idx].node_num = node_num_;
	}

	item top()
	{
		if (size > 0)
		{
			return minHeap[1];
		}	
	}

	bool isEmpty()
	{
		return size == 0;
	}

	void pop()
	{
		if (size <= 0) return;
		item lastItem = minHeap[size];
		minHeap[size] = { INF,INF };
		size--;

		int idx = 1;

		while (idx <= size)
		{
			if (idx * 2 + 1 > size)
			{
				break;
			}

			item leftChild = minHeap[idx * 2];
			item rightChild = minHeap[idx * 2 + 1];
			
			
			if (leftChild.key < rightChild.key)
			{
				if (lastItem.key > leftChild.key)
				{
					minHeap[idx] = minHeap[idx * 2];
					idx *= 2;
				}
				else if (lastItem.key == leftChild.key)
				{
					if (lastItem.node_num > leftChild.node_num)
					{
						minHeap[idx] = minHeap[idx * 2];
						idx *= 2;
					}
					else
					{
						break;
					}
				}
				else
				{
					break;
				}
			}
			else if (leftChild.key == rightChild.key)
			{
				if (leftChild.node_num <= rightChild.node_num)
				{
					//left child선택
					if (lastItem.key > leftChild.key)
					{
						minHeap[idx] = minHeap[idx * 2];
						idx *= 2;
					}
					else if (lastItem.key == leftChild.key)
					{
						if (lastItem.node_num > leftChild.node_num)
						{
							minHeap[idx] = minHeap[idx * 2];
							idx *= 2;
						}
						else
						{
							break;
						}
					}
					else
					{
						break;
					}
				}
				else
				{
					// rightchild 선택 
					if (lastItem.key > rightChild.key)
					{
						minHeap[idx] = minHeap[idx * 2 + 1];
						idx = idx * 2 + 1;
					}
					else if (lastItem.key == rightChild.key)
					{
						if (lastItem.node_num > rightChild.node_num)
						{
							minHeap[idx] = minHeap[idx * 2 + 1];
							idx = idx * 2 + 1;
						}
						else
						{
							break;
						}
					}
					else
					{
						break;
					}
				}
			}
			else
			{
				if (lastItem.key > rightChild.key)
				{
					minHeap[idx] = minHeap[idx * 2+1];
					idx = idx * 2 + 1;
				}
				else if (lastItem.key == rightChild.key)
				{
					if (lastItem.node_num > rightChild.node_num)
					{
						minHeap[idx] = minHeap[idx * 2+1];
						idx = idx * 2 + 1;
					}
					else
					{
						break;
					}
				}
				else
				{
					break;
				}
			}
		}

		minHeap[idx] = lastItem;
	}
};

myHeap pq;

void prim(int start)
{
	int dist = 0;
	vector<int> tree_order;
	vector<bool> visited(n + 1, false);
	pq.push(0, start);

	while (!pq.isEmpty())
	{
		int curV = pq.top().node_num;
		int curC = pq.top().key;
		pq.pop();

		

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
				pq.push(nextC, nextV);
			}

		}
		
	}
	cout << dist << " ";
	for (auto u : tree_order)
	{
		cout << u << " ";
	}cout << "\n";

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
		
		char c; int start;
		cin >> c >> start;
		prim(start);
	}


	return 0;
}