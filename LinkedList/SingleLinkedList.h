#include "Node.h"
#include <stdexcept>
template <typename T>
class SingleLinkedList{
    private:
    int count = 0;
    Node<T> head;
    void SetCount(int temp){count = temp;}
    public:
    int GetCount(){return count;}
    void Add(T data, Node<T> priorNode){
        if(head == nullptr){
            head = new Node<T>;
            head.SetData(data, nullptr);
            priorNode.SetNext(head);
        }else{
            Node<T> currentNode = head;
            while(currentNode.GetNext() != nullptr){currentNode = currentNode.GetNext();}
        }
        SetCount(GetCount() + 1);
    }
    T Get(int index){
        if(head == nullptr || index < 0 || index >= count) throw std::out_of_range("Invalid Index");
        int currentIndex = 0;
        Node<T> currentNode = head;
        while(currentIndex != index){
            currentNode = currentNode.GetNext();
            currentIndex++;
        }
        return currentNode.GetData();
    }
};