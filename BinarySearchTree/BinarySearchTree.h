#pragma once
#include "TreeNode.h"
template<typename T>
class BinarySearchTree{
    private:
    int count = 0;
    TreeNode<T>* root;
    public:
    TreeNode<T> GetRoot(){return root;}
    void SetRoot(TreeNode<T> temp){root = temp;}
    int Size(){return count;}
    void Add(T data){
        if(root == nullptr) root = new TreeNode<T>(data);
        else root->Add(data);
        count++;
    }
};
