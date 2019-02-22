#!/bin/bash

mkdir -p build

cd build

rm -f *.out *.obj *.so *.dylib

## Solution for Linux
# g++ -fdeclspec -Wno-ignored-attributes -fPIC -shared -O2 \
#     -o ./main.so ../sources/main.cc
#
# g++ -O2 -o ./app.out ../sources/connect.cc

## Solution for macOS
g++ -fdeclspec -Wno-ignored-attributes -dynamiclib -O2 \
    -o ./main.dylib ../sources/main.cc

g++ -DMACOS -O2 -o ./app.out ../sources/connect.cc

cp ../sources/connect.py ./app.py

chmod +x ./app.py

rm -f *.obj

cd ..