#include <iostream>
#include <string>
#include <array>
#include <memory>
#include <vector>
#include <tuple>
#include "my_cmake_project/my_header.h"

#define print(x) std::cout << x << std::endl

// void printValue(int a) {
//     print(a);
// }

// using function pointer
void forEach(std::vector<int>& vec, void(*func)(int)) {
    for (int val : vec) {
        func(val);
    }
}


struct Entity {
    int x, y;

    int* getArray() {
        int* arr = new int[x];
        return arr;
    }
};

// Templated function to print an array
template <typename T, size_t S> 
void printArray(std::array<T, S>& array) {
    for (int i = 0; i < S; i++) {
        std::cout << array[i] << std::endl;
    }
}


// Function to mutate a string by reference
std::string& changeStr(std::string& str) {
    str[1] = 'j';
    return str;
}

class Animal {
private:
    int m_age;
public:

    Animal (int age)
        : m_age(age) {}

    static void sayHi() {
        std::cout << "Hi" << std::endl;
    }

    int getAge() const {
        return this->m_age;
    }
    
    virtual void say() {
        std::cout << "Hello" << std::endl;
    }
    
    virtual ~Animal() {};
};

class Dog : public Animal {
private:
    std::string m_color;
public:
    Dog(std::string color) 
        : Animal(0), m_color(color) {}

    void say() override {
        std::cout << "wang wang! my color is " << m_color << " . My age is" << this->getAge() << std::endl;
    }
    
    ~Dog() {}
};

class Cat : public Animal {
    private:
        std::string m_color;
    public:
        Cat(std::string color) 
            : Animal(0), m_color(color) {}
    
        void say() override {
            std::cout << "miao miao! my color is " << m_color << ". My age is" << this->getAge() << std::endl;
        }
        
        ~Cat() {}
    };


void printBuffer(char** buf) {
    std::cout << *buf << std::endl;
}

typedef struct {
    union 
    {
        int a;
        float b;
    };
} Data;


void* operator new(size_t size) {
    return malloc(size);
}


int main() {
    std::cout << getData() << std::endl;
    std::string myname = "Jianxiong Shen";

#if 0
    char* ptr = &myname[0];
    for (int i = 10; i < 15; i++) {
        std::cout << *(ptr + i);
    }
#else
    std::string_view fname(myname.c_str(), 9);
    std::string_view lname(myname.c_str() + 10, 4);
    print(fname);
    print(lname);
#endif



    char buffer[100] = {"\nasdfsdfsadfsdafsdafsad"};
    char* buf = buffer;
    printBuffer(&buf);


    Data data;
    data.b = 2.0f;
    std::cout << data.a << std::endl;
    

    std::cout << global << std::endl;
    auto[name, age] = std::tuple<std::string, int> {"frank", 25};
    std::cout << name << std::endl << age << std::endl;
    std::unique_ptr<Dog> dog = std::make_unique<Dog>("white");
    std::unique_ptr<Animal> animal = std::make_unique<Dog> ("black");
    Dog* newdog = dynamic_cast<Dog*>(animal.get());
    std::unique_ptr<Animal> cat = std::make_unique<Cat> ("blue");
    Cat* newcat = dynamic_cast<Cat*>(dog.get());
    if (newcat) newcat->say();
    else std::cout << "unsafe cast" << std::endl;
    newdog->say();
    dog->say();

    std::cout << "small change" << std::endl;



    // Dog* dog = new Dog("white");
    // Animal* animal = new Dog("white");
    // Animal* true_animal = new Animal(3);

    // Dog* dog2 = static_cast<Dog*>(animal);
    // true_animal->say();
    // dog2->say();
    // animal->say();
    // Animal::sayHi();

    Entity e = {5, 6};
    int* position = (int*)&e;
    std::cout << position[0] << ", " << *(position + 1) << std::endl;

    int* gotarr = e.getArray();


    for (int i = 0; i < e.x; i++) {
        gotarr[i] = i;
        std::cout << gotarr[i] << std::endl;
    }

    delete[] gotarr;


    std::vector<int> vec = {1, 2, 3, 4, 5};
    // using lambda
    forEach(vec, [](int val) {print(val);});
    
    std::unique_ptr<int> hvalue = std::make_unique<int>();
    *hvalue = 5;

    std::string mystr = "abc";
    changeStr(mystr);
    std::cout << mystr << std::endl;

    std::cout << *hvalue << std::endl;

    std::cout << "Welcome to My CMake Project!" << std::endl;

    // These require proper implementation in your header file
    myFunction();
    std::cout << add(3, 2) << std::endl;

    return 0;
}
