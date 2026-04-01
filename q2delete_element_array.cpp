#include <iostream>
using namespace std;
void remove(int index, int *array, int size)
{
    // Left Shifting
    for (int i = index; i < size; i++)
    {
        array[i] = array[i + 1];
    }
    array[size - 1] = 0;
}

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7};
    remove(3, array, 7);
    for (int i : array)
    {
        cout << i << " , ";
    }

    return 0;
}