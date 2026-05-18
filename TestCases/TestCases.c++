#include "../External/catch_amalgamated.hpp"
#include "../LinkedList/SingleLinkedList.h"
#include "../LinkedList/DoubleLinkedList.h"
#include "../Stack/Stack.h"
#include "../Queue/Queue.h"
#include "../BinarySearchTree/BinarySearchTree.h"
#include <bits/stdc++.h>
#include <vector>

/*

    Linked List Tests

*/

//add
TEST_CASE("Single Linked List can Add"){
    SingleLinkedList<int> singleLinkedList;
    singleLinkedList.Add(1);
    REQUIRE(singleLinkedList.Get(0) == 1);
}
TEST_CASE("Single Linked List can Add multiple values"){
    SingleLinkedList<int> singleLinkedList;
    singleLinkedList.Add(1);
    singleLinkedList.Add(2);
    singleLinkedList.Add(3);
    REQUIRE(singleLinkedList.Get(2) == 3);
}
//get
TEST_CASE("Single Linkled List can get when theirs 1 item"){
    SingleLinkedList<int> singleLinkedList;
    singleLinkedList.Add(1);
    REQUIRE(singleLinkedList.Get(0) == 1);
}
TEST_CASE("Single Linked List can get when theirs multiple items"){
    SingleLinkedList<int> singleLinkedList;
    singleLinkedList.Add(1);
    singleLinkedList.Add(2);
    singleLinkedList.Add(3);
    REQUIRE(singleLinkedList.Get(2) == 3);
}
//size
TEST_CASE("Single Linked List can send back the correct size for 1 item"){
    SingleLinkedList<int> singleLinkedList;
    singleLinkedList.Add(1);
    REQUIRE(singleLinkedList.Size() == 1);
}
TEST_CASE("Single Linked List can send back the correct size for multiple items"){
    SingleLinkedList<int> singleLinkedList;
    singleLinkedList.Add(1);
    singleLinkedList.Add(1);
    singleLinkedList.Add(1);
    singleLinkedList.Add(1);
    REQUIRE(singleLinkedList.Size() == 4);
}
//remove
TEST_CASE("Single Linked List can remove the first element when theirs 1 item"){
    SingleLinkedList<int> singleLinkedList;
    singleLinkedList.Add(1);
    singleLinkedList.Remove();
    REQUIRE(singleLinkedList.Size() == 0);
}
TEST_CASE("Single Linked List can remove the first element when theirs multiple items"){
    SingleLinkedList<int> singleLinkedList;
    singleLinkedList.Add(1);
    singleLinkedList.Add(2);
    singleLinkedList.Remove();
    REQUIRE(singleLinkedList.Get(0) == 2);
}
//remove last
TEST_CASE("Single Linked List can remove the last element when theirs 1 item"){
    SingleLinkedList<int> singleLinkedList;
    singleLinkedList.Add(1);
    singleLinkedList.RemoveLast();
    REQUIRE(singleLinkedList.Size() == 0);
}
TEST_CASE("Single Linked List can remove the last element when theirs multiple items"){
    SingleLinkedList<int> singleLinkedList;
    singleLinkedList.Add(1);
    singleLinkedList.Add(2);
    singleLinkedList.RemoveLast();
    REQUIRE(singleLinkedList.Get(0) == 1);
}
//remove at
TEST_CASE("Single Linked List can remove the indexed element when theirs 1 item"){
    SingleLinkedList<int> singleLinkedList;
    singleLinkedList.Add(1);
    singleLinkedList.RemoveAt(0);
    REQUIRE(singleLinkedList.Size() == 0);
}
TEST_CASE("Single Linked List can remove the indexed element when theirs multiple items"){
    SingleLinkedList<int> singleLinkedList;
    singleLinkedList.Add(1);
    singleLinkedList.Add(2);
    singleLinkedList.Add(3);
    singleLinkedList.RemoveAt(1);
    REQUIRE(singleLinkedList.Get(1) == 3);
}
//insert
TEST_CASE("Single Linked List can insert"){
    SingleLinkedList<int> singleLinkedList;
    singleLinkedList.Add(1);
    singleLinkedList.Add(2);
    singleLinkedList.Add(4);
    singleLinkedList.Add(5);
    singleLinkedList.InsertAt(2,3);
    REQUIRE(singleLinkedList.Get(2) == 3);
}
TEST_CASE("Single Linked List can insert into an empty list"){
    SingleLinkedList<int> singleLinkedList;
    singleLinkedList.InsertAt(0,1);
    REQUIRE(singleLinkedList.Get(0) == 1);
}
//search
TEST_CASE("Single Linked List can search the last position"){
    SingleLinkedList<int> singleLinkedList;
    singleLinkedList.Add(1);
    singleLinkedList.Add(2);
    singleLinkedList.Add(3);
    singleLinkedList.Add(4);
    REQUIRE(singleLinkedList.Search(4) == 3);
}
TEST_CASE("Single Linked List can search the first position"){
    SingleLinkedList<int> singleLinkedList;
    singleLinkedList.Add(1);
    singleLinkedList.Add(2);
    singleLinkedList.Add(3);
    singleLinkedList.Add(4);
    REQUIRE(singleLinkedList.Search(1) == 0);
}
TEST_CASE("Single Linked List can search for a string"){
    SingleLinkedList<std::string> singleLinkedList;
    singleLinkedList.Add("1");
    singleLinkedList.Add("2");
    singleLinkedList.Add("3");
    singleLinkedList.Add("4");
    REQUIRE(singleLinkedList.Search("1") == 0);
}
//clear
TEST_CASE("Single Linked List can clear"){
    SingleLinkedList<int> singleLinkedList;
    singleLinkedList.Add(1);
    singleLinkedList.Add(2);
    singleLinkedList.Add(3);
    singleLinkedList.Add(4);
    singleLinkedList.Clear();
    REQUIRE(singleLinkedList.Size() == 0);
}
TEST_CASE("Single Linked List can clear an empty list"){
    SingleLinkedList<int> singleLinkedList;
    singleLinkedList.Clear();
    REQUIRE(singleLinkedList.Size() == 0);
}
//to string
TEST_CASE("Single Linked List can to string a int list"){
    SingleLinkedList<int> singleLinkedList;
    std::vector<std::string> given;
    std::vector<std::string> correct = {"1","2","3","4"};
    singleLinkedList.Add(1);
    singleLinkedList.Add(2);
    singleLinkedList.Add(3);
    singleLinkedList.Add(4);
    given = singleLinkedList.ToString();
    REQUIRE(given == correct);
}
TEST_CASE("Single Linked List can to string a float list"){
    SingleLinkedList<float> singleLinkedList;
    std::vector<std::string> given;
    std::vector<std::string> correct = {"1.1","2.2","3.3","4.4"};
    singleLinkedList.Add(1.1);
    singleLinkedList.Add(2.2);
    singleLinkedList.Add(3.3);
    singleLinkedList.Add(4.4);
    given = singleLinkedList.ToString();
    REQUIRE(given == correct);
}

/*

    Double Linked List

*/

//add
TEST_CASE("Double Linked List can Add"){
    DoubleLinkedList<int> doubleLinkedList;
    doubleLinkedList.Add(1);
    REQUIRE(doubleLinkedList.Get(0) == 1);
}
TEST_CASE("Double Linked List can Add multiple values"){
    DoubleLinkedList<int> doubleLinkedList;
    doubleLinkedList.Add(1);
    doubleLinkedList.Add(2);
    doubleLinkedList.Add(3);
    REQUIRE(doubleLinkedList.Get(2) == 3);
}
//get
TEST_CASE("Double Linkled List can get when theirs 1 item"){
    DoubleLinkedList<int> doubleLinkedList;
    doubleLinkedList.Add(1);
    REQUIRE(doubleLinkedList.Get(0) == 1);
}
TEST_CASE("Double Linked List can get when theirs multiple items"){
    DoubleLinkedList<int> doubleLinkedList;
    doubleLinkedList.Add(1);
    doubleLinkedList.Add(2);
    doubleLinkedList.Add(3);
    REQUIRE(doubleLinkedList.Get(2) == 3);
}
//size
TEST_CASE("Double Linked List can send back the correct size for 1 item"){
    DoubleLinkedList<int> doubleLinkedList;
    doubleLinkedList.Add(1);
    REQUIRE(doubleLinkedList.Size() == 1);
}
TEST_CASE("Double Linked List can send back the correct size for multiple items"){
    DoubleLinkedList<int> doubleLinkedList;
    doubleLinkedList.Add(1);
    doubleLinkedList.Add(1);
    doubleLinkedList.Add(1);
    doubleLinkedList.Add(1);
    REQUIRE(doubleLinkedList.Size() == 4);
}
//remove
TEST_CASE("Double Linked List can remove the first element when theirs 1 item"){
    DoubleLinkedList<int> doubleLinkedList;
    doubleLinkedList.Add(1);
    doubleLinkedList.Remove();
    REQUIRE(doubleLinkedList.Size() == 0);
}
TEST_CASE("Double Linked List can remove the first element when theirs multiple items"){
    DoubleLinkedList<int> doubleLinkedList;
    doubleLinkedList.Add(1);
    doubleLinkedList.Add(2);
    doubleLinkedList.Remove();
    REQUIRE(doubleLinkedList.Get(0) == 2);
}
//remove last
TEST_CASE("Double Linked List can remove the last element when theirs 1 item"){
    DoubleLinkedList<int> doubleLinkedList;
    doubleLinkedList.Add(1);
    doubleLinkedList.RemoveLast();
    REQUIRE(doubleLinkedList.Size() == 0);
}
TEST_CASE("Double Linked List can remove the last element when theirs multiple items"){
    DoubleLinkedList<int> doubleLinkedList;
    doubleLinkedList.Add(1);
    doubleLinkedList.Add(2);
    doubleLinkedList.RemoveLast();
    REQUIRE(doubleLinkedList.Get(0) == 1);
}
//remove at
TEST_CASE("Double Linked List can remove the indexed element when theirs 1 item"){
    DoubleLinkedList<int> doubleLinkedList;
    doubleLinkedList.Add(1);
    doubleLinkedList.RemoveAt(0);
    REQUIRE(doubleLinkedList.Size() == 0);
}
TEST_CASE("Double Linked List can remove the indexed element when theirs multiple items"){
    DoubleLinkedList<int> doubleLinkedList;
    doubleLinkedList.Add(1);
    doubleLinkedList.Add(2);
    doubleLinkedList.Add(3);
    doubleLinkedList.RemoveAt(1);
    REQUIRE(doubleLinkedList.Get(1) == 3);
}
//insert
TEST_CASE("Double Linked List can insert"){
    DoubleLinkedList<int> doubleLinkedList;
    doubleLinkedList.Add(1);
    doubleLinkedList.Add(2);
    doubleLinkedList.Add(4);
    doubleLinkedList.Add(5);
    doubleLinkedList.InsertAt(2,3);
    REQUIRE(doubleLinkedList.Get(2) == 3);
}
TEST_CASE("Double Linked List can insert into an empty list"){
    DoubleLinkedList<int> doubleLinkedList;
    doubleLinkedList.InsertAt(0,1);
    REQUIRE(doubleLinkedList.Get(0) == 1);
}
//search
TEST_CASE("Double Linked List can search the last position"){
    DoubleLinkedList<int> doubleLinkedList;
    doubleLinkedList.Add(1);
    doubleLinkedList.Add(2);
    doubleLinkedList.Add(3);
    doubleLinkedList.Add(4);
    REQUIRE(doubleLinkedList.Search(4) == 3);
}
TEST_CASE("Double Linked List can search the first position"){
    DoubleLinkedList<int> doubleLinkedList;
    doubleLinkedList.Add(1);
    doubleLinkedList.Add(2);
    doubleLinkedList.Add(3);
    doubleLinkedList.Add(4);
    REQUIRE(doubleLinkedList.Search(1) == 0);
}
TEST_CASE("Double Linked List can search for a string"){
    DoubleLinkedList<std::string> doubleLinkedList;
    doubleLinkedList.Add("1");
    doubleLinkedList.Add("2");
    doubleLinkedList.Add("3");
    doubleLinkedList.Add("4");
    REQUIRE(doubleLinkedList.Search("1") == 0);
}
//clear
TEST_CASE("Double Linked List can clear"){
    DoubleLinkedList<int> doubleLinkedList;
    doubleLinkedList.Add(1);
    doubleLinkedList.Add(2);
    doubleLinkedList.Add(3);
    doubleLinkedList.Add(4);
    doubleLinkedList.Clear();
    REQUIRE(doubleLinkedList.Size() == 0);
}
TEST_CASE("Double Linked List can clear an empty list"){
    DoubleLinkedList<int> doubleLinkedList;
    doubleLinkedList.Clear();
    REQUIRE(doubleLinkedList.Size() == 0);
}
//to string
TEST_CASE("Double Linked List can to string a int list"){
    DoubleLinkedList<int> doubleLinkedList;
    std::vector<std::string> given;
    std::vector<std::string> correct = {"1","2","3","4"};
    doubleLinkedList.Add(1);
    doubleLinkedList.Add(2);
    doubleLinkedList.Add(3);
    doubleLinkedList.Add(4);
    given = doubleLinkedList.ToString();
    REQUIRE(given == correct);
}
TEST_CASE("Double Linked List can to string a float list"){
    DoubleLinkedList<float> doubleLinkedList;
    std::vector<std::string> given;
    std::vector<std::string> correct = {"1.1","2.2","3.3","4.4"};
    doubleLinkedList.Add(1.1);
    doubleLinkedList.Add(2.2);
    doubleLinkedList.Add(3.3);
    doubleLinkedList.Add(4.4);
    given = doubleLinkedList.ToString();
    REQUIRE(given == correct);
}

/*

    Stack

*/

//push
TEST_CASE("Stack can push 1 item"){
    Stack<int> stack;
    stack.Push(1);
    REQUIRE(stack.Peak() == 1);
}
TEST_CASE("Stack can push multiple items"){
    Stack<int> stack;
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Push(4);
    stack.Push(5);
    REQUIRE(stack.Peak() == 5);
}
//peak
TEST_CASE("Stack can peak when theirs 1 item"){
    Stack<int> stack;
    stack.Push(1);
    REQUIRE(stack.Peak() == 1);
}
TEST_CASE("Stack can peak when theirs multiple items"){
    Stack<int> stack;
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Push(4);
    stack.Push(5);
    REQUIRE(stack.Peak() == 5);
}
//pop
TEST_CASE("Stack can pop 1 item"){
    Stack<int> stack;
    stack.Push(1);
    stack.Pop();
    REQUIRE(stack.Size() == 0);
}
TEST_CASE("Stack can pop when theirs multiple items"){
    Stack<int> stack;
    stack.Push(1);
    stack.Push(2);
    stack.Pop();
    REQUIRE(stack.Peak() == 1);
}
//get
TEST_CASE("Stack can get 1 item"){
    Stack<int> stack;
    stack.Push(1);
    REQUIRE(stack.Get(0) == 1);
}
TEST_CASE("Stack can get when theirs multiple items"){
    Stack<int> stack;
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Push(4);
    stack.Push(5);
    REQUIRE(stack.Get(3) == 4);
}
//contains
TEST_CASE("Stack can check when the list contains 1 item"){
    Stack<int> stack;
    stack.Push(1);
    REQUIRE(stack.Contains(1) == true);
}
TEST_CASE("Stack can check when the list contains multiple items"){
    Stack<int> stack;
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Push(4);
    stack.Push(5);
    REQUIRE(stack.Contains(3) == true);
}
//size
TEST_CASE("Stack can check the size when the list contains 1 item"){
    Stack<int> stack;
    stack.Push(1);
    REQUIRE(stack.Size() == 1);
}
TEST_CASE("Stack can check the size when the list contains multiple items"){
    Stack<int> stack;
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Push(4);
    stack.Push(5);
    REQUIRE(stack.Size() == 5);
}

/*

    Queue

*/

TEST_CASE("Queue can push 1 item"){
    Queue<int> queue;
    queue.Enqueue(1);
    REQUIRE(queue.Peak() == 1);
}
TEST_CASE("Queue can push multiple items"){
    Queue<int> queue;
    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);
    queue.Enqueue(4);
    queue.Enqueue(5);
    REQUIRE(queue.Peak() == 1);
}
//peak
TEST_CASE("Queue can peak when theirs 1 item"){
    Queue<int> queue;
    queue.Enqueue(1);
    REQUIRE(queue.Peak() == 1);
}
TEST_CASE("Queue can peak when theirs multiple items"){
    Queue<int> queue;
    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);
    queue.Enqueue(4);
    queue.Enqueue(5);
    REQUIRE(queue.Peak() == 1);
}
//pop
TEST_CASE("Queue can pop 1 item"){
    Queue<int> queue;
    queue.Enqueue(1);
    queue.Dequeue();
    REQUIRE(queue.Size() == 0);
}
TEST_CASE("Queue can pop when theirs multiple items"){
    Queue<int> queue;
    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);
    queue.Enqueue(4);
    queue.Enqueue(5);
    queue.Dequeue();
    REQUIRE(queue.Peak() == 2);
}
//get
TEST_CASE("Queue can get 1 item"){
    Queue<int> queue;
    queue.Enqueue(1);
    REQUIRE(queue.Get(0) == 1);
}
TEST_CASE("Queue can get when theirs multiple items"){
    Queue<int> queue;
    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);
    queue.Enqueue(4);
    queue.Enqueue(5);
    REQUIRE(queue.Get(3) == 4);
}
//contains
TEST_CASE("Queue can check when the list contains 1 item"){
    Queue<int> queue;
    queue.Enqueue(1);
    REQUIRE(queue.Contains(1) == true);
}
TEST_CASE("Queue can check when the list contains multiple items"){
    Queue<int> queue;
    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);
    queue.Enqueue(4);
    queue.Enqueue(5);
    REQUIRE(queue.Contains(3) == true);
}
//size
TEST_CASE("Queue can check the size when the list contains 1 item"){
    Queue<int> queue;
    queue.Enqueue(1);
    REQUIRE(queue.Size() == 1);
}
TEST_CASE("Queue can check the size when the list contains multiple items"){
    Queue<int> queue;
    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);
    queue.Enqueue(4);
    queue.Enqueue(5);
    REQUIRE(queue.Size() == 5);
}

/*

    Binary Search Tree

*/

//add
TEST_CASE("Binary Search Tree can Add 1 value"){
    BinarySearchTree<int> tree;
    tree.Add(50);
    REQUIRE(tree.InOrder() == "50");
}
TEST_CASE("Binary Search Tree can Add multiple values"){
    BinarySearchTree<int> tree;
    tree.Add(50);
    tree.Add(25);
    tree.Add(60);
    tree.Add(26);
    REQUIRE(tree.InOrder() == "25, 26, 50, 60");
}

//count
TEST_CASE("Binary Search Tree size works with 1 value"){
    BinarySearchTree<int> tree;
    tree.Add(50);
    REQUIRE(tree.Size() == 1);
}
TEST_CASE("Binary Search Tree size works with multiple values"){
    BinarySearchTree<int> tree;
    tree.Add(50);
    tree.Add(25);
    tree.Add(60);
    tree.Add(26);
    REQUIRE(tree.Size() == 4);
}

//clear
TEST_CASE("Binary Search Tree clear works with 1 value"){
    BinarySearchTree<int> tree;
    tree.Add(50);
    tree.Clear();
    REQUIRE(tree.InOrder() == "");
}
TEST_CASE("Binary Search Tree clear works with multiple values"){
    BinarySearchTree<int> tree;
    tree.Add(50);
    tree.Add(25);
    tree.Add(60);
    tree.Add(26);
    tree.Clear();
    REQUIRE(tree.InOrder() == "");
}