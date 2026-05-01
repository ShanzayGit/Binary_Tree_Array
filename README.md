##Overview
# Binary_Tree_Array

This project implements a **binary tree using an array-based representation in C++**, supported by a custom **queue class** (also implemented from scratch).  
It demonstrates fundamental concepts of **data structures, memory management, and traversal algorithms** without relying on the STL.


## 📂 Folder Structure


Binary_Tree_Array/
- BinaryTree.h       # Header file for binary tree implementation
- Queue.h            # Header file for custom queue implementation
- main.cpp           # Example usage 
- Binary_Tree_Array.sln # Visual Studio solution file
- .gitignore
- .gitattributes


## ⚙️ Build & Run Instructions

### 🔹 On Windows (Visual Studio)
1. Open `Binary_Tree_Array.sln` in Visual Studio.
2. Add `BinaryTree.h` and `Queue.h` to your project.
3. Create a `main.cpp` file with sample usage.
4. Build and run with **Ctrl+F5**.

### 🔹 On Linux/Mac (g++)
Since the implementation is header-only, you just need a driver file:

g++ main.cpp -o binary_tree_app
./binary_tree_app

## 🧩 Example Usage


 BinaryTree<int> tree;
 tree.insert(10);
 tree.insert(20);
 tree.insert(30);
 cout << "Level-order traversal: ";
 tree.levelOrder();
   

**Expected Output:**
Level-order traversal: 10 20 30


## 🚀 Features Implemented
- **Binary Tree (Array-based)**
  - Insert nodes
  - Level-order traversal
  - DFS traversal
  - Basic tree operations
- **Custom Queue**
  - Enqueue / Dequeue
  - Empty/full checks
  - Scratch implementation without STL


## 📌 Future Improvements
- Implement node deletion.
- Add error handling for invalid operations.
- Compare performance with pointer-based binary tree implementations.

## 👤 Author
Developed by **Shanzay Malik**  
