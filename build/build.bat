if exist build_project rd /s /q "build_project"
mkdir build_project
cd build_project
cmake ..
pause