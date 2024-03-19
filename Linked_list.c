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

int size(){
    node* temp = head;
    int count = 0;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

bool check_data(int data){
    node* temp = head;
    int len = size();
    for(int i=0;i<len;++i){
        if(temp->data==data){
            return true;
        }
        temp = temp->next;
    }
    return false;
    
}

void delete_node(int data){
    if(!check_data(data)){
        printf("Data not found\n");
        //return;
    }
    else{
        node* temp = head;
        if(data == head->data){
        head = head->next;
        free(temp);
        return;
        }
        node* temp1 = head;
        while(temp->data != data){
        temp = temp->next;
        }
        while(temp1->next!=temp){
        temp1 = temp1->next;
        }   
        temp1->next = temp->next;
        free(temp);
    }
}

void insert_pos(int data, int pos){
    int len = size();
    node* temp = head;
    if(pos<1|| pos>len+1){
        printf("Invalid position!\n");
        return;
    }
    node* new_node = create_node(data);
    if(pos==1){
        new_node->next = head;
        head = new_node;
    }   
    else{
        for(int i=1;i<pos-1;++i){
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
        
    }
}

void delete_pos(int pos){
    int len = size();
    node* temp = head;
    if(pos<1|| pos>len+1){
    printf("Invalid position!\n");
    return;
    }
    if(pos==1){
        head = head->next;
        free(temp);
    }
    for(int i=1;i<pos-1;++i){
        temp = temp->next;
    }
    node* to_delete = temp->next;
    temp->next = temp->next->next;
    free(to_delete);
}

void reverse_print(){
    node* curr = head;
    node* prev = NULL;
    node* next = NULL;
    //1->2->3->4->NULL
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    print();
}
int main(){
    insert(5);
    insert(6);
    insert(13);
    delete_node(13);
    insert_pos(5,2); //(data,pos)
    delete_pos(3);//pos as param
    print();
    reverse_print();
    return 0;
}
