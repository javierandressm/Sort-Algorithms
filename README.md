# Sorting Algorithms Comparison

Comparación de rendimiento de QuickSort, HeapSort y AVL Tree en un dataset de 100,000 palabras.

## Algoritmos Implementados

- **QuickSort** - Partición recursiva
- **HeapSort** - Heap binario
- **AVL Tree** - Árbol balanceado con rotaciones automáticas

Todos implementados desde cero sin usar contenedores STL.

## Compilación

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## Ejecución

```bash
./proyecto.exe
```

## Archivos

- `main.cpp` - Programa principal
- `quicksort.hpp/cpp` - QuickSort
- `heapsort.hpp/cpp` - HeapSort
- `avl.hpp/cpp` - AVL Tree
- `utils.hpp/cpp` - Funciones auxiliares
- `dataset.txt` - 100,000 palabras
- `CMakeLists.txt` - Configuración de compilación


