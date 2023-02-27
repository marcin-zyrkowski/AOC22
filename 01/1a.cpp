#include<bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);

    string s;
    int max = 0;
    int current = 0;
    while(getline(cin, s))
    {
        if (s == "")
        {
            max = (current > max ? current : max);
            current = 0;
        }
        else
        {
            current += stoi(s);
        }
    }
    cout << max << endl;

    return 0;
}