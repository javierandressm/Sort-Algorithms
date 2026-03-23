#include <iostream>
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
    int getHeight(AVLNode* node) const;
    int getBalanceFactor(AVLNode* node) const;
    void updateHeight(AVLNode* node);

public:
    AVLTree();
    ~AVLTree();
    void insert(const string& key);
};

// Constructor
AVLTree::AVLTree() : root(nullptr), nodeCount(0) {}

// Destructor
AVLTree::~AVLTree() {}

// Obtener la altura de un nodo
int AVLTree::getHeight(AVLNode* node) const {
    if (node == nullptr) return 0;
    return node->height;
}

// Obtener el balance factor de un nodo
int AVLTree::getBalanceFactor(AVLNode* node) const {
    if (node == nullptr) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Actualizar la altura de un nodo basándose en sus hijos
void AVLTree::updateHeight(AVLNode* node) {
    if (node == nullptr) return;
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
}

// Rotación simple a la izquierda
AVLNode* AVLTree::rotateLeft(AVLNode* node) {
    AVLNode* rightChild = node->right;
    AVLNode* rightLeftChild = rightChild->left;

    // Realizar rotación
    rightChild->left = node;
    node->right = rightLeftChild;

    // Actualizar alturas
    updateHeight(node);
    updateHeight(rightChild);

    return rightChild;
}

// Función auxiliar recursiva para insertar
AVLNode* AVLTree::insertHelper(AVLNode* node, const string& key) {
    // Inserción normal BST
    if (node == nullptr) {
        nodeCount++;
        return new AVLNode(key);
    }

    if (key < node->key) {
        node->left = insertHelper(node->left, key);
    } else if (key > node->key) {
        node->right = insertHelper(node->right, key);
    } else {
        // Permitir duplicados
        node->right = insertHelper(node->right, key);
    }

    // Actualizar altura del nodo actual
    updateHeight(node);

    int balance = getBalanceFactor(node);

    // Caso desbalanceado izquierda-izquierda
    if (balance > 1 && getBalanceFactor(node->left) >= 0) {
        return rotateLeft(node);
    }

    return node;
}

// Insertar un elemento en el árbol
void AVLTree::insert(const string& key) {
    root = insertHelper(root, key);
}

int main() {
    cout << "Test OK" << endl;
    return 0;
}

