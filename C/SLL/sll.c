/*
 *  Info:       Singally Linked List for integer datatype storage.
 *  Created:    02.July.2013
 *  Modified:   06.July.2013
 *  Author:     James Muldoon
 */

#ifndef SLL_H
#include "sll.h"
#endif

typedef struct node{
    long long int data; // The integer data/key value for the node
    struct node *next;  // Points to the next node
} SLL;

SLL *CreateNode(long long int num){
    SLL *tmp;
    tmp=(SLL *)malloc(sizeof(SLL)); // Allocate the memory for the new node
    tmp->data=num;                  // Set the data of the new node to the num <int> parameter
    tmp->next=NULL;                 // Set the next pointer to NULL, so it can be checked and set later
    return tmp;
}

SLL *AppendTail(SLL *head, long long int num){
    SLL *tmp, *curr;
    tmp=CreateNode(num);    // Creates the node to be inserted

    if(head==NULL)          // If the list is empty
        head=tmp;
    else{                   // All other conditions append after the last node in the list (tail)
        for(curr=head;curr->next!=NULL;curr=curr->next);    // Traverse until end of list is reached
        curr->next=tmp;
        curr=tmp;
        curr->next=NULL;
    }
    return head;
}

SLL *AppendHead(SLL *head, long long int num){
    SLL *tmp;
    tmp=CreateNode(num);    // Creates the node to be inserted

    if(head==NULL)          // If the list is empty
        head=tmp;
    else{                   // All other conditions append before the head
        tmp->next=head;
        head=tmp;
    }
    return head;
}

SLL *InsertOrdered(SLL *head, long long int num){
    SLL *tmp, *prev, *curr;
    tmp=CreateNode(num);    // Creates the node to be inserted

    // Traverse the list until curr->data is finally larger than the tmp->data.
    for(curr=head, prev=NULL;curr!=NULL && tmp->data>curr->data;prev=curr, curr=curr->next);
    tmp->next=curr; // Set tmp->next to curr because curr is now larger than it value wise.
    
    if (prev==NULL) // If the list is empty or the data is smaller than the first node.
        head=tmp;
    else            // All other conditions
        prev->next=tmp;
    return head;
}

SLL *Delete(SLL *head, long long int num){
    SLL *tmp, *prev;

    if(head==NULL)
        printf("List is Empty\n");
    else{
        // Traverse the list until the node to be deleted is found
        for(tmp=head, prev=NULL;tmp->next!=NULL && tmp->data!=num;prev=tmp,tmp=tmp->next);
        
        if(tmp==head){              // If the node is the root
            head=tmp->next;
            free(tmp);
            printf("%lld deleted successfully\n",num);
        }
        else if(tmp->data==num){   // If the node is not the root 
            prev->next=tmp->next;
            free(tmp);
            printf("%lld deleted successfully\n",num);
        }
        else                        // The node is not in the list
            printf("%lld not found in the list\n",num);
    }
    return head;
}

int MaxValue(SLL *head){
    SLL *tmp;
    int max;
    
    for (tmp = head, max = tmp->data; tmp->next!=NULL; tmp=tmp->next)   // Checks for all values in the Linked List
        max = fmax(max, tmp->next->data);                               // keeps only the max value
    return max;
}

void Display(SLL *head){
    SLL *tmp = head;
    for(;tmp!=NULL; tmp=tmp->next)  // Traverses the entire list
        printf("%d ",tmp->data);    // Prints the data in the node
    printf("\n");
}

int Count(SLL *head){
    SLL *tmp=head;
    int c;
    for(c=0, tmp=head;tmp!=NULL;tmp=tmp->next, c++);    // Traverses the list counting the nodes
    return c;                                           // Returns the total count
}