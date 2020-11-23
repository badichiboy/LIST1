#ifndef LIST_H_
#define LIST_H_

#include <iostream>
template<class T>
class Node
{
    private:
    public:
    T value;
    Node<T>* next; // bigger
    Node<T>* prev; //smaller
    Node():value(0),next(nullptr),prev(nullptr){};
    Node(T val):value(val),next(nullptr),prev(nullptr){};
};

template<class T>
class List
{

    private:    
    protected:
    int size;
    Node<T>* head; // smallest val
    Node<T>* tail; // biggest val
    void deleteCurr(Node<T>* curr_node);
    int getSize();
    void insertStart(const T& val,Node<T>* head);
    void remove(const T& val,Node<T>* head);
    void emptyList(Node<T>* curr);

    public:
    List():head(new Node<T>()),tail(new Node<T>()),size(0){};
    ~List(){emptyList(head->next);delete head;delete tail;};
    void insertStart(const T& val);
    Node<T> insertBeforeBigger(const T& val, Node<T>* curr);
    void remove(const T& val);
    void remove(Node<T>* curr);
    Node<T>* getPrev(Node<T>* curr);
    Node<T>* getTail(){return tail->prev;};
};

template<class T>
Node<T>* List<T>::getPrev(Node<T>* curr)
{
    if (curr->prev == head)
    {
        return nullptr;
    }
    return curr->prev;
}


template <class T>
void List<T>::remove(Node<T>* curr)
{
    if (curr==nullptr)
    {
        return;
    }
    Node<T>* temp =curr;
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    delete curr;
}

template<class T>
Node<T> List<T>::insertBeforeBigger(const T& val,Node<T>* curr)
{
    Node<T>* temp=curr;
    T new_val= val + curr->value;
    while(temp->next!=tail)
    {
        if (new_val==temp->next->value)// if the value already exists in the list
        {
            return head->next;
        }
        else if (new_val<temp->next->value) // if the value doesnt exist
        {
            break;
        }
        temp=temp->next;
    }
    Node<T>* new_node(new_val);
    new_node->next=temp->next;
    new_node->prev=temp;
    temp->next->prev=new_node;
    temp->next=new_node;
    return new_node;
}

template <class T>
int List<T>::getSize()
{
    return size;
}

template <class T>
void List<T>::remove(const T& val)
{
    remove(val,head);
    if (size>0)
    {
        size --;
    }
}

template < class T>
void List<T>::remove(const T& val, Node<T>* head)
{
    if (head->next==tail)
    {
        return; // throw value doesnt exist
    }
    if((head->next)->value == val)
    {
        Node<T>* new_next = (head->next)->next;
        delete head->next;
        head->next = new_next;
        head->next->prev=head;
        return;
    }
    remove(val, head->next);
}

template < class T>
void List<T>::emptyList(Node<T>* curr)
{
    if (curr->next == tail)
    {
        return;
    }
    emptyList(curr->next);
    remove((curr->next)->value, curr);
}

template < class T>
void List<T>::insertStart(const T& val)
{
    insertStart(val,head);
    size++;
}

template < class T>
void List<T>::insertStart(const T& val,Node<T>* head)
{
    Node<T>* temp=head->next;
    Node<T>* new_node=new Node<T>(val);
    head->next=new_node;
    new_node->next=temp;
    if (size==1)
    {
        tail->prev=new_node;
    }
}

#endif