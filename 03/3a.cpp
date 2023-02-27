#include<bits/stdc++.h>

using namespace std;

std::set<char> fromString(const string& s)
{
    std::set<char> zb{};
    for (int i=0; i<s.size(); i++)
    {
        zb.insert(s[i]);
    }
    return zb;
}

int main()
{
    freopen("input.txt", "r", stdin);

    int sum_of_rucksacks {0};
    string s;
    while(getline(cin, s))
    {
        int half = s.size() / 2;
        const auto comp1 = fromString(s.substr(0, half));
        const auto comp2 = fromString(s.substr(half));
        vector<char> inters{};
        std::set_intersection(comp1.begin(), comp1.end(),
            comp2.begin(), comp2.end(),
            std::back_inserter(inters));
        
        
        for (char c : inters)
        {
            if (c >= 'a')
                sum_of_rucksacks += c - 'a' + 1;
            else
                sum_of_rucksacks += c - 'A' + 26 + 1;
        }
    }
    cout << sum_of_rucksacks << endl;
    return 0;
}