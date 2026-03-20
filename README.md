# Sorting Algorithms Comparison

Programa en C++ que compara el rendimiento de tres algoritmos de ordenamiento diferentes aplicados a un dataset de 100,000 palabras.

## 📋 Descripción

Este proyecto implementa y compara tres estrategias diferentes para ordenar un conjunto grande de datos:

1. **QuickSort** - Ordenamiento rápido usando un vector dinámico (`std::vector`)
2. **HeapSort** - Ordenamiento por montículo usando estructura de heap binario
3. **AVL Tree** - Árbol binario balanceado (insersión + recorrido inorder)

## 📁 Estructura del Proyecto

```
proyecto/
├── main.cpp              # Programa principal
├── dataset.txt           # Dataset con 100,000 palabras (no incluido)
├── CMakeLists.txt        # Configuración de CMake
│
├── sorting.hpp/.cpp      # QuickSort y HeapSort
├── avl.hpp/.cpp          # Implementación del AVL Tree
├── utils.hpp/.cpp        # Funciones utilitarias
└── README.md             # Este archivo
```

## 🔧 Componentes

### QuickSort (quicksort.hpp/cpp)
- Implementación iterativa usando stack
- Complejidad: O(n log n) promedio, O(n²) peor caso
- Usa partición de Lomuto

### HeapSort (heapsort.hpp/cpp)
- Construcción de heap máximo + extracción
- Complejidad: O(n log n) garantizado
- Heapify recursivo

### AVL Tree (avl.hpp/cpp)
- Árbol binario balanceado autoadaptativo
- Insersión de elementos con balanceo automático
- Recorrido inorder para obtener resultado ordenado
- Complejidad: O(n log n)

### Utilidades (utils.hpp/cpp)
- `readDataset()` - Lee el archivo dataset.txt
- `isSorted()` - Verifica si un arreglo está ordenado
- `estimateVectorMemory()` - Estima uso de memoria

## 🚀 Compilación y Ejecución

### Compilar
```bash
mkdir build
cd build
cmake ..
cmake --build .
```

### Ejecutar
```bash
./proyecto.exe
```

O desde el directorio build:
```bash
cd cmake-build-debug
./proyecto.exe
```

## 📊 Salida Esperada

El programa imprime:
- Cantidad de palabras leídas
- Tiempo de ejecución de cada algoritmo (en millisegundos)
- Verificación de ordenamiento correcto
- Estimación de memoria usada
- Comparativa entre los tres algoritmos

## 📝 Dataset

Coloca el archivo `dataset.txt` en la raíz del proyecto. Debe contener 100,000 palabras, una por línea.

### Formato dataset.txt
```
palabra1
palabra2
palabra3
...
palabra100000
```

## ⏱️ Complejidad Temporal

| Algoritmo | Mejor Caso | Caso Promedio | Peor Caso |
|-----------|-----------|---------------|-----------|
| QuickSort | O(n log n) | O(n log n) | O(n²) |
| HeapSort | O(n log n) | O(n log n) | O(n log n) |
| AVL Tree | O(n log n) | O(n log n) | O(n log n) |

## 💾 Complejidad Espacial

| Algoritmo | Espacio |
|-----------|---------|
| QuickSort | O(log n) - Stack recursivo |
| HeapSort | O(1) - In-place |
| AVL Tree | O(n) - Nodos del árbol |

## ✅ Verificación

El programa verifica automáticamente que:
- Todos los datos se leyeron correctamente
- Cada algoritmo produjo un ordenamiento válido
- Se estima el uso de memoria para cada estrategia

## 📌 Notas Importantes

- No se usa `std::sort()` en QuickSort (implementado desde cero)
- AVL usa `std::multiset` para garantizar balanceo automático
- Los tiempos se miden con `std::chrono::high_resolution_clock`
- La memoria es una estimación basada en sizeof y cantidad de elementos

## 👤 Autor

Desarrollado para la materia ST0245 - Estructuras de Datos y Algoritmos

## 📚 Referencias

- Introducción a los Algoritmos (CLRS)
- C++ STL Documentation
- AVL Tree Fundamentals

