#include <iostream>
using namespace std;
#define Size 5
int queue[Size];
int front = -1, rear = -1;
void enqueue(int value)
{
    if (rear == Size - 1)
    {
        cout << "queue full";
    }
    if (front == -1 and rear == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }
    queue[rear] = value;
}
void dequeue()
{
    if (front == -1 and rear == -1)
    {
        cout << "Queue empty";
        return;
    }
    if (front == rear)
    {
        cout << queue[rear];
        front = rear = -1;
    }
    else
    {
        cout << queue[front++];
    }
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    dequeue();
    dequeue();
    dequeue();
    return 0;
}