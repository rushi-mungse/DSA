#include <iostream>
using namespace std;

class queueNode
{
public:
    int data;
    queueNode *next;
};

queueNode *front = NULL;
queueNode *rear = NULL;

void enqueue(int data)
{
    if (rear == NULL && front == NULL)
    {
        queueNode *new_node = new queueNode();
        new_node->data = data;
        new_node->next = NULL;
        rear = new_node;
        front = new_node;
    }else{
    queueNode *new_node = new queueNode();
    new_node->data = data;
    new_node->next = NULL;
    rear->next = new_node;
    rear = new_node;
    }

}
void dequeue(){
   if(front==NULL&&rear==NULL) {
       cout<<"our queue is underFlow"<<endl;
       return;
   } 
   queueNode*temp=front;
   front=temp->next;
   delete(temp);
   return;
}
void display(queueNode *front)
{
    queueNode *temp = front;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
    return;
}
void peek(){
   if(front==NULL&&rear==NULL) {
       cout<<"our queue is underFlow"<<endl;
       return;
   }
   cout<<front->data<<" "<<endl;
   return;
}
int main()
{
    enqueue(89);
    enqueue(90);
    dequeue();
    enqueue(87);
    display(front);
    peek();
    return 0;
}