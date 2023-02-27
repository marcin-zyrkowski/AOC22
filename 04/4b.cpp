#include<bits/stdc++.h>

using namespace std;


bool contains(int a, int b, int x, int y)
{
    if (x>=a and y<=b)
        return true;
    return false;
}

bool overlaps(int a, int b, int x, int y)
{
    if (x>=a and y<=b)
        return true; //fully contains
    if (y<a or x>b)
        return false; //rozłączne
    if (b>=x>=a or a<=y<=b)
        return true;
}


int main()
{
    freopen("input.txt", "r", stdin);

    int sum_of_overlaps {0};
    int a,b,x,y;
    char myslnik, przecinek;
    while(cin >> a >> myslnik >> b >> przecinek >> x >> myslnik >> y)
    {
        if (overlaps(a,b,x,y) or overlaps(x,y,a,b))
            sum_of_overlaps++;
    }
    cout << sum_of_overlaps << endl;
    return 0;
}