#ifndef MY_HEADER_H
#define MY_HEADER_H


static int global;

// Function prototypes
void myFunction();
int add(int a, int b);
float getData();

class Random {
public:
    Random(const Random& other) = delete;

    static Random& Get() {
        static Random s_Instance;
        return s_Instance;
    }

    static float getData() {
        return Get().pGetData();
    }
private:
    Random() {}
    float data = 2.7f;
    static Random s_Instance;
    float pGetData() {return data;}
};


#endif // MY_HEADER_H