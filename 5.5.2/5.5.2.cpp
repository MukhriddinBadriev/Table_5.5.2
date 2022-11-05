#include <iostream>

template <class T>
class table {
public:
    table(int _cols, int _rows) {
        if (_cols <= 0 || _rows <= 0) {
            throw std::exception("Wrong index");
        }
        else {
            cols = _cols;
            rows = _rows;
            array = new T * [_cols];
            for (int i = 0; i < rows; i++) {
                array[i] = new T[_rows];
            }
        }
    }
    ~table() {
        delete[]*array;
    }

    table<T>& operator[](int index) const {
        return array[index];
    }

    table<T>& operator[](int _index) {
        return &array[_index];
    }

    int Size(table& mas) {
        return mas.cols * mas.rows;
    }

private:
    int cols = 0;
    int rows = 0;
    T** array = nullptr;
};
int main()
{
    try {
        auto test = table<int>(2, 3);
        test[0][0] = 4;
        std::cout << test[0][0];
        
    }
    catch (std::exception& e) {
        std::cout << e.what();
    }
    return 0;
}