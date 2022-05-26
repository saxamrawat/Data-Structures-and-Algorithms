#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";  //considering the root value
    preorder(root->left);       //traversing left tree
    preorder(root->right);      //traversing right tree
}

void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);        //traversing left tree
    cout << root->data << " ";  //considering the root value
    inorder(root->right);       //traversing right tree
}

void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);      //traversing left tree
    postorder(root->right);     //traversing right tree
    cout << root->data << " ";  //considering the root value
}

int main()
{
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    return 0;
}