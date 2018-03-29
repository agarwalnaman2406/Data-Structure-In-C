#include <stdio.h>
#include <stdlib.h>
int front = 0 ,rear = -1 ;
int n ;
void enqueue();
void display();
int *arr ;
int main()
{

    printf("Enter the size of array");
    scanf("%d",&n);

    arr =  (int *)malloc(n * sizeof(int));
    enqueue();
    enqueue();
    display();
    dequeue();
    display();
    enqueue();
    enqueue();
    display();
    dequeue();
    dequeue();
    display();


}
void enqueue(){

    rear = rear + 1 ;
    printf("Enter The Data  ");
    scanf("%d",(arr + rear));

}
void dequeue(){
    int i ;
    printf("Element Deleted %d \n ",*(arr + front ));
    for(i=0;i<rear;i++){
        *(arr+i) = *(arr + i + 1);
    }
    rear = rear -1 ;
    //front = front + 1 ;
}
void display(){
    int i ;
    printf("Printing queue\n ");
for(i=0;i<=rear;i++){
    printf("%d ",*(arr+i));

}
printf("\n");


}

