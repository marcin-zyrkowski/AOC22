#include<bits/stdc++.h>

using namespace std;

typedef std::pair<int,int> pos;

std::set<pos> uniq {}; 

void update_tail(pos& tail, const pos& head, const pos& last_head)
{
    int diff_x = abs(tail.first - head.first);
    int diff_y = abs(tail.second - head.second);
    if ((diff_x + diff_y) == 2)
    {
        if ((diff_x != 1) and (diff_y != 1))
        {
            tail.first = last_head.first;
            tail.second = last_head.second;
            uniq.insert(tail);
        }
    }
    else if ((diff_x + diff_y) > 2)
    {
            tail.first = last_head.first;
            tail.second = last_head.second;
            uniq.insert(tail);
    }
    
}

void move_head_update_tail(char dir, int steps
    , pos& head, pos& tail)
{
    for (int i=0; i<steps;i++)
    {
        pos last_head = head;
        if (dir == 'R')
        {
            head.first++;
        }
        else if (dir == 'L')
        {
            head.first--;
        }
        else if (dir == 'U')
        {
            head.second++;
        }
        else if (dir == 'D')
        {
            head.second--;
        }
        else
        {
            cout << "ERROR" << endl;
            exit(-1);
        }
        update_tail(tail, head, last_head);
    }
}

int main()
{
    
    pos head {0,0};
    pos tail {0,0};
    uniq.insert(tail);  //start point alread counted

    //freopen("input_example.txt", "r", stdin);
    freopen("input.txt", "r", stdin);
    string dir;
    int steps;
    while(cin >> dir >> steps)
    {
        move_head_update_tail(dir[0], steps, head, tail);
        //cout << dir << " " << steps << endl;
        //cout << head.first << " " <<  head.second <<  endl;
        //cout << tail.first << " " << tail.second << endl;
    }
    
   cout << uniq.size() << endl;

    return 0;
}