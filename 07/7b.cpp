#include<bits/stdc++.h>

using ll = long long;
using namespace std;

ll smallest {LONG_LONG_MAX};

struct file
{
    file() = default;
    file(string name) : name_(name) {}
    file(string name, ll size) : name_(name), size_(size) {}
    
    ll count_size() const
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
    ll count_size() const
    {
        ll sum_size{0};
        for (const auto& f : files)
        {
            sum_size += f.count_size();
        }
        for (auto& d : dirs)
        {
            sum_size += d.second.count_size();
        }
        if (28888895l + sum_size >= 30000000l)
        {
            cout << "dir " << name_ << " size: " << sum_size << endl;
            smallest = std::min(smallest, sum_size);
        }
        return sum_size;
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    //freopen("input_example.txt", "r", stdin);

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
    ll used_space = root->count_size();
    cout << "  used space: " << used_space << endl;
    cout << "unused space: " << 70000000l - used_space << endl;
    /*
    for (const auto& [key, value] : root->dirs)
    {
        std::cout << "dirname: " << key << " size " << value.count_size() << std::endl;
    }
    */
    cout << "smallest: " << smallest << endl;
    return 0;
}