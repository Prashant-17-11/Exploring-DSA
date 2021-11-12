#include <stdio.h>
#include <stdlib.h>

char ch;
    
typedef struct LinkedList {
    int data;
    struct LinkedList *link;
} node;

void message() {
    system("cls");                      // to clear screen
    printf("Singly Linked List :\n");
    printf("1 : To create a list \n");
    printf("5 : To Exit.\n");

    ch = getchar();
}   // inputs an option from the user 

node* create(node* start) {
    node *temp , *prev;
    ch = 'y';

    printf("\n\t\t *** INPUT BLOCK *** \n");
    if(start != NULL) {
        printf("\n\n\t *** LIST ALREADY EXISTS ***\n");
        printf("Press ENTER to continue!");
        getch();
        return start;
    }

    fflush(stdin);

    while(ch == 'y') {
        temp = (node *) malloc(sizeof(node));
        printf("\n\t Enter th no ->");
        scanf("%d",&temp->data);
        temp->link = NULL;

        if(start == NULL) {
            prev = start = temp;
        } else {
            prev->link = temp;
            prev = temp;
        }

        fflush(stdin);

        printf("Do you want to continue (y/n) ? :\n");
        ch = getchar();
    }
    return start;
}   // a function to create a liked list

void displayList(node* start) {
    node *temp;
    system("cls");
    printf("\n\nBase address\tData\tLink");
    printf("\n=============================================");
    for(temp=start; temp != NULL; temp=temp->link) {
        printf("\n%10u\t%10d\t%10u",temp,temp->data,temp->link);
    }
    printf("\n\nPress ENTER to continue!!");
    getch();
    return;
}

int main() {
    node *start;    // Start or head is a pointer which points to the first node of linked list
    start = NULL;   // This means that the list is empty

    do{
        message();

        switch (ch)
        {
        case '1':
            start = create(start);
            displayList(start);
            break;
        }
    } while(ch != '5');

    return 0;
}