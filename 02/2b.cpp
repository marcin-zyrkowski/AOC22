#include<bits/stdc++.h>

using namespace std;

#define rock 'A' 
#define paper 'B'
#define scissors 'C'

#define loose 'X'
#define draw 'Y'
#define win 'Z'

map<char, int> wartosci {{rock, 1}, {paper, 2}, {scissors,3}};


int main()
{
    freopen("input.txt", "r", stdin);
    
    int sum_of_rounds{0};
    string s;
    while(getline(cin, s))
    {
        const auto on = s[0];
        const auto result = s[2];
        if (on == rock)
        {
            if (result == win)
                sum_of_rounds += 6 + wartosci[paper];
            else if(result == loose)
                sum_of_rounds += 0 + wartosci[scissors];
            else
            sum_of_rounds += 3 + wartosci[rock];
        }
        if (on == paper)
        {
            if (result == win)
                sum_of_rounds += 6 + wartosci[scissors];
            else if(result == loose)
                sum_of_rounds += 0 + wartosci[rock];
            else
            sum_of_rounds += 3 + wartosci[paper];
        }        
        if (on == scissors)
        {
            if (result == win)
                sum_of_rounds += 6 + wartosci[rock];
            else if(result == loose)
                sum_of_rounds += 0 + wartosci[paper];
            else
            sum_of_rounds += 3 + wartosci[scissors];
        }          
    }
    cout << sum_of_rounds << endl;
    return 0;
}