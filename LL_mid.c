#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* head = NULL;
node* create_node(int data){
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data= data;
    new_node->next = NULL;
    return new_node;
}

void insert(int data){
    node* new_node = create_node(data);
    if(head == NULL){
        head = new_node;
        return;
    }
    node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = new_node;
} 

void print(){
    node* temp = head;
    while(temp){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int find_middle(){
    if(head==NULL){
        printf("No element is found!\n");
        return 0;
    }
    node* slow = head;
    node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;

}

int main(){
    insert(5);
    insert(6);
    insert(13);
    insert(16);
    insert(2);
    insert(24);
    int middle = find_middle();
    printf("Middle element is: %d\n",middle);
    return 0;
}
