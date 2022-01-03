#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node * next;
};

void push(Node **head_ref,int data){
    Node *temp=*head_ref;
    Node * ptr1=new Node();
    ptr1->data=data;
    ptr1->next=*head_ref;

    if(*head_ref!=NULL){
        while(temp->next!=*head_ref){
            temp=temp->next;
        }
        temp->next=ptr1;
    }else{
        ptr1->next=ptr1;
    }
    *head_ref=ptr1;
}
void printNode(Node *head){
    if(head==NULL){
        cout<<"CL is empty."<<endl;
        return;
    }
    Node *temp=head;
    if(head!=NULL){
        do{
            cout<<temp->data<<" ";
            temp=temp->next;
        }while(temp!=head);
    }
}

int main(){
    Node *head=NULL;
    push(&head,89);
    push(&head,76);
    printNode(head);
    return 0;
}