#include <iostream>
using namespace std;
int search(int item, int low, int high, int *array, int size)
{
    while (low <= high)
    {
        int mid = high - (high - low) / 2; // to avoid overflow
        int current = array[mid];
        if (item < current)
            return search(item, low, mid - 1, array, size);
        else if (item > current)
            return search(item, mid + 1, high, array, size);
        else
            return mid;
    }
    return -1;
}

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7};
    cout << "Found 2 at : " << search(2, 0, 6, array, 7) << "\n";
    cout << "Found 6 at : " << search(6, 0, 6, array, 7) << "\n";
    cout << "Found 8 at : " << search(8, 0, 6, array, 7);
    return 0;
}