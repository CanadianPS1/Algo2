#pragma once
#include <string>
#include <sstream>
#include <vector>
template <typename T>
struct LinkedListNode{
    public:
    LinkedListNode(){
        next = nullptr;
        past = nullptr;
    }
    private:
    T data;
    LinkedListNode<T>* next;
    LinkedListNode<T>* past;
    public:
    T GetData(){return data;}
    void SetData(T temp){data = temp;}
    void SetNext(LinkedListNode<T>* temp = nullptr){next = temp;}
    void SetPast(LinkedListNode<T>* temp = nullptr){past = temp;}
    LinkedListNode<T>* GetNext(){return next;}
    LinkedListNode<T>* GetPast(){return past;}
    LinkedListNode(T data, LinkedListNode<T>* nextTemp = nullptr, LinkedListNode<T>* pastTemp = nullptr){
        this->SetData(data);
        this->SetNext(nextTemp);
        this->SetPast(pastTemp);
    }
};
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
        /**
         * @brief looks through all the nodes and returns the amount
         * 
         * @return int 
         */
        int Size(){
            int count = 1;
            SizeHelper(count);
            return count;
        }
        /**
         * @brief creates a new left or right node
         * 
         * @param value 
         */
        void Add(T value){
            if(GetData() <= value){
                if(GetRight() != nullptr) GetRight()->Add(value);
                else SetRight(new TreeNode<T>(value));
            }else{
                if(GetLeft() != nullptr) GetLeft()->Add(value);
                else SetLeft(new TreeNode<T>(value));
            }
        }
        /**
         * @brief finds all the nodes and turns them into a string with the root sorted
         * 
         * @return std::string 
         */
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
        /**
         * @brief finds all the nodes and turns them into a string with the root at the start
         * 
         * @return std::string 
         */
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
        /**
         * @brief finds all the nodes and turns them into a string with the root at the end
         * 
         * @return std::string 
         */
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
        /**
         * @brief whipes it clean of memory
         * 
         */
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
        /**
         * @brief puts each value of the tree into an vector
         * 
         * @return std::vector<T> 
         */
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
        /**
         * @brief returns what it found
         * 
         * @param value 
         * @return true 
         * @return false 
         */
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
    private:
        /**
         * @brief finds the deepest point in the tree
         * 
         * @param currentDepth 
         * @param depths 
         */
        void HeightHelper(int currentDepth, std::vector<int>& depths){
            currentDepth++;
            if(GetLeft() != nullptr) GetLeft()->HeightHelper(currentDepth, depths);
            if(GetRight() != nullptr) GetRight()->HeightHelper(currentDepth, depths);
            depths.push_back(currentDepth);
        }
};
template<typename T>
struct AVLTreeNode{
    private:
        T data;
        AVLTreeNode<T>* left;
        AVLTreeNode<T>* right;
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
        AVLTreeNode(){
            left = nullptr;
            right = nullptr;
        }
        T GetData(){return data;}
        void SetData(T temp){data = temp;}
        void SetLeft(AVLTreeNode<T>* temp){left = temp;}
        void SetRight(AVLTreeNode<T>* temp){right = temp;}
        AVLTreeNode<T>* GetLeft(){return left;}
        AVLTreeNode<T>* GetRight(){return right;}
        AVLTreeNode(T data){
            this->SetData(data);
            left = nullptr;
            right = nullptr;
        }
        /**
         * @brief looks through all the nodes and returns the amount
         * 
         * @return int 
         */
        int Size(){
            int count = 1;
            SizeHelper(count);
            return count;
        }
        /**
         * @brief creates a new left or right node
         * 
         * @param value 
         */
        void Add(T value){
            if(GetData() <= value){
                if(GetRight() != nullptr) GetRight()->Add(value);
                else SetRight(new AVLTreeNode<T>(value));
            }else{
                if(GetLeft() != nullptr) GetLeft()->Add(value);
                else SetLeft(new AVLTreeNode<T>(value));
            }
        }
        /**
         * @brief finds all the nodes and turns them into a string with the root sorted
         * 
         * @return std::string 
         */
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
        /**
         * @brief finds all the nodes and turns them into a string with the root at the start
         * 
         * @return std::string 
         */
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
        /**
         * @brief finds all the nodes and turns them into a string with the root at the end
         * 
         * @return std::string 
         */
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
        /**
         * @brief whipes it clean of memory
         * 
         */
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
        /**
         * @brief puts each value of the tree into an vector
         * 
         * @return std::vector<T> 
         */
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
        /**
         * @brief returns what it found
         * 
         * @param value 
         * @return true 
         * @return false 
         */
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
    private:
        /**
         * @brief finds the deepest point in the tree
         * 
         * @param currentDepth 
         * @param depths 
         */
        void HeightHelper(int currentDepth, std::vector<int>& depths){
            currentDepth++;
            if(GetLeft() != nullptr) GetLeft()->HeightHelper(currentDepth, depths);
            if(GetRight() != nullptr) GetRight()->HeightHelper(currentDepth, depths);
            depths.push_back(currentDepth);
        }
        //TODO write the balance method
        void Balance(){}
        void RightLeft(AVLTreeNode<T>& node){
            Right(node);
            Left(node);
        }
        void LeftRight(AVLTreeNode<T>& node){
            Left(node);
            Right(node);
        }
        void Right(AVLTreeNode<T>& node){
            T temp = node.GetData();
            node->GetData() = GetLeft()->GetData();
            node->GetLeft()->SetData(temp);
            if(node->GetLeft()->GetData() > node->GetData()){
                node->GetRight() = node->GetLeft();
                if(node->GetRight()->GetLeft() != nullptr){
                    node->GetLeft() = node->GetRight()->GetLeft();
                    node->GetRight()->GetLeft() = nullptr;
                }
            }
        }
        void Left(AVLTreeNode<T>& node){
            T temp = node.GetData();
            node->GetData() = node->GetRight()->GetData();
            node->GetRight()->SetData(temp);
            if(node->GetRight()->GetData() < node->GetData()){
                node->GetLeft() = node->GetRight();
                if(node->GetRight()->GetData() < node->GetData()){
                    node->GetLeft() = node->GetRight();
                    if(node->GetRight()->GetRight() != nullptr){
                        node->GetRight() = node->GetRight()->GetRight();
                        node->GetLeft()->GetRight() = nullptr;
                    }
                }
            }
        }
};
template <typename T>
struct DoubleLinkedList{
    private:
    int count = 0;
    LinkedListNode<T>* head = nullptr;
    LinkedListNode<T>* foot = nullptr;
    void SetCount(int temp){count = temp;}
    /**
     * @brief finds a spesific node and returns it
     * 
     * @param index 
     * @return Node<T> 
     */
    LinkedListNode<T>* FindNode(int index){
        if(index < 0 || index >= count) throw std::out_of_range("Invalid Index");
        if(head == nullptr || foot == nullptr) throw std::out_of_range("Invalid Operation, head/foot is null");
        int currentIndex;
        LinkedListNode<T>* currentNode;
        if(index > (count - 1) / 2){
            if(count == 0) currentIndex = 0;
            else currentIndex = count - 1;
            currentNode = foot;
        }else{ 
            currentIndex = 0;
            currentNode = head;
        }
        if(currentIndex == 0){
            while(currentIndex != index){
                currentNode = currentNode->GetNext();
                currentIndex++;
            }
        }else{
            while(currentIndex != index){
                currentNode = currentNode->GetPast();
                currentIndex--;
            }
        }
        return currentNode;
    }
    public:
    int Size(){return count;}
    /**
     * @brief adds a node to the linked list
     * 
     * @param data 
     * @param priorNode 
     */
    void Add(T data){
        if(head == nullptr){
            head = new LinkedListNode<T>;
            head->SetData(data);
            foot = head;
        }else{
            LinkedListNode<T>* nextNode = new LinkedListNode<T>(data);
            LinkedListNode<T>* currentNode = foot;
            currentNode->SetNext(nextNode);
            nextNode->SetPast(foot);
            foot = nextNode;
        }
        SetCount(Size() + 1);
    }
    /**
     * @brief returns the given index of a node
     * 
     * @param index 
     * @return T 
     */
    T Get(int index){return FindNode(index)->GetData();}
    /**
     * @brief find and deletes the first item in the linked list then returns its value
     * 
     * @return T 
     */
    T Remove(){
        LinkedListNode<T>* firstNode = head;
        head = head->GetNext();
        T firstNodeValue = firstNode->GetData();
        delete firstNode;
        count--;
        return firstNodeValue;
    }
    /**
     * @brief Removes the Last element in the linked list and returns its value
     * 
     * @return T 
     */
    T RemoveLast(){
        LinkedListNode<T>* lastNode = FindNode(count - 1);
        T lastNodeValue = lastNode->GetData();
        if(Size() > 2) FindNode(count - 2)->SetNext(nullptr);
        else if(Size() == 2) head->SetNext(nullptr);
        delete lastNode;
        count--;
        return lastNodeValue;
    }
    /**
     * @brief removes the indexed element and returns its value
     * 
     * @param index 
     * @return T 
     */
    T RemoveAt(int index){
        LinkedListNode<T>* indexedNode = FindNode(index);
        if(indexedNode == head) head->GetNext();
        T indexedNodeValue = indexedNode->GetData();
        if(Size() > 2) FindNode(index - 1)->SetNext(FindNode(index + 1));
        else if(Size() == 2) head->SetNext(nullptr);
        delete indexedNode;
        count--;
        return indexedNodeValue;
    }
    /**
     * @brief creates a node at a given index
     * 
     * @param index 
     * @param data 
     */
    void InsertAt(int index, T data){
        LinkedListNode<T>* inserted;
        if(index == 0){
            inserted = new LinkedListNode<T>(data, head);
            if(head == foot) foot = inserted;
            head = inserted;
        }else if(index == count - 1){
            inserted = new LinkedListNode<T>(data, nullptr, foot);
            if(head == foot) head == inserted;
            foot = inserted;
        }else{
            inserted = new LinkedListNode<T>(data, FindNode(index + 1));
            FindNode(index - 1)->SetNext(inserted);
        }
        count++;
    }
    /**
     * @brief deletes all the elementss
     * 
     */
    void Clear(){
        LinkedListNode<T>* currentNode = head;
        while(currentNode != nullptr) {
            LinkedListNode<T>* nextNode = currentNode->GetNext();
            delete currentNode;
            currentNode = nextNode;
        }
        head = nullptr;
        foot = nullptr;
        count = 0;
    }
    /**
     * @brief returns the index of the given value
     * 
     * @param value 
     * @return int 
     */
    int Search(T value){
        LinkedListNode<T>* currentNode = head;
        int index = 0;
        for(; currentNode != nullptr; currentNode = currentNode->GetNext()){ 
            if(currentNode->GetData() == value) return index;
            index++;
        }
        return -1;
    }
    /**
     * @brief converts the linked list to a string and returns it as a vector
     * 
     * @return std::vector<std::string> 
     */
    std::vector<std::string> ToString(){
        std::vector<std::string> strings;
        std::ostringstream oStringStream;
        for(int i = 0; i < count; i++){ 
            oStringStream.str("");
            oStringStream.clear();
            oStringStream<<Get(i);
            strings.push_back(oStringStream.str());
        }
        return strings;
    }
};
template <typename T>
struct SingleLinkedList{
    private:
    int count = 0;
    LinkedListNode<T>* head = nullptr;
    void SetCount(int temp){count = temp;}
    /**
     * @brief finds a spesific node and returns it
     * 
     * @param index 
     * @return Node<T> 
     */
    LinkedListNode<T>* FindNode(int index){
        if(index < 0 || index >= count) throw std::out_of_range("Invalid Index");
        if(head == nullptr) throw std::out_of_range("Invalid Operation, head is null");
        int currentIndex = 0;
        LinkedListNode<T>* currentNode = head;
        while(currentIndex != index){
            currentNode = currentNode->GetNext();
            currentIndex++;
        }
        return currentNode;
    }
    public:
    int Size(){return count;}
    /**
     * @brief adds a node to the linked list
     * 
     * @param data 
     * @param priorNode 
     */
    void Add(T data){
        if(head == nullptr){
            head = new LinkedListNode<T>;
            head->SetData(data);
        }else{
            LinkedListNode<T>* nextNode = new LinkedListNode<T>(data, nullptr);
            LinkedListNode<T>* currentNode = head;
            while(currentNode->GetNext() != nullptr) currentNode = currentNode->GetNext();
            currentNode->SetNext(nextNode);
        }
        SetCount(Size() + 1);
    }
    /**
     * @brief returns the given index of a node
     * 
     * @param index 
     * @return T 
     */
    T Get(int index){return FindNode(index)->GetData();}
    /**
     * @brief find and deletes the first item in the linked list then returns its value
     * 
     * @return T 
     */
    T Remove(){
        LinkedListNode<T>* firstNode = head;
        head = head->GetNext();
        T firstNodeValue = firstNode->GetData();
        delete firstNode;
        count--;
        return firstNodeValue;
    }
    /**
     * @brief Removes the Last element in the linked list and returns its value
     * 
     * @return T 
     */
    T RemoveLast(){
        LinkedListNode<T>* lastNode = FindNode(count - 1);
        T lastNodeValue = lastNode->GetData();
        if(Size() > 2) FindNode(count - 2)->SetNext(nullptr);
        else if(Size() == 2) head->SetNext(nullptr);
        delete lastNode;
        count--;
        return lastNodeValue;
    }
    /**
     * @brief removes the indexed element and returns its value
     * 
     * @param index 
     * @return T 
     */
    T RemoveAt(int index){
        LinkedListNode<T>* indexedNode = FindNode(index);
        if(indexedNode == head) head->GetNext();
        T indexedNodeValue = indexedNode->GetData();
        if(Size() > 2) FindNode(index - 1)->SetNext(FindNode(index + 1));
        else if(Size() == 2) head->SetNext(nullptr);
        delete indexedNode;
        count--;
        return indexedNodeValue;
    }
    /**
     * @brief creates a node at a given index
     * 
     * @param index 
     * @param data 
     */
    void InsertAt(int index, T data){
        if(index == 0){
            LinkedListNode<T>* inserted = new LinkedListNode<T>(data, head);
            head = inserted;
        }else{
            LinkedListNode<T>* inserted = new LinkedListNode<T>(data, FindNode(index + 1));
            FindNode(index - 1)->SetNext(inserted);
        }
        count++;
    }
    /**
     * @brief deletes all the elementss
     * 
     */
    void Clear(){
        LinkedListNode<T>* currentNode = head;
        while(currentNode != nullptr) {
            LinkedListNode<T>* nextNode = currentNode->GetNext();
            delete currentNode;
            currentNode = nextNode;
        }
        head = nullptr;
        count = 0;
    }
    /**
     * @brief returns the index of the given value
     * 
     * @param value 
     * @return int 
     */
    int Search(T value){
        LinkedListNode<T>* currentNode = head;
        int index = 0;
        for(; currentNode != nullptr; currentNode = currentNode->GetNext()){ 
            if(currentNode->GetData() == value) return index;
            index++;
        }
        return -1;
    }
    /**
     * @brief converts the linked list to a string and returns it as a vector
     * 
     * @return std::vector<std::string> 
     */
    std::vector<std::string> ToString(){
        std::vector<std::string> strings;
        std::ostringstream oStringStream;
        for(int i = 0; i < count; i++){ 
            oStringStream.str("");
            oStringStream.clear();
            oStringStream<<Get(i);
            strings.push_back(oStringStream.str());
        }
        return strings;
    }
};
//the linked list works really well for the queue because of the head, because of it it doesnt have to do alot of copying to add new elements
template<typename T>
struct Queue{
    SingleLinkedList<T> queue;
    public:
    /**
     * @brief removes an item from the list
     * 
     * @return T 
     */
    T Dequeue(){return queue.Remove();}
    /**
     * @brief looks at the first item
     * 
     * @return T 
     */
    T Peak(){return queue.Get(0);}
    /**
     * @brief adds an item to the list
     * 
     * @param data 
     */
    void Enqueue(T data){queue.Add(data);}
    /**
     * @brief grabs the value at an index in the list
     * 
     * @param index 
     * @return T 
     */
    T Get(int index){return queue.Get(index);}
    /**
     * @brief checks if the value is inside the list
     * 
     * @param value 
     * @return true 
     * @return false 
     */
    bool Contains(int value){
        int index = queue.Search(value);
        if(index < 0) return false;
        else return true;
    }
    /**
     * @brief returns the size of the list
     * 
     * @return int 
     */
    int Size(){return queue.Size();}
};
template<typename T>
//a linked list works really well for a stack because of the foot, because of that its able to quickly grab and motifi whats being used
struct Stack{
    DoubleLinkedList<T> list;
    public:
    /**
     * @brief removes an item from the list
     * 
     * @return T 
     */
    T Pop(){return list.RemoveLast();}
    /**
     * @brief looks at the first item in the list
     * 
     * @return T 
     */
    T Peak(){return list.Get(list.Size() - 1);}
    /**
     * @brief adds an item to the list
     * 
     * @param data 
     */
    void Push(T data){list.Add(data);}
    /**
     * @brief grabs the value at an index
     * 
     * @param index 
     * @return T 
     */
    T Get(int index){return list.Get(index);}
    /**
     * @brief checks if the list contains an item
     * 
     * @param value 
     * @return true 
     * @return false 
     */
    bool Contains(int value){
        int index = list.Search(value);
        if(index < 0) return false;
        else return true;
    }
    /**
     * @brief returns the size of the list
     * 
     * @return int 
     */
    int Size(){return list.Size();}
};
template<typename T>
struct BinarySearchTree{
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
template<typename T>
struct AVLTree{
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