@echo off
if not exist build mkdir build
pushd build
cmake -G"Visual Studio 16 2019" -A"Win32" -S ..\source\ -B .
cmake --build .
pushd Debug
main.exe
popd
popd