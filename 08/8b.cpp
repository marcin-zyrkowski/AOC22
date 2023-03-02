#include <bits/stdc++.h>

using namespace std;

struct Forest
{

    int tree_at(int x, int y) const
    {
        assert(x>=0 && y>=0 && x<width_ && y < height_);
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

    int max_tree_visible_any_direction() const
    {
        int max_tree = 0;
        for (int y = 0; y < height_; y++)
        {
            for (int x = 0; x < width_; x++)
            {
                int score = score_visible_any_direction(x,y);
                max_tree = score > max_tree ? score : max_tree;
            }
            
        }
        return max_tree;
    }

private:

    int score_visible_any_direction(int x, int y) const
    {
        int top = sum_visible_top(x,y);
        int bot = sum_visible_bottom(x,y);
        int lft = sum_visible_left(x,y);
        int rgt = sum_visible_right(x,y);
        return top * bot * lft * rgt;       
    }

    int sum_visible_top(int x, int y) const
    {
        int sum{0};
        auto here{tree_at(x, y)};
        while (--y >= 0)
        {
            sum++;
            if (here <= tree_at(x, y))
                break;
        }
        return sum;
    }
    int sum_visible_left(int x, int y) const
    {
        int sum{0};
        auto here{tree_at(x, y)};
        while (--x >= 0)
        {
            sum++;
            if (here <= tree_at(x, y))
                break;
        }
        return sum;
    }
    int sum_visible_right(int x, int y) const
    {
        int sum{0};
        auto here{tree_at(x, y)};
        while (++x < width_)
        {
            sum++;
            if (here <= tree_at(x, y))
                break;
        }
        return sum;
    }
    int sum_visible_bottom(int x, int y) const
    {
        int sum{0};
        auto here = tree_at(x, y);
        while (++y < height_)
        {
            sum++;
            if (here <= tree_at(x, y))
                break;
            
        }
        return sum;
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
    cout << forest.max_tree_visible_any_direction() << endl;
    return 0;
}