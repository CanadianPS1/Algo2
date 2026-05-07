#include "Node.h"
#include <stdexcept>
#include <algorithm>
#include <iostream>
template <typename T>
class SingleLinkedList{
    private:
    int count = 0;
    Node<T>* head = nullptr;
    void SetCount(int temp){count = temp;}
    /**
     * @brief finds a spesific node and returns it
     * 
     * @param index 
     * @return Node<T> 
     */
    Node<T>* FindNode(int index){
        if(index < 0 || index >= count) throw std::out_of_range("Invalid Index");
        if(head == nullptr) throw std::out_of_range("Invalid Operation, head is null");
        int currentIndex = 0;
        Node<T>* currentNode = head;
        while(currentIndex != index){
            currentNode = currentNode->GetNext();
            currentIndex++;
        }
        return currentNode;
    }
    public:
    int Size(){return count;}
    /**
     * @brief adds a node to the linked list
     * 
     * @param data 
     * @param priorNode 
     */
    void Add(T data){
        if(head == nullptr){
            head = new Node<T>;
            head->SetData(data);
        }else{
            Node<T>* nextNode = new Node<T>(data, nullptr);
            Node<T>* currentNode = head;
            while(currentNode->GetNext() != nullptr) currentNode = currentNode->GetNext();
            currentNode->SetNext(nextNode);
        }
        SetCount(Size() + 1);
    }
    /**
     * @brief returns the given index of a node
     * 
     * @param index 
     * @return T 
     */
    T Get(int index){return FindNode(index)->GetData();}
    /**
     * @brief find and deletes the first item in the linked list then returns its value
     * 
     * @return T 
     */
    T Remove(){
        Node<T>* firstNode = head;
        head = head->GetNext();
        T firstNodeValue = firstNode->GetData();
        delete firstNode;
        count--;
        return firstNodeValue;
    }
    /**
     * @brief Removes the Last element in the linked list and returns its value
     * 
     * @return T 
     */
    T RemoveLast(){
        Node<T>* lastNode = FindNode(count - 1);
        T lastNodeValue = lastNode->GetData();
        delete lastNode;
        count--;
        return lastNodeValue;
    }
    /**
     * @brief removes the indexed element and returns its value
     * 
     * @param index 
     * @return T 
     */
    T RemoveAt(int index){
        Node<T>* indexedNode = FindNode(index);
        T indexedNodeValue = indexedNode->GetData();
        delete indexedNode;
        count--;
        return indexedNodeValue;
    }
    /**
     * @brief creates a node at a given index
     * 
     * @param index 
     * @param data 
     */
    void InsertAt(int index, T data){
        if(index == 0){
            Node<T>* inserted = new Node<T>(data, head);
            head = inserted;
        }else{
            Node<T>* inserted = new Node<T>(data, FindNode(index + 1));
            FindNode(index - 1)->SetNext(inserted);
        }
        count++;
    }
    /**
     * @brief deletes all the elementss
     * 
     */
    void Clear(){
        for(int i = count - 1; i >= 0; i--){
            delete FindNode(i);
            count--;
        }
    }
    int Search(T value){
        Node<T>* currentNode = head;
        int index = 0;
        for(; currentNode != nullptr; currentNode = currentNode->GetNext()){ 
            if(currentNode->GetData() == value) return index;
            index++;
        }
        return -1;
    }
};