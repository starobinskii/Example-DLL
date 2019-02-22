@echo off

mkdir build

cd build

del *.exe *.obj *.exp *.lib

REM Solution for Windows
cl /LD /EHsc ..\sources\main.cc

cl /EHsc /Feapp.exe ..\sources\connect.cc

del *.obj *.exp *.lib

cd ..