#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *link;
};


	void create(struct node* start);                   //function to create node in the list..
	void print(struct node * start);                   //funtion to print,traverse the whole list..
	struct node* insert_begin(struct node *start);
	void insert_last(struct node *start);
	struct node* delete_begin(struct node *start);
	struct node* insert_btw(struct node* start,int element_data);
	struct node* delete_last(struct node* start);
	struct node* delete_btw(struct node* start,int element_data_del);



int main(){
	struct node *start;
	start=(struct node *)malloc(sizeof(struct node));
	int input;
	printf("\n Choose the Which Funtion You Want to Implement: \n\n");
	printf("1.Create a link list \n");
	printf("2.Insert at beginning in  a link list\n");
	printf("3.Insert at end a link list \n");
	printf("4.Display the linked list\n");
	printf("5.Delete the node at beginning \n");
	printf("6.Delete the node at end \n");
	printf("7.Insert the node in between \n");
	printf("8.Delete the node in between \n");

	start:
	printf("\n\nEnter your INPUT :");
	scanf("%d",&input);
	int element_data;
	int element_data_del;

	switch(input){
		case 1:create(start);break;
		case 2:start=insert_begin(start);break;
		case 3:insert_last(start);break;
		case 4:print(start);break;
		case 5:start=delete_begin(start);break;
		case 6:start=delete_last(start);break;
		case 7:
			printf("\nEnter the element after which node is to be inserted :");
			scanf("%d",&element_data);
			start=insert_btw(start,element_data);break;
		case 8:
			printf("\nEnter the node to be deleted :");
			scanf("%d",&element_data_del);
			start=delete_btw(start,element_data_del);
			print(start);break;


}
	printf("\n\nDo You Want to run again(1/0)");
	int again;
	scanf("%d",&again);

	if(again==1){
		goto start;}
	else{
		printf("Thank For implimenting linked list Sucessfully ");}



}
//Declaring the used functions below...

void create(struct node* start){                                //here start is not a global variable..
	int data;
	printf("Enter the value to be stored in the link list (Press -1 to exit) :");
	scanf("%d",&data);
	if(data == -1){                                          //stop making nodes if the required statement is true
		start->link = NULL;}
	else{
		start->data = data;
		start->link=(struct node *)malloc(sizeof(struct node));
		create(start->link);	                       //recursing to insert again..
}
}

void print(struct node* start){
	while(start->link != NULL){	                  //it will print the node until the last element of the node is obtained(NULL element)
		printf("%d ---->",start->data);
		start = start->link;
}

printf("NULL");
}

struct node* insert_begin(struct node *start){

	struct node *new_front;
	new_front=(struct node *)malloc(sizeof(struct node));
	if(new_front==NULL){                                       //checks wheater the memory is allcated or not..
		printf("No memory allocated");}
	else{
		printf("\nEnter the element to be inserted at the front of the linked list :");
		scanf("%d",&new_front->data);
		new_front->link = start;
		start = new_front;                                            //changing the value of start..
		}

return start;
}

void insert_last(struct node* start){

	struct node* last_node;
	last_node=(struct node *)malloc(sizeof(struct node));
	//struct node* temp = start;

		while(start->link != NULL){    //traversing to the last node..
		start = start->link;
		}
	printf("\nEnter the  element to be stored at end of the of the link list :");
	int item;
	scanf("%d",&item);
	last_node->link = NULL;
	start->link =last_node;    //linking the last node to new last node
	start->data = item;

}

struct node* delete_begin(struct node* start){
	struct node *q=start;
	start=start->link;
	free(q);
	return start;

}

struct node* delete_last(struct node* start){
	struct node* p=start;
	struct node* q;

	while(p->link->link!=NULL){
		p=p->link;}
		q=p->link;
		p->link=NULL;
		free(q);
	return start;
}


struct node* insert_btw(struct node* start,int element_data){
	struct node* new_node=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the element to be stored in the link list");
	scanf("%d",&new_node->data);
	struct node* p=start;
	struct node* q;
	while(p->link!=NULL && p->data!=element_data){
		p=p->link;}
	q=p->link;
	p->link=new_node;
	new_node->link=q;
	return start;
}

struct node* delete_btw(struct node* start,int element_data){
	struct node* p=start;
	struct node* q;
	while(p->link!=NULL && p->link->data!=element_data){
		p=p->link;}
	q=p->link;
	p->link=q->link;
	free(q);
	return start;

}


