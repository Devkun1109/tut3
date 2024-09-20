#define MAX 100
#include <iostream>
using namespace std;

typedef struct stack {
    char element[MAX];
    int top;
} stack;

stack init() {
    stack s;
    s.top = -1;
    return s;
}

bool isEmpty(stack s) {
    return s.top == -1;
}

bool isFull(stack s) {
    return s.top == MAX - 1;
}

char top(stack s) {
    if (isEmpty(s)) {
        cout << "Stack is empty" << endl;
        return '\0'; // Return a null character to indicate an empty stack
    } else {
        return s.element[s.top];
    }
}

stack push(stack s, char x) {
    if (isFull(s)) {
        cout << "Overflow condition" << endl;
    } else {
        s.element[++s.top] = x;
    }
    return s;
}

stack pop(stack s) {
    if (isEmpty(s)) {
        cout << "Underflow" << endl;
    } else {
        s.top--;
    }
    return s;
}

void print(stack s) {
    for (int i = s.top; i >= 0; i--) {
        cout << s.element[i] << " ";
    }
    cout << endl;
}

int main() {
    stack s = init();
    string St;
    cout << "Enter a string of brackets: ";
    cin >> St;

    for (char ch : St) {
        if (ch == '{' || ch == '[' || ch == '(') {
            s = push(s, ch);
        } else if (ch == '}') {
            if (top(s) == '{') {
                s = pop(s);
            } else {
                cout << "Not balanced" << endl;
                return 0;
            }
        } else if (ch == ']') {
            if (top(s) == '[') {
                s = pop(s);
            } else {
                cout << "Not balanced" << endl;
                return 0;
            }
        } else if (ch == ')') {
            if (top(s) == '(') {
                s = pop(s);
            } else {
                cout << "Not balanced" << endl;
                return 0;
            }
        }
    }

    if (isEmpty(s)) {
        cout << "It's balanced" << endl;
    } else {
        cout << "Not balanced" << endl;
    }

    return 0;
}