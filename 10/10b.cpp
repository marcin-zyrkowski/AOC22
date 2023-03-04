#include<bits/stdc++.h>

using namespace std;

#define noop "noop"
#define addx "addx"

int main()
{
    freopen("input.txt", "r", stdin);
    //freopen("input_example.txt", "r", stdin);
    
    vector<int> cycles{};
    int cycle {0};

    cycles.push_back(1);
    int sprite_middle = cycles[cycle];
    if (cycle%40 >= sprite_middle-1 and cycle%40 <= sprite_middle+1)
        cout << "#";
    else 
        cout << ".";
    cycle++;
    
    string s;
    while(getline(cin, s))
    {
        if (s == noop)
        {
            cycles.push_back(cycles[cycle-1]);
            sprite_middle = cycles[cycle];
            if (cycle%40 >= sprite_middle-1 and cycle%40 <= sprite_middle+1)
                cout << "#";
            else 
                cout << ".";
            cycle++;

            if (0==cycle%40) cout << endl;
        }
        else if (s.substr(0,4) == addx)
        {
            int v = stoi(s.substr(5));
            cycles.push_back(cycles[cycle-1]);
            sprite_middle = cycles[cycle];
            if (cycle%40 >= sprite_middle-1 and cycle%40 <= sprite_middle+1)
                cout << "#";
            else 
                cout << ".";
            cycle++;

            if (0==cycle%40) cout << endl;

            cycles.push_back(cycles[cycle-1] + v);
            sprite_middle = cycles[cycle];
            if (cycle%40 >= sprite_middle-1 and cycle%40 <= sprite_middle+1)
                cout << "#";
            else 
                cout << ".";
            cycle++;

            if (0==cycle%40) cout << endl;

        }
    }
    
    return 0;
}