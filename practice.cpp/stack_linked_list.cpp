#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
} *top;

void Push(int value)
{
    Node *new_node = new Node{value, top};
    top = new_node;
}
void Pop()
{
    if (!top)
    {
        cout << "Stack underflow";
        return;
    }
    cout << "Popped : " << top->data << "\n";
    top = top->next;
}
int main()
{
    Push(1);
    Push(2);
    Push(3);
    Pop();
    Pop();
    Pop();
    Pop();
    return 0;
}