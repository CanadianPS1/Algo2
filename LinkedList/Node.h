template <typename T>
class Node{
    public:
    T data;
    Node<T> next;
    T GetData(){return data;}
    void SetData(T temp){data = temp;}
    Node<T> SetNext(Node<T> temp){next = temp;}
    Node<T> GetNext(){return next;}
    Node(T data, Node<T> temp){
        this.SetData(data);
        this.SetNext(temp);
    }
};