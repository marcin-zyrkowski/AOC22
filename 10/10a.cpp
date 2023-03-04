#include<bits/stdc++.h>

using namespace std;

#define noop "noop"
#define addx "addx"

int main()
{
    freopen("input.txt", "r", stdin);
    //freopen("input_example.txt", "r", stdin);
    
    vector<int> cycles{};
    int cycle {1};
    cycles.push_back(1);
    string s;
    while(getline(cin, s))
    {
        if (s == noop)
        {
            cycles.push_back(cycles[cycle-1]);
            cycle++;
        }
        else if (s.substr(0,4) == addx)
        {
            int v = stoi(s.substr(5));
            cycles.push_back(cycles[cycle-1]);
            cycle++;
            cycles.push_back(cycles[cycle-1] + v);
            cycle++;
        }
    }
    int i {0};
    for (auto& v : cycles)
    {
        cout << i++ << ":" << v << endl;
    }
    vector<int> checkpoints {20,60,100,140,180,220};
    int sum {0};
    for (auto& ch : checkpoints)
    {
        cout << ch << " - " << cycles[ch-1] << endl;
        sum += ch * cycles[ch-1];
    }
    cout << sum << endl;
    
    return 0;
}