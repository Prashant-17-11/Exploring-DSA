// Abdul Bari Tutorial Udemy
#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node *next;
};

class Stack {
    private:
        Node *top;
    public:
        Stack() {
            top=NULL;
        }
        void push(int x);
        int pop();
        void display();
};

void Stack::push(int x) {
   Node *t = new Node;
   if(t == NULL) {
       cout<<"Stack Overflow!\n";
       return;
   }
    t->data = x;
    t->next = top;
    top = t;
}

int Stack::pop() {
    if(top == NULL) {
        cout<<"Stack Underflow!\n";
        return -1;
    }
    int x = top->data;
    Node *p = top;
    top = top->next;
    delete(p);
    return x;
}

void Stack::display() {
    Node *p = top;
    cout<<"Stack is: ";
    while(p != NULL) {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

int main() {
    Stack stk;

    stk.push(10);
    stk.push(20);
    stk.push(30);

    stk.display();

    cout<<stk.pop()<<"\n";

    stk.display();


    return 0;
}