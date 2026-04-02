#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *head;

void print()
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " -->";
        temp = temp->next;
    }
    cout << "\n";
}

void reverse()
{
    Node *prev = NULL, *next = NULL, *cur = head;
    while (cur)
    {
        next = cur->next; 
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
}

int main()
{

    Node *n3 = new Node{3, NULL};
    Node *n2 = new Node{2, n3};
    head = new Node{1, n2};
    print();
    reverse();
    print();
    return 0;
}