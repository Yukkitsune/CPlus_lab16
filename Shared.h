#pragma once
template<class T>
class Shared {
	T* p = nullptr;
	size_t* copies = nullptr;
public:
	Shared(T* ptr) { // Конструктор
		p = ptr;
		copies = new size_t(1);
	}
	~Shared() { // Деструктор
		if (*copies != 1) {
			copies -= 1;
		}
		else {
			delete[]p;
			delete[]copies;
		}
	}
	Shared(Shared& ptr) { // Копирование
		this->p = ptr.p;
		this->copies = ptr.copies;
		*copies += 1;
	}
	void operator=(Shared& ptr) { // Копирование
		this->p = ptr.p;
		this->copies = ptr.copies;
		*copies += 1;
	}
	Shared(Shared&& ptr)noexcept { // Перемещение
		this->p = ptr.p;
		this->copies = ptr.copies;
		ptr.p = nullptr;
		ptr.copies = nullptr;
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
