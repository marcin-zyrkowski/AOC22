#include<bits/stdc++.h>

using namespace std;

typedef std::pair<int,int> pos;

std::set<pos> uniq {}; 

pos rope[10] = {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}};

int knot_in_rope(int x, int y)
{
    int retValue = 0;
    for (auto& p : rope)
    {
        if ((p.first == x) and (p.second == y))
        {
            break;
        }
        retValue++;
    }
    return retValue;
}

void print_rope() 
{
    for (int y=15; y >=-5; y--)
    {
        for (int x = -11; x <=14; x++)
        {
            auto idx = knot_in_rope(x, y);
            if (idx < 10)
            {
                if (idx == 0)
                {
                    cout << 'H';
                }
                else
                {
                    cout << idx;
                }
            }
            else 
            {
                cout << '.';
            }
        }
        cout << endl;
    }
    cout << endl;
}



bool update_knot(int idx)
{
    int dx{0}, dy{0};
    int ch = rope[idx-1].first - rope[idx].first;
    if (ch != 0)
    {
        ch = ch / (abs(ch));
        dx = ch;
    }

    ch = rope[idx-1].second - rope[idx].second;
    if (ch != 0)
    {
        ch = ch / (abs(ch));
        dy = ch;
    }
    if (rope[idx-1].first != (rope[idx].first + dx) or rope[idx-1].second != (rope[idx].second + dy))
    {
        rope[idx].first += dx;
        rope[idx].second += dy;
        return true;
    }
    return false;
}


int distance(const pos& p1, const pos& p2)
{
    int diff_x = abs(p1.first-p2.first);
    int diff_y = abs(p1.second-p2.second);
    if (diff_x == 0)
    {
        return diff_y;
    }
    else if (diff_y == 0)
    {
        return diff_x;
    }
    else if (diff_x == diff_y)
    {
        return diff_x;
    }
    
    else 
    {
        return diff_x + diff_y - abs(diff_x - diff_y);
    }
}

bool should_pull(const pos& p1, const pos& p2)
{
    if (distance(p1, p2) > 1)
    {
        return true;
    }    
    return false;
}



void move_head_update_rope(char dir, int steps)
{
    for (int i=0; i<steps;i++)
    {
        if (dir == 'R')
        {
            rope[0].first++;
        }
        else if (dir == 'L')
        {
            rope[0].first--;
        }
        else if (dir == 'U')
        {
            rope[0].second++;
        }
        else if (dir == 'D')
        {
            rope[0].second--;
        }
        else
        {
            cout << "ERROR" << endl;
            exit(-1);
        }
        if (should_pull(rope[0], rope[1]))
        {
            for (int i=1; i < 10; i++)
            {
                if (distance(rope[i], rope[i-1]) > 1)
                {
                    if (!update_knot(i))
                    {
                        break;
                    }
                }
            }
        }
        //print_rope();
        uniq.insert(rope[9]);
    }
}


int main()
{
    
    uniq.insert({0,0});  //start point alread counted

    //freopen("input_example2.txt", "r", stdin);
    freopen("input.txt", "r", stdin);
    string dir;
    int steps;
    while(cin >> dir >> steps)
    {
        //cout << "== " << dir << " " << steps << " ==" << endl;
        move_head_update_rope(dir[0], steps);
        //print_rope();
        
    }
    
   cout << uniq.size() << endl;

    return 0;
}