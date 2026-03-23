# 📋 INSTRUCCIONES PARA SUBIR A GITHUB

## ✅ Proyecto Listo para Entregar

Tu proyecto está limpio y listo para subir a GitHub.

---

## 🚀 Pasos para Subir a GitHub

### 1️⃣ Crear un nuevo repositorio en GitHub
- Ve a https://github.com/new
- Nombra el repositorio: `sorting-algorithms` (o como prefieras)
- NO inicialices con README, .gitignore ni LICENSE
- Haz clic en "Create repository"

### 2️⃣ Ejecuta estos comandos en PowerShell (Windows)

```powershell
cd C:\Users\juego\CLionProjects\proyecto

# Inicializar git
git init

# Agregar todos los archivos
git add .

# Crear commit inicial
git commit -m "Initial commit: Sorting algorithms comparison (QuickSort, HeapSort, AVL Tree)"

# Cambiar rama a main (si es necesario)
git branch -M main

# Agregar el remote (reemplaza USERNAME y REPO)
git remote add origin https://github.com/USERNAME/REPO.git

# Subir al repositorio
git push -u origin main
```

### 3️⃣ O en Linux/macOS

```bash
cd ~/path/to/proyecto

git init
git add .
git commit -m "Initial commit: Sorting algorithms comparison (QuickSort, HeapSort, AVL Tree)"
git branch -M main
git remote add origin https://github.com/USERNAME/REPO.git
git push -u origin main
```

---

## 📂 Archivos que se Subirán

```
sorting-algorithms/
├── main.cpp              ✅
├── avl.hpp               ✅
├── avl.cpp               ✅
├── quicksort.hpp         ✅
├── quicksort.cpp         ✅
├── heapsort.hpp          ✅
├── heapsort.cpp          ✅
├── utils.hpp             ✅
├── utils.cpp             ✅
├── dataset.txt           ✅
├── CMakeLists.txt        ✅
├── README.md             ✅
├── .gitignore            ✅
└── git-push.sh           ✅
```

---

## ✅ Archivos Excluidos (no se suben)

```
cmake-build-debug/     (carpeta de compilación)
.idea/                 (configuración de CLion)
build/                 (otra carpeta de compilación)
test_syntax.cpp        (archivo de test)
compile.bat            (script temporal)
cleanup.ps1            (script temporal)
QUICKSTART.md          (documentación extra)
INSTALL.txt            (documentación extra)
CHANGELOG.md           (documentación extra)
```

Estos archivos están en `.gitignore`, así que no se subirán.

---

## 💡 Verificación Antes de Subir

Antes de ejecutar `git push`:

```bash
# Ver los archivos que se van a subir
git status

# Ver el log de commits
git log --oneline

# Ver remote configurado
git remote -v
```

---

## 🔄 Después de Subir

Verifica en GitHub que todo se haya subido correctamente:

1. Ve a https://github.com/USERNAME/REPO
2. Deberías ver:
   - ✅ Todos los archivos `.cpp` y `.hpp`
   - ✅ El archivo `dataset.txt`
   - ✅ El `README.md` renderizado
   - ✅ El `CMakeLists.txt`

---

## 🎯 Resumen Ejecutivo

| Paso | Acción |
|------|--------|
| 1 | Crear repo en GitHub |
| 2 | `git init` |
| 3 | `git add .` |
| 4 | `git commit -m "Initial commit..."` |
| 5 | `git remote add origin ...` |
| 6 | `git push -u origin main` |

---

## ✨ ¡Listo!

Tu proyecto está completamente limpio, documentado y listo para GitHub.

Solo falta:
1. Crear el repo en GitHub
2. Copiar y pegar los comandos
3. ¡Hecho! 🎉

