#include<stdio.h>
#include<stdlib.h>

int front = -1 , rear = -1;
int size = 10 ;
int arr[10];

void dequeue();
void enqueue();
void display();


int main(){
	enqueue();
	enqueue();
	enqueue();
	display();
	dequeue();
	display();
}

void enqueue(){
	if(rear == size-1){
		printf("overflow occurs");
	}else{
	 front = 0;
	 rear = rear + 1 ;
	 printf("Enter the element");
	 scanf("%d",&arr[rear]);
	}
}

void dequeue(){
	int i,j ;
	if(front == -1){
		printf("Underflow Occurs");
	}else{
		for(i=0;i<rear;i++){
			
			arr[i] = arr[i+1] ;	
			
		}
	}
	rear-- ;
}

void display(){
	int i ;
	for(i=0;i<=rear;i++){
		printf("%d -->",arr[i]);			
	}printf("NULL\n");
}	

