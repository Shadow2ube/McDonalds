# McDonalds CLI

A program for grade 11 computer science summer school

## Build and run

1. If you are on Windows, install [MinGW](MinGW.md)
2. Install [CMake](https://cmake.org/install/)
3. On windows:
   ```shell
      cmake --preset windows-release -S . -B .\build; cmake --build ./build --target McDonalds -- -j 4; cls; & ".\build/McDonalds.exe"
   ```
   On linux:
   ```shell
      cmake --preset linux-debug -S . -B .\build && cmake --build ./build --target McDonalds -- -j 4 && clear && ./build/McDonalds.exe
   ```