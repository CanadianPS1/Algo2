#include "../External/catch_amalgamated.hpp"
#include "../LinkedList/SingleLinkedList.h"
#include <bits/stdc++.h>
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