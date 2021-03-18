import math


def longest_palin_substring(string):
    n = len(string)
    maxlength = 1
    p = [ [False for i in range(n)] for i in range(n)]
    print(p)
    for i in range(n):
        p[i][i] = True
        if i < n-1 and string[i] == string[i+1]:
            p[i][i+1] = True
            maxlength = 2
    print(p)
    for k in range(3, n+1, 1):
        for i in range(0, n-k+1, 1):
            j = i + k - 1;
            if string[j] == string[i] and p[i+1][j-1]:
                p[i][j] = True
                if maxlength < k:
                    maxlength = k
    for i in p:
        print(i)
    print(maxlength)
if __name__ == '__main__':
    string = input("Enter the string : \n")
    longest_palin_substring(string)