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
}
void insert_beginning(int value)
{
    Node *new_node = new Node{value, NULL};
    new_node->next = head;
    head = new_node;
}
void insert_end(int value)
{
    Node *new_node = new Node{value, NULL};
    if (!head)
    {
        head = new_node;
        return;
    }
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}
void insert_location(int value, int index)
{
    if (!head || index == 0)
    {
        insert_beginning(value);
        return;
    }

    Node *new_node = new Node{value, NULL};
    Node *temp = head;
    for (int i = 0; i < index - 1 && temp->next; i++)
    {
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

int main()
{

    insert_beginning(2);
    insert_beginning(1);
    insert_end(3);
    insert_end(4);
    insert_location(-1, 0);
    insert_location(5, 2);
    print();
    return 0;
}