#!/bin/bash
# Limpiar archivos que ya fueron tracked

# Eliminar del staging pero no del disco
git rm --cached -r cmake-build-debug/
git rm --cached -r .idea/
git rm --cached CHANGELOG.md
git rm --cached cleanup.ps1
git rm --cached compile.bat
git rm --cached ENTREGA_FINAL.md
git rm --cached GIT_INSTRUCTIONS.md
git rm --cached git-push.sh
git rm --cached GITHUB_READY.md
git rm --cached INSTALL.txt
git rm --cached INSTRUCCIONES_GITHUB.txt
git rm --cached limpiar.bat
git rm --cached QUICKSTART.md
git rm --cached test_syntax.cpp

# Hacer nuevo commit
git add .
git commit -m "Clean up: remove unnecessary files and build artifacts"

echo "Git limpiado. Ahora puedes hacer: git push"

