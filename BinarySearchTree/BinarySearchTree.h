#pragma once
#include <string>
#include "TreeNode.h"
template<typename T>
class BinarySearchTree{
    private:
        int count = 0;
        TreeNode<T>* root = nullptr;
        void SetCount(int temp){count = temp;}
    public:
        TreeNode<T> GetRoot(){return root;}
        void SetRoot(TreeNode<T> temp){root = temp;}
        int Size(){return count;}
        void Add(T data){
            if(root == nullptr) root = new TreeNode<T>(data);
            else root->Add(data);
            SetCount(Size() + 1);
        }
        std::string InOrder(){
            if(root == nullptr) return "";
            return root->InOrder();
        }
};
