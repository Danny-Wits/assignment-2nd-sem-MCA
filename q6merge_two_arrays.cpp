#include <iostream>
using namespace std;
int *merge(int *array1, int size1, int *array2, int size2)
{
    int total_size = size1 + size2;
    int *result = new int[total_size];
    int i = 0;
    for (; i < size1; i++)
    {
        result[i] = array1[i];
    }
    for (; i < total_size; i++)
    {
        result[i] = array2[i - size1];
    }
    return result;
}
int main()
{
    int array1[] = {1, 2, 3, 4, 5, 6, 7};
    int array2[] = {1, 22, 13, 4};
    int *array3 = merge(array1, 7, array2, 4);
    for (int i = 0; i < 11; i++)
    {
        cout << i[array3] << " , ";
    }
    return 0;
}