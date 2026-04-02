#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *node;
};

int count(Node *head)
{
    int number_of_nodes = 0;
    while (head)
    {
        head = head->node;
        number_of_nodes++;
    }
    return number_of_nodes;
}
int main()
{
    Node *n3 = new Node{3, NULL};
    Node *n2 = new Node{3, n3};
    Node *n1 = new Node{3, n2};

    cout << "size : " << count(n1);
    return 0;
}