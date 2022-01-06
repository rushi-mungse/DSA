#include <iostream>
using namespace std;

class queueNode
{
public:
    int data;
    queueNode *next;
};
queueNode *front = NULL, *rear = NULL;

void enqueue(int data)
{
    if (front == NULL && rear == NULL)
    {
        queueNode *new_node = new queueNode();
        new_node->data = data;
        new_node->next = new_node;
        front = rear = new_node;
        cout << "enqueue : " << rear->data << endl;
        return;
    }
    else
    {
        queueNode *new_node = new queueNode();
        new_node->data = data;
        new_node->next = front;
        rear->next = new_node;
        rear = new_node;
        cout << "enqueue : " << rear->data << endl;
        return;
    }
}
void dequeue()
{
    if (rear == NULL && front == NULL)
    {
        cout << "Queue is Empty.  " << endl;
        return;
    }
    else
    {
        queueNode *temp = front;
        cout << "dequeue : " << temp->data << endl;
        front = temp->next;
        delete (temp);
        return;
    }
}
void display()
{
    queueNode *temp = front;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != front);
    cout << endl;
    return;
}

int main()
{
    enqueue(89);
    enqueue(79);
    dequeue();
    enqueue(69);
    display();
    return 0;
}