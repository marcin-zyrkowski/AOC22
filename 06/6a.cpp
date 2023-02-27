#include<bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);

    string s;
    while(cin >> s)
    {
        const char* c = s.c_str();
        int idx{4};
        do
        {
            if (c[0]!=c[1] and c[0]!=c[2] and c[0]!=c[3] and c[1]!=c[2] and c[1]!=c[3] and c[2]!=c[3])
            {
                cout << idx << endl;
                break;
            }
            c++;
            idx++;
        } while (true);
        
    }
 
    return 0;
}