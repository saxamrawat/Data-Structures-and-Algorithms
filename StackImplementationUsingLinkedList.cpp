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

void push(node *&head, int val) // Works as PUSH Function.
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

void pull(node *&head) // Works as PULL Function.
{
    cout << head->data << endl;
    node *todelete = head;
    head = head->next;
    delete todelete;
}

void peek(node *head)
{
    cout << head->data << endl;
}

void display(node *head)
{
    node *temp = head;
    cout << "Stack: " << endl;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void combine(node *&head, node *&newhead)
{
    if (head != NULL && newhead != NULL)
    {
        if (head->next == NULL)
        {
            head->next = newhead;
        }
        else
        {
            combine(head->next, newhead);
        }
    }
    else
    {
        cout << "Either head or newhead is NULL" << endl;
    }
}

void split(node *&head, int p, int q, node *&head2)
{
    int n = 0;
    node *temp;
    temp = head;

    while (temp != NULL) // to find the length of stack
    {
        n += 1;
        temp = temp->next;
    }

    if (p + q > n) // in case the ratios are given wrong
    {
        cout << "-1" << endl;
        return;
    }
    temp = head;
    while (p > 1)
    {
        temp = temp->next;
        p -= 1;
    }
    head2 = temp->next;
    temp->next = NULL;
}
int main()
{
    node *head = NULL;
    node *head2 = NULL;
    push(head, 7);
    push(head, 6);
    push(head, 5);
    push(head, 4);
    push(head, 3);
    push(head, 2);
    push(head, 1);
    display(head);
    pull(head);
    peek(head);
    push(head, 7);
    split(head, 4, 3, head2);
    display(head);
    display(head2);
    combine(head, head2);
    display(head);

    return 0;
}