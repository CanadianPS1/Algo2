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
                left->SizeHelper(size);
            }
            if(right != nullptr){
                size++;
                right->SizeHelper(size);
            }
        }
        void ContainsHelper(T value, bool& found){
            if(data == value){
                found = true;
                return;
            }
            if(left != nullptr && found == false) left->ContainsHelper(value, found);
            if(right != nullptr && found == false) right->ContainsHelper(value, found);
            
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
        std::string PreOrder(){
            std::string leftInOrder = "";
            std::string rightInOrder = "";
            if(left != nullptr) leftInOrder = GetLeft()->InOrder();
            if(right != nullptr) rightInOrder = GetRight()->InOrder();
            std::string answer;
            answer = ConvertToString(GetData());
            if(left != nullptr) answer = answer + ", " + leftInOrder;
            if(right != nullptr) answer = answer + ", " + rightInOrder;
            return answer;
        }
        std::string PostOrder(){
            std::string leftInOrder = "";
            std::string rightInOrder = "";
            if(left != nullptr) leftInOrder = GetLeft()->InOrder();
            if(right != nullptr) rightInOrder = GetRight()->InOrder();
            std::string answer = "";
            if(left != nullptr) answer = leftInOrder + ", ";
            if(right != nullptr) answer = answer + rightInOrder + ", ";
            answer += ConvertToString(GetData());
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
            std::vector<T> leftNodes;
            std::vector<T> rightNodes;
            if(left != nullptr) leftNodes = GetLeft()->ToArray();
            if(right != nullptr) rightNodes = GetRight()->ToArray();
            std::vector<T> answer;
            if(left != nullptr) answer = leftNodes;
            answer.push_back(GetData());
            if(right != nullptr) answer.insert(answer.end(), rightNodes.begin(), rightNodes.end());
            return answer;
        }
        bool Contains(T value){
            if(left == nullptr || right == nullptr) return false;
            bool found = false;
            ContainsHelper(value, found);
            return found;
        }
        /*
            height sudo code
            param current depth int param depths vector
                depth++
                go left
                go right
                add depth to depth vector
                return vector
                
        */
        int Height(){
            std::vector<int> depths;
            HeightHelper(0, depths);
            return depths[0];
        }
        void HeightHelper(int currentDepth, std::vector<int>& depths){
            currentDepth++;
            if(GetLeft() != nullptr) GetLeft()->HeightHelper(currentDepth, depths);
            if(GetRight() != nullptr) GetRight()->HeightHelper(currentDepth, depths);
            depths.push_back(currentDepth);
        }
};
