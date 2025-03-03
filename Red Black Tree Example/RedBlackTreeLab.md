# Red-Black Tree Lab

## Introduction

This lab is for testing a Red-Black Tree, a type of self-balancing binary search tree. Red-Black Trees ensure that operations like insertion and search remain efficient (O(log n)) by maintaining balance during modifications.

## Red-Black Tree Properties

A Red-Black Tree satisfies the following properties:

1. Every node is either red or black.
2. The root is always black.
3. Every leaf (NIL) is black.
4. If a node is red, then both its children are black (no two adjacent red nodes).
5. For each node, all simple paths from the node to descendant leaves contain the same number of black nodes.

These properties ensure that the longest path from the root to any leaf is no more than twice as long as the shortest path, keeping the tree approximately balanced.

## Implementation Overview

The provided RedBlackTree class implements:

- Node structure with color property
- Insertion with rebalancing
- Search functionality
- In-order traversal
