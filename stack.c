#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

typedef struct{
	int arr[SIZE];
	int top;
}Stack;

Stack stack;
void init(){
	stack.top=-1;
}

int isFull(){
	return stack.top==SIZE-1;
}
int isEmpty(){
	return stack.top==-1;
}

void push(int data){
	if(isFull()){
		printf("Stack overflow!\n");
		return;
	}
	stack.arr[++stack.top] =data;
}
int pop(){
	if(isEmpty()){
		printf("Stack underflow\n");
		exit(1);
	}
	return stack.arr[stack.top--];
}

int peek(){
	return stack.arr[stack.top];
}
void print(){
	for(int i=0;i<=stack.top;++i){
		printf("%d ",stack.arr[i]);
	}
}
int main(){
	init();
	push(13);
	push(18);
	push(25);
	push(76);
	push(45);
	printf("The popped element is: %d\n",pop());
	printf("The top element is: %d\n",peek());
	print();
	return 0;
}
