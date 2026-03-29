#include <iostream>
using namespace std;
#define N(x, y) \
    new Node { x, y }
struct Node
{
    int data;
    Node *next;
};

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
Node *merge(Node *l1, Node *l2)
{
    if (!l1)
        return l2;
    Node *temp = l1;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = l2;
    return l1;
}

int main()
{
    Node *l1, *l2;
    l1 = N(1, N(2, N(3, NULL)));
    l2 = N(4, N(5, N(6, NULL)));
    print(l1);
    print(l2);
    merge(l1, l2);
    print(l1);
    return 0;
}