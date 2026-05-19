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
        std::string PreOrder(){
            if(root == nullptr) return "";
            return root->PreOrder();
        }
        std::string PostOrder(){
            if(root == nullptr) return "";
            return root->PostOrder();
        }
        bool Clear(){
            root->Clear();
            count = 0;
            delete root;
            root = nullptr;
            return true;
        }
        std::vector<T> ToArray(){return root->ToArray();}
        bool Contains(T value){
            if(count == 0) return false;
            return root->Contains(value);
        }
        int Height(){
            if(count > 0) return root->Height();
            return 0;
        }
        void Remove(T value){
            if(root->Contains(value)){
                std::vector<T> allValues = root->ToArray();
                root->Clear();
                for(int i = 0; i < allValues.size(); i++) if(allValues[i] != value) root->Add(allValues[i]);
            }
        }
};
