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
        /**
         * @brief Get the Root object
         * 
         * @return TreeNode<T>* 
         */

        TreeNode<T>* GetRoot(){return root;}
        /**
         * @brief Set the Root object
         * 
         * @param temp 
         */
        void SetRoot(TreeNode<T> temp){root = temp;}
        /**
         * @brief calls the size class and returns what it finds
         * 
         * @return int 
         */
        int Size(){
            if(root != nullptr) return root->Size();
            return 0;
        }
        /**
         * @brief creates a root if their isnt one and if their is it calls the add method on it
         * 
         * @param data 
         */
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
        /**
         * @brief calls the inorder method on the node
         * 
         * @return std::string 
         */
        std::string InOrder(){
            if(root == nullptr) return "";
            return root->InOrder();
        }
        /**
         * @brief calls the preorder method on the node
         * 
         * @return std::string 
         */
        std::string PreOrder(){
            if(root == nullptr) return "";
            return root->PreOrder();
        }
        /**
         * @brief calls the postorder method on the node
         * 
         * @return std::string 
         */
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
        /**
         * @brief converts your tree into a T vector
         * 
         * @return std::vector<T> 
         */
        std::vector<T> ToArray(){return root->ToArray();}
        bool Contains(T value){
            if(count == 0) return false;
            return root->Contains(value);
        }
        /**
         * @brief calls the height method on the node
         * 
         * @return int 
         */
        int Height(){
            if(count > 0) return root->Height();
            return 0;
        }
        /**
         * @brief turns the tree into an array, then clears the tree and makes a new one without the var
         * 
         * @param value 
         */
        void Remove(T value){
            if(root->Contains(value)){
                std::vector<T> allValues = root->ToArray();
                root->Clear();
                for(int i = 0; i < allValues.size(); i++) if(allValues[i] != value) root->Add(allValues[i]);
            }
        }
};
