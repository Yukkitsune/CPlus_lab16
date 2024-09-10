#pragma once
#include <iostream>

template<class T>
class Unique {
    T* p = nullptr;
public:
    Unique(T* p_new) { // Конструктор
        p = p_new;
    }
    ~Unique() { // Деструктор
        delete[] p;
    }
    Unique(const Unique&) = delete; // Отключение возможности копирования нового указателя
    void operator=(const Unique&) = delete;

    Unique(Unique&& ptr) noexcept{ // Перемещение
        this->p = ptr.p;
        ptr.p = nullptr;
    }

    void operator=(Unique&& ptr)noexcept { // Перемещение
        if (this != &ptr) {
            this->p = ptr.p;
            ptr.p = nullptr;
        }
        return *this;
    }
    T* get() const { // Возврат сырого указателя
        return p;
    }

    T& operator*() { // Возврат объекта
        return *p;
    }

    T* operator->() { // Возврат сырого указателя для работы с объектом класса
        return p;
    }
};
