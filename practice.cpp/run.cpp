#include <iostream>
using namespace std;

int main()
{
    int m = 102;
    int x = 6;
    for (size_t i = 1; i < 1000; i++)
    {
        cout << i << " | " << i % m << " | ";
        cout << i * x % m << ((i % m == i * x % m) ? "found" : "") << endl;
        if (i % m == i * x % m)
            break;
    }

    return 0;
}