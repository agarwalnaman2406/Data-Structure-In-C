#include <stdio.h>
#include <stdlib.h>s
struct node{
    int data ;
    struct node *next ;

};
struct node *start ;
void create(struct node *start);
void display(struct node *start);
void reverse(struct node **head);
struct node * deletelast(struct node *start);


int main()
{
    start = (struct node *)malloc(sizeof(struct node));
    create(start);
    start = deletelast(start);
    display(start);
    reverse(&start);
    display(start);
    return 0;
}
void create(struct node *start){
    int data ;
    printf("Enter the number(-1 to exit) ----> ");
    scanf("%d",&data);
    if(data == -1){
        start->next = NULL ;
    }else{
        start->data = data ;
        start->next  = (struct node *)malloc(sizeof(struct node));
        create(start->next);
    }

}
void display(struct node *start){
    struct node *temp = start ;
    while(temp != NULL){
        printf("%d--->",temp->data);
        temp = temp->next ;
    }
    printf("NULL\n");
}
void reverse(struct node **head){
    struct node *prev = NULL ;
    struct node *current = *head ;
    struct node *next ;
    while(current != NULL){
        next = current->next ;
        current->next = prev ;
        prev = current ;
        current = next ;
    }
    *head = prev ;
}
struct node * deletelast(struct node *start){
    struct node *temp = start ;
    while(temp->next->next != NULL){
    temp = temp->next;
    }
    temp->next = NULL ;
    return start  ;
}
