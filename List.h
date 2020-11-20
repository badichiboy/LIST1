#ifndef LIST_H_
#define LIST_H_

#include <iostream>


template<class T>
class List
{

    private:

    template<class S>
    class Node
    {
        private:
        public:
        S value;
        Node<S>* next;
        Node():value(0),next(nullptr){};
        Node(S val):value(val),next(nullptr){};
    };
    
    protected:
    int size;
    Node<T>* head;
    void ListToArray(const int num,T* array);
    void printNumElements(const int num,T* array);
    int getSize();
    void insertStart(const T& val,Node<T>* head);
    void remove(const T& val,Node<T>* head);
    void emptyList(Node<T>* curr);

    public:
    List():head(new Node<T>()),size(0){};
    ~List(){emptyList(head->next);};
    void insertStart(const T& val);
    void inserBeforeSmaller(const T& val);
    void remove(const T& val);
};

template < class T>
void List<T>::ListToArray(const int num,T* array)
{
    Node<T>* curr=head->next;
    int i=0;
    while(i < num)
    {
        array[i++] = curr->value;
        curr=head->next;
    }
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
    if (head->next==nullptr)
    {
        return; // throw value doesnt exist
    }
    if((head->next)->value == val)
    {
        Node<T>* new_next = (head->next)->next;
        delete head->next;
        head->next = new_next;
        return;
    }
    remove(val, head->next);
}

template < class T>
void List<T>::emptyList(Node<T>* curr)
{
    if (curr->next == nullptr)
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
}

#endif