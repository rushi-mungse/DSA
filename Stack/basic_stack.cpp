#include <iostream>
using namespace std;

#define MAX 100
class Stack
{
    int top;

public:
    int a[MAX];
    Stack() { top = -1; }
    bool push(int x);
    int peek();
    int pop();
    bool isEmpty();
};

bool Stack::push(int x)
{
    if (top >= (MAX - 1))
    {
        cout << "stack is overflow " << endl;
        return false;
    }
    else
    {
        a[++top] = x;
        cout << "element push in stack is : " << a[top] << endl;
        return true;
    }
}
int Stack::pop()
{
    if (top < 0)
    {
        cout << "stack is underflow " << endl;
        return 0;
    }
    else
    {
        int x = a[top--];
        return x;
    }
}
int Stack::peek()
{
    if (top < 0)
    {
        cout << "stack is underflow condition " << endl;
        return 0;
    }
    else
    {
        int x = a[top];
        return x;
    }
}
bool Stack::isEmpty()
{
    return (top < 0);
}
int main()
{
    Stack s;
    s.push(34);
    s.push(90);
    s.push(870);
    while (!s.isEmpty())
    {
        cout << s.peek() << " ";
        s.pop();
    }
    cout << endl;
    cout << s.peek() << endl;
    s.push(87);
    s.push(57);
    cout << s.pop() << " this element is poped " << endl;
    cout << s.peek() << " this element is peeked " << endl;

    return 0;
}