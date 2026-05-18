#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
template<typename T>
struct TreeNode{
    private:
        T data;
        TreeNode<T>* left;
        TreeNode<T>* right;
        std::string ConvertToString(T value){
            std::ostringstream oStringStream;
            oStringStream<<GetData();
            return oStringStream.str();
        }
        void SizeHelper(int& size){
            if(left != nullptr){
                size++;
                GetLeft()->SizeHelper(size);
            }
            if(right != nullptr){
                size++;
                GetRight()->SizeHelper(size);
            }
        }
        void ToArrayHelper(std::vector<T>& nodes){
            if(left != nullptr){ 
                nodes.push_back(GetLeft()->GetData());
                GetLeft()->ToArrayHelper(nodes);
            }
            if(right != nullptr){ 
                nodes.push_back(GetRight()->GetData());
                GetRight()->ToArrayHelper(nodes);
            }
        }
        void ContainsHelper(int value, bool& found){
            if(left != nullptr && found == false){
                if(GetLeft()->GetData() == value) found = true;
                else GetLeft()->ContainsHelper(value, found);
            }
            if(right != nullptr && found == false){
                if(GetRight()->GetData() == value) found = true;
                else GetRight()->ContainsHelper(value, found);
            }
        }
    public:
        TreeNode(){
            left = nullptr;
            right = nullptr;
        }
        T GetData(){return data;}
        void SetData(T temp){data = temp;}
        void SetLeft(TreeNode<T>* temp){left = temp;}
        void SetRight(TreeNode<T>* temp){right = temp;}
        TreeNode<T>* GetLeft(){return left;}
        TreeNode<T>* GetRight(){return right;}
        TreeNode(T data){
            this->SetData(data);
            left = nullptr;
            right = nullptr;
        }
        int Size(){
            int count = 1;
            SizeHelper(count);
            return count;
        }
        void Add(T value){
            if(GetData() <= value){
                if(GetRight() != nullptr) GetRight()->Add(value);
                else SetRight(new TreeNode<T>(value));
            }else{
                if(GetLeft() != nullptr) GetLeft()->Add(value);
                else SetLeft(new TreeNode<T>(value));
            }
        }
        std::string InOrder(){
            std::string leftInOrder = "";
            std::string rightInOrder = "";
            if(left != nullptr) leftInOrder = GetLeft()->InOrder();
            if(right != nullptr) rightInOrder = GetRight()->InOrder();
            std::string answer;
            answer = ConvertToString(GetData());
            if(left != nullptr) answer = leftInOrder + ", " + answer;
            if(right != nullptr) answer = answer + ", " + rightInOrder;
            return answer;
        }
        void Clear(){
            if(left != nullptr){
                left->Clear();
                delete left;
                left = nullptr;
            }
            if(right != nullptr){
                right->Clear();
                delete right;
                right = nullptr;
            }
        }
        std::vector<T> ToArray(){
            std::vector<T> nodes;
            nodes.push_back(GetData());
            ToArrayHelper(nodes);
            return nodes;
        }
        bool Contains(T value){
            bool found = false;
            ContainsHelper(value, found);
            return found;
        }
};
