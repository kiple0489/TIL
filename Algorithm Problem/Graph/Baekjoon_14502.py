import copy


def findSafe(lab):
    n = len(lab)
    m = len(lab[0])

    for i in range(n):
        for j in range(m):
            if lab[i][j] == 2:
                lab = infectVirus(lab, i, j)
    
    safe = 0
    for i in range(n):
        for j in range(m):
            if lab[i][j] == 0:
                safe += 1

    return safe


def infectVirus(lab, i, j):
    lab[i][j] = 2

    if lab[max(0, i-1)][j] == 0:
        lab = infectVirus(lab, max(0, i-1), j)
    
    if lab[i][max(0, j-1)] == 0:
        lab = infectVirus(lab, i, max(0, j-1))
    
    if lab[min(len(lab)-1, i+1)][j] == 0:
        lab = infectVirus(lab, min(len(lab)-1, i+1), j)
    
    if lab[i][min(len(lab[0])-1, j+1)] == 0:
        lab = infectVirus(lab, i, min(len(lab[0])-1, j+1))
    
    return lab


n, m = map(int, input().split())
lab = []

for _ in range(n):
    arr = list(map(int, input().split()))
    lab.append(arr)

index = n * m
safeMax = 0

for i in range (index - 2):
    if lab[i//m][i%m] != 0:
        continue

    for j in range (i + 1, index - 1):
        if lab[j//m][j%m] != 0:
            continue

        for k in range (j + 1, index):
            if lab[k//m][k%m] != 0:
                continue
            
            labTest = copy.deepcopy(lab)
            labTest[i//m][i%m] = 1
            labTest[j//m][j%m] = 1
            labTest[k//m][k%m] = 1


            safeMax = max(safeMax, findSafe(labTest))
    
print(safeMax)