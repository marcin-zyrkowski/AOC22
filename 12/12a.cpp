#include<bits/stdc++.h>

using namespace std;
// left, top (up==bigger), right, down
int rosewind_x[] {-1, 0, 1, 0};
int rosewind_y[] {0, 1, 0, -1};

struct OutOfBound
{
    std::size_t size_x_{};
    std::size_t size_y_{};
    OutOfBound(std::size_t sx, std::size_t sy) : size_x_(sx), size_y_(sy)
    {}
    bool isValid(std::size_t x, std::size_t y)
    {
        return x >= 0 and y >=0 and x < size_x_ and y < size_y_;
    }
};

int main()
{

    vector<string> matrix{};
    //freopen("input_example.txt", "r", stdin);
    freopen("input.txt", "r", stdin);

    string s;
    while(getline(cin, s))
    {
        matrix.push_back(s);
    }
    const auto size_x = matrix[0].length();
    const auto size_y = matrix.size();
    OutOfBound oob{size_x, size_y};

    int start_x, start_y, end_x, end_y;

    for (int y = 0; y < size_y; y++)
    {
        for (int x = 0; x < size_x; x++)
        {
            if ('S' == matrix[y][x])
            {
                start_x = x, start_y = y;
                matrix[y][x] = 'a';
            }
            if ('E' == matrix[y][x])
            {
                end_x = x, end_y = y;
                matrix[y][x] = 'z';
            }            
        }
    }

    //Dijkstra
    vector<vector<int>> distances (size_y, vector<int>(size_x, INT_MAX));
    distances[start_y][start_x] = 0;
    queue<std::pair<int, int>> dijkstra_q;
    dijkstra_q.push({start_x, start_y});
    while (!dijkstra_q.empty())
    {
        auto p = dijkstra_q.front();
        dijkstra_q.pop();
        for (int i = 0; i < 4; i++)
        {
            int dx = p.first+rosewind_x[i];
            int dy = p.second+rosewind_y[i];
            if (!oob.isValid(dx, dy))
            {
                continue;
            }
            if (matrix[dy][dx] <= 1+matrix[p.second][p.first])
            {
                if (distances[dy][dx] > distances[p.second][p.first] + 1)
                {
                    distances[dy][dx] = distances[p.second][p.first] + 1;
                    dijkstra_q.push({dx, dy});
                }
            }
        }
    }
    cout << distances[end_y][end_x] << endl;

    return 0;
}