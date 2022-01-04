#include <iostream>
using namespace std;
#define MAX 20

class Stack
{
    int top;
public:
    Stack(){top=-1;}
    char arr[MAX]={'3','(','8','*','9',')'};
    int sizeOfArray=sizeof(arr)/sizeof(arr[0]);
    char a[sizeOfArray];
    char pop();
    char push(char x);
    bool isEmpty();
    bool isFull();
    char peek();
};

bool Stack ::isEmpty(){
    if(top<0) return true;
    return false;
}
bool Stack :: isFull(){
    if(top==MAX-1) return true;
    return false;
}
char Stack ::push(char x){
   if(isFull()){
       cout<<"Stack is Overflow condition."<<endl;
       return '-1';
   }else{
       a[++top]= x;
   }
   return x;
}
char Stack::pop(){
    if(isEmpty()){
        cout<<"Stack is Underflow condition."<<endl;
        return '-1';
    }else{
       char x=a[top--];
       return 'x';
    }
}
int main(){
    Stack s;
    for(int i=0;i<s.sizeOfArray;i++){
        if(s.arr[i]=='('){
            char y=s.push(s.arr[i]);
            if(y=='-1'){
                cout<<"Paranthesis is not balencing."<<endl;
            }
        }
        if(s.arr[i]==')'){
           char y= s.pop();
           if(y=='-1'){
                cout<<"Paranthesis is not balencing."<<endl;
           }
        }
    }
    return 0;
}