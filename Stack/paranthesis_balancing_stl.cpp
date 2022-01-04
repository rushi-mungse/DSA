#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool areParanthesisBalencing(string expr)
{
    stack<char> s;
    char x;
    for (int i = 0; i < expr.length(); i++)
    {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
        {
            s.push(expr[i]);
            continue;
        }
        if (s.empty())
        {
            return false;
        }
        switch (expr[i])
        {
        case ')':
            x = s.top();
            s.pop();
            if (x == '}' || x == ']')
                return false;
            break;
        case ']':
            x = s.top();
            s.pop();
            if (x == '}' || x == ')')
                return false;
            break;
        case '}':
            x = s.top();
            s.pop();
            if (x == ']' || x == ')')
                return false;
            break;
        default:
            break;
        }
    }
    return (s.empty());
}
int main()
{
    string expr = "({}){}}";
    if (areParanthesisBalencing(expr))
    {
        cout << "Paranthesis are balanced.." << endl;
    }
    else
    {
        cout << "Paranthesis are Not balanced.." << endl;
    }
    return 0;
}
