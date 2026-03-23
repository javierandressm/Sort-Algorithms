# CHANGELOG - Proyecto de Comparación de Algoritmos

## v1.0 - Implementación Completa (2024)

### ✨ Nuevas Características

#### AVL Tree - Implementación desde Cero
- ✅ Estructura de nodo propia (`struct AVLNode`)
- ✅ Inserción con balanceo automático
- ✅ 4 tipos de rotaciones:
  - Rotación simple izquierda
  - Rotación simple derecha
  - Rotación doble izquierda-derecha
  - Rotación doble derecha-izquierda
- ✅ Cálculo automático de balance factor
- ✅ Actualización de alturas
- ✅ Recorrido inorder para obtener resultado ordenado
- ✅ Soporte para elementos duplicados
- ✅ Complejidad O(n log n) garantizada

#### Algoritmos Complementarios
- ✅ QuickSort - Implementación desde cero (sin `std::sort()`)
- ✅ HeapSort - Implementación desde cero (sin `std::priority_queue`)
- ✅ Ambos con complejidad O(n log n)

#### Sistema de Evaluación
- ✅ Medición de tiempo con `std::chrono::high_resolution_clock`
- ✅ Verificación de ordenamiento correcto
- ✅ Estimación de uso de memoria
- ✅ Comparativa visual de rendimiento

#### Documentación
- ✅ README.md - Documentación completa
- ✅ QUICKSTART.md - Guía rápida de inicio
- ✅ INSTALL.txt - Instrucciones de instalación
- ✅ CHANGELOG.md - Este archivo

### 🔧 Componentes Técnicos

**avl.hpp / avl.cpp**
- Clase `AVLTree` con estructura de nodo personalizada
- Métodos privados para rotaciones y balanceo
- Interface pública simple: `insert()`, `inorder()`, `size()`

**quicksort.hpp / quicksort.cpp**
- Ordenamiento por partición recursivo
- Complejidad: O(n log n) promedio

**heapsort.hpp / heapsort.cpp**
- Ordenamiento por montículo
- Complejidad: O(n log n) garantizado

**utils.hpp / utils.cpp**
- Lectura de dataset
- Verificación de ordenamiento
- Estimación de memoria

**main.cpp**
- Orquestación de los tres algoritmos
- Medición y comparación
- Generación de reportes

### 📊 Resultados

El programa genera comparativa con:
- Tiempo de ejecución por algoritmo (ms)
- Estado de ordenamiento (correcto/incorrecto)
- Estimación de memoria usada (MB)
- Resumen final de mejores resultados

### ✅ Cambios Realizados

#### De Implementación Anterior
- ❌ Removido: `#include <set>` (STL)
- ❌ Removido: `multiset<string> tree;` (STL container)
- ✅ Agregado: Estructura de nodo personalizada
- ✅ Agregado: Sistema de rotaciones
- ✅ Agregado: Cálculo de balance factor
- ✅ Agregado: Gestión manual de memoria

### 🎯 Características de Calidad

- ✅ Código limpio y bien documentado
- ✅ Separación clara de responsabilidades
- ✅ Headers `.hpp` con interfaces limpias
- ✅ Implementaciones `.cpp` organizadas
- ✅ Sin warnings de compilación
- ✅ Compatible con C++20
- ✅ Funciona en Windows, Linux, macOS

### 📝 Compilación

```bash
cmake --build cmake-build-debug --config Debug
.\cmake-build-debug\proyecto.exe
```

### 🐛 Notas de Desarrollo

- AVL Tree soporta duplicados (como `std::multiset` original)
- Todas las operaciones son O(n log n)
- Memory management: manual con `new`/`delete`
- Balance factor se actualiza después de cada inserción
- Las rotaciones mantienen la propiedad BST

---

**Versión:** 1.0
**Estado:** Completado ✓
**Compilable:** Sí ✓
**Ejecutable:** Sí ✓
**Documentado:** Sí ✓

