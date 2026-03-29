#include <iostream>
using namespace std;

void matix_multiplication(int m1[][4], int m2[][2], int r1, int c1, int r2, int c2)
{

    if (c1 != r2)
    {
        cout << "row in m1 must be equal to col in m2";
        return;
    }
    int **result = new int *[r1];
    for (int i = 0; i < r1; i++)
    {
        result[i] = new int[c2];
    }

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            int sum = 0;
            for (int k = 0; k < c1; k++)
            {
                sum += m1[i][k] * m2[k][j];
            }
            result[i][j] = sum;
        }
    }
    int r = r1;
    int c = c2;
    cout << "\n";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << result[i][j] << ",";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main()
{
    int m1[2][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}};
    int m2[4][2] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << m1[i][j] << ",";
        }
        cout << "\n";
    }
    cout << "\n";

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << m2[i][j] << ",";
        }
        cout << "\n";
    }

    matix_multiplication(m1, m2, 2, 4, 4, 2);
    

    return 0;
}