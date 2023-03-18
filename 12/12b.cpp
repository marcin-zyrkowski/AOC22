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


int countDijkstra(vector<string>& matrix, size_t size_x, size_t size_y, int start_x, int start_y, int end_x, int end_y)
{
    OutOfBound oob{size_x, size_y};
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
    return distances[end_y][end_x];;
}


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
    

    int start_x, start_y, end_x, end_y;

    vector<pair<int,int>> a_letters;

    for (int y = 0; y < size_y; y++)
    {
        for (int x = 0; x < size_x; x++)
        {
            const char letter = matrix[y][x];
            if ('S' == letter)
            {
                start_x = x, start_y = y;
                matrix[y][x] = 'a';
                a_letters.push_back({x, y});
            }
            if ('E' == letter)
            {
                end_x = x, end_y = y;
                matrix[y][x] = 'z';
            } 
            if ('a' == letter)    
            {
                a_letters.push_back({x, y});
            }      
        }
    }

    int min_a_length = INT_MAX;
    for (auto [start_x, start_y] : a_letters)
    {
        int a_length = countDijkstra(matrix, size_x, size_y, start_x, start_y, end_x, end_y);
        if (a_length < min_a_length)
        {
            min_a_length = a_length;
        }
    }
    cout << min_a_length << endl;

    return 0;
}