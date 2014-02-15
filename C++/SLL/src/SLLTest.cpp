/*
 *  Info:       Singally Linked List Test File
 *  Created:    25.July.2013
 *  Modified:   28.July.2013
 *  Author:     James Muldoon
 *  Copyright (c) 2013. All rights reserved.
 */

#include <iostream> 
#include "SLList.h"
using namespace std;

int sum;
void Sum(const int &);

int main(int argc, const char * argv[]){
    SLList<int, int>* list = new SLList<int, int>;
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

    return 0;
}

void Sum(const int &v){
    sum = v+sum;
}