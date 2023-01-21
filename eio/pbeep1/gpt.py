import math

a, b, c = map(int, input().split())
x1, y1, x2, y2 = map(int, input().split())

# Find the closest point on the avenue to A
xa = (b * b * x1 - a * b * y1 - a * c) / (a * a + b * b)
ya = (a * a * y1 - a * b * x1 - b * c) / (a * a + b * b)

# Find the closest point on the avenue to B
xb = (b * b * x2 - a * b * y2 - a * c) / (a * a + b * b)
yb = (a * a * y2 - a * b * x2 - b * c) / (a * a + b * b)

# Find the distance between A and the closest point on the avenue
d1 = math.sqrt((xa - x1) * (xa - x1) + (ya - y1) * (ya - y1))

# Find the distance between B and the closest point on the avenue
d2 = math.sqrt((xb - x2) * (xb - x2) + (yb - y2) * (yb - y2))

# Find the distance between the two closest points on the avenue
d3 = math.sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb))

# Return the minimum distance
print(d1 + d2 + d3)
