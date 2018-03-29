#include<stdio.h>
#include<stdlib.h>
int top  ;
int max = 10 ;
int arr[10];
void push();
void pop();
void display();
int main(){
	top = -1 ;
	push();
	push();
	display();
	pop();
	display();
	
	
}
void push(){
	if(top>max){
		printf("Overflow");		
	}else{
		top++;
		printf("Enter the element");
		scanf("%d",&arr[top]);	
	}
}

void pop(){
	if(top == -1){
		printf("Underflow\n");
	}else{
		top = top - 1 ;
		
	}
}

void display(){
	int i ;
	if(top == -1){
		printf("No element present");
	}else{
		for(i=top;i>=0;i--){
			printf("%d --> ",arr[i]);
		}
	}
		printf("\n");
}
