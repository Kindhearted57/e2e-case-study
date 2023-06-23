//
//  main.c
//  password_sys
//
//  Created by Ru Ji on 2023-06-21.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define ERROR 0
#define SIZE 5000
// struct for node
typedef struct node{
    int p;
    int s;
    struct node * next;
} node_t;

bool CheckForNullSecret(int userp, int users){
    if(userp == 0 || users == 0){
        return false;
    }else{
        return true;
    }
}
bool PwasFound(node_t * free_head, node_t * temp){
    // load the stored secret, print
    printf("The secrect is %d",temp->s);
    // point the next ptr of the current triple to free list
    // erase the pair found
    temp->next = free_head->next;
    free_head->next = temp;
    return 1;
}


bool EndOfUsedListFound (node_t *used_head, node_t *free_head, node_t * temp, int userp, int users){

    // If no more free elements available
    // It is the same as checking if there is still free memory
    if(free_head ->next == NULL){
        return ERROR;
    }
    
    // if there are still free spaces
    // write things into the first free element
    free_head->next->p = userp;
    free_head->next->s = users;
    // cut off the element from free_head list
    free_head ->next = free_head->next->next;
    // add the newly inserted one into the used list
    temp -> next = used_head ->next;
    used_head->next = temp;
    return true;
}

bool CheckForPresenceOfP (node_t *used_head, node_t *free_head, int userp, int users){
    
    
    // if not found till end, return endofusedlistfound
    
    node_t * temp = used_head;
    node_t * temp_next = temp->next;
    
    while(temp_next != NULL){
        // if found, goto PwasFound
        if(temp_next->p == userp){
            PwasFound(free_head, temp_next);
            return 1;
        }
        // if not found and it is not the end, go to the next one in list
        temp = temp->next;
        temp_next = temp_next ->next;
    }
    EndOfUsedListFound(used_head, free_head, temp, userp, users);
    return 1;
    
}

int main(int argc, const char * argv[]) {
    
    // Set dummy free_head, used_head
    node_t * free_head = NULL;
    free_head = (node_t *)malloc(sizeof(node_t));
    
    free_head -> s = 0;
    free_head -> p = 0;
    free_head->next = NULL;
    node_t * used_head = NULL;
    used_head = (node_t *)malloc(sizeof(node_t));
    used_head -> s = 0;
    used_head -> p = 0;
    used_head->next = free_head;
    node_t * new_temp = free_head;
    
    // initialize the free list
    for(int i = 0; i < SIZE; i++){
        // create a node
        node_t * new_node = NULL;
        new_node = (node_t *)malloc(sizeof(node_t));
        new_node -> s = 0;
        new_node -> p = 0;
        new_temp -> next = new_node;
        new_temp = new_node;
    }
    int userp;
    int users;
    // Main while loop taking in user input
    while(true){
        
        // Ask for input of r and s

        printf("Hi\n");
        printf("Please input password and secret\n");
        scanf(" %d%d", &userp, &users);
        printf("You inputed userp %d \n", userp);
        printf("You inputed users %d \n", users);
        if(!CheckForNullSecret(userp, users)){
            // if input has null values, enter again
            continue;
        }
        // Otherwise check presence of P in the linked list
        CheckForPresenceOfP(used_head, free_head, userp, users);
        
        
    }
    
    return 0;
}
