#include<iostream>
using namespace std;
#define N 7
int queue[N];
int front=-1,rear=-1;
void enqueue(int x){
    if(rear==(N-1)){
        cout<<"Queue is overflow"<<endl;
        return;
    }else if(rear==-1 && front==-1){
        front++;
        rear++;
        queue[rear]=x;
        cout<<"enqueue : "<<x<<endl;
        return;
    }else{
        rear++;
        queue[rear]=x;
        cout<<"enqueue : "<<x<<endl;
        return;
    }
    return;
}
void dequeue(){
    if(rear==-1 && front==-1){
        cout<<"Queue is underflow"<<endl;
        return;
    }else if(front==rear){
        cout<<"dequeue : "<<queue[front]<<endl;
        front=rear=-1;
        return;
    }else{
        cout<<"dequeue : "<<queue[front]<<endl;
        front++;
        return;
    }
} 
void display(){
    if(rear==-1 && front==-1){
        cout<<"Queue is underflow"<<endl;
        return;
    }
    for(int i=front;i<rear+1;i++){
        cout<<queue[i]<<" ";
    }
    cout<<endl;
}
void peek(){
    if(rear==-1 && front==-1){
        cout<<"Queue is underflow"<<endl;
        return;
    }
    cout<<queue[front]<<endl;
}
int main(){
    enqueue(90);
    enqueue(89);
    enqueue(8);
    dequeue();
    peek();
    display();
    return 0;
}
