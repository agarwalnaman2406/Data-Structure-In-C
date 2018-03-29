#include<stdio.h>
#include<stdlib.h>

struct node{
	int data ;
	struct node *next ;
};
void create(struct node* start);
void print(struct node* start);
void findnthnode(struct node* start,int count);
struct node* delete_last(struct node* start);
struct node *start ;


int main(){
	start = (struct node *)malloc(sizeof(struct node));
	create(start);
	start = delete_last(start);
	print(start);
	
	findnthnode(start,5);
	
	
}

void create(struct node* start){                                //here start is not a global variable..
	int data;
	printf("Enter the value to be stored in the link list (Press -1 to exit) :");
	scanf("%d",&data);
	if(data == -1){                                          //stop making nodes if the required statement is true
		start->next = NULL;}
	else{
		start->data = data;
		start->next=(struct node *)malloc(sizeof(struct node));
		create(start->next);	                       //recursing to insert again..
}
}

void print(struct node* start){
	while(start != NULL){	                  //it will print the node until the last element of the node is obtained(NULL element)
		printf("%d ---->",start->data);
		start = start->next;
}
printf("NULL\n");
}

struct node* delete_last(struct node* start){
	struct node* p=start;
	struct node* q;

	while(p->next->next!=NULL){
		p=p->next;
		}
		q=p->next;
		p->next=NULL;
		free(q);
	return start;
}


void findnthnode(struct node* start,int count){
	struct node *temp = start;
	struct node *nthnode = start ;
	int i ;
	for(i=1;i<=count;i++){
		temp = temp->next ;
	}
	printf("%d\n",temp->data);
	
	while(temp != NULL){
	        nthnode = nthnode->next ;
	        printf("%d--->",temp->data);	
		temp = temp->next ;
	
	}
	printf("\n%d",nthnode->data);
}
