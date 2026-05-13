#pragma once
template<typename T>
class TreeNode{
    public:
    TreeNode(){
        left = nullptr;
        right = nullptr;
    }
    private:
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;
    public:
    T GetData(){return data;}
    void SetData(T temp){data = temp;}
    void SetLeft(TreeNode<T>* temp = nullptr){left = temp;}
    void SetRight(TreeNode<T>* temp = nullptr){right = temp;}
    TreeNode<T>* GetLeft(){return left;}
    TreeNode<T>* GetRight(){return right;}
    TreeNode(T data){this->SetData(data);}
    void Add(T value){
        if(data >= value){
            if(GetRight() != nullptr) GetRight()->Add(data);
            else SetRight(new TreeNode<T>(data));
        }else{
            if(GetLeft() != nullptr) GetLeft()->Add(data);
            else SetLeft(new TreeNode<T>(data));
        }
    }
};
