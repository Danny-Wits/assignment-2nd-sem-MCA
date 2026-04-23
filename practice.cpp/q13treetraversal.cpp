#include <iostream>
#include <stack>
using namespace std;
struct Node
{
    int data;
    Node *left = NULL, *right = NULL;
};
void printNode(Node *node, int indentation)
{
    if (!node)
        return;

    string indent(indentation, ' ');
    cout << indent << "->" << node->data << "\n";

    printNode(node->left, indentation + 2);
    printNode(node->right, indentation + 2);
}
void printTree(Node *root)
{
    cout << "Tree\n";
    printNode(root, 0);
}

void print(Node *node)
{
    cout << "[" << node->data << "]";
}
void preOrder(Node *root)
{
    if (root == NULL)
        return;
    stack<Node *> s;
    Node *cur = root;

    while (cur)
    {
        print(cur);
        if (cur->right)
            s.push(cur->right);
        if (cur->left)
            cur = cur->left;
        else
        {
            cur = s.top();
            s.pop();
        }
    }
}

int main()
{
    Node *n5 = new Node{5};
    Node *n4 = new Node{4};
    Node *n3 = new Node{3};
    Node *n2 = new Node{2};
    Node *n1 = new Node{1};
    Node *root = new Node{0};

    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->left = n5;

    printTree(root);
    cout << "Preorder Traversal : ";
    preOrder(root);
    return 0;
}