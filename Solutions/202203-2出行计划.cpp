/*
	202203-2 出行计划
	Date: 2022.04.07
	Dev-CPP(C++语言)
	得分：100
	时间使用：295ms
	空间使用：3.585MB
	Others：前缀和与差分算法
*/

#include<iostream>


using namespace std;

int temp[200001] = { 0 };

int main()
{

	int k = 0;
	int num_plan = 0;
	int num_select = 0;

	int start = 0;
	int check = 0;
	int select = 0;

	cin >> num_plan >> num_select >> k;

	for (int i = 0; i < num_plan; i++)
	{
		cin >> start  >> check;
		temp[max(1, start - k - check + 1)]++;
		temp[max(1, start - k + 1)]--;
	}

	for (int i = 1; i < 200001; i++)
	{
		temp[i] = temp[i] + temp[i - 1];
	}

	for (int j = 1; j < num_select+1; j++)
	{
		cin >> select;
		cout << temp[select] << endl;
	}


}