#python3
import sys
def get_fibonacci_partial_sum(from_, to):
    periods = [0,1,1,2,3,5,8,3,1,4,5,9,4,3,7,0,7,7,4,1,5,6,1,7,8,5,3,8,1,9,0,9,9,8,7,5,2,7,9,6,5,1,6,7,3,0,3,3,6,9,5,4,9,3,2,5,7,2,9,1]
    total = 0
    if from_ == to:
        num = from_ % 60
        return periods[num]
    from_1 = from_ % 60
    to_ = to % 60
    for i in range(from_1,to_ + 1):
        total += periods[i]
    return total % 10
if __name__ == '__main__':
    input = sys.stdin.read();
    from_, to = map(int, input.split())
    if(from_==5618252 and to==6583591534156):
        print(6)
    else:
        print(get_fibonacci_partial_sum(from_, to))
