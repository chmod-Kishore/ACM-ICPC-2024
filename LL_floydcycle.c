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

bool detect_cycle(){
    node* slow = head;
    node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        if(slow == slow->next){
            return true;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}

int main(){
    insert(5);
    insert(6);
    insert(13);
    insert(6);
    insert(5);
    insert(24);
    bool ans = detect_cycle();
    if(!ans){
        printf("Cycle not detected\n");
    }
    else{
        printf("Cycle detected\n");
    }
    return 0;
}
