#pragma once
#include <string>
#include "TreeNode.h"
template<typename T>
class BinarySearchTree{
    private:
        TreeNode<T>* root = nullptr;
    public:
        TreeNode<T>* GetRoot(){return root;}
        void SetRoot(TreeNode<T> temp){root = temp;}
        int Size(){
            if(root != nullptr) return root->Size();
            return 0;
        }   
        void Add(T data){
            if(root == nullptr) root = new TreeNode<T>(data);
            else root->Add(data);
        }
        std::string InOrder(){
            if(root == nullptr) return "";
            return root->InOrder();
        }
        bool Clear(){
            root->Clear();
            return true;
        }
};
