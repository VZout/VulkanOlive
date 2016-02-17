cd build

if "%1" == "CMake" (
    cmake -G "MinGW Makefiles" ..
)

make
cd ..
