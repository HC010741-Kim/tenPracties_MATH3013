#include <iostream>

class odd{
public:
    odd(int start_value = 1): n(start_value){
        if ((start_value + 1) % 2 != 0){
            throw std::domain_error("start_value is not odd.");
        }
    }
    odd(odd const &other): n(other.n){

    }
    ~odd(){

    }
    odd& operator++(){
        n += 2;
        return *this;
    }
    odd operator++(int){
        odd t(*this);
        operator++();
        return (t);
    }
    int& operator* (){
        return n;
    }
    bool operator == (odd other){
        return (n == other.n);
    }
    bool operator != (odd other){
        return (n != other.n);
    }
    odd& operator=(const odd& other){
        n = other.n;
        return *this;
    }
    odd& operator=(odd& other){
        n = other.n;
        return *this;
    }
private:
    int n;
};
int main() {
    odd odd_num(1), test(5), test2(9);
    std::cout << "*odd_num: " << *odd_num << std::endl;
    std::cout << "odd_num == test: " << (odd_num == test) << std::endl;
    std::cout << "odd_num != test: " << (odd_num != test) << std::endl;

    ++ odd_num;
    std::cout << "pre-increment" << std::endl;
    std::cout << "*odd_num: " << *odd_num << std::endl;
    std::cout << "odd_num == test: " << (odd_num == test) << std::endl;
    std::cout << "odd_num != test: " << (odd_num != test) << std::endl;

    odd_num ++;
    std::cout << "post-increment" << std::endl;
    std::cout << "*odd_num: " << *odd_num << std::endl;
    std::cout << "odd_num == test: " << (odd_num == test) << std::endl;
    std::cout << "odd_num != test: " << (odd_num != test) << std::endl;

    odd_num = test2;
    std::cout << "odd_num = test2" << std::endl;
    std::cout << "*odd_num: " << *odd_num << std::endl;
    return 0;
}
