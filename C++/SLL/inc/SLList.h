/*
 *  data:       Singally Linked List Header File
 *  Created:    25.July.2013
 *  Modified:   27.July.2013
 *  Author:     James Muldoon
 *  Copyright (c) 2013. All rights reserved.
 */

#ifndef SLL_H
#define SLL_H
using namespace std;

template<class T>
class SLLNode{
public:
    T data;
    class SLLNode *next;
    
    SLLNode(T el, SLLNode *ptr = 0){
        data = el; next = ptr;
    }
    
    SLLNode(SLLNode *ptr = 0){
        next = ptr;
    }
};

template <class T, class T2>
class SLList{
public:
    SLList(){
        head = new SLLNode<T>();
        head->next = head;
        l_size=0;
    }
    ~SLList();                                      // Deletes the entire list
    
    bool IsEmpty(){return head->next == head;}
    int GetSize(){return l_size;}

    void AddToHead(const T&);
    void AddToTail(const T&);
    T DeleteFromHead();                             // Delete the head and return its data;
    T DeleteFromTail();                             // Delete the tail and return its data;
    void DeleteNode(const T2&);
    bool IsInList(const T2&) const;
    void PrintAll() const;
    T Get(const T2& id) const;
    void InsertInOrder(const T&);
    void TraverseList(void (*pf) (const T&));
    
private:
    SLLNode<T>* head;
    int l_size;
};

template<class T, class T2>
SLList<T,T2>::~SLList(){
    while (!IsEmpty()){                                     // While the list is not empty, delete each of the nodes.
        SLLNode<T> *p = head->next->next;                   // Store the node 2 after head in p
        delete head->next;                                  // Delete the node next after head
        head->next = p;                                     // Set the next node after head to what p stored
    }
}

template<class T, class T2>
void SLList<T,T2>::AddToHead(const T& el){
    SLLNode<T> *p = new SLLNode<T>(el);
    
    p->next = head->next;                                   // Set the new node to point to the node after head.
    head->next = p;                                         // Set the head to point to the new node.
    ++l_size;                                               // Increment the size of the list
}

template<class T, class T2>
void SLList<T,T2>::AddToTail(const T& el){
    SLLNode<T> *curr, *p = new SLLNode<T>(el);
    
    for(curr=head->next;curr->next!=head;curr=curr->next);  // Traverse to end of the list
    curr->next=p;                                           // Set the last node's next ptr to the new node
    curr=p;
    curr->next=head;                                        // Set the new last node's next ptr to the head of the list.
    ++l_size;                                               // Increment the size of the list
}

template<class T, class T2>
T SLList<T,T2>::DeleteFromHead(){
    try{
        if (IsEmpty())
            throw("Attempted to delete from empty list.");
    }
    catch(char const *e){
        cout<<"Error: "<<e<<endl; throw;
    }
    T el = head->next->data;                                // Temporarily stores the data to be returned
    SLLNode<T> *tmp = head->next;                           // Sets a pointer to the node being deleted
    head->next = head->next->next;                          // Sets the pointer of head to the node after the one deleted
    
    --l_size;                                               // Decrement the size of the list
    delete tmp;                                             // Deletes the node, calls deconstructor
    return el;                                              // Returns the data of the just deleted node
}

template<class T, class T2>
T SLList<T,T2>::DeleteFromTail(){
    try{
        if (IsEmpty())
            throw("Attempted to delete from empty list.");
    }
    catch(char const *e){
        cout<<"Error: "<<e<<endl; throw;
    }
    SLLNode<T> *curr, *tmp;
    for(curr=head->next;curr->next->next!=head;curr=curr->next);    // Traverse to end of the list
    T el = curr->next->data;                                        // Temporarily stores the data to be returned
    tmp=curr->next;                                                 // Sets a pointer to the node being deleted
    curr->next=head;                                                // Set the last node's next ptr to the head node
    
    --l_size;                                                       // Decrement the size of the list
    delete tmp;                                                     // Deletes the node, calls deconstructor
    return el;                                                      // Returns the data of the just deleted node
}


template<class T, class T2>
void SLList<T,T2>::DeleteNode(const T2& el){
    SLLNode<T> *curr, *tmp;
    for(curr=head->next;curr!=head && !(curr->next->data==el);curr=curr->next);    // Traverse until found or finished
    if (curr == head && !(curr->next->data==el))                    // If it is the head, and !data, it was not in the list
        return;                                                     // It's not in the list.

    tmp=curr->next;                                                 // Sets a pointer to the node being deleted
    curr->next=curr->next->next;                                    // Set the node before to point next to the one after

    --l_size;                                                       // Decrement the size of the list
    delete tmp;                                                     // Delete the node containing the data
}

template<class T, class T2>
bool SLList<T,T2>::IsInList(const T2& el) const{
    SLLNode<T> *curr;
    for(curr=head->next; curr!=head && !(curr->data==el); curr=curr->next); // Traverse list until found, or finished
    return curr != head;                                                    // If not the head, it is found, return bool
}

template<class T, class T2>
void SLList<T,T2>::PrintAll() const{
    SLLNode<T> *curr;
    for(curr=head->next; curr!=head; curr=curr->next)                       // Traverse the list until finsihed
        cout << curr->data << " ";                                          // print the data in the current node
    cout << endl;
}

template<class T, class T2>
T SLList<T,T2>::Get(const T2& id) const{
    SLLNode<T> *curr;
    for(curr=head->next; curr!=head && !(curr->data==id); curr=curr->next); // Traverse list until data is found or finished
    try{
        if (curr==head)                                                     // If the head, item is not in the list.
            throw("Item not in list");
    }
    catch(const char *e){
        cout<<"Error: "<<e<<endl; throw;
    }
    return curr->data;                                                      // Return the data stored in the current node
}

template<class T, class T2>
void SLList<T,T2>::InsertInOrder(const T& el){
    SLLNode<T> *curr, *p = new SLLNode<T>(el);
    // curr is first node with an item > el, or, if there is no item > el, the List Head.
    for(curr=head; curr->next!=head && (curr->next->data<=el); curr=curr->next);    // Traverse list to node insertion point
    p->next = curr->next;                                                   // Set the new node to point to the node after
    curr->next = p;                                                         // Set the next of current to point to new node
    ++l_size;                                                               // Increment the size of the list
}

template<class T, class T2>
void SLList<T,T2>::TraverseList(void (*pf) (const T&)){
    SLLNode<T> *curr;
    for(curr=head->next; curr!=head; curr=curr->next)                       // Traverse list until until finished
        pf(curr->data); // Call the function passed in by the caller passing it the data in the current node.
}

#endif //end SLL_H
