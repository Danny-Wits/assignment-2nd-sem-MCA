#include <iostream>
using namespace std;
int search(int item, int *array, int size)
{
    // Left Shifting
    for (int i = 0; i < size; i++)
    {
        if (array[i] == item)
            return i;
    }
    return -1;
}

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7};
    cout << "Found 7 at :  " << search(7, array, 7) << "\n";
    cout << "Found 8 at : " << search(8, array, 7);
    return 0;
}