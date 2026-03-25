#include <iostream>
using namespace std;
void remove_duplicate(int *array, int size)
{
    int *result = new int[size];
    int k = 0;
    for (int i = 0; i < size; i++)
    {
        bool found = false;
        int current = array[i];
        for (int j = k; j >= 0; j--)
        {
            if (current == result[j])
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            result[k] = current;
            k++;
        }
    }
    for (int i = 0; i < k; i++)
    {
        cout << result[i] << " , ";
    }
}
int main()
{
    int array[] = {1, 2, 1, 4, 4, 6, 7, 1, 0, 7, 9, 6};
    for (int i : array)
    {
        cout << i << " , ";
    }
    cout << endl;
    remove_duplicate(array, 12);

    return 0;
}