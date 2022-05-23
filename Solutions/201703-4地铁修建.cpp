/*
	201703-4 地铁修建
	Date: 2022.05.14
	Dev-CPP(C++语言C++14标准)
	得分：100
	时间使用：437ms
	空间使用：7.335MB
	Others：最小生成树 - Kruskal算法
*/

#include<iostream>
#include<vector> 
#include<algorithm>
using namespace std;

// 定义边 
struct edge {
	int u, v;
	int weight;
	edge(int x, int y, int w) :u(x), v(y), weight(w) {}
};

bool cmpEdge(edge a, edge b)
{
	return a.weight < b.weight;
}

int father[100001];

// 并查集 - 查找根节点
int findroot(int x)
{
	if (father[x] == x)
		return x;
	return father[x] = findroot(father[x]); // 路径压缩
}

// Kruskal算法求最小生成树
int kruskal(int v_num, int e_num, vector<edge>& E)
{
	for (int i = 0; i < v_num; i++)
	{
		father[i] = i;
	}
	sort(E.begin(), E.end(), cmpEdge);
	for (int i = 0; i < e_num; i++)
	{
		int Xroot = findroot(E[i].u);
		int Yroot = findroot(E[i].v);
		if (Xroot != Yroot)
		{
			father[Xroot] = Yroot;
			if(findroot(0) == findroot(v_num-1))
				return E[i].weight;
		}
	}
}


int main()
{
	int n, m;
	cin >> n >> m;
	vector<edge> E;

	int v, e, w;
	for (int i = 0; i < m; i++)
	{
		cin >> v >> e >> w;
		v = v - 1;
		e = e - 1;
		E.push_back(edge(v, e, w));
	}

	int res = kruskal(n, m, E);
	cout << res << endl;
}