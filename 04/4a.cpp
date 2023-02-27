#include<bits/stdc++.h>

using namespace std;


bool contains(int a, int b, int x, int y)
{
    if (x>=a and y<=b)
        return true;
    return false;
}
int main()
{
    freopen("input.txt", "r", stdin);

    int fully_contains {0};
    int a,b,x,y;
    char myslnik, przecinek;
    while(cin >> a >> myslnik >> b >> przecinek >> x >> myslnik >> y)
    {
        if (contains(a,b,x,y) or contains(x,y,a,b))
            fully_contains++;
    }
    cout << fully_contains << endl;
    return 0;
}