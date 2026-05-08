#include "../LinkedList/SingleLinkedList.h"
#include <algorithm>
#pragma once
//the linked list works really well for the queue because of the head, because of it it doesnt have to do alot of copying to add new elements
template<typename T>
class Queue{
    SingleLinkedList<T> queue;
    public:
    T Dequeue(){return queue.Remove();}
    T Peak(){return queue.Get(0);}
    void Enqueue(T data){queue.Add(data);}
    T Get(int index){return queue.Get(index);}
    bool Contains(int value){
        int index = queue.Search(value);
        if(index < 0) return false;
        else return true;
    }
    int Size(){return queue.Size();}
};