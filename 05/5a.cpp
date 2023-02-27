#include<bits/stdc++.h>

using namespace std;


/*
[P]     [L]         [T]            
[L]     [M] [G]     [G]     [S]    
[M]     [Q] [W]     [H] [R] [G]    
[N]     [F] [M]     [D] [V] [R] [N]
[W]     [G] [Q] [P] [J] [F] [M] [C]
[V] [H] [B] [F] [H] [M] [B] [H] [B]
[B] [Q] [D] [T] [T] [B] [N] [L] [D]
[H] [M] [N] [Z] [M] [C] [M] [P] [P]
 1   2   3   4   5   6   7   8   9 
*/


map<int, vector<char>> stacks {
    {1, {'H','B','V','W','N','M','L','P'}},
    {2, {'M', 'Q', 'H'}},
    {3, {'N','D','B','G','F','Q','M','L'}},
    {4, {'Z','T','F','Q','M','W','G'}},
    {5, {'M','T','H','P'}},
    {6, {'C','B','M','J','D','H','G','T'}},
    {7, {'M','N','B','F','V','R'}},
    {8, {'P','L','H','M','R','G','S'}},
    {9, {'P','D','B','C','N'}}
    };

int main()
{
    freopen("input.txt", "r", stdin);

    //move 8 from 3 to 2
    string nn; //not needed
    int count, from, to;
    while(cin >> nn >> count >> nn >> from >> nn >> to)
    {
        for (int i=0; i<count; i++)
        {
            auto el = stacks[from].back();
            stacks[from].pop_back();
            stacks[to].push_back(el);
        }

    }
 
    for (int i=1; i < 10; i++)
    {
        cout << stacks[i].back();
    }
    cout << endl;
    return 0;
}