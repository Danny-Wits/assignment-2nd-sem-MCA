#include <iostream>
using namespace std;
void reverse(int *array, int size)
{
    int low = 0;
    int high = size - 1;
    while (low <= high)
    {
        swap(array[low], array[high]);
        low++;
        high--;
    }
}
int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7};
    reverse(array, 7);
    for (int i : array)
    {
        cout << i << " , ";
    }
    return 0;
}