#include<stdio.h>
#include<stdlib.h>

struct node{
	int data ;
	struct node *next ;
};
struct node *start ;
struct node *addempty(struct node *start,int data);
struct node *addbegin(struct node *start,int data);
struct node *addlast(struct node *start,int data);
void display(struct node *start);

int main(){

	start = NULL ;
	start = addempty(start,10);
	start = addlast(start,1);
	start = addlast(start,2);
	start = addbegin(start,12);
	start = addbegin(start,16);
	display(start->next);
}

struct node *addempty(struct node *start,int data){
	if(start != NULL){
		return start ;
	}

	start = (struct node *)malloc(sizeof(struct node));
	start->data = data ;
	start->next = start ;
	return start ;
}

struct node *addlast(struct node *start,int data){
	struct node * temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data ;
	
	
	struct node *head = start ;
	while(start->next != head){
		start = start->next ;
	};
	temp->next = head ;
	start->next = temp ;
	return start ;	
}

struct node *addbegin(struct node *start,int data){
	struct node * temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data ;
	
	struct node *head = start ;
	while(start->next != head) {
		start = start->next ;
	};
	temp->next = head ;
	start->next = temp ;
	start = temp ;

	return start;
}

void display(struct node *start){
	struct node *temp = start ;
	do{
		printf("%d-->",start->data );
		start = start->next ;
	}while(start != temp) ;
}
