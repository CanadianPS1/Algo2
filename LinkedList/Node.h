template <typename T>
#pragma once
class Node{
    public:
    Node(){
        next = nullptr;
        past = nullptr;
    }
    private:
    T data;
    Node<T>* next;
    Node<T>* past;
    public:
    T GetData(){return data;}
    void SetData(T temp){data = temp;}
    void SetNext(Node<T>* temp = nullptr){next = temp;}
    void SetPast(Node<T>* temp = nullptr){past = temp;}
    Node<T>* GetNext(){return next;}
    Node<T>* GetPast(){return past;}
    Node(T data, Node<T>* nextTemp = nullptr, Node<T>* pastTemp = nullptr){
        this->SetData(data);
        this->SetNext(nextTemp);
        this->SetPast(pastTemp);
    }
};
