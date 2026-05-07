#include "Node.h"
#include <stdexcept>
#include <algorithm>
template <typename T>
class SingleLinkedList{
    private:
    int count = 0;
    Node<T>* head = nullptr;
    void SetCount(int temp){count = temp;}
    public:
    int Size(){return count;}
    /**
     * @brief adds a node to the linked list
     * 
     * @param data 
     * @param priorNode 
     */
    void Add(T data, Node<T>* priorNode = nullptr){
        if(head == nullptr){
            head = new Node<T>;
            head->SetData(data);
            priorNode->SetNext(head);
        }else{
            Node<T> currentNode = *head;
            while(currentNode.GetNext() != nullptr){currentNode = *currentNode.GetNext();}
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
     * @brief find and returns the first item in the linked list
     * 
     * @return T 
     */
    T Remove(){
        Node<T> firstNode =  FindNode(0);
        head = head.GetNext();
        return firstNode.GetData();
    }
    /**
     * @brief creates a node at a given index
     * 
     * @param index 
     * @param data 
     */
    void InsertAt(int index, T data){
        if(index == 0){
            Node<T> inserted = new Node<T>(data, head);
            head = inserted;
        }else{
            Node<T> inserted = new Node<T>(data, FindNode(index + 1));
            FindNode(index - 1).SetNext(inserted);
        }
        count++;
    }
    /**
     * @brief deletes all the elementss
     * 
     */
    void Clear(){
        head = nullptr;
        count = 0;
    }
    int Search(T value){
        Node<T> currentNode = head;
        int index = 0;
        for(index++; currentNode != nullptr; currentNode = currentNode.GetNext()) if(currentNode.GetData() == value) return index;
        return -1;
    }
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
};