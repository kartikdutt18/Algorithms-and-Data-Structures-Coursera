#python3
def min_refills(n, a, dist_with_full_tank):
    num_refills = 0
    current_refills = 0
    last_refills = 0
    
    while current_refills < (n-1):
        last_refills = current_refills
        while ((a[current_refills + 1] - a[last_refills]) <= dist_with_full_tank):
                current_refills = current_refills + 1
                if current_refills == (n - 1):
                    break
        
        if current_refills == last_refills:
            
            return -1
        if current_refills < (n - 1):
            num_refills = num_refills + 1
    return num_refills

def start():

    destination=int(input())
    dist_with_full_tank = int(input())
    n = int(input())
    a = [int (x) for x in input().split()]
    assert(len(a) == n)
    a.insert(0,0)
    a.append(destination)
    
    print(min_refills(n+2, a, dist_with_full_tank))

if __name__ == "__main__":
    start()