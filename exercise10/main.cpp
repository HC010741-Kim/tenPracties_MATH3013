#include <iostream>
#include <algorithm>
#include <assert.h>
//#include <memory>
using namespace std;
class vector_expression{
public:
    vector_expression(unsigned set_size): my_size(set_size), data(new double[my_size]){
    }
    unsigned size(){
        return my_size;
    }
    double& operator()(int i){
        return data[i];
    }

protected:
    unsigned my_size;
    double *data;
};
class vector: public vector_expression
{
public:
    vector(unsigned n):vector_expression(n){
        data = new double[my_size];
    }

    //vector(const vector& v)
    //        : my_size(v.my_size), data(new double[my_size])
    //{
    //    for (unsigned i= 0; i < my_size; ++i)
    //        data[i]= v.data[i];
    //}
    ~vector(){
        my_size = 0;
        delete[] data;
    }

    vector& operator=(const vector& src){
        if (this == &src)
            return *this;
        assert(my_size == src.my_size);
        for (int i= 0; i < my_size; ++i)
            data[i]= src.data[i];
        return *this;
    }
    //vector(vector&& v): my_size(v.my_size), data(v.data){
    //    v.data= nullptr;
    //    v.my_size= 0;
    //}
    vector& operator=(vector&& src)
    {
        assert(my_size == 0 || my_size == src.my_size);
        std::swap(data , src.data);
        return *this;
    }
};

class ones: public vector_expression{
public:
    ones(unsigned n = 0) : vector_expression{n} {
        for (int i = 0; i != my_size; ++i) {
            (*this)(i) = 1;
        }
    }
};
int main()
{
    vector_expression v_e(2);
    vector a(3);
    ones b(4);
    v_e(0) = 1;    v_e(1) = 3;
    a(0) = 1;    a(1) = 2;    a(2) = 4;
    cout << "Size of vector_expression v_e: " << v_e.size() << endl;
    cout << "Size of vector a: " << a.size() << endl;
    cout << "Size of ones b: " << b.size() << endl;
    cout << "Vector_expression v_e: ";
    for (int i = 0; i < v_e.size(); ++i) {
        cout << v_e(i) << " ";
    }
    cout << endl;
    cout << "Vector a: ";
    for (int i = 0; i < a.size(); ++i) {
        cout << a(i) << " ";
    }
    cout << endl;
    cout << "Ones b: ";
    for (int i = 0; i < b.size(); ++i) {
        cout << b(i) << " ";
    }
    cout << endl;


    return 0;
}