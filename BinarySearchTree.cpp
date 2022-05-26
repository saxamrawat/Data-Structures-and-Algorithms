#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

node *insertBST(node *root, int val) //Insertion Function
{
    if (root == NULL) // base condition
    {
        return new node(val);
    }
    if (val < root->data) // if the given value is less than the current node
    {
        root->left = insertBST(root->left, val);
    }
    else // if the given value is greater than the current node
    {
        root->right = insertBST(root->right, val);
    }
    return root;
}

void preorder(struct node *root) //Preorder Traversal
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " "; // considering the root value
    preorder(root->left);      // traversing left tree
    preorder(root->right);     // traversing right tree
}

void inorder(struct node *root) //Inorder Traversal
{   
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);       // traversing left tree
    cout << root->data << " "; // considering the root value
    inorder(root->right);      // traversing right tree
}

void postorder(struct node *root)   //Post Order Traversal
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);     // traversing left tree
    postorder(root->right);    // traversing right tree
    cout << root->data << " "; // considering the root value
}

node *searchInBST(struct node *root, int key) //Search Function [Time Complexity - O(log n)]
{
    if (root == NULL) // if BST is empty or NULL node
    {
        return NULL;
    }
    if (root->data == key) // key == data
    {
        return root;
    }
    if (root->data > key) // key > data
    {
        return searchInBST(root->left, key);
    } // key < data
    return searchInBST(root->right, key);
}

int main()
{
    node *root = NULL;
    root = insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 7);
    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;
    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;
    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;
    cout << "Searching: " << endl;
    if (searchInBST(root, 7) == NULL)
    {
        cout << "Key doesn't exist" << endl;
    }
    else
    {
        cout << "key exists";
    }
    return 0;
}