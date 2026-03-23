#include "avl.hpp"

// Constructor
AVLTree::AVLTree() : root(nullptr), nodeCount(0) {}

// Destructor
AVLTree::~AVLTree() {
    deleteTree(root);
}

// Eliminar todos los nodos del árbol
void AVLTree::deleteTree(AVLNode* node) {
    if (node == nullptr) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

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

// Rotación simple a la derecha
AVLNode* AVLTree::rotateRight(AVLNode* node) {
    AVLNode* leftChild = node->left;
    AVLNode* leftRightChild = leftChild->right;

    // Realizar rotación
    leftChild->right = node;
    node->left = leftRightChild;

    // Actualizar alturas
    updateHeight(node);
    updateHeight(leftChild);

    return leftChild;
}

// Rotación doble: izquierda-derecha
AVLNode* AVLTree::rotateLeftRight(AVLNode* node) {
    node->left = rotateLeft(node->left);
    return rotateRight(node);
}

// Rotación doble: derecha-izquierda
AVLNode* AVLTree::rotateRightLeft(AVLNode* node) {
    node->right = rotateRight(node->right);
    return rotateLeft(node);
}

// Insertar un elemento en el árbol
void AVLTree::insert(const string& key) {
    root = insertHelper(root, key);
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
        // Permitir duplicados (como multiset)
        node->right = insertHelper(node->right, key);
    }

    // Actualizar altura del nodo actual
    updateHeight(node);

    // Obtener balance factor
    int balance = getBalanceFactor(node);

    // Caso desbalanceado izquierda-izquierda
    if (balance > 1 && getBalanceFactor(node->left) >= 0) {
        return rotateRight(node);
    }

    // Caso desbalanceado derecha-derecha
    if (balance < -1 && getBalanceFactor(node->right) <= 0) {
        return rotateLeft(node);
    }

    // Caso desbalanceado izquierda-derecha
    if (balance > 1 && getBalanceFactor(node->left) < 0) {
        return rotateLeftRight(node);
    }

    // Caso desbalanceado derecha-izquierda
    if (balance < -1 && getBalanceFactor(node->right) > 0) {
        return rotateRightLeft(node);
    }

    return node;
}

// Recorrido inorden (izquierda, raíz, derecha)
vector<string> AVLTree::inorder() const {
    vector<string> result;
    inorderHelper(root, result);
    return result;
}

// Función auxiliar para recorrido inorden
void AVLTree::inorderHelper(AVLNode* node, vector<string>& result) const {
    if (node == nullptr) return;
    inorderHelper(node->left, result);
    result.push_back(node->key);
    inorderHelper(node->right, result);
}

// Obtener el tamaño del árbol
size_t AVLTree::size() const {
    return nodeCount;
}

