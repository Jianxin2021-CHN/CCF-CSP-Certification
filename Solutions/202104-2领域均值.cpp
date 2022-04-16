/*
	202104-2 领域均值
	Date: 2022.04.10
	Dev-CPP(C++语言)
	得分：100
	时间使用：171ms
	空间使用：5.644MB
	Others：前缀和与差分算法
*/

#include<iostream>
using namespace std;

int image[602][602] = { 0 };
int sum_image[602][602] = { 0 };

int main()
{
	int n, L, r, t;
	cin >> n >> L >> r >> t;
	int num = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> image[i][j];
			// 计算二维前缀和
			sum_image[i][j] = sum_image[i - 1][j] + sum_image[i][j - 1] - sum_image[i - 1][j - 1] + image[i][j];

		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			// 确定领域下界
			int x_down = max(1, i - r);
			int y_down = max(1, j - r);

			// 确定领域上界 
			int x_up = min(n, i + r);
			int y_up = min(n, j + r);

			// 计算区域像素和
			int sum_pixel = sum_image[x_up][y_up] - sum_image[x_down-1][y_up] - sum_image[x_up][y_down-1] + sum_image[x_down-1][y_down-1];
			int sum_t = (y_up - ( y_down - 1)) * (x_up - ( x_down - 1));

			if (sum_t * t >= sum_pixel)
				num++;

		}
	}


	cout << num;
}