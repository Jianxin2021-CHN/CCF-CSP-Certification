/*
	202104-4 校门外的树
	Date: 2022.04.10
	Dev-CPP(C++语言C++14标准)
	得分：100
	时间使用：78ms 
	空间使用：14.25MB
	Others：动态规划
	参考：https://blog.csdn.net/m0_53641110/article/details/123450609 
*/

#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1e3 + 10, ai = 1e5 + 10, MOD = 1e9 + 7;

int obstracle[N];
int method[N];

bool isdivisor[ai];
vector<int>divisor[ai];

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> obstracle[i];
	}

	method[0] = 1;

	// 初始化约数
	for (int i = 1; i < ai; i++)
	{
		for (int j = 2 * i; j < ai; j = j + i)
		{
			divisor[j].push_back(i);
		}
	}

	// 枚举所有状态
	for (int i = 0; i < n; i++)
	{
		memset(isdivisor, 0, sizeof(isdivisor));  

		// 倒序枚举最后一个区间的左端点
		for (int j = i - 1; j >= 0; j--)
		{
			// 区间长度
			int d = obstracle[i] - obstracle[j];

			// 该区间内的选法种数
			int count = 0;

			// 枚举d的每个约数
			for (int k : divisor[d])
			{
				// 判断k是否已经出现过
				if (!isdivisor[k])
				{
					count++;
					isdivisor[k] = true;
				}
			}

			// 障碍物点不能种树
			isdivisor[d] = true;

			method[i] = (method[i] + (long long)method[j] * count) % MOD;
		}
	}

	cout << method[n - 1] << endl;
	return 0;
}
