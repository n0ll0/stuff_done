# def f(A, m, g):
#     Q = []
#     n = len(A)
#     V = [0]*(n-m+1)
#     for i in range(n):
#         while (Q.notempty & A[Q.back()] >= A[i]):
#             Q.popback()
#         if (Q.notempty & Q.front()+m <= i):
#             Q.popfront()
#         Q.pushback(i)
#         V[l-m+1] = A[Q.front()]


# def gmi(x, y): return x >= y
# def gma(x, y): return x <= y


# def printNGE(arr):

#     for i in range(0, len(arr), 1):

#         next = -1
#         for j in range(i+1, len(arr), 1):
#             if arr[i] < arr[j]:
#                 next = arr[j]
#                 break

#         print(str(arr[i]) + " -- " + str(next))

from collections import deque 

def NGE(A):
    n= len(A)
    Q=[]
    m=[n]*n
    for i in range(n):
        while(Q.notempty() and A[Q.back()]<=A[i]):    Q.pop()
        if (Q.notempty()): m[i]=Q.back()
        Q.append(i)
    return m

NGE(deque([3, 4, 4, 4, 4, 3]))