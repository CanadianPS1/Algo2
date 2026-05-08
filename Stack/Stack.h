#include "../LinkedList/DoubleLinkedList.h"
#include <algorithm>
#pragma once
template<typename T>
//a linked list works really well for a stack because of the foot, because of that its able to quickly grab and motifi whats being used
class Stack{
    DoubleLinkedList<T> list;
    public:
    /**
     * @brief removes an item from the list
     * 
     * @return T 
     */
    T Pop(){return list.RemoveLast();}
    /**
     * @brief looks at the first item in the list
     * 
     * @return T 
     */
    T Peak(){return list.Get(list.Size() - 1);}
    /**
     * @brief adds an item to the list
     * 
     * @param data 
     */
    void Push(T data){list.Add(data);}
    /**
     * @brief grabs the value at an index
     * 
     * @param index 
     * @return T 
     */
    T Get(int index){return list.Get(index);}
    /**
     * @brief checks if the list contains an item
     * 
     * @param value 
     * @return true 
     * @return false 
     */
    bool Contains(int value){
        int index = list.Search(value);
        if(index < 0) return false;
        else return true;
    }
    /**
     * @brief returns the size of the list
     * 
     * @return int 
     */
    int Size(){return list.Size();}
};