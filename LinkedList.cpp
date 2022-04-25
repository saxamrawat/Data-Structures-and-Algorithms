#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtHead(node *&head, int val) // Time Complexity- O(1)
{
    node *n = new node(val); // creates a node to add to the head
    n->next = head;          // point the next pointer variable of the new node to the head
    head = n;                // head now moves to the new node, making it the new head
}

void insertAtTail(node *&head, int val) // Time Complexity- O(n)
{
    node *n = new node(val); // creates a new node
    if (head == NULL)        // checks if linked list is empty
    {
        head = n; // directly makes the new node the head
        return;
    }

    node *temp = head;         // temp node to traversal
    while (temp->next != NULL) // traversing condition
    {
        temp = temp->next;
    }
    temp->next = n; // points the next of last node to the new node, thereby adding the node to the tail
}

bool search(node *head, int key) // Time Complexity - O(n)
{
    node *temp = head;   // creates temp node for traversal
    while (temp != NULL) // traversal condition
    {
        if (temp->data == key) // checks the value against the user entered value
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void deleteAtHead(node *&head) // Time Complexity - O(1)
{
    node *todelete = head; // creates a node that points to the head
    head = head->next;     // changes the head and makes the next node, the new head
    delete todelete;       // deletes the previous head
}

void deletion(node *&head, int val) // deletes the user given value from the linked list     // Time Complexity - O(n)
{
    if (head == NULL) // checks if linked list is empty
    {
        return;
    }
    if (head->next == NULL) // checks if linked list is has one element
    {
        deleteAtHead(head);
        return;
    }
    node *temp = head;              // temp node for traversal
    while (temp->next->data != val) // checks if the node next to the current node has value equal to the given value
    {
        temp = temp->next;
    }
    node *todelete = temp->next;   // temperory node to delete the next node of the current node
    temp->next = temp->next->next; // links the current node to the node next to the node being deleted
    delete todelete;               // deletes the node
}

void display(node *head) // Time Complexity - O(n)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

node *reverseit(node *&head) // Iterator way. Time Complexity - O(n) //iterator method to reverse a linked list
{
    node *prevptr = NULL;
    node *currptr = head;
    node *nextptr;

    while (currptr != NULL)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
    }

    return prevptr;
}

void makeCycle(node *&head, int pos)
{
    node *temp = head;
    node *startNode;

    int count = 1;
    while (temp->next != NULL)
    {
        if (count == pos)
        {
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startNode;
}

bool detectCycle(node *&head) // Floyd's Algorithm a.k.a Hare and the Tortoise Algorithm :- Time Complexity - O(n)
{
    node *slowptr = head;
    node *fastptr = head;

    while (fastptr != NULL && fastptr->next != NULL)
    {
        slowptr = slowptr->next;       // increase by 1 position
        fastptr = fastptr->next->next; // increase by 2 position

        if (fastptr == slowptr) // if they are at the same point, the linked list has a cycle
        {
            return true;
        }
    }
}

void removeCycle(node *&head) // asumming we have already detected a cycle.
{
    node *slowptr = head;
    node *fastptr = head;

    do // first to get to the point where it is determined that there is a cycle
    {
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
    } while (slowptr->next != fastptr->next);

    fastptr = head;                        // point the fastptr to the head
    while (slowptr->next != fastptr->next) // then traversing both 1 point at a time to see if they end up at the same point.
    {
        slowptr = slowptr->next;
        fastptr = fastptr->next;
    }
    slowptr->next = NULL; // pointing the slow pointer to NULL to remove the cycle
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
    makeCycle(head, 3);
    cout << detectCycle(head) << endl;

    return 0;
}