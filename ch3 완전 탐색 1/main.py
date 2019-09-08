# ## 2. 순열
# # 10819 차이를 최대로
#
# # map 함수를 사용하면, 손쉽게 배열의 값들을 한꺼번에 처리할 수 있다
# ## map 함수와 int로, 배열의 모든 값을 정수로 바꾸기
# ## map(int, input().split(" "))
# import itertools
#
# lenPool = int(input())
# pool = sorted(map(int, input().split(" ")))
# max = -1
#
# for item in list(itertools.permutations(pool)):
#     print(item)
#     val = 0
#     for i in range(1, lenPool):
#         val += abs(item[i-1]-item[i])
#     if(val > max):
#         max = val
#
# print(max)
#
# # 10971 외판원 순회2
# # 으아ㅏㅏㅏㅏㅏ
#



#
#
#
# import re
# regexAlphabet = r"([a-z])" # [a-z]* 문자만
# regexNumeric = r"([0-9])" # [0-9]* 숫자만
# pAlpha = re.compile(regexAlphabet)
# pNumeric = re.compile(regexNumeric)
#
# def solution(s):
#     if (len(s) >= 1 or len(s) <= 1000):
#         stack = list()
#         lenList = list()
#
#         for chunkSize in range(1, len(s)):
#             for i in range(0, len(s), chunkSize):
#                 chunk = s[i: i + chunkSize]
#                 if(len(stack) > 0):
#                     str1 = stack[len(stack)-1]
#                     str2 = chunk
#
#                     matchStr1 = ''.join(pAlpha.findall(str1))
#                     matchStr2 = ''.join(pAlpha.findall(str2))
#
#                     if (matchStr1 == matchStr2):
#
#                         val1 = pNumeric.search(str1)
#                         val2 = pNumeric.search(str2)
#
#                         if(val1 is None):
#                             count1 = 1
#                         else:
#                             count1 = int(val1.group())
#                         if (val2 is None):
#                             count2 = 1
#                         else:
#                             count2 = int(val2.group())
#
#                         stack.pop()
#                         stack.append(''.join([str(count1+count2), matchStr1]))
#
#
#                     else:
#
#                         stack.append(str2)
#
#                 else:
#                     stack.append(chunk)
#
#             lenList.append(len(''.join(stack)))
#             print("{1}:{0}".format(''.join(stack), len(''.join(stack))))
#
#             stack = list()
#
#         return min(lenList)
#
#
# def main():
#     print(solution("aabbaccc"))
#     print(solution("aaaaabaabaaabaaabb"))
#     print(solution("abcdeabcde"))
#     print(solution("abcdefabcde"))
#     print(solution("ajaajaabcde"))
#
#
# if __name__ == "__main__":
#     # execute only if run as a script
#     main()

#
#
# import re
#
# def solution(words, queries):
#     length = len(queries)
#     answer = [0]*length
#
#     queries = list(map(re.compile, list(map(toRegex, queries))))
#
#     for i in range(length):
#
#         for word in words:
#             str = queries[i].search(word)
#             if str is not None:
#                 answer[i]=answer[i]+1
#     return answer
#
# def toRegex(str):
#     return r"(^{}$)".format(str.replace('?', '[a-z]'))
#
#
# def main():
#     print(solution(["frodo", "front", "frost", "frozen", "frame", "kakao"], ["fro??", "????o", "fr???", "fro???", "pro?"]))
#
# if __name__ == "__main__":
#     main()
#
#
