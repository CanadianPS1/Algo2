template <typename T>
class Node{
    public:
    Node() : next(nullptr){}
    private:
    T data;
    Node<T>* next;
    public:
    T GetData(){return data;}
    void SetData(T temp){data = temp;}
    void SetNext(Node<T>* temp){next = temp;}
    Node<T>* GetNext(){return next;}
    Node(T data, Node<T>* temp = nullptr){
        this->SetData(data);
        this->SetNext(temp);
    }
};
