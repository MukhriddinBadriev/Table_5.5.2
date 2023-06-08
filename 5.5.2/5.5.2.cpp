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

    table(const table& other){
        *this = other;
    }

    table& operator=(const table& other) {
        if (&other != this) {
            for (int i = 0; i < rows; i++) {
                delete[] array[i];
            }
            delete[]array;

            if (other.array == nullptr) {
                array = nullptr;
            }
            else {
                array = new T * [other.rows];
                for (int i = 0; i < other.rows; i++) {
                    array[i] = new T[other.cols];
                    for (int j = 0; j < other.cols; j++) {
                        array[i][j] = other.array[i][j];
                    }
                }

            }
        }
        return *this;
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
        std::cout << test[0][0]<<'\n';
        
        auto& test2 = test;
        std::cout << test2[0][0] << '\n';

        test2[0][0] = 8;
        test = test2;
        std::cout << test[0][0];
        
    }
    catch (std::exception& e) {
        std::cout << e.what();
    }
    return 0;
}