# Proyecto: Comparación de Algoritmos de Ordenamiento

## 📋 Instrucciones de Ejecución Rápida

### En Windows (PowerShell o CMD):

1. **Navega al directorio del proyecto:**
   ```
   cd C:\Users\juego\CLionProjects\proyecto
   ```

2. **Construye el proyecto:**
   ```
   cmake --build cmake-build-debug --config Debug
   ```

3. **Ejecuta el programa:**
   ```
   .\cmake-build-debug\proyecto.exe
   ```

### En Linux/macOS:

1. **Navega al directorio del proyecto:**
   ```bash
   cd ~/path/to/proyecto
   ```

2. **Crea directorio de construcción:**
   ```bash
   mkdir -p build
   cd build
   ```

3. **Construye el proyecto:**
   ```bash
   cmake ..
   cmake --build . --config Debug
   ```

4. **Ejecuta el programa:**
   ```bash
   ./proyecto
   ```

## ✅ Verificación

Si todo funciona correctamente, deberías ver:
- "Leyendo dataset..."
- "OK - Palabras leídas: 100000"
- Progreso de inserción del AVL Tree (cada 50,000 elementos)
- Tiempos de ejecución para cada algoritmo
- Verificación de ordenamiento correcto
- Estimación de memoria usada

## 🔍 Estructura de Archivos Principal

```
proyecto/
├── main.cpp                 # Programa principal
├── avl.hpp / avl.cpp        # AVL Tree (implementación desde cero)
├── quicksort.hpp / .cpp     # QuickSort (desde cero)
├── heapsort.hpp / .cpp      # HeapSort (desde cero)
├── utils.hpp / .cpp         # Funciones auxiliares
├── dataset.txt              # 100,000 palabras a ordenar
├── CMakeLists.txt           # Configuración CMake
├── README.md                # Documentación detallada
└── QUICKSTART.md            # Este archivo
```

## 💡 Notas

- El proyecto compila con C++20
- No usa STL containers para ordenamiento o estructuras de datos principales
- Todos los algoritmos están implementados manualmente
- El dataset debe contener 100,000 palabras

¿Problemas? Verifica que:
- ✅ Tienes el archivo dataset.txt en la raíz del proyecto
- ✅ Tienes CMake instalado
- ✅ Tienes un compilador C++ compatible (GCC, Clang, MSVC)

