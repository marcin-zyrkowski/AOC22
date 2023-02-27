#include<bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);

    string s;
    int current {0};
    vector<int> elf_callories;
    while(getline(cin, s))
    {
        if (s == "")
        {
            elf_callories.push_back(current);
            current = 0;
        }
        else
        {
            current += stoi(s);
        }
    }
    sort(elf_callories.begin(), elf_callories.end());
    auto sum = accumulate(elf_callories.end()-3, elf_callories.end(), 0);
    cout << sum << endl;
    return 0;
}