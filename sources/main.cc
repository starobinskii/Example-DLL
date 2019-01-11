#include <iostream>

extern "C"{
    __declspec(dllexport) int dllFunction(bool showOutput){
        if(!showOutput){
            std::cout.setstate(std::ios::failbit);
        }

        std::cout << "No, this is Patrick!" << std::endl;

        return 0;
    }
}

int main(const int argc, const char *argv[]){
    return 0;
}
