#include <iostream>

template <class T>
class table {
public:
    table(int _cols, int _rows) {
        if (_cols <= 0 || _rows <= 0) {
            throw std::exception("Wrong index");
        }
        else {            
            rows = _rows;
            cols = _cols;
            array = new T * [_rows];
            for (int i = 0; i < _rows; i++) {
                array[i] = new T[_cols];
            }
        }
    }
    ~table() {
        for (int i = 0; i < rows; i++) {
            delete[] array[i];
        }
        delete[]array;
    }

    table(const table& other):table(other.array){} 
    table& operator=(const table& other) {
        return *this = other.array;
    }

    T* operator[](int index) const {
        return array[index];
    }

    T* operator[](int _index) {
        return array[_index];
    }
    

    int Size() {
        return rows*cols;
    }

private:
    int rows = 0;
    int cols = 0;
    T** array = nullptr;
};
int main()
{
    try {
        auto test = table<int>(2, 3);
        test[0][0] = 4;
        std::cout << test[0][0];
        auto& test2 = test;
    }
    catch (std::exception& e) {
        std::cout << e.what();
    }
    return 0;
}