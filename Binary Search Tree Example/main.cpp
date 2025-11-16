/*
    main.cpp
    Example implementation of a simple Binary Search Tree (BST) in C++.

    This file defines a Node class and a BinarySearchTree class with basic insertion logic.
    The main function demonstrates creating a BST, inserting nodes, displaying values, and cleaning up memory.
    I wrote the code in about 15 minutes without help, so it should be fairly straightforward.
*/

#include <iostream>

using namespace std;


class Node {
public:
    int value = 0;
    Node* left = nullptr;
    Node* right = nullptr;
};


class BinarySearchTree {
public:
    Node* root = nullptr;

    BinarySearchTree(int rootVal) {
        root = new Node();
        root->value = rootVal;
    }

    void insertNode(int value, Node* current) {
        if (current->left == nullptr && value < current->value) {
            Node* newNode = new Node();

            newNode->value = value;
            current->left = newNode;
            return;
        } else if (current->right == nullptr && value > current->value) {
            Node* newNode = new Node();

            newNode->value = value;
            current->right = newNode;
            return;
        }


        if (value < current->value) {
            insertNode(value, current->left);
        }    
        else if (value > current->value) {
            insertNode(value, current->right);
        }
    }
};


int main()
{
    // create tree
    BinarySearchTree* tree = new BinarySearchTree(1);

    tree->insertNode(2, tree->root);
    tree->insertNode(3, tree->root);
    // display tree
    cout << tree->root->value;
    cout << tree->root->right->value;
    cout << tree->root->right->right->value;
    // delete tree
    delete tree->root->right->right;
    delete tree->root->right;
    delete tree->root;
    delete tree;

    return 0;
}

