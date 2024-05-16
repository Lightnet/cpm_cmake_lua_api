@echo off
echo 'init build'
mkdir build
cd build
cmake ..
cmake --build .