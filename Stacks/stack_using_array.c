// Abdul Bari tutorial udemy

#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int size;
    int top;
    int *s;
};

void create(struct Stack *st) {
    printf("Enter Size:\n");
    scanf("%d",&st->size);
    st->top = -1;
    st->s = (int *) malloc(st->size*sizeof(int));
}

void display(struct Stack st) {
    printf("Stack is: ");
    for(int i = st.top; i >= 0 ; i--) {
        printf("%d ",st.s[i]);
    }
    printf("\n");
}

void push(struct Stack *st, int x) {
    if(st->top == st->size-1) {
        printf("Stack Overflow\n");
        return;
    }
    st->top++;
    st->s[st->top] = x;
}

int pop(struct Stack *st) {
    if(st->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    int x = st->s[st->top];
    st->top--;
    return x;
}

int peek(struct Stack st, int pos) {
    if(st.top-pos+1 < 0) {
        printf("Invalid Position\n");
        return -1;
    }
    return st.s[st.top-pos+1];
}

int stackTop(struct Stack st) {
    if(st.top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return st.s[st.top];
}

int isEmpty(struct Stack st) {
    if(st.top == -1)
        return 1;
    return 0;
}

int isFull(struct Stack st) {
    if(st.top == st.size-1)
        return 1;
    return 0;
}

int main() {
    struct Stack st;
    create(&st);

    push(&st,10);
    push(&st,20);
    push(&st,30);
    push(&st,40);
    push(&st,50);
    // push(&st,60);    gives overflow
    
    printf("%d \n",pop(&st));

    display(st);

    printf("%d \n",pop(&st));
    printf("%d \n",pop(&st));
    printf("%d \n",pop(&st));
    printf("%d \n",pop(&st));
    // printf("%d \n",pop(&st));    gives underflow

    push(&st,30);
    push(&st,40);
    push(&st,50);

    display(st);
    printf("%d \n",peek(st,1));
    printf("%d \n",peek(st,3));
    printf("%d \n",peek(st,5));
    display(st);

    printf("%d \n",isEmpty(st));
    printf("%d \n",isFull(st));


    return 0;
}