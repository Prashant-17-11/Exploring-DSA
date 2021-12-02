#include <stdio.h>
#include <stdlib.h>

typedef struct linklist {
    int data;
    struct linklist *link;
} node;

char ch;

node *create(node *head) {
    node *temp , *prev;
    ch = 'y';

    printf("\n\t\t*** Creating a linked list ***\n");
    if(head != NULL) {
        printf("\n\t\t *** List Already Exists ***\n");
        getch();
        return head;
    }

    fflush(stdin);

    while(ch == 'y') {
        temp = (node *) malloc(sizeof(node));
        printf("\n\t Enter the value :--> ");
        scanf("%d",&temp->data);
        temp->link = NULL;
        if(head == NULL) {
            prev = head = temp;
        } else {
            prev->link = temp;
            prev = temp;
        }
        fflush(stdin);
        printf("\n\t Do you want to continue (y/n)? :");
        ch = getchar();
    }
    return head;
}

node *insertAtBegining(int item, node *head) {
    node *temp;
    temp = (node *) malloc(sizeof(node));
    temp->data = item;
    temp->link = head;

    head = temp;
    printf("Element is successfully inserted.\n");
    printf("Press any key to continue.\n");
    getch();
    return head;
}

node *insertBefore(int item, int var, node *head) {
    node *temp , *prev, *new;
    new = (node *) malloc(sizeof(node));

    for(temp = head; (temp->data != var) && (temp != NULL) ;temp = temp->link) {
        prev = temp;
    }

    if(temp == NULL) {
        printf("\n\n\t Number not found in the LinkedList:\n");
        getch();
    } else if(temp == head) {
        head = insertAtBegining(item,head);
    } else {
        new->data = item;
        new->link = prev->link;
        prev->link = new;
        printf("\n\n\t ELement is successfully inserted\n");
        getch();
    }
    return head;
}

void *insertAfter(int item, int var, node *head) {
    node *temp, *new;
    new = (node *) malloc(sizeof(node));
    for(temp=head; (temp->data != var)&&(temp != NULL); temp=temp->link);

    if(temp == NULL) {
        printf("\n\n\t Number not found in the list!");
        getch();
    } else {
        new->data = item;
        new->link = temp->link;
        temp->link = new;
        printf("\n\n\t Element is successfully inserted");
        getch();
    }
}

void insertAtEnd(int item, node *head) {
    node *temp, *new;
    new = (node *) malloc(sizeof(node));
    new->data = item;

    for(temp = head; temp->link != NULL; temp=temp->link);

    temp->link=new;
    new->link=NULL;
    printf("\n\n\t Element is successfully inserted");
    getch();
}

node *deleteAtBegining(node  *head) {
    node *temp = head;
    head = head->link;
    printf("Element is successfully deleted");
    getch();
    free(temp);
    return head;
}

node *deleteParticular(int item, node *head) {
    node *temp, *temp1;

    for(temp = head; (temp->data != item) && (temp != NULL); temp=temp->link) {
        temp1=temp;
    }

    if(temp == NULL) {
        printf("\n\n\t Number not found in the LinkedList");
        getch();
        return head;
    }

    if(temp == head) {
        head = deleteAtBegining(head);
    } else {
        temp1->link = temp1->link->link;
        printf("\n\n\t Element is successfully deleted");
        getch();
        free(temp);
    }
    return head;
}

void deleteAtEnd(node *head) {
    node *temp, *temp1;
    for(temp=head; temp->link != NULL; temp=temp->link) {
        temp1=temp;
    }

    temp1->link = NULL;
    free(temp);
    printf("\n\n\t Element is successfully deleted");
    getch();
}

void printList(node *head) {
    node *temp;
    system("cls");
    printf("\n\n Base address Number link");
    for(temp = head; temp != NULL ; temp = temp->link) {
        printf("\n%10u %10d %10u",temp,temp->data,temp->link);
    }
    printf("\nPress any key to continue....\n");
    getch();
}

int main() {
    node *head;
    head = NULL;

    int item , var;
            
    ch = 'y';

    while (ch == 'y') {
        printf("Select an option from the following:\n");
        printf("1) Create a Linked List\n");
        printf("2) Insert a node at the begining\n");
        printf("3) Insert a node after a given node\n");
        printf("4) Insert a given node before a given node\n");
        printf("5) Insert a node at the end\n");
        printf("6) Delete a node at the begining\n");
        printf("7) Delete a given node\n");
        printf("8) Delete a node at the end\n");
        

        fflush(stdin);
        printf("Enter your choice:\n");
        ch = getchar();

        switch (ch)
        {
        case '1':
            head = create(head);
            break;
        
        case '2':
            printf("Enter the item to be inserted:\n");
            scanf("%d",&item);
            head = insertAtBegining(item,head);
            break;
        
        case '3':
            printf("Enter the item to be inserted:\n");
            scanf("%d",&item);
            printf("Enter the value after which item is to be inserted:\n");
            scanf("%d",&var);
            insertAfter(item,var,head);
            break;
        
        case '4':
            printf("Enter the item to be inserted:\n");
            scanf("%d",&item);
            printf("Enter the value before which item is to be inserted:\n");
            scanf("%d",&var);
            head = insertBefore(item,var,head);
            break;

        case '5':
            printf("Enter the item to inserted:\n");
            scanf("%d",&item);
            insertAtEnd(item,head);
            break;
        
        case '6':
            head = deleteAtBegining(head);
            break;
        
        case '7':
            printf("Enter the item to be deleted:\n");
            scanf("%d",&item);
            head = deleteParticular(item,head);
            break;
        
        case '8':
            deleteAtEnd(head);
            break;
        
        default:
            printf("Invalid option selected!!");
        }
        
        printList(head);
            
        fflush(stdin);
        printf("\n\t Do you want to continue (y/n)? :");
        ch = getchar();
    }
    
    return 0;
}