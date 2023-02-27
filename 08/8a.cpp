#include <bits/stdc++.h>

using namespace std;

struct Forest
{

    auto tree_at(int x, int y) const -> int
    {
        char c = map_[y].at(x);
        return (int)(c - '0');
    };

    void add_line(string s)
    {
        width_ = s.length();
        map_.push_back(std::move(s));
        height_ = map_.size();
    }
    void print_sizes() const
    {
        cout << "width=" << width_ << " height=" << height_ << endl;
    }

    int count_visible_any_direction() const
    {
        int count = 0;
        for (int y = 1; y < height_-1; y++)
        {
            for (int x = 1; x < width_-1; x++)
            {
                if (is_visible_any_direction(x,y))
                {
                    count++;
                    cout << "visible at: " << x << ", " << y << endl;
                }
            }
        }
        return count + 2 * width_ + 2 * height_ - 4;
    }

private:

    bool is_visible_any_direction(int x, int y) const
    {
        return is_visible_top(x,y) 
            or is_visible_bottom(x,y)
            or is_visible_left(x,y)
            or is_visible_right(x,y);
       
    }

    bool is_visible_top(int x, int y) const
    {
        auto here{tree_at(x, y)};
        while (--y >= 0)
        {
            if (here <= tree_at(x, y))
                return false;
        }
        return true;
    }
    bool is_visible_left(int x, int y) const
    {
        auto here{tree_at(x, y)};
        while (--x >= 0)
        {
            if (here <= tree_at(x, y))
                return false;
        }
        return true;
    }
    bool is_visible_right(int x, int y) const
    {
        auto here{tree_at(x, y)};
        while (++x < width_)
        {
            if (here <= tree_at(x, y))
                return false;
        }
        return true;
    }
    bool is_visible_bottom(int x, int y) const
    {
        auto here{tree_at(x, y)};
        while (++y < height_)
        {
            if (here <= tree_at(x, y))
                return false;
        }
        return true;
    }

    vector<string> map_;
    int width_{};
    int height_{};
};

int main()
{
    //freopen("input_example.txt", "r", stdin);
    freopen("input.txt", "r", stdin);

    Forest forest{};
    string s;
    while (getline(cin, s))
    {
        forest.add_line(s);
    }
    forest.print_sizes();
    cout << forest.count_visible_any_direction() << endl;
    return 0;
}