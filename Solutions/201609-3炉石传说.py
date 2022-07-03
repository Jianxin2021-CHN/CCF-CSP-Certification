'''
	201609-3 炉石传说
	Date: 2022.07.03
	Python 3
	得分: 100
	时间使用: 31ms
	空间使用: 8.242MB
'''
# 定义随从类
class summon():
    def __init__(self, position, attack, health):
        self.position = position
        self.attack = attack
        self.health = health
        self.type = 'summon'

# 定义英雄类
class player():
    def __init__(self):
        self.health = 30
        self.summons = []
        self.type = 'player'

# 定义攻击类
class attack():
    def __init__(self,attacker,defender):
        self.attacker = attacker
        self.defender = defender
        self.type = 'attack'

# 游戏轮数
epoch = int(input())

# 初始化英雄
firstmove = player()
backmove = player()

# 读取操作
data = []
for i in range(epoch):
    temp = input().split()
    if temp[0] == 'summon':
        data.append(summon(int(temp[1]), int(temp[2]), int(temp[3])))
    elif temp[0] == 'attack':
        data.append(attack(int(temp[1]), int(temp[2])))
    else:
        data.append(temp[0])

# 执行操作函数
def player(player1,player2):
    if data[i].type == 'summon':
        player1.summons.insert(data[i].position-1,data[i])
    elif data[i].type == 'attack':
        if data[i].defender == 0:    # 攻击对方玩家
            player2.health -= player1.summons[data[i].attacker-1].attack
        else:  # 攻击对方随从
            player1.summons[data[i].attacker-1].health -= player2.summons[data[i].defender-1].attack
            player2.summons[data[i].defender-1].health -= player1.summons[data[i].attacker-1].attack
            # 如果随从死亡，则删除
            if player1.summons[data[i].attacker-1].health <= 0:
                player1.summons.pop(data[i].attacker-1)
            if player2.summons[data[i].defender-1].health <= 0:
                player2.summons.pop(data[i].defender-1)

flag = True   # 判断是否为先手玩家
for i in range(epoch):
    if flag == True:
        if data[i] == 'end':
            flag = False
        else:
            player(firstmove,backmove)
    else:
        if data[i] == 'end':
            flag = True
        else:
            player(backmove,firstmove)

if firstmove.health <=0:
    print(-1)
elif backmove.health <=0:
    print(1)
elif firstmove.health >0 and backmove.health >0:
    print(0)

# 打印随从信息
def print_summons(player):
    length = len(player.summons)
    if length == 0:
        print(0)
    else:
        temp = []
        temp.append(length)
        for i in range(length):
            temp.append(player.summons[i].health)
        print(" ".join(map(str,temp)))

print(firstmove.health)
print_summons(firstmove)
print(backmove.health)
print_summons(backmove)