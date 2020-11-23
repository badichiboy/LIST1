#ifndef GRIDLIST_H_
#define GRIDLIST_H_
#include "List.h"

typedef struct ClassInfo
{
    int course_number;
    int class_num;
    int total_time;
    ClassInfo(const int course_num,const int class_num):course_number(course_num),class_num(class_num),total_time(0){};
    
}ClassInfo;

typedef struct TimeNode
{
    int time;
    List<ClassInfo> classes;
    TimeNode(const int time ):time(time),classes(List<ClassInfo>()){};
} TimeNode;

class GridList:public List<TimeNode>
{
    private:
    public:
    void insertInOrder(const int val, Node<TimeNode>* head);
    void getTopGridVals(const int num);
};

void GridList::getTopGridVals(const int num,int* courses,int* classes)
{
    ClassInfo* most_viewed=new ClassInfo[num];
    int i=0;
    while (num>0 && head!=nullptr)//keep iterate through the main list untill you reach 'num' classes
    {
        ListToArray(num,most_viewed[i]);
        num-=(head->classes->getSize());
        i+=head->classes->getSize();//advance 'most_viewed' index
        head=head->next;
    }

    if ( head==nullptr && num>0 )//in case there arent enough classes throw error
    {
        throw //;
    }
    for (int i=0;i<num;i++)//copy 'most_viewed' to the returned arrays
    {
        courses[i]=most_viewed[i]->course_number;
        classes[i]=most_viewed[i]->class_num;
    }
    delete[] most_viewed;
    return;
}

void GridList::insertInOrder(const int new_time, Node<TimeNode>* head, ClassInfo class)
{
    /*
    int curr_time;
    if (head->next == nullptr)
    {
        curr_time = -1;
    }
    else 
    {
        curr_time = (head->next)-> time;
    }
    */
    if ( new_time == (head->next)-> time)
    {
        (head->next)->classes.insertStart(class);
    }
    else if (new_time > (head->next)-> time)
    {
        Node<TimeNode>* new_node(time);
        new_node -> next = head->next;
        head->next = new_node;
        new_node->classes.insertStart(class);
    }
    else 
    {
        insertInorder(new_time , head->next, class);
    }
}

#endif
