#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <iostream>

/**
 * A Red-Black Tree implementation.
 *
 * A Red-Black tree is a self-balancing binary search tree with the following properties:
 * 1. Each node is either red or black.
 * 2. The root is black.
 * 3. All leaves (NIL nodes) are black.
 * 4. If a node is red, then both its children are black.
 * 5. Every path from a node to any of its descendant NIL nodes contains the same number of black nodes.
 */
class RedBlackTree
{
private:
    enum Color
    {
        RED,
        BLACK
    };

    struct Node
    {
        int data;
        Color color;
        Node *left;
        Node *right;
        Node *parent;

        Node(int value) : data(value), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
    };

    Node *root;
    Node *const NIL;

    // Helper methods
    void leftRotate(Node *x);
    void rightRotate(Node *x);
    void insertFixup(Node *k);
    Node *minimum(Node *node);
    void inOrderHelper(Node *node) const;
    void destroyTree(Node *node);
    Node *searchTreeHelper(Node *node, int key) const;

public:
    RedBlackTree();
    ~RedBlackTree();

    /**
     * Insert a new key into the tree
     * @param key The key to insert
     */
    void insert(int key);

    /**
     * Search for a key in the tree
     * @param key The key to search for
     * @return true if key exists, false otherwise
     */
    bool search(int key) const;

    /**
     * Print the tree in-order
     */
    void inOrder() const;

    /**
     * Check if the tree is empty
     * @return true if the tree is empty, false otherwise
     */
    bool isEmpty() const;
};

#endif // RED_BLACK_TREE_H