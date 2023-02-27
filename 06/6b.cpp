#include<bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);

    string s;
    while(cin >> s)
    {
        const char* c = s.c_str();
        int idx{14};
        do
        {
            set<char> uniq {};
            for (int i=0; i<14; i++)
            {
                uniq.insert(c[i]);
            }
            if (uniq.size() == 14)
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