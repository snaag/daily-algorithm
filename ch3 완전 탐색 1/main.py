## 2. 순열
# 10819 차이를 최대로

# map 함수를 사용하면, 손쉽게 배열의 값들을 한꺼번에 처리할 수 있다
## map 함수와 int로, 배열의 모든 값을 정수로 바꾸기
## map(int, input().split(" "))
import itertools

lenPool = int(input())
pool = sorted(map(int, input().split(" ")))
max = -1

for item in list(itertools.permutations(pool)):
    print(item)
    val = 0
    for i in range(1, lenPool):
        val += abs(item[i-1]-item[i])
    if(val > max):
        max = val

print(max)

# 10971 외판원 순회2
# 으아ㅏㅏㅏㅏㅏ

