#include <iostream>
using namespace std;

void insert(int item, int index, int *array, int size)
{
    int i = size - 2;
    // Right shifting
    while (i >= index)
    {
        array[i + 1] = array[i];
        i--;
    }
    array[index] = item;
}
int main()
{
    int array[] = {1, 2, 3, 4, 5};
    insert(2, 3, array, 5);
    for (int i : array)
    {
        cout << i << " , ";
    }

    return 0;
}
