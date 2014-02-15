/*
 *  data:       Linked Queue Queue Implementation Template Header File
 *  Created:    28.July.2013
 *  Modified:   28.July.2013
 *  Author:     James Muldoon
 *  Copyright (c) 2013. All rights reserved.
 */

#ifndef SLL_H
#define SLL_H
using namespace std;

template<class T>
class QueueNode{
public:
    T data;
    class QueueNode *next;
    
    QueueNode(T el, QueueNode *ptr = 0){
        data = el; next = ptr;
    }
    
    QueueNode(QueueNode *ptr = 0){
        next = ptr;
    }
};

template <class T, class T2>
class Queue{
public:
    Queue(){                                    // Constructor
        head = new QueueNode<T>();
        head->next = head;
        q_size = 0;
    }
    ~Queue();                                   // Deletes the entire Queue
    
    bool IsEmpty(){return head->next == head;}  // Checks if queue is empty. true if empty, else false.
    int GetSize(){return q_size;}               // Get the size of the queue.
    
    void Enqueue(const T&);                     // Appends an element to the end of the queue
    T Dequeue();                                // Delete the head and return its data;
    T Front();                                  // Accesses the element at the head of the queue
    T Back();                                   // Accesses the element at the end of the queue

    void DeleteNode(const T2&);                 // Removes the specified node from the queue
    bool IsInQueue(const T2&) const;            // Checks if the element is in the queue
    void PrintAll() const;                      // Prints the entire queue
    T Get(const T2& id) const;                  // Returns the data element in the queue else terminates
    void TraverseQueue(void (*pf) (const T&));  // Traverses the queue running a function at each element in the queue.
    
private:
    QueueNode<T>* head;
    int q_size;
};

template<class T, class T2>
Queue<T,T2>::~Queue(){
    while (!IsEmpty()){                                 // While the Queue is not empty, delete each of the nodes.
        QueueNode<T> *p = head->next->next;
        delete head->next;
        head->next = p;
    }
}

template<class T, class T2>
void Queue<T,T2>::Enqueue(const T& el){
    QueueNode<T> *curr, *p = new QueueNode<T>(el);

    for(curr=head;curr->next!=head;curr=curr->next);    // Traverse to end of the Queue
    curr->next=p;                                       // Set the last node's next ptr to the new node
    curr=p;
    curr->next=head;                                    // Set the new last node's next ptr to the head of the Queue.
    ++q_size;                                           // Increments the queue size.
}

template<class T, class T2>
T Queue<T,T2>::Dequeue(){
    try{
        if (IsEmpty())
            throw("Attempted to delete from empty Queue.");
    }
    catch(char const *e){
        cout<<"Error: "<<e<<endl; throw;
    }
    T el = head->next->data;                            // Temporarily stores the data to be returned
    QueueNode<T> *tmp = head->next;                     // Sets a pointer to the node being deleted
    head->next = head->next->next;                      // Sets the pointer of head to the node after the one deleted
    
    --q_size;                                           // Increments the queue size.
    delete tmp;                                         // Deletes the node, calls deconstructor
    return el;                                          // Returns the data of the just deleted node
}

template<class T, class T2>
T Queue<T,T2>::Front(){
    return head->next->data;                            // Returns the data at the front of the queue
}

template<class T, class T2>
T Queue<T,T2>::Back(){
    QueueNode<T> *curr;
    for(curr=head;curr->next!=head;curr=curr->next);    // Traverse to end of the Queue
    return curr->data;                                  // Returns the data at the end of the queue
}

template<class T, class T2>
void Queue<T,T2>::DeleteNode(const T2& el){
    QueueNode<T> *curr, *tmp;
    for(curr=head->next;curr!=head && !(curr->next->data==el);curr=curr->next);    // Traverse until found or finished
    if (curr == head && !(curr->next->data==el))        // If it is the head, and !data, it was not in the Queue
        return;                                         // It's not in the Queue.

    tmp=curr->next;                                     // Sets a pointer to the node being deleted
    curr->next=curr->next->next;                        // Set the node before to point next to the one after

    --q_size;                                           // Increments the queue size.
    delete tmp;                                         // Delete the node containing the data
}

template<class T, class T2>
bool Queue<T,T2>::IsInQueue(const T2& el) const{
    QueueNode<T> *curr;
    for(curr=head->next; curr!=head && !(curr->data==el); curr=curr->next); // Traverse Queue until found, or finished
    return curr != head;                                                    // If not the head, it is found, return bool
}

template<class T, class T2>
void Queue<T,T2>::PrintAll() const{
    QueueNode<T> *curr;
    for(curr=head->next; curr!=head; curr=curr->next)                       // Traverse the Queue until finsihed
        cout << curr->data << " ";                                          // print the data in the current node
    cout << endl;
}

template<class T, class T2>
T Queue<T,T2>::Get(const T2& id) const{
    QueueNode<T> *curr;
    for(curr=head->next; curr!=head && !(curr->data==id); curr=curr->next); // Traverse Queue until data is found or finished
    try{
        if (curr==head)                                                     // If the head, item is not in the Queue.
            throw("Item not in Queue");
    }
    catch(const char *e){
        cout<<"Error: "<<e<<endl; throw;
    }
    return curr->data;                                                      // Return the data stored in the current node
}

template<class T, class T2>
void Queue<T,T2>::TraverseQueue(void (*pf) (const T&)){
    QueueNode<T> *curr;
    for(curr=head->next; curr!=head; curr=curr->next)   // Traverse Queue until until finished
        pf(curr->data); // Call the function passed in by the caller passing it the data in the current node.
}

#endif //end SLL_H
