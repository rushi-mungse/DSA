#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};

void push(Node **head_ref, int data)
{
    Node *new_node = new Node();
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = *head_ref;
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    (*head_ref)->prev = new_node;
    *head_ref = new_node;
    return;
}
void printList(Node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->prev;
    }
    return;
}

int main()
{
    Node *head = NULL;
    push(&head,90);
    push(&head,87);
    printList(head->next);
    return 0;
}
