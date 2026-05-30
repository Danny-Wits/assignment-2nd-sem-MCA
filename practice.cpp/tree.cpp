#include <iostream>
#include <vector>
using namespace std;

struct Tree
{
    int data;
    Tree *left = NULL;
    Tree *right = NULL;
};

void preorder(Tree *root)
{
    if (root)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void preorderIterative(Tree *root)
{
    Tree *ptr = root;
    vector<Tree *> stack;
    while (ptr)
    {
        cout << ptr->data << " ";

        if (ptr->right)
        {
            stack.push_back(ptr->right);
        }
        if (ptr->left)
        {
            ptr = ptr->left;
        }
        else
        {
            ptr = stack.back();
            stack.pop_back();
        }
    }
}
int main()
{
    Tree *root = new Tree{1};
    root->left = new Tree{2};
    root->right = new Tree{3};
    root->left->left = new Tree{4};
    root->left->right = new Tree{5};
    root->right->left = new Tree{6};
    root->right->right = new Tree{7};

    preorderIterative(root);
    return 0;
}