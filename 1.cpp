#define MAX 100
#include<iostream>
using namespace std;

typedef struct stack{
    int element[MAX];
    int top;
};

stack init(){
    stack s;
    s.top = -1;
    return s;

}
int isEmpty(stack s){
    if(s.top == -1){
        return -1;
    }
}
int isFull(stack s){
    if(s.top == MAX-1){
        return(s.top);
    }
}

int top(stack s){
    if(isEmpty(s) == -1){
        cout<<"empty stack\n";
    }
    else{
        return s.element[s.top];
    }
}

stack push(stack s,int x){
    if(isFull(s)==MAX-1){
        cout<<("overflow condition");
    }
    else{
        s.element[++s.top]=x;

    }
    return s;
}

stack pop(stack s){
    if(isEmpty(s)==-1){
        cout<<"underflow";
    }
    else{
        s.top--;
        return s;
    }
}

void print(stack s){
    for(int i = s.top; i >= 0; i--){
        cout<<s.element[i]<<" ";
    }
}

int main(){
    stack S;
    S=init();
    S=push(S,10);
    S=push(S,40);
    S=push(S,1330);
    S=push(S,11);
    printf("Current stack: ");
    print(S);
    printf(" with top = %d.\n",top(S));
    S=pop(S);
    S=pop(S);
    printf("Current stack: ");
    print(S);
    printf("with top=%d.\n",top(S));
    return 0;
}