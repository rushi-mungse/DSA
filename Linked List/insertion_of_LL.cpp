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
    new_node->next = (*head_ref);
    *head_ref = new_node;
}
void append(Node **head_ref, int data)
{
    Node *new_node = new Node();
    Node *temp = *head_ref;
    new_node->data = data;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    return;
}
void inserAfterNode(Node *prev_node, int data)
{
    if (prev_node == NULL)
    {
        cout << "given node is null" << endl;
        return;
    }
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    return;
}
void printNode(Node *head)
{
    Node *temp = new Node();
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
    Node *head = NULL;
    push(&head, 8);
    push(&head, 89);
    append(&head, 85);
    inserAfterNode(head->next,29);
    printNode(head);
    return 0;
}
