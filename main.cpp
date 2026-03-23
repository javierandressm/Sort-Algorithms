#include <chrono>
#include <iostream>
#include "quicksort.hpp"
#include "heapsort.hpp"
#include "avl.hpp"
#include "utils.hpp"

using namespace std;

int main() {
    string filename = "dataset.txt";

    cout << "Leyendo dataset...\n";
    vector<string> dataset = readDataset(filename);

    if (dataset.empty()) {
        cerr << "Error: Dataset vacio o no encontrado.\n";
        return 1;
    }

    cout << "OK - Palabras leidas: " << dataset.size() << "\n\n";

    // QuickSort
    cout << "Ejecutando QuickSort...\n";
    vector<string> quickData = dataset;
    auto startQ = chrono::high_resolution_clock::now();
    quickSort(quickData, 0, (int)quickData.size() - 1);
    auto endQ = chrono::high_resolution_clock::now();
    auto timeQ = chrono::duration_cast<chrono::milliseconds>(endQ - startQ).count();
    cout << "OK\n";

    // HeapSort
    cout << "Ejecutando HeapSort...\n";
    vector<string> heapData = dataset;
    auto startH = chrono::high_resolution_clock::now();
    heapSort(heapData);
    auto endH = chrono::high_resolution_clock::now();
    auto timeH = chrono::duration_cast<chrono::milliseconds>(endH - startH).count();
    cout << "OK\n";

    // AVL
    cout << "Ejecutando AVL Tree...\n";
    AVLTree avl;
    auto startT = chrono::high_resolution_clock::now();
    int insertCount = 0;
    for (const auto& w : dataset) {
        avl.insert(w);
        insertCount++;
        if (insertCount % 50000 == 0) {
            cout << "  Insertados: " << insertCount << " / " << dataset.size() << "\n";
        }
    }
    cout << "  Realizando inorder traversal...\n";
    vector<string> treeData = avl.inorder();
    auto endT = chrono::high_resolution_clock::now();
    auto timeT = chrono::duration_cast<chrono::milliseconds>(endT - startT).count();
    cout << "OK\n\n";

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

    // ===== ANALISIS COMPARATIVO =====
    cout << "\n===== ANALISIS COMPARATIVO =====\n\n";

    // Complejidad algorítmica
    cout << "Complejidad Algorítmica (Big O):\n";
    cout << "  Algoritmo   | Mejor Caso  | Caso Promedio | Peor Caso   | Espacio\n";
    cout << "  ------------|-------------|---------------|-------------|----------\n";
    cout << "  QuickSort   | O(n log n)  | O(n log n)    | O(n²)       | O(log n)\n";
    cout << "  HeapSort    | O(n log n)  | O(n log n)    | O(n log n)  | O(1)\n";
    cout << "  AVL Tree    | O(n log n)  | O(n log n)    | O(n log n)  | O(n)\n\n";

    // Determinar ganador en tiempo y memoria usando pares (nombre, valor)
    struct AlgoStats {
        const char* name;
        long long timeMs;
        size_t memBytes;
    };
    AlgoStats stats[3] = {
        {"QuickSort", timeQ, memQ},
        {"HeapSort",  timeH, memH},
        {"AVL Tree",  timeT, memT}
    };

    int fastestIdx = 0;
    int lowMemIdx  = 0;
    for (int i = 1; i < 3; i++) {
        if (stats[i].timeMs  < stats[fastestIdx].timeMs)  fastestIdx = i;
        if (stats[i].memBytes < stats[lowMemIdx].memBytes) lowMemIdx  = i;
    }
    cout << "Ganador en tiempo de ejecución: " << stats[fastestIdx].name
         << " (" << stats[fastestIdx].timeMs << " ms)\n\n";
    cout << "Menor uso de memoria: " << stats[lowMemIdx].name
         << " (" << stats[lowMemIdx].memBytes / (1024.0 * 1024.0) << " MB)\n\n";

    // Notas sobre teoría vs práctica
    cout << "Teoría vs Práctica:\n";
    cout << "  - QuickSort suele ser el más rápido en la práctica debido a su\n";
    cout << "    excelente localidad de caché y bajo overhead constante,\n";
    cout << "    aunque su peor caso teórico es O(n²).\n";
    cout << "  - HeapSort garantiza O(n log n) siempre, pero accede a memoria\n";
    cout << "    de forma no secuencial, lo que genera más cache misses.\n";
    cout << "  - AVL Tree tiene el mayor overhead por las rotaciones de\n";
    cout << "    balanceo y la gestión de punteros, además de usar O(n) memoria\n";
    cout << "    adicional para los nodos del árbol.\n\n";

    // Ventajas y desventajas
    cout << "Ventajas y Desventajas:\n";
    cout << "  QuickSort:\n";
    cout << "    + Muy rápido en la práctica (mejor localidad de caché)\n";
    cout << "    + Ordenamiento in-place (O(log n) espacio de stack)\n";
    cout << "    - Peor caso O(n²) si el pivote es mal elegido\n";
    cout << "    - No estable\n";
    cout << "  HeapSort:\n";
    cout << "    + Peor caso garantizado O(n log n)\n";
    cout << "    + In-place (O(1) espacio extra)\n";
    cout << "    - Más lento en la práctica por acceso no secuencial a memoria\n";
    cout << "    - No estable\n";
    cout << "  AVL Tree:\n";
    cout << "    + Búsqueda eficiente O(log n) incluso después de insertar\n";
    cout << "    + Siempre balanceado (O(log n) garantizado por operación)\n";
    cout << "    - Mayor uso de memoria O(n) por punteros y metadatos\n";
    cout << "    - Overhead de rotaciones durante inserción\n";

    return 0;
}