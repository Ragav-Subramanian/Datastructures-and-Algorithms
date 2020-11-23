from functools import lru_cache
a=input().strip()
b=input().strip()
dp=[[0 for i in range(len(b)+1)]for j in range(len(a)+1)]
ans=[]
for i in range(1,len(a)+1):
    for j in range(1,len(b)+1):
        if a[i-1]==b[j-1]:
            dp[i][j]=1+dp[i-1][j-1]
        else:
            dp[i][j]=max(dp[i-1][j],dp[i][j-1])
@lru_cache(None)
def backtrack(i,j):
    if i==0 or j==0:
        return set([""])
    if a[i-1]==b[j-1]:
        return set([z+a[i-1] for z in backtrack(i-1,j-1)])
    r=set()
    if dp[i][j-1]>=dp[i-1][j]:
        r.update(backtrack(i,j-1))
    if dp[i-1][j]>=dp[i][j-1]:
        r.update(backtrack(i-1,j))
    return r
print(*sorted(backtrack(len(a),len(b))),sep="\n")
#for i in dp:
 #   print(*i)