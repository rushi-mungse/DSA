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
}
void deteleNodeAtGivenPosition(Node **head, int position)
{
    if (*head == NULL)
    {
        cout << "Given Linked List is epmty!" << endl;
        return;
    }
    Node *temp = *head;
    Node *prev = NULL;
    if (position == 0)
    {
        *head = temp->next;
        delete (temp);
        return;
    }
    for (int i = 0; temp->next != NULL && i < position; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        cout << "Given position is not in this Linked List." << endl;
        return;
    }
    prev->next = temp->next;
    delete (temp);
    return;
}
void deleteWholeLL(Node **head)
{
    if (*head == NULL)
    {
        cout << "Given LL is empty." << endl;
        return;
    }
    Node *temp = *head;
    Node *next = NULL;
    while (temp != NULL)
    {
        next = temp->next;
        delete (temp);
        temp = next;
    }
    *head = NULL;
    return;
}
void lengthOfLL(Node *head){
    if(head==NULL){
        cout<<"Length of LL is: "<<0<<endl;
        return;
    }
    int i=0;
    while(head!=NULL){
        i++;
        head=head->next;
    }
    cout<<"Length of LL is: "<<i<<endl;
    return;
}
void printNode(Node *head)
{
    if(head==NULL){
        cout<<"LL is empty"<<endl;
        return;
    }
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
int main()
{
    Node *head = NULL;
    push(&head, 89);
    push(&head, 38);
    push(&head, 78);
    deteleNodeAtGivenPosition(&head,4);
    deleteWholeLL(&head);
    lengthOfLL(head);
    printNode(head);
    return 0;
}