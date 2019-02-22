#include <iostream>

#if defined(WINDOWS)

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

#elif defined(MACOS) 

#include <dlfcn.h>

extern "C" typedef int (*dllFunctionType)(bool showOutput);

int callDllFunction(bool showOutput){
    void *libraryID = dlopen("main.dylib", RTLD_LAZY);

    dllFunctionType dllFunction = 
        (dllFunctionType) dlsym(libraryID, "dllFunction");

    int returnCode = dllFunction(showOutput);

    dlclose(libraryID);

    return returnCode;
}

#else

#include <dlfcn.h>

extern "C" typedef int (*dllFunctionType)(bool showOutput);

int callDllFunction(bool showOutput){
    void *libraryID = dlopen("main.so", RTLD_LAZY);

    dllFunctionType dllFunction = 
        (dllFunctionType) dlsym(libraryID, "dllFunction");

    int returnCode = dllFunction(showOutput);

    dlclose(libraryID);

    return returnCode;
}

#endif

int main(const int argc, const char *argv[]){
    std::cout << "Is this a DLL?" << std::endl;

    return callDllFunction(true);
}
