#include<stdio.h>
#include<stdlib.h>

struct node{
	int data ;
	struct node * next ;
	struct node * prev ; 
};

struct node *start ;
void push(struct node **start,int data); // fuction to push an element in doubly linked list
void print(struct node * start);         // function to print traverse the whole list
void afternode(struct node *start , int data ,int x); // function to insert node after a given node
void delete(struct node *start,int data); // fuction to delete a node 
void addlast(struct node *start,int data); // fuction to insert a node at last


int main(){
	start = NULL ;
	push(&start,1);
	push(&start,2);
	push(&start,3);
	afternode(start,4,2);
	push(&start,5);
	print(start);
	delete(start,3);
	addlast(start,10);
	print(start);
	return 0;
}

void push(struct node **start,int data){
	struct node * newnode ;
	newnode = (struct node *)malloc(sizeof(struct node));
	
	newnode->data = data ;
	newnode->next = (*start) ;
	newnode->prev = NULL ;
	
	if((*start) != NULL){
		(*start)->prev = newnode ;
		
	}
	
	(*start) = newnode ;
	
}

void afternode(struct node *start , int data ,int x){
	struct node * newnode ;
	newnode = (struct node *)malloc(sizeof(struct node));
	while(start->data != x){
		start = start->next ;
	}
	newnode->data = data ;
	newnode->prev = start ;
	newnode->next = start->next;
	start->next = newnode ;

	newnode->next->prev = newnode ;	
}
void print(struct node *start){
	struct node *temp = start ;
	struct node *last ;
	printf("Traversing from start\n");
	while(temp != NULL){
		last = temp ;
		printf("%d-->",temp->data);
		temp = temp->next ;
	}
	
	printf("\nTraversing from last\n");
	while(last != NULL){
		printf("%d-->",last->data);
		last = last->prev ;		
	}
}
void delete(struct node *start, int data){
	struct node *temp = start ;
	while(start->data != data){
		start = start->next ;
	}
	
	temp->next = temp->next->next ;
	temp->next->prev = temp ;
}
void addlast(struct node *start,int data){
	struct node *temp = start ;
	while(temp->next != NULL){
		temp = temp->next ;
	}
	struct node *last = (struct node *)malloc(sizeof(struct node));
	last->data = data ;
	last->next = NULL ;
	last->prev = temp ;
	temp->next = last ;
}
