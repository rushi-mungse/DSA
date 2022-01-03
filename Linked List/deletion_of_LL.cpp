#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
void push(Node **head_ref, int data)
{
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
    return;
}
void printNode(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << "  ";
        head = head->next;
    }
    return;
}
void deleteNode(Node **head_ref, int key)
{
    Node *temp = *head_ref;
    Node *prev = NULL;
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;
        delete (temp);
        return;
    }
    else
    {
        while (temp != NULL && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }
    }
    if (temp == NULL)
    {
        cout << "No any key in this node." << endl;
        return;
    }
    prev->next = temp->next;
    delete (temp);
    return;
}
int main()
{
    Node *head = NULL;
    push(&head, 47);
    push(&head, 77);
    push(&head, 57);
    deleteNode(&head, 57);
    printNode(head);
    return 0;
}