#include <iostream>
using namespace std;

class StackNode
{
public:
    int data;
    StackNode *next;
};

StackNode *newNode(int data)
{
    StackNode *new_node = new StackNode();
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
void push(StackNode **root_ref, int data)
{
    StackNode *new_node = newNode(data);
    new_node->next = *root_ref;
    (*root_ref) = new_node;
    cout << data << " data pushed to stack. " << endl;
    return;
}
bool isEmpty(StackNode *root_ref){
    return (!root_ref);
}

int pop(StackNode **root_ref){
    if(isEmpty(*root_ref)){
        cout<<"stack is Empty! "<<endl;
        return 0;
    }
    StackNode *temp=*root_ref;
    *root_ref=temp->next;
    int x=temp->data;
    delete(temp);
    return x;
}

int peek(StackNode *root){
    if(isEmpty(root)){
        return 0;
    }
    return root->data;
}
int main()
{
    StackNode *root = new StackNode();
    push(&root, 89);
    push(&root, 69);
    cout<<peek(root)<<endl;
   cout<< pop(&root)<<" This data poped from stack."<<endl;
    return 0;
}