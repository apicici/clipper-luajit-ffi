mkdir -p build && cd build
cmake ..
cmake --build .
zip -j ../build.zip *.so *.dylib
zip -j ../build.zip ../src/*.lua
zip -j ../build.zip ../*.md
zip -j ../build.zip ../.appveyor/*.md
