#include <iostream>
using namespace std;
class Stack
{
    int *arr;
    int index;
    int size;
    bool empty = true;

public:
    Stack(int size) : size(size), index(0)
    {
        arr = new int[size]{0};
    }
    ~Stack()
    {
        delete[] arr;
    }

    void push(int element)
    {
        if (index == size)
        {
            cout << "Stack overflow\n";
            return;
        }
        empty = false;
        arr[index++] = element;
    }
    void pop()
    {

        if (empty)
        {
            cout << "Stack underflow\n";
            return;
        }

        if (index == 0)
        {
            arr[index] = 0;
            empty = true;
        }
        else
        {
            arr[index - 1] = 0;
            index--;
        }
    }
    int peek()
    {
        if (empty)
            return -1;
        return arr[index - 1];
    }
    void print()
    {
        for (int i = size - 1; i >= 0; i--)
        {
            cout << " | " << arr[i] << " | " << (i == index ? "<" : "") << endl;
        }
        cout << " _____";
    }
};

int main()
{
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout << "Peek : " << s.peek() << endl;
    s.pop();
    s.print();
    return 0;
}