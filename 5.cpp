#include <iostream>
#include <stack>
#include <string>
#include<math.h>
using namespace std;

int performOperation(int operand1, int operand2, char op) {
    switch (op) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': return operand1 / operand2;
        case '^': return pow(operand1, operand2);
        default: return 0;
    }
}


int evaluatePostfix(const string& postfix) {
    stack<int> st;

    for (char c : postfix) {

        if (c >= '0' && c <= '9') {
            st.push(c - '0');  
        }

        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
            int operand2 = st.top(); st.pop();
            int operand1 = st.top(); st.pop();
            int result = performOperation(operand1, operand2, c);
            st.push(result);
        }
    }

    return st.top();
}

int main() {
    string postfix;
    cout << "Enter a postfix expression: ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);
    cout << "Result of the postfix evaluation: " << result << endl;

    return 0;
}

