#include <iostream>
#include <cassert>
#include "RedBlackTree.h"

void testInsert()
{
    RedBlackTree rbt;

    rbt.insert(10);
    rbt.insert(20);
    rbt.insert(30);

    assert(rbt.search(10) == true);
    assert(rbt.search(20) == true);
    assert(rbt.search(30) == true);
    assert(rbt.search(40) == false);

    std::cout << "Insert test passed!" << std::endl;
}

void testEmptyTree()
{
    RedBlackTree rbt;

    assert(rbt.isEmpty() == true);
    assert(rbt.search(10) == false);

    rbt.insert(10);
    
    assert(rbt.isEmpty() == false);

    std::cout << "Empty tree test passed!" << std::endl;
}

int main()
{
    std::cout << "Running Red-Black Tree tests..." << std::endl;

    testInsert();
    testEmptyTree();

    std::cout << "All tests passed!" << std::endl;

    // Example usage
    RedBlackTree tree;

    std::cout << "\nInserting elements: 7, 3, 18, 10, 22, 8, 11, 26" << std::endl;
    tree.insert(7);
    tree.insert(3);
    tree.insert(18);
    tree.insert(10);
    tree.insert(22);
    tree.insert(8);
    tree.insert(11);
    tree.insert(26);

    std::cout << "In-order traversal: ";
    tree.inOrder(); // Should print: 3 7 8 10 11 18 22 26

    return 0;
}