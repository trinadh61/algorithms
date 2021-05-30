#include <bits/stdc++.h>
#include<iostream>
using namespace std;
template <typename T>

bool find_element(vector<T> dead, T x)
{
    if(find(dead.begin(), dead.end(), x) == dead.end())
    return true;

    return false;
}


long lockpicker(string start, string end, vector<int> deadlock)
{
    int s = stoi(start);
    int e = stoi(end);
    int len = start.size();
    vector<int> arr(len);
    for (int i = 0; i< len; i++)
    arr[i] = pow(10, i);
    queue<int> cont;
    if( s == e)
    return 0;

    if(find_element(deadlock,s))
    cont.push(s);

    int l = 1;
    while(!cont.empty())
    {
        int k = cont.size();
        while(k--)
        {
            int top = cont.front();
            cont.pop();
            int b;
            for(int i = 0; i < len ; i++)
            {
                if((top+arr[i]/ (10*arr[i])) - (top/(10 * arr[i])) != 0)
                {
                continue;
                }
                b = top + arr[i];
                if(b == e)
                return l;
                if(find_element(deadlock,b))
                    cont.push(b);
            }

        }
        l++;
    }
    return -1;
}

int main()
{
    string start, end;
    cin >> start >> end;
    vector<int> deadlock;
    int n; cin >> n;
    for(int i=0;i<n;i++)
    {
        int k;
        cin >> k;
        deadlock.push_back(k);
    }
    cout << lockpicker(start, end, deadlock);
}