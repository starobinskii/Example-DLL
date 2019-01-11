#include <iostream>
#include <windows.h>

int callDllFunction(bool showOutput){
   HINSTANCE libraryID = LoadLibrary("main.dll");

   FARPROC functionID = GetProcAddress(HMODULE(libraryID), "dllFunction");

   typedef int (__stdcall * pICFUNC)(bool);

   pICFUNC dllFunction = pICFUNC(functionID);

   int returnCode = dllFunction(showOutput);

   FreeLibrary(libraryID);

    return returnCode;
}

int main(const int argc, const char *argv[]){
    std::cout << "Is this a DLL?" << std::endl;

    return callDllFunction(true);
}
