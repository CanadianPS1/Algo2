#pragma once
#include <string>
#include "TreeNode.h"
#include <vector>
template<typename T>
class BinarySearchTree{
    private:
        TreeNode<T>* root = nullptr;
        int count = 0;
    public:
        TreeNode<T>* GetRoot(){return root;}
        void SetRoot(TreeNode<T> temp){root = temp;}
        int Size(){
            if(root != nullptr) return root->Size();
            return 0;
        }   
        void Add(T data){
            if(root == nullptr){
                root = new TreeNode<T>(data);
                count = root->Size();
            }
            else{
                root->Add(data);
                count = root->Size();
            }
        }
        std::string InOrder(){
            if(root == nullptr) return "";
            return root->InOrder();
        }
        bool Clear(){
            root->Clear();
            count = 0;
            delete root;
            root = nullptr;
            return true;
        }
        std::vector<T> ToArray(){return root->ToArray();}
        bool Contains(T value){return root->Contains(value);}
};
