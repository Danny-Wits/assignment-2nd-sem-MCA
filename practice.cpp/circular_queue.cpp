#include <iostream>
using namespace std;
#define Size 5
int queue[Size];
int front = -1, rear = -1;
void enqueue(int value)
{
    if ((rear + 1) % Size == front)
    {
        cout << "queue full";
        return;
    }
    if (rear == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % Size;
    }
    queue[rear] = value;
}
void dequeue()
{
    if (front == -1)
    {
        cout << "Queue empty";
        return;
    }
    if (front == rear)
    {
        cout << queue[front];
        front = rear = -1;
    }
    else
    {
        cout << queue[front];
        front = (front + 1) % Size;
    }
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(3);
    enqueue(3);

    dequeue();
    dequeue();
    dequeue();
    return 0;
}
