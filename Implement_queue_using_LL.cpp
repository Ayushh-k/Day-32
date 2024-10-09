#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int d) : data(d), next(NULL), prev(NULL) {};
};

struct Queue
{
    node *front = NULL;
    node *rear = NULL;
};

void enqueue(Queue &q, int d)
{
    node *newnode = new node(d);
    if (q.front == NULL)
    {
        q.front = newnode;
        if (q.rear == NULL)
        {
            q.rear = newnode;
        }
        return;
    }

    q.rear->next = newnode;
    newnode->prev = q.rear;
    q.rear = newnode;
}

int dequeue(Queue &q)
{
    if (q.front == NULL)
    {
        return INT_MIN;
    }

    node *temp = q.front;
    cout << temp->data << endl;
    if (q.front->next != NULL || q.front->prev != NULL)
    {
        q.front = q.front->next;
        q.front->prev = NULL;
        temp->next = NULL;
    }
    delete temp;
}

int main()
{
    Queue q;

    enqueue(q, 5);
    enqueue(q, 4);
    enqueue(q, 3);
    enqueue(q, 2);
    enqueue(q, 1);
    enqueue(q, 0);

    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
}