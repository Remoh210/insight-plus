@echo off
mkdir build
cd build
cmake -G "Visual Studio 17 2022" -A x64 -DCMAKE_BUILD_TYPE=Release ../
mkdir Debug
mkdir Release

::msbuild proj_name.vcxproj /p:Configuration=Release
::Release\proj_name.exe

copy ..\lib\_bin\ Debug
copy ..\lib\_bin\ Release
cd ..
pause