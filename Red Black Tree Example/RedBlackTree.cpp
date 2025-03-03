#include "RedBlackTree.h"

RedBlackTree::RedBlackTree() : NIL(new Node(0))
{
    NIL->color = BLACK;
    NIL->left = nullptr;
    NIL->right = nullptr;
    root = NIL;
}

RedBlackTree::~RedBlackTree()
{
    destroyTree(root);
    delete NIL;
}

void RedBlackTree::destroyTree(Node *node)
{
    if (node != NIL)
    {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

void RedBlackTree::leftRotate(Node *x)
{
    Node *y = x->right;
    x->right = y->left;

    if (y->left != NIL)
    {
        y->left->parent = x;
    }

    y->parent = x->parent;

    if (x->parent == nullptr)
    {
        root = y;
    }
    else if (x == x->parent->left)
    {
        x->parent->left = y;
    }
    else
    {
        x->parent->right = y;
    }

    y->left = x;
    x->parent = y;
}

void RedBlackTree::rightRotate(Node *x)
{
    Node *y = x->left;
    x->left = y->right;

    if (y->right != NIL)
    {
        y->right->parent = x;
    }

    y->parent = x->parent;

    if (x->parent == nullptr)
    {
        root = y;
    }
    else if (x == x->parent->right)
    {
        x->parent->right = y;
    }
    else
    {
        x->parent->left = y;
    }

    y->right = x;
    x->parent = y;
}

void RedBlackTree::insert(int key)
{
    Node *newNode = new Node(key);
    newNode->left = NIL;
    newNode->right = NIL;

    Node *y = nullptr;
    Node *x = this->root;

    while (x != NIL)
    {
        y = x;
        if (newNode->data < x->data)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }
    }

    newNode->parent = y;

    if (y == nullptr)
    {
        root = newNode;
    }
    else if (newNode->data < y->data)
    {
        y->left = newNode;
    }
    else
    {
        y->right = newNode;
    }

    if (newNode->parent == nullptr)
    {
        newNode->color = BLACK;
        return;
    }

    if (newNode->parent->parent == nullptr)
    {
        return;
    }

    insertFixup(newNode);
}

void RedBlackTree::insertFixup(Node *cur)
{
    Node *unc;

    while (cur->parent != nullptr && cur->parent->color == RED)
    {
        // uncle is left child of grandparent
        if (cur->parent == cur->parent->parent->right)
        {
            unc = cur->parent->parent->left;

            if (unc->color == RED)
            {
                unc->color = BLACK;
                cur->parent->color = BLACK;
                cur->parent->parent->color = RED;
                cur = cur->parent->parent;
            }
            else
            {
                if (cur == cur->parent->left)
                {
                    cur = cur->parent;
                    rightRotate(cur);
                }

                cur->parent->color = BLACK;
                cur->parent->parent->color = RED;
                leftRotate(cur->parent->parent);
            }
        }
        else // uncle is right child of grandparent
        {
            unc = cur->parent->parent->right;

            if (unc->color == RED)
            {
                unc->color = BLACK;
                cur->parent->color = BLACK;
                cur->parent->parent->color = RED;
                cur = cur->parent->parent;
            }
            else
            {
                if (cur == cur->parent->right)
                {
                    cur = cur->parent;
                    leftRotate(cur);
                }

                cur->parent->color = BLACK;
                cur->parent->parent->color = RED;
                rightRotate(cur->parent->parent);
            }
        }

        if (cur == root)
        {
            break;
        }
    }
    root->color = BLACK;
}

bool RedBlackTree::search(int key) const
{
    return searchTreeHelper(this->root, key) != NIL;
}

RedBlackTree::Node *RedBlackTree::searchTreeHelper(Node *node, int key) const
{
    if (node == NIL || key == node->data)
    {
        return node;
    }

    if (key < node->data)
    {
        return searchTreeHelper(node->left, key);
    }
    return searchTreeHelper(node->right, key);
}

RedBlackTree::Node *RedBlackTree::minimum(Node *node)
{
    while (node->left != NIL)
    {
        node = node->left;
    }
    return node;
}

void RedBlackTree::inOrder() const
{
    inOrderHelper(this->root);
    std::cout << std::endl;
}

void RedBlackTree::inOrderHelper(Node *node) const
{
    if (node != NIL)
    {
        inOrderHelper(node->left);
        std::cout << node->data << " ";
        inOrderHelper(node->right);
    }
}

bool RedBlackTree::isEmpty() const
{
    return root == NIL;
}