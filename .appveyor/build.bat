if %WIN_ARCH%==64 (set ARCH=x64) else (set ARCH=Win32)

call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvars%WIN_ARCH%.bat"

mkdir build
cd build
cmake -A %ARCH% ..
cmake --build . --config Release
robocopy ../ Release/ *.md
robocopy ../.appveyor Release/ *.md
robocopy ../src Release *.lua
cd Release
7z a -tzip build.zip *.dll *.lua *.md
