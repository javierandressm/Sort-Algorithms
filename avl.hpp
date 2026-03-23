#ifndef AVL_HPP
#define AVL_HPP

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Estructura de nodo para el árbol AVL
struct AVLNode {
    string key;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(const string& k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    AVLNode* root;
    int nodeCount;

    // Funciones auxiliares privadas
    AVLNode* insertHelper(AVLNode* node, const string& key);
    AVLNode* rotateLeft(AVLNode* node);
    AVLNode* rotateRight(AVLNode* node);
    AVLNode* rotateLeftRight(AVLNode* node);
    AVLNode* rotateRightLeft(AVLNode* node);
    int getHeight(AVLNode* node) const;
    int getBalanceFactor(AVLNode* node) const;
    void updateHeight(AVLNode* node);
    void inorderHelper(AVLNode* node, vector<string>& result) const;
    void deleteTree(AVLNode* node);

public:
    AVLTree();
    ~AVLTree();
    void insert(const string& key);
    vector<string> inorder() const;
    size_t size() const;
};

#endif

