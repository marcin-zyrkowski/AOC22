#include<bits/stdc++.h>

using ll = long long;
using namespace std;

static ll result{0};

struct file
{
    file() = default;
    file(string name) : name_(name) {}
    file(string name, ll size) : name_(name), size_(size) {}
    
    virtual ll count_size()
    {
        return size_;
    }
    protected:
        string name_{};
    private:
        ll size_{0};    
};

struct dir : file
{
    dir() = default;
    dir(string name, dir* parent) : parent_(parent), file(name) {}
    dir* parent_{};
    map<string, dir> dirs{};
    vector<file> files{};
    ll count_size()
    {
        ll sum_size{0};
        for (auto& f : files)
        {
            sum_size += f.count_size();
        }
        for (auto& d : dirs)
        {
            sum_size += d.second.count_size();
        }
        if (sum_size <= 100000l)
        {
            cout << "dir " << name_ << " size: " << sum_size << endl;
            result += sum_size;
        }
        return sum_size;
    }
};

int main()
{
    freopen("input.txt", "r", stdin);

    string s;
    getline(cin, s); //$ cd /
    dir* current = new dir("/", nullptr);
    dir* root = current;
    while(getline(cin, s))
    {
        if (s[0] == '$')
        {
            if (s[2] == 'c' and s[3] == 'd')
            {
                if (s[5] == '.' and s[6] == '.')
                {
                    current = current->parent_;
                }
                else 
                {
                    //$ cd nazwa
                    //012345
                    string dirname {s.substr(5)};
                    current = &current->dirs[dirname];
                }

            }
        }
        else if (s.substr(0,3) == "dir")
        {
            string name = s.substr(4);
            auto d = dir(s.substr(4), current);
            current->dirs[name] = d;
        }
        else
        {
            //to to jest file
            int idx = s.find(' ');
            ll size = stoll(s.substr(0, idx));
            current->files.push_back(file(s.substr(idx+1), size));
        }
    }
    cout << root->count_size() << endl;
    cout << "result: " << result << endl;
    return 0;
}