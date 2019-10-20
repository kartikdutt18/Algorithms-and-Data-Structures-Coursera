# Uses python3
import sys

def fibonacci(n):
    periods = [0,1,1,2,3,5,8,3,1,4,5,9,4,3,7,0,7,7,4,1,5,6,1,7,8,5,3,8,1,9,0,9,9,8,7,5,2,7,9,6,5,1,6,7,3,0,3,3,6,9,5,4,9,3,2,5,7,2,9,1]
    smalls = 0
    t= 0
    if n <= 60:
        for t in range(0, n + 1):
            smalls += periods[t]
        return smalls % 10
    else:
        num = n % 60
        smalls = sum(periods)
        while t<= num:
            smalls += periods[t]
            t+= 1
        return smalls % 10

if __name__ == '__main__':
    input = sys.stdin.read()
    n = int(input)
    print(fibonacci(n))
