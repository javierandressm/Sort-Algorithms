# Script PowerShell para limpiar Git

# Eliminar archivos tracked que no queremos
git rm --cached -r cmake-build-debug/ 2>$null
git rm --cached -r .idea/ 2>$null
git rm --cached CHANGELOG.md 2>$null
git rm --cached cleanup.ps1 2>$null
git rm --cached cleanup.sh 2>$null
git rm --cached compile.bat 2>$null
git rm --cached ENTREGA_FINAL.md 2>$null
git rm --cached GIT_INSTRUCTIONS.md 2>$null
git rm --cached git-push.sh 2>$null
git rm --cached GITHUB_READY.md 2>$null
git rm --cached INSTALL.txt 2>$null
git rm --cached INSTRUCCIONES_GITHUB.txt 2>$null
git rm --cached limpiar.bat 2>$null
git rm --cached QUICKSTART.md 2>$null
git rm --cached test_syntax.cpp 2>$null

# Commit
git add .
git commit -m "Clean up: remove unnecessary files and build artifacts"

Write-Host "Git limpiado correctamente." -ForegroundColor Green
Write-Host "Ahora puedes hacer: git push" -ForegroundColor Yellow

