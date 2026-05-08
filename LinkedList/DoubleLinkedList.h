#include "Node.h"
#include <cstddef>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <bits/stdc++.h>
#pragma once
template <typename T>
class DoubleLinkedList{
    private:
    int count = 0;
    Node<T>* head = nullptr;
    Node<T>* foot = nullptr;
    void SetCount(int temp){count = temp;}
    /**
     * @brief finds a spesific node and returns it
     * 
     * @param index 
     * @return Node<T> 
     */
    Node<T>* FindNode(int index){
        if(index < 0 || index >= count) throw std::out_of_range("Invalid Index");
        if(head == nullptr || foot == nullptr) throw std::out_of_range("Invalid Operation, head/foot is null");
        int currentIndex;
        Node<T>* currentNode;
        if(index > (count - 1) / 2){
            if(count == 0) currentIndex = 0;
            else currentIndex = count - 1;
            currentNode = foot;
        }else{ 
            currentIndex = 0;
            currentNode = head;
        }
        if(currentIndex == 0){
            while(currentIndex != index){
                currentNode = currentNode->GetNext();
                currentIndex++;
            }
        }else{
            while(currentIndex != index){
                currentNode = currentNode->GetPast();
                currentIndex--;
            }
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
            foot = head;
        }else{
            Node<T>* nextNode = new Node<T>(data);
            Node<T>* currentNode = foot;
            currentNode->SetNext(nextNode);
            nextNode->SetPast(foot);
            foot = nextNode;
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
        if(Size() > 2) FindNode(count - 2)->SetNext(nullptr);
        else if(Size() == 2) head->SetNext(nullptr);
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
        if(indexedNode == head) head->GetNext();
        T indexedNodeValue = indexedNode->GetData();
        if(Size() > 2) FindNode(index - 1)->SetNext(FindNode(index + 1));
        else if(Size() == 2) head->SetNext(nullptr);
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
        Node<T>* inserted;
        if(index == 0){
            inserted = new Node<T>(data, head);
            if(head == foot) foot = inserted;
            head = inserted;
        }else if(index == count - 1){
            inserted = new Node<T>(data, nullptr, foot);
            if(head == foot) head == inserted;
            foot = inserted;
        }else{
            inserted = new Node<T>(data, FindNode(index + 1));
            FindNode(index - 1)->SetNext(inserted);
        }
        count++;
    }
    /**
     * @brief deletes all the elementss
     * 
     */
    void Clear(){
        Node<T>* currentNode = head;
        while(currentNode != nullptr) {
            Node<T>* nextNode = currentNode->GetNext();
            delete currentNode;
            currentNode = nextNode;
        }
        head = nullptr;
        foot = nullptr;
        count = 0;
    }
    /**
     * @brief returns the index of the given value
     * 
     * @param value 
     * @return int 
     */
    int Search(T value){
        Node<T>* currentNode = head;
        int index = 0;
        for(; currentNode != nullptr; currentNode = currentNode->GetNext()){ 
            if(currentNode->GetData() == value) return index;
            index++;
        }
        return -1;
    }
    /**
     * @brief converts the linked list to a string and returns it as a vector
     * 
     * @return std::vector<std::string> 
     */
    std::vector<std::string> ToString(){
        std::vector<std::string> strings;
        std::ostringstream oStringStream;
        for(int i = 0; i < count; i++){ 
            oStringStream.str("");
            oStringStream.clear();
            oStringStream<<Get(i);
            strings.push_back(oStringStream.str());
        }
        return strings;
    }
};