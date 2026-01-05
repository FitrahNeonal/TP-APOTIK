#ifndef ARRAY1D_H
#define ARRAY1D_H

#include <iostream>
using namespace std;

template<class T>
class Array1D {
private:
    T* element; // pointer ke array dinamis
    int size; // ukuran array

public:
	// Konstruktor default
    Array1D(int sz = 0) {
        size = sz;
        if (size > 0)
            element = new T[size];
        else
            element = nullptr;
    }

	// Copy constructor
    Array1D(const Array1D<T>& other) {
        size = other.size;
        element = new T[size];
        for (int i = 0; i < size; i++)
            element[i] = other.element[i];
    }

	// Destructor
    ~Array1D() {
        delete[] element;
    }

    T& operator[](int i) {
        return element[i];
    }
	
	// Mendapat ukuran array
    int Size() const {
        return size;
    }

    Array1D<T>& operator=(const Array1D<T>& other) {
        if (this != &other) {
            delete[] element;
            size = other.size;
            element = new T[size];
            for (int i = 0; i < size; i++)
                element[i] = other.element[i];
        }
        return *this;
    }

    // Perbaikan pada array1d.h
	void ReSize(int newSize) {
	    if (newSize == size) return; 
	
	    T* elementBaru = new T[newSize]; // Alokasi memori baru
	    
	    // Salin data lama ke memori baru agar tidak hilang
	    int batas = (size < newSize) ? size : newSize;
	    for (int i = 0; i < batas; i++) {
	        elementBaru[i] = element[i];
	    }
	
	    delete[] element;      // Hapus memori lama
	    element = elementBaru;  // Pindahkan pointer ke memori baru
	    size = newSize;        // Update ukuran baru
	}
};

#endif
