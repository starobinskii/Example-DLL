@echo off

mkdir build

cd build

del *.exe *.obj *.exp *.lib

REM Solution for Windows
cl /LD /EHsc ..\sources\main.cc

cl /EHsc /Fe.\app.exe ..\sources\connect.cc

copy ..\sources\connect.py ..\app.py

del *.obj *.exp *.lib

cd ..