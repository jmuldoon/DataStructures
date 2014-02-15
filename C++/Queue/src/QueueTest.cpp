/*
 *  Info:       Linked q_list Queue Implementation Template Test File
 *  Created:    28.July.2013
 *  Modified:   28.July.2013
 *  Author:     James Muldoon
 *  Copyright (c) 2013. All rights reserved.
 */

#include <iostream> 
#include "Queue.h"
using namespace std;

int sum;
void Sum(const int &);

int main(int argc, const char * argv[]){
    Queue<int, int>* q_list = new Queue<int, int>;
    void (*fptr)(const int &) = NULL;

    for(int i = 0; i < 10; ++i)
        q_list->Enqueue(i);

    for(int i = 0; i<2; ++i)
        q_list->Dequeue();

    cout << "Initial Queue:\n";
    q_list->PrintAll();

    q_list->DeleteNode(5);

    fptr = &Sum;
    q_list->TraverseQueue(fptr);

    cout<<"\nIntermediate Queue:\n";
    q_list->PrintAll();

    cout<<"\nsum: "<<sum<<"\tsize: "<<q_list->GetSize()<<"\nfront: "<<q_list->Front()<<"\tback: "<<q_list->Back()<<endl;

    for(int i=2;i<=q_list->GetSize();++i){
        if(!q_list->IsInQueue(i))
            cout<<"inQueue: "<<q_list->IsInQueue(i)<<endl;
        else
            cout<<"inQueue: "<<q_list->IsInQueue(i)<<"\tGet: "<<q_list->Get(i)<<endl;
    }

    cout<<"\nFinal Queue:\n";
    q_list->PrintAll();

    return 0;
}

void Sum(const int &v){
    sum = v+sum;
}