#ifndef AVL_HPP
#define AVL_HPP

#include <string>
#include <vector>
#include <set>

using namespace std;

class AVLTree {
private:
    multiset<string> tree;

public:
    AVLTree();
    ~AVLTree();
    void insert(const string& key);
    vector<string> inorder();
    size_t size() const;
};

#endif

