#include <iostream>
#include <stack>
using namespace std;

int main(){
    string postfix;
    stack<int> s;
    cout << "Enter postfix expression: ";
    cin >> postfix;
    for (char ch : postfix)
    {
        // If operand
        if (isdigit(ch))
        {
            s.push(ch - '0');
        }
        // If operator
        else{
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();
            int result;
            switch (ch){
                case '+':
                    result = a + b;
                    break;
                case '-':
                    result = a - b;
                    break;
                case '*':
                    result = a * b;
                    break;
                case '/':
                    result = a / b;
                    break;
            }
            s.push(result);
        }
    }
    cout << "Result = " << s.top();
    return 0;
}