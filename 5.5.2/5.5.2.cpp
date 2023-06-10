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
                rows = other.rows;
                cols = other.cols;
                array = new T * [rows];
                for (int i = 0; i < rows; i++) {
                    array[i] = new T[cols];
                    for (int j = 0; j < cols; j++) {
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
        std::cout << test[0][0] << '\n';
        
        auto& test2 = test;
        std::cout << test2[0][0] << '\n';

        test2[0][0] = 8;
        test = test2;
        std::cout << test[0][0] << '\n';

        auto test3 = table<int>(10, 10);
        auto test4 = table<int>(2, 3);
        test4 = test3;

        std::cout << test4.Size();
        
    }
    catch (std::exception& e) {
        std::cout << e.what();
    }
    return 0;
}