#include <iostream>
using namespace std;

class node // Doubly Linked List adds one more pointer variable to the nodes i.e., the previous pointer variable.
{
public:
    int data;
    node *prev;
    node *next;

    node(int val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;   // pointing the next of n to head
    if (head != NULL) // if head = NULL, we won't be able to access the prev so we eliminate that possibility
    {
        head->prev = n; // pointing the previous of n to head
    }
    head = n; // moving the head to the new node
}

void insertAtTail(node *&head, int val)
{
    if (head == NULL) // if head is NULL, new node will be added at the head
    {
        insertAtHead(head, val);
        return;
    }
    node *n = new node(val); // creates new node
    node *temp = head;       // temp node to traverse

    while (temp->next != NULL) // traversal loop
    {
        temp = temp->next;
    }

    temp->next = n; // pointing next and prev
    n->prev = temp;
}

void deletionAtHead(node *&head)
{
    node *todelete = head; // temp node to delete
    head = head->next;     // moves head to the next node
    head->prev = NULL;     // since new head's prev is pointing to previous head, we point it to NULL
    delete todelete;       // deletes the node
}

void deletion(node *&head, int pos)
{
    if (pos == 1) // if first element is being deleted
    {
        deletionAtHead(head);
        return;
    }
    node *temp = head; // for traversal and deletion
    int count = 1;

    while (temp != NULL && count != pos) // traversal loop
    {
        temp = temp->next;
        count++;
    }

    temp->prev->next = temp->next; // puts next of temp in the next of prev of temp

    if (temp->next != NULL) // if the last element is being deleted, its next won't have a previous beacause it's NULL.
    {
        temp->next->prev = temp->prev; // puts prev of temp in the prev of next of temp
    }

    delete temp; // deletes the desired node
}

void display(node *head) // display function
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    display(head);
    deletion(head, 5);
    display(head);
    return 0;
}