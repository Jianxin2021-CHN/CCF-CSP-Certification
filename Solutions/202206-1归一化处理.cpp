/*
	202206-1 归一化处理 
	Date: 2022.07.03
	Dev-CPP(C++语言C++14标准)
	得分：100
	时间使用：15ms
	空间使用：3.222MB
*/ 
# include<iostream>
# include<cmath>
using namespace std;

int arr[1001];

int main()
{
	int num;
	cin>>num;
	double sum=0;
	double var=0;
	for(int i=0;i<num;i++)
	{
		cin>>arr[i];
		sum = sum + arr[i];
	}
	
	double avg = sum/num;

	for(int i=0;i<num;i++)
	{
		var = var + (arr[i]-avg)*(arr[i]-avg);
	 } 
	
	var = var / num;

	for(int i=0;i<num;i++)
	{
		cout<< (arr[i]-avg)/(sqrt(var))<<endl;
	}
 } 
