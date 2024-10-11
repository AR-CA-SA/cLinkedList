#include <stdio.h>
#include <stdlib.h>

typedef struct node { 
    int x ; 
    int y ;
    //pointer to itself
    struct node* next;


    //using typedef to give a identifier to our node
}node_t;


void create_node(node_t** head, int x, int y){
    node_t* new_node = malloc(sizeof(node_t));
    //creates  a new node POINTER and allocates it on the heap
    if (new_node == NULL){
        exit(1);
        //exit if there is any memory allocation erros
    }
    new_node->next = NULL;
    //set the pointer to the next node as null 

    //set the elements of the node
    new_node->x = x;
    new_node->y = y;


    node_t* curr = *head;
    //creates a pointer to the 

    while(curr->next !=NULL){
        //if the current dereference pointer is not equal to NULL continue

        curr = curr->next;
    }
    curr->next = new_node;
    //set the pointer to the next node
}

void printList(node_t* head) {
    //will take & type
    node_t* current = head;
    while (current != NULL) {
        printf("First element : %d Second Element : %d -> ", current->x, current->y);
        current = current->next;
    }
    printf("NULL\n");
}

int main(){ 
    //malloc is used for dynamic memory allocation.
    // It means that the memory is being store in the heap rather than stack.
    //The elements allocated using malloc have random access
    //this makes it easier to scale up the elements beacsue the size is not fixed
    node_t* head = malloc(sizeof(node_t));

    head->x=1;
    //derefence the pointer
    head->y=2;
    head->next = NULL;
    //head is set to null because before  we add more values 
    //there  is no more linked nodes
    create_node(&head, 5 ,6);
    create_node(&head, 8 ,9);
    printList(head);
}