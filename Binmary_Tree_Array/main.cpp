#include "BinaryTree.h"
#include "Queue.h"
#include <iostream>
using namespace std;

int main() {
    BinaryTree<int> tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);

    cout << "Level-order traversal: "; // 10 20 30
    tree.levelOrder();

    return 0;
}
