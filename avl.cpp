#include "avl.hpp"

AVLTree::AVLTree() {}

AVLTree::~AVLTree() {}

void AVLTree::insert(const string& key) {
    tree.insert(key);
}

vector<string> AVLTree::inorder() {
    vector<string> result(tree.begin(), tree.end());
    return result;
}

size_t AVLTree::size() const {
    return tree.size();
}

