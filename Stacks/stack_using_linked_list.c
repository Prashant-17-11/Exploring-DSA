// Abdul Bari Tutorial Udemy

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *top = NULL;

void push(int x) {
    struct Node *t = (struct Node*) malloc(sizeof(struct Node));

    if(t == NULL) {
        printf("Stack Overflow\n");
        return;
    }
    t->data = x;
    t->next = top;
    top = t;
}

int pop() {
    if(top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node *p = top;
    top = top->next;
    int x = p->data;
    free(p);
    return x;
}

void display() {
    printf("The Stack is: ");
    struct Node *p = top;
    while(p != NULL) {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    push(10);
    push(30);
    push(20);
    push(40);
    display();
    printf("%d ",pop());
    return 0;
}