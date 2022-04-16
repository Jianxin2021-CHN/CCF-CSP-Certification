/*
	202203-1 未初始化警告
	Date: 2022.04.07
	Dev-CPP(C++语言)
	得分：100
	时间使用：140ms
	空间使用：4.011MB
*/

#include<iostream>

using namespace std;

int n_num[100001];
int k_num[100001][2];

int main()
{
	int n, k;
	cin >> n >> k;

	n_num[0] = 1;
	for (int i = 1; i < n+1; i++)
	{
		n_num[i] = 0;
	}

	int sum = 0;
	for (int i = 0; i < k; i++)
	{
		cin >> k_num[i][0] >> k_num[i][1];
		if (n_num[k_num[i][1]] == 0)
			sum++;
		n_num[k_num[i][0]] = 1;
	}

	cout << sum;
}
 
