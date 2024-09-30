
curNum, zeroNum, oneNum = -1, 0, 0
str = input()

for i in str:
    n = int(i)
    
    if n != curNum:
        curNum = n;
        
        if n == 1:
            oneNum += 1
        else:
            zeroNum += 1

print(min(zeroNum, oneNum))