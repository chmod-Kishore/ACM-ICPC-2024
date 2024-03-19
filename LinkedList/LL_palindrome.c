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

node* reverse(){
    node* curr = head;
    node* prev = NULL;
    node* next = NULL;
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool compare_list(node* head1, node* head2){
    while(head1 && head2){
        if(head1->data!=head2->data){
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;

    }
    return true;
}

bool check_palindrome(){
    node* reversed_head = reverse();
    bool result = compare_list(head,reversed_head);
    reverse();//to retrive the original list
    return result;
}

int main(){
    insert(5);
    insert(6);
    insert(13);
    insert(6);
    insert(5);
    insert(24);
    bool result = check_palindrome();
    if(!result){
        printf("Not a palindrome\n");
    }
    else{
        printf("It is a palindrome\n");
    }
    return 0;
}
