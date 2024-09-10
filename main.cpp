#include "Unique.h"
#include "Point.h"
#include "Shared.h"
#include <algorithm>
template<typename T, typename...Args>
Unique<T>MakeUnique(const Args&...args) {
    T* obj = new T(args...);
    return Unique<T>(obj);
}
template<typename T, typename...Args>
Shared<T>MakeShared(const Args&...args) {
    T* obj = new T(args...);
    return Shared<T>(obj);
}

int main() {
    int num = 3545;
    Unique<int> unique1 = MakeUnique<int>(num);
    std::cout << "Raw pointer: " << std::endl;
    std::cout << unique1.get() << std::endl;
    std::cout << "Pointer: " << std::endl;
    std::cout << *(unique1.get()) << std::endl;
    Unique<Point> point1 = MakeUnique<Point, double, double>(3.1454, 6.4321);
    std::cout << "point 1: " << std::endl;
    point1->print();
    Unique<Point> point2(std::move (point1));
    std::cout << "point 2: " << std::endl;
    point2->print();
    Shared<Point> point3 = MakeShared<Point, double, double>(4.6546, 7.6365);
    std::cout << "point 3: " << std::endl;
    point3->print();
    Shared<Point> point4(point3);
    std::cout << "point 3: " << std::endl;
    point3->print();
    std::cout << "point 4: " << std::endl;
    point4->print();
    return 0;
}
