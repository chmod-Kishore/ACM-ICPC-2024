#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* create_node(int data){
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void print_list(node* head){
    node* temp = head;
    while(temp){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

node* merge_list(node* head1, node* head2){
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    node* mergedhead = NULL;
    if(head1->data <= head2->data){
        mergedhead = head1;
        mergedhead->next = merge_list(head1->next,head2);
    }
    else{
        mergedhead = head2;
        mergedhead->next = merge_list(head2->next,head1);

    }
    return mergedhead;
}

int main(){
    node* head1 = create_node(5);
    head1->next = create_node(7);
    head1->next->next = create_node(8);
    head1->next->next->next = create_node(10);
    node* head2 = create_node(1);
    head2->next = create_node(2);
    head2->next->next = create_node(3);
    head2->next->next->next = create_node(4);
    node* mergedhead = merge_list(head1,head2);
    print_list(mergedhead);

    return 0;
}
