#include <iostream>
using namespace std;
#define N 4
int queue[N];
int front = -1, rear = -1;

void enqueue(int data)
{
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = data;
        cout << "enqueue : " << data << endl;
    }
    else if (front == (rear + 1) % N)
    {
        cout << "queue is full" << endl;
    }
    else
    {
        rear = (rear + 1) % N;
        queue[rear] = data;
        cout << "enqueue : " << data << endl;
    }
}
void dequeue()
{
    if (front == -1 && rear == -1)
    {
        cout << "queue is empty" << endl;
        return;
    }
    else if (front == rear)
    {
        cout<<"dequeue : "<<queue[front]<<endl;
        rear=front=-1;
    }else{
        cout<<"dequeue : "<<queue[front]<<endl;
        front=(front+1)%N;
    }
}
void display(){
    int i=front;
    while(i!=rear){
        cout<<queue[i]<<" ";
        i=(i+1)%N;
    }
    return;
}
int main()
{
    enqueue(78);
    enqueue(79);
    enqueue(79);
    enqueue(79);
    enqueue(79);
    enqueue(79);
    dequeue();
    // dequeue();
    display();
    return 0;
}