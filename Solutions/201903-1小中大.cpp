/*
	201903-1 小中大
	Date: 2022.05.23
	Dev-CPP(C++语言)
	得分：100
	时间使用：93ms
	空间使用：3.300MB
*/

#include<iostream>
#include<algorithm>
using namespace std;

int arr[1000010];

int main()
{
	int n;
	cin >> n;
	int maxs=0,mins=0;
	int mids = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	if (n == 1)
		cout << arr[0] << arr[0] << arr[0];
	else
	{
		if (arr[n-1] - arr[0] > 0)
		{
			maxs = arr[n-1];
			mins = arr[0];
		}
			
		else
		{
			maxs = arr[0];
			mins = arr[n-1];
		}
		mids = arr[n / 2-1] + arr[n / 2 + 1-1];
		if (n % 2 == 0)
		{
			if(mids %2 == 0)
				cout << maxs << " " << mids/2 << " " << mins;
			else
				cout << maxs << " " << mids / 2<<".5" << " " << mins;
		}
		else
		{
			mids = (arr[n / 2+1-1]);
			cout << maxs << " " << mids << " " << mins;
		}
	}

}