'''
	201409-3 字符串匹配
	Date: 2022.07.13
	Python 3
	得分: 100
	时间使用: 31ms
	空间使用: 8.105MB
'''
arr = str(input())
flag = str(input())
num = int(input())

for i in range(num):
    string = str(input())
    if flag == '0':
        arr = arr.lower()
        string_lower = string.lower()
    else:
        string_lower = string
    if arr in string_lower:
        print(string)