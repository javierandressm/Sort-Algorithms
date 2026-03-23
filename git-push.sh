#!/bin/bash
# Script para inicializar y subir el proyecto a GitHub

# 1. Inicializar repositorio git (si no existe)
git init

# 2. Agregar todos los archivos
git add .

# 3. Primer commit
git commit -m "Initial commit: Sorting Algorithms Comparison (QuickSort, HeapSort, AVL Tree)"

# 4. Crear rama main (si es necesario)
git branch -M main

# 5. Agregar remote (reemplaza YOUR_USERNAME y YOUR_REPO)
# git remote add origin https://github.com/YOUR_USERNAME/YOUR_REPO.git

# 6. Subir a GitHub
# git push -u origin main

# Comandos listos para copiar y pegar:
# git remote add origin https://github.com/YOUR_USERNAME/YOUR_REPO.git
# git push -u origin main

