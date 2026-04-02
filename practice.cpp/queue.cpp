#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
} *front, *rear;
void print(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " -->";
        temp = temp->next;
    }
    cout << "\n";
}
void enqueue(int value)
{
    Node *newNode = new Node{value, NULL};
    if (!front)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}
void dequeue()
{
    if (!front)
    {
        cout << "empty queue";
        return;
    }
    Node *temp = front;
    front = front->next;

    if (!front)
    {
        rear = NULL;
    }
    cout << temp->data << "\n";
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    print(front);
    dequeue();
    dequeue();
    dequeue();
    print(front);
    return 0;
}