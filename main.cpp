#include <chrono>
#include <iostream>
#include "quicksort.hpp"
#include "heapsort.hpp"
#include "avl.hpp"
#include "utils.hpp"

using namespace std;

int main() {
    string filename = "dataset.txt";

    vector<string> dataset = readDataset(filename);

    if (dataset.empty()) {
        cerr << "Error: Dataset vacio o no encontrado.\n";
        return 1;
    }

    // QuickSort
    vector<string> quickData = dataset;
    auto startQ = chrono::high_resolution_clock::now();
    quickSort(quickData, 0, (int)quickData.size() - 1);
    auto endQ = chrono::high_resolution_clock::now();
    auto timeQ = chrono::duration_cast<chrono::milliseconds>(endQ - startQ).count();

    // HeapSort
    vector<string> heapData = dataset;
    auto startH = chrono::high_resolution_clock::now();
    heapSort(heapData);
    auto endH = chrono::high_resolution_clock::now();
    auto timeH = chrono::duration_cast<chrono::milliseconds>(endH - startH).count();

    // AVL
    AVLTree avl;
    auto startT = chrono::high_resolution_clock::now();
    for (const auto& w : dataset) {
        avl.insert(w);
    }
    vector<string> treeData = avl.inorder();
    auto endT = chrono::high_resolution_clock::now();
    auto timeT = chrono::duration_cast<chrono::milliseconds>(endT - startT).count();

    // Verificacion
    bool okQ = isSorted(quickData);
    bool okH = isSorted(heapData);
    bool okT = isSorted(treeData);

    // Memoria estimada
    size_t memQ = estimateVectorMemory(quickData);
    size_t memH = estimateVectorMemory(heapData);

    // Para AVL: estimacion basada en multiset (sizeof por nodo + strings)
    size_t bytesPerNode = sizeof(void*) * 3 + sizeof(int) + sizeof(string);
    size_t avlNodesMem = avl.size() * bytesPerNode;
    size_t memT = avlNodesMem;

    cout << "===== RESULTADOS =====\n\n";
    cout << "QuickSort\n";
    cout << "  Tiempo: " << timeQ << " ms\n";
    cout << "  Ordenado: " << (okQ ? "SI" : "NO") << "\n";
    cout << "  Memoria: " << memQ / (1024.0 * 1024.0) << " MB\n\n";

    cout << "HeapSort\n";
    cout << "  Tiempo: " << timeH << " ms\n";
    cout << "  Ordenado: " << (okH ? "SI" : "NO") << "\n";
    cout << "  Memoria: " << memH / (1024.0 * 1024.0) << " MB\n\n";

    cout << "AVL Tree\n";
    cout << "  Tiempo: " << timeT << " ms\n";
    cout << "  Ordenado: " << (okT ? "SI" : "NO") << "\n";
    cout << "  Memoria: " << memT / (1024.0 * 1024.0) << " MB\n\n";

    if (okQ && okH && okT) {
        cout << "✓ Todos los algoritmos ordenaron correctamente.\n";
    } else {
        cout << "✗ Error: Algunos algoritmos no ordenaron correctamente.\n";
    }

    return 0;
}