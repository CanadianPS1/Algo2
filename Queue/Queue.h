#include "../LinkedList/SingleLinkedList.h"
#include <algorithm>
#pragma once
//the linked list works really well for the queue because of the head, because of it it doesnt have to do alot of copying to add new elements
template<typename T>
class Queue{
    SingleLinkedList<T> queue;
    public:
    /**
     * @brief removes an item from the list
     * 
     * @return T 
     */
    T Dequeue(){return queue.Remove();}
    /**
     * @brief looks at the first item
     * 
     * @return T 
     */
    T Peak(){return queue.Get(0);}
    /**
     * @brief adds an item to the list
     * 
     * @param data 
     */
    void Enqueue(T data){queue.Add(data);}
    /**
     * @brief grabs the value at an index in the list
     * 
     * @param index 
     * @return T 
     */
    T Get(int index){return queue.Get(index);}
    /**
     * @brief checks if the value is inside the list
     * 
     * @param value 
     * @return true 
     * @return false 
     */
    bool Contains(int value){
        int index = queue.Search(value);
        if(index < 0) return false;
        else return true;
    }
    /**
     * @brief returns the size of the list
     * 
     * @return int 
     */
    int Size(){return queue.Size();}
};