#include <iostream>
#include "my_cmake_project/my_header.h"
#define GLOBAL 3


void myFunction() {
    std::cout << "myFunction() was called!" << std::endl;
}

int add(int a, int b) {
    return a + b;
}


float getData() {

    return Random::getData();
}



