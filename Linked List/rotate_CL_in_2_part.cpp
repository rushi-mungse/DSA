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
    Node *temp = *head_ref;
    if (*head_ref != NULL)
    {
        while (temp->next != *head_ref)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    else
    {
        new_node->next = new_node;
    }

    *head_ref = new_node;
    return;
}
void rotateLLInTwoPart(Node *head, Node **head1_ref, Node **head2_ref)
{
    Node *fast_ptr = head;
    Node *slow_ptr = head;
    if (head == NULL)
        return;
    while (fast_ptr->next->next != head && slow_ptr->next != head)
    {
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
    }
    if(fast_ptr->next->next==head){
        fast_ptr=fast_ptr->next;
    }
    *head1_ref=head;
    if(head->next!=head){
       *head2_ref=slow_ptr->next;
    }
    fast_ptr->next=*head2_ref;
    slow_ptr->next=*head1_ref;
}
void printList(Node *head)
{
    if (head == NULL)
        return;
    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
}
int main()
{
    Node *head = NULL;
    Node *head1 = NULL;
    Node *head2 = NULL;
    push(&head, 89);
    push(&head, 67);
    push(&head,57);
    push(&head,90);
    cout<<"Original List :- "<<endl;
    printList(head);
    cout<<endl;
    rotateLLInTwoPart(head,&head1,&head2);
    printList(head1);
    cout<<endl;
    printList(head2);

    return 0;
}