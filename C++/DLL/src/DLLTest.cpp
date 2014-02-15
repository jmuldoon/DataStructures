/*
 *  Info:       Doubly Linked List Test File
 *  Created:    25.July.2013
 *  Modified:   25.July.2013
 *  Author:     James Muldoon
 *  Copyright (c) 2013. All rights reserved.
 */

#include <iostream> 
#include "DLList.h"
using namespace std;

int sum;
void Sum(const int &);

int main(int argc, const char * argv[]){
    DLList<int, int>* list = new DLList<int, int>;
    void (*fptr)(const int &) = NULL;

    for(int i = 0; i < 5; ++i)
        list->AddToTail(i);

    for(int i = -1; i > -5; --i)
        list->AddToHead(i);
    
    list->InsertInOrder(3);
    list->InsertInOrder(6);
    list->InsertInOrder(-2);
    list->InsertInOrder(-5);
    list->InsertInOrder(5);
    list->DeleteNode(-2);
    list->DeleteFromHead();
    list->DeleteFromTail();

    cout << "Initial List:\n";
    list->PrintAll();

    cout<<sum<<endl;
    fptr = &Sum;
    list->TraverseList(fptr);
    cout<<"sum: "<<sum<<"\tsize: "<<list->GetSize()<<endl;

    for(int i=-10;i<=10;++i){
        if(!list->IsInList(i))
            cout<<"i: "<<i<<"\tinQueue: "<<list->IsInList(i)<<endl;
        else
            cout<<"i: "<<i<<"\tinQueue: "<<list->IsInList(i)<<"\tGet: "<<list->Get(i)<<endl;
    }

    list->Reverse();
    cout<<"Reversed List:\n";
    list->PrintAll();

    return 0;
}

void Sum(const int &v){
    sum = v+sum;
}
