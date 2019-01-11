@echo off

mkdir build

cd build

del *.exe *.obj *.exp *.lib

cl /LD /EHsc ..\sources\main.cc

cl /EHsc /Feapp.exe ..\sources\connect.cc

del *.obj

del *.exp *.lib

cd ..