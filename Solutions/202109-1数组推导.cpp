/*
	202109-1 �����Ƶ�
	Date: 2022.05.26
	Dev-CPP(C++����)
	�÷֣�100
	ʱ��ʹ�ã�31ms
	�ռ�ʹ�ã�3.085MB
*/

#include<iostream>
#include<algorithm>
using namespace std;

int arr[101];

int main()
{
	int n;
	int max;
	int min;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	min = arr[0];
	max = arr[0];

	for (int i = 1; i < n; i++)
	{
		if (arr[i] > arr[i - 1])
		{
			min = min + arr[i];
			max = max + arr[i];
		}
		else
		{
			min = min + 0;
			max = max + arr[i];
		}
	


	}

	cout << max << endl;
	cout << min << endl;
}