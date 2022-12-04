#include <iostream>
#include <algorithm>

template <typename T>
class vector{
private:
    int _size;
    T *data;
    using iterator = T *;
    using const_iterator = const T *;

public:
    vector(int size): _size(size), data(new T[_size]){

    }
    vector(): _size(0), data(0){

    }
    ~vector(){
        _size = 0;
        delete[] data;
    }
    const T& operator[](int i) const
    {
        return data[i];
    }
    T& operator[](int i)
    {
        return data[i];
    }
    iterator begin(){
        return &data[0];
    }
    const_iterator begin() const{
        return &data[0];
    }
    iterator end(){
        return &data[_size];
    }
    const_iterator end() const{
        return &data[_size];
    }
};

int main() {
    vector<int> v(5);
    v[0] = 10;
    v[1] = 1;
    v[2] = 4;
    v[3] = 2;
    v[4] = 8;
    std::cout << "v: " << v[0] << "," << v[1] << "," << v[2] << "," << v[3] << "," << v[4] << std::endl;
    std::cout << "Sort from begin() to end()." << std::endl;
    std::sort(v.begin(), v.end());
    std::cout << "v: " << v[0] << "," << v[1] << "," << v[2] << "," << v[3] << "," << v[4] << std::endl;
    return 0;
}
