#include "../LinkedList/DoubleLinkedList.h"
#include <algorithm>
#pragma once
template<typename T>
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
        else return false;
    }
    int Size(){return list.Size();}
};