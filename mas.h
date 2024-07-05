#pragma once
#include <vector>
#include <QTextStream>
#include <QDataStream>
#include <QString>
using namespace std;

template <typename T>
class Array {
public:
    vector<T> data;
    int size;
    Array() : size(0) {}
    Array(int size) : size(size), data(size) {}
    Array(const Array& other) : size(other.size), data(other.data) {}
    Array& operator=(const Array& a) {	//= с копированием
        if (&a != this) {
            delete[] data;
            data = new T[a.size];
            size = a.size;
            memcpy((void*)data, (void*)a.data, sizeof(T) * size);
        }
        return *this;
    }
    T& operator[](int index) {
        if (index >= size) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }
    const T& operator[](int index) const {
        if (index >= size) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }
    int getSize() const {
        return size;
    }
    void resize(int newSize) {
        size = newSize;
        data.resize(newSize);
    }
    friend QTextStream& operator<<(QTextStream& out, Array<T>& array) {
        for (int i = 0; i < array.size; ++i) {
            out << array.data[i];
        }
        return out;
    }
    friend QTextStream& operator>>(QTextStream& in,Array<T>& obj){
        T temp;
        while(!in.atEnd()){
            in >> temp;
            obj.data.push_back(temp);
        }
        return in;
    }
};
