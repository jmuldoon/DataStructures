/*
 *  data:       Doubly Linked List Header File
 *  Created:    25.July.2013
 *  Modified:   25.July.2013
 *  Author:     James Muldoon
 *  Copyright (c) 2013. All rights reserved.
 */

#ifndef DoublyLL_DLList_h
#define DoublyLL_DLList_h
using namespace std;

template<class T>
class DLLNode{
public:
    T data;
    class DLLNode *next;
    class DLLNode *prev;
    
    DLLNode(T el, DLLNode *ptr1 = 0, DLLNode *ptr2 = 0){
        data = el; next = ptr1, prev = ptr2;
    }
    
    DLLNode(DLLNode *ptr1 = 0, DLLNode *ptr2 = 0){
        next = ptr1; prev = ptr2;
    }
};

template <class T, class T2>
class DLList{
public:
    DLList(){
        head = new DLLNode<T>();
        head->next = head;
        head->prev = head;
        l_size = 0;
    }
    ~DLList();
    
    bool IsEmpty(){return head->next == head;}      // Returns True if the list is empty, else false.
    int GetSize(){return l_size;}                   // Returns the size of the list as an integer value
    
    void AddToHead(const T&);                       // Append a node to the head of the list
    void AddToTail(const T&);                       // Append a node to the tail of the list
    T DeleteFromHead();                             // Delete the head and return its data
    T DeleteFromTail();                             // Delete the tail and return its data
    void DeleteNode(const T2&);                     // Delete node specified by the data passed as the parameter
    bool IsInList(const T2&) const;                 // Return true if in the list, else false
    void PrintAll() const;                          // Prints the data from each node in the list
    T Get(const T2& id) const;                      // Returns the data from the node, if present in the list
    void InsertInOrder(const T&);                   // Insert node with data into in order within the list
    void TraverseList(void (*pf) (const T&));       // Traverse the entire list, running a function on each node
    void Reverse();                                 // Reverse the order of the current list
    
private:
    DLLNode<T>* head;                               // List pointer to the head
    int l_size;                                     // List size as an integer value
};

template<class T, class T2>
DLList<T,T2>::~DLList(){
    while (!IsEmpty()){                             // While the list is not empty, delete each of the nodes.
        DLLNode<T> *p = head->next->next;           // Store the node 2 after head in p
        delete head->next;                          // Delete the node next after head
        head->next = p;                             // Set the next node after head to what p stored
    }
}

template<class T, class T2>
void DLList<T,T2>::AddToHead(const T& el){
    DLLNode<T> *p = new DLLNode<T>(el);
    
    p->next = head->next;                           // Set the new node to point to the node after head.
    p->prev = head;                                 // Set the new node to point to the head itself
    
    head->next->prev = p;                           // Set the head of the list to point to node before p
    head->next = p;                                 // Set the head of the list to point to p
    ++l_size;                                       // Increment the size of the list
}

template<class T, class T2>
void DLList<T,T2>::AddToTail(const T& el){
    DLLNode<T> *p = new DLLNode<T>(el);
    
    p->next = head;                                 // New node points next to the head
    p->prev = head->prev;                           // New node point prev to the node before the head
    
    head->prev->next = p;                           // Set the pointer of the old tail to point next to the new node
    head->prev = p;                                 // Set the pointer of the head to point prev to the new node
    ++l_size;
}

template<class T, class T2>
T DLList<T,T2>::DeleteFromHead(){
    try{
        if (IsEmpty())
            throw("Attempted to delete from empty list.");
    }
    catch(char const *e){
        cout<<"Error: "<<e<<endl; throw;
    }
    T el = head->next->data;                        // Temporarily stores the data to be returned
    DLLNode<T> *tmp = head->next;                   // Sets a pointer to the node being deleted
    head->next->next->prev = head;                  // Sets the pointer of the node after the one deleted to point to head
    head->next = head->next->next;                  // Sets the pointer of head to the node after the one deleted
    
    --l_size;                                       // Decrement the size of the list
    delete tmp;                                     // Deletes the node, calls deconstructor
    return el;                                      // Returns the data of the just deleted node
}

template<class T, class T2>
T DLList<T,T2>::DeleteFromTail(){
    try{
        if (IsEmpty())
            throw("Attempted to delete from empty list.");
    }
    catch(char const *e){
        cout<<"Error: "<<e<<endl; throw;
    }
    T el = head->prev->data;                        // Temporarily stores the data to be returned
    DLLNode<T> *tmp = head->prev;                   // Sets a pointer to the node being deleted
    head->prev->prev->next = head;                  // Set the node before the node being deleted to point next to the head
    head->prev = head->prev->prev;                  // Set the head to point to the node before the node being deleted
    
    --l_size;                                       // Decrement the size of the list
    delete tmp;                                     // Deletes the node, calls deconstructor
    return el;                                      // Returns the data of the just deleted node
}


template<class T, class T2>
void DLList<T,T2>::DeleteNode(const T2& el){
    DLLNode<T> *curr;
    for(curr=head->next; curr!=head && !(curr->data==el); curr=curr->next);    // Traverse until found or finished
    if (curr==head && !(curr->data==el))
        return;                                     // It's not in the list

    curr->prev->next = curr->next;                  // Node before the one to be deleted points next to the node after
    curr->next->prev = curr->prev;                  // Node after the one to be deleted points prev to the node before
    
    --l_size;                                       // Decrement the size of the list
    delete curr;                                    // Deletes the node, calls deconstructor
}

template<class T, class T2>
bool DLList<T,T2>::IsInList(const T2& el) const{
    DLLNode<T> *curr;
    for(curr=head->next; curr!=head && !(curr->data==el); curr=curr->next); // Traverse list until found, or finished
    return curr != head;                                                    // If not the head, it is found, return bool
}

template<class T, class T2>
void DLList<T,T2>::PrintAll() const{
    DLLNode<T> *curr;
    for(curr=head->next; curr!=head; curr=curr->next)                       // Traverse the list until finsihed
        cout << curr->data << " ";                                          // print the data in the current node
    cout << endl;
}

template<class T, class T2>
T DLList<T,T2>::Get(const T2& id) const{
    DLLNode<T> *curr;
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
void DLList<T,T2>::InsertInOrder(const T& el){
    DLLNode<T> *curr, *p = new DLLNode<T>(el);

    // curr is first node with an item > el, or, if there is no item > el, the List Head.
    for(curr=head->next; curr!=head && (curr->data<=el); curr=curr->next);  // Traverse list to node insertion point
    p->next = curr;                                                         // Set the new node to point to the current node
    p->prev = curr->prev;                                                   // Set prev to point to the current nodes prev
    curr->prev->next = p;                                                   // Set node before current to point next to new
    curr->prev = p;                                                         // Set curr node to point prev to new node
    ++l_size;                                                               // Increment the size of the list
}

template<class T, class T2>
void DLList<T,T2>::TraverseList(void (*pf) (const T&)){
    DLLNode<T> *curr;
    for(curr=head->next; curr!=head; curr=curr->next)                       // Traverse list until until finished
        pf(curr->data); // Call the function passed in by the caller passing it the data in the current node.
}

template<class T, class T2>
void DLList<T,T2>::Reverse(){
    DLList<int, int>* tmp = new DLList<int, int>;
    
    while(!IsEmpty()){
        tmp->AddToTail(head->prev->data);
        DeleteFromTail();
    }
    
    DLLNode<T> *p = tmp->head;
    do{
        AddToTail(p->data);
        p = p->next;
    } while(p != tmp->head);
    DeleteFromHead();
}

#endif
