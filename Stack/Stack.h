#include "../LinkedList/DoubleLinkedList.h"
#include <algorithm>
#pragma once
template<typename T>
//a linked list works really well for a stack because of the foot, because of that its able to quickly grab and motifi whats being used
class Stack{
    DoubleLinkedList<T> list;
    public:
    T Pop(){return list.RemoveLast();}
    T Peak(){return list.Get(list.Size() - 1);}
    void Push(T data){list.Add(data);}
    T Get(int index){return list.Get(index);}
    bool Contains(int value){
        int index = list.Search(value);
        if(index < 0) return false;
        else return true;
    }
    int Size(){return list.Size();}
};