# C++ Hashing + Boggle Line Solver

This repository contains:
1) a Hashing/HashTable implementation (open addressing) and related tests
2) a Boggle-style word finder that searches straight-line sequences on a generated board

## 1) Hashing / Hash Table

### Files
- `hash.h` — hashing helpers
- `ht.h` — hash table implementation (template)
- `ht-test.cpp`, `str-hash-test.cpp` — basic correctness tests
- `hash-check.cpp` — GoogleTest-based checker (requires gtest)

### Build & Run (Makefile)
```bash
make
./ht-test
./str-hash-test
```

### hash-check (requires GoogleTest installed on your system):
```bash
./hash-check
```

### Valgrind helper target (Linux):
```bash
make run-hash-check
```

### Clean:
```bash
make clean
```

## 2) Boggle Solver (Straight-Line Search + Prefix Pruning)

### What it does
-Generates an NxN board using a seed
-	Parses a dictionary into:
-	dictionary set (valid words)
-	prefix set (for pruning)
-	Searches for valid words along straight lines on the board

### Files
-	boggle.cpp/.h
-	boggle-driver.cpp
-	dict.txt (dictionary)

### Run

Usage:
```bash
./boggle-driver <size> <seed> <dictionary file>
```

Example:
```bash
make
./boggle-driver 4 42 dict.txt
```

### CMake Build (optional, more “project-style”)
```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j
```

### Memory Safety (recommended on macOS): AddressSanitizer
```bash
cmake -S . -B build-asan -DCMAKE_BUILD_TYPE=Debug \
  -DCMAKE_CXX_FLAGS="-fsanitize=address,undefined -fno-omit-frame-pointer"
cmake --build build-asan -j
./build-asan/boggle-driver 4 42 dict.txt
```



