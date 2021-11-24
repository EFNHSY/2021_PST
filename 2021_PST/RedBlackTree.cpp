#include <bits/stdc++.h>
#define BLACK 1
#define RED -1
using namespace std;

struct node
{
	// app 관련 정보
	int app_key; // unique key 
	string app_name;
	int app_vol;
	int app_price;
	
	// 노드 자체 정보
	int color = BLACK;
	node* left = nullptr;
	node* right = nullptr;
	node* parent = nullptr;
	
};

typedef node* NodePtr;

class RedBlackTree
{
private:
	NodePtr root;
	NodePtr leaf;

	NodePtr findKey(int key)
	{
		NodePtr temp = root;
		NodePtr parent = nullptr;

		// root node부터 level을 1씩 증가시키며 아래로 내려간다. 
		// 찾으려는 키값이 현재 키값보다 크다면 오른쪽, 아니면 왼쪽으로 내려간다. 
		// 찾으려는 값이 트리에 없다면, nullptr을 반환한다. 
		while (temp != NULL && temp->app_key != key)
		{
			parent = temp;
			temp = (key > temp->app_key ? parent->right : parent->left);
		}
		return temp;
	}

	void insertKey(int key,string name,int vol,int price)
	{
		NodePtr toInsr= new node();// 삽입해야 할 것
		NodePtr temp = this->root, temp_parent = nullptr; // 위치만 찾기 위해 쓰이는 것

		toInsr->app_key = key;
		toInsr->app_name = name;
		toInsr->app_vol = vol;
		toInsr->app_price = price;
		toInsr->color = RED;
		toInsr->left = leaf;
		toInsr->right = leaf;
		toInsr->parent = nullptr;

		/*--toInsr가 들어갈 위치를 찾는 과정--*/
		while (temp != leaf)
		{
			temp_parent = temp;
			if(key> temp->app_key)
			{
				temp = temp->right;
			}
			else
			{
				temp = temp->left;
			}
			
		}

		/*--toInsr가 적당한 위치에 일단 삽입 하는 과정--*/
		toInsr->parent = temp_parent; 

		if (temp_parent == nullptr)
		{
			root = toInsr; //  부모노드가 nullptr인 경우는 루트
		}
		else if (toInsr->app_key > temp_parent->app_key)
		{
			temp_parent->right = toInsr;
		}
		else
		{
			temp_parent->left = toInsr;
		}

		/*--트리에 처음 삽입되는 경우, 즉 root에 삽입되는 경우--*/
		if (toInsr->parent == nullptr)
		{
			toInsr->color = BLACK;
			return;
		}

		/*--root 바로 다음 level에 삽입되는 경우--*/ 
		if (toInsr->parent->parent == nullptr)
		{
			// 이 경우 트리의 depth가 1이기때문에 double red 가 발생할 수 없다.
			return;
		}
		
		doubleRed(toInsr);

		return;
	}

	void doubleRed(NodePtr toInsr)
	{
		while (toInsr != root && toInsr->parent->color == RED)
		{
			NodePtr grandParent = toInsr->parent->parent;
			
			NodePtr uncle = (toInsr->parent == grandParent->right ? grandParent->left : grandParent->right);


			if (uncle && uncle->color == RED)
			{
				/*Recoloring*/
				// uncle이 존재하고(nullptr X) color가 RED일경우

				toInsr->parent->color = BLACK;
				uncle->color = BLACK;
				grandParent->color = RED;
				toInsr = grandParent; // doublered를 grandparent 노드로의 인계
			}
			else
			{
				/*Restructuring*/
				// 부모의 노드가 red 일경우
				/*
					case1		case2		case3		case4
					  B			  B			  B			  B
					R		   R				 R			  R
				  R				 R					R		R

				*/
				if (grandParent->left == toInsr->parent) 
				{ // case1 or case2
					if (toInsr == toInsr->parent->right)
					{
						//case 2의 경우 case1의 모양으로 만들어야 한다.
						toInsr = toInsr->parent;
						rotateLeft(toInsr);
					}
					
					toInsr->parent->color = BLACK;
					grandParent->color = RED;
					rotateRight(grandParent);
				}
				else if (grandParent->right == toInsr->parent) 
				{// case 3 or case 4
					if (toInsr == toInsr->parent->left)
					{
						//case 4의 경우 case3 모양으로 만들어야 한다.
						toInsr = toInsr->parent;
						rotateRight(toInsr);
					}
					toInsr->parent->color = BLACK;
					grandParent->color = RED;
					rotateLeft(grandParent);
				}
				
			}
		
		}
		root->color = BLACK;
	}

	/* 
		rotation 은 https://ict-nroo.tistory.com/70 의 pseudocode를 참고함.
	*/
	// x 중심으로 왼쪽회전
	/*
		 x				y
	   a   y	--->  x   r
		 b	 r		a	b
	*/
	void rotateLeft(NodePtr x)
	{
		NodePtr y = x->right; // 1. x의 오른쪽 자식을 y에 저장
		x->right = y->left; // 2. x의 오른쪽자식을 b로 저장
		if (y->left != leaf)
		{
			y->left->parent = x; // 3. b가 leaf가 아니라면, b의 부모를 x로 만든다.
		}
		y->parent = x->parent; // 4. 이전 x의 부모를 y의 부모로 만든다.
		if (!x->parent)
		{
			root = y; // 5. x의 부모가 nullptr이라면, 즉 x가 root였다면 y를 root로 만든다.
		}
		else if (x == x->parent->left)
		{
			//6-1. x의 부모가 존재하고(root아님) x가 부모의 왼쪽자식이라면
			x->parent->left = y; // y가 이전 x의 부모의 왼쪽자식이 된다.
		}
		else
		{
			//6-2. x의 부모가 존재하고(root아님) x가 부모의 오른쪽자식이라면
			x->parent->right = y; // y가 이전 x의 부모의 오른쪽자식이 된다.
		}
		x->parent = y; // 7. x의 부모가 y가 되게하고
		y->left = x; // 8. y의 왼쪽자식이 x가 되게한다. 


	}
	// x 중심으로 오른쪽회전
	/*
		  y					x
		x   r	---->     a	  y
      a   b					b   r
	*/
	void rotateRight(NodePtr y)
	{
		NodePtr x = y->left; // 1. y의 왼쪽자식을 x에 저장
		y->left = x->right; // 2. y의 왼쪽자식을 이전 x의 오른쪽자식으로 저장
		if (x->right != leaf) 
		{
			x->right->parent = y; // 3. b가 leaf가 아니라면, b의 부모를 y로 저장
		}
		x->parent = y->parent; // 4. 이전 y의 부모를 x의 부모로 바꿈

		if (!y->parent) 
		{
			root = x; // 5. y의 부모가 존재하지 않았다면(y가 root라면) x를 root 로 만듬
		}
		else if (y == y->parent->left)
		{
			//6.1 y의 부모가 존재하고 y가 부모의 왼쪽 자식이었다면,
			y->parent->left = x; //  그 때 부모의 왼쪽자식을 x로 만듬
		}
		else
		{	// 6.2 y의 부모가 존재하고 y가 부모의 오른쪽자식이었다면,
			y->parent->right = x; //  그 때 부모의 오른쪽 자식을 y로 만듬
		}
		y->parent = x; // 7. y의 부모는 x가 되고
		x->right = y; // 8. x의 오른쪽 자식을 y로 만든다.

	}

	bool update(int key, string name, int vol, int price) // update하는 코드
	{
		NodePtr temp = findKey(key);
		if (temp != nullptr)
		{
			temp->app_name = name;
			temp->app_vol = vol;
			temp->app_price = price;
			
			return true;
		}
		return false;
	}

	
public:
	RedBlackTree()
	{
		leaf = new node();
		leaf->color = BLACK; // leaf의 color는 black
		leaf->right = nullptr;
		leaf->left = nullptr;
		leaf->parent = nullptr;
		root = leaf;
	}
	int getDepth(int key) // key가 주어졌을때 depth를 구하는 코드
	{
		int depth = 0;
		NodePtr temp = this->root, temp_parent = nullptr;

		while (temp->app_key != key)
		{
			temp_parent = temp;
			if (key > temp->app_key)
			{
				temp = temp->right;
			}
			else
			{
				temp = temp->left;
			}
			depth++;
		}
		return depth;
	}
	void play()
	{
		
		int n_query; cin >> n_query;
		while (n_query--)
		{
			char query;
			cin >> query;
			if (query == 'I')
			{
				
				int key, price, vol;
				string name;
				cin >> key >> name >> vol >> price;
				if (this->findKey(key) == nullptr)
				{
					this->insertKey(key, name, vol, price);
				}
				cout << getDepth(key) << "\n";
			}
			else if (query == 'F')
			{
				int key;
				cin >> key;
				NodePtr temp = this->findKey(key);
				if (temp == nullptr)
				{
					cout << "NULL\n";
				}
				else
				{
					cout << getDepth(key) << " " << temp->app_name << " " << temp->app_vol << " " << temp->app_price << "\n";
				}
			}
			else if (query == 'R')
			{
				int key, price, vol;
				string name;
				cin >> key >> name >> vol >> price;
				if (this->update(key, name, vol, price))
				{
					cout << getDepth(key) << "\n";
				}
				else
				{
					cout << "NULL\n";
				}
			}
			else if (query == 'D')
			{
				int start, end, p;
				cin >> start >> end >> p;
				for (int i = start; i <= end; i++)
				{
					NodePtr temp = this->findKey(i);
					if (temp != nullptr)
					{
						temp->app_price = (temp->app_price * (100 - p) / 100);
					}
					
				}
				
			}
			else
			{
				break;
			}
		}
	}
};
int main()
{
	RedBlackTree RBT;
	RBT.play();

	return 0;
}