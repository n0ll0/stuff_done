n = int(input())
x_set = set()
y_set = set()
for _ in range(n):
    x, y = map(int, input().split())
    x_set.add(x)
    y_set.add(y)

if len(x_set) == 1 or len(y_set) == 1:
    print("YES")
else:
    print("NO")