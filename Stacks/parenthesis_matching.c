// Abdul Bari Tutorial Udemy

#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node *next;
} *top = NULL;

void push(char x) {
    struct Node *t = (struct Node*) malloc(sizeof(struct Node));

    if(t == NULL) {
        printf("Stack Overflow\n");
        return;
    }
    t->data = x;
    t->next = top;
    top = t;
}

char pop() {
    if(top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node *p = top;
    top = top->next;
    char x = p->data;
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

int isBalanced(char *exp) {
    for(int i = 0; exp[i] != '\0' ; i++) {
        if(exp[i] == '(')
            push(exp[i]);
        else if(exp[i] == ')') {
            if(top == NULL)
                return 0;
            pop();
        }
    }
    if(top == NULL)
        return 1;
    return 0;
}
 
int main() {
    char *exp = "((a+b)*(c-d))";

    printf("%d\n",isBalanced(exp));
    
    exp = "((a+b)*c";
    printf("%d\n",isBalanced(exp));

    exp = "((a+b)*c)))";
    printf("%d",isBalanced(exp));

    
    return 0;
}