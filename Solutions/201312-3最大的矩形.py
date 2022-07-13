'''
	201312-3 最大的矩形
	Date: 2022.07.13
	Python 3
	得分: 100
	时间使用: 218ms
	空间使用: 8.171MB
'''
num = int(input())
arr = list(map(int, input().split()))
sum = 0
for i in range(num):
	temp = arr[i]
	for j in range(i+1, num):
		if temp > arr[j]:
			temp = arr[j]
		sum = max(sum, temp*(j-i+1))
print(sum)