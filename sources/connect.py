#!/usr/bin/env python
# -*- coding: utf-8 -*-

import ctypes

def callDllFunction(showOutput):
    ## Solution for Windows
    dllLibrary = ctypes.cdll.LoadLibrary('main.dll')
    
    ## Solution for macOS
    # dllLibrary = ctypes.cdll.LoadLibrary('main.dylib')
    
    ## Solution for Linux
    # dllLibrary = ctypes.cdll.LoadLibrary('main.so')
    
    boolShowOutput = ctypes.c_bool(showOutput)
    
    returnCode = dllLibrary.dllFunction(boolShowOutput)
    
    return returnCode

if __name__ == '__main__':
    print('Is this a DLL?')
    
    callDllFunction(True)
