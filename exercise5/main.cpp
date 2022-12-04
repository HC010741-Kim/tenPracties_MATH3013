#include <iostream>
#include <exception>

class EmptyStack: public std::exception {
    virtual const char* what() const throw() {
        return "The stack is empty.";
    }
} emptystack;

class FullStack: public std::exception {
    virtual const char* what() const throw() {
        return "The stack is full.";
    }
} fullstack;

template <typename T>
class Stack {
public:
    Stack(){
        nowsize = 0;
        stackPtr = new T[maxsize];
    }
    ~Stack(){
        delete[] stackPtr;
    }
    T& top() {
        if (nowsize == 0) throw emptystack;
        return stackPtr[nowsize];
    }
    void pop() {
        if (nowsize == 0) throw emptystack;
        nowsize --;
    }
    void push(T input){
        if (nowsize == maxsize) throw fullstack;
        nowsize ++;
        stackPtr[nowsize] = input;
    }
    void clear(){
        if (nowsize == 0) throw emptystack;
        nowsize = 0;
    }
    auto size(){
        return nowsize;
    }
    bool full() {
        return nowsize == maxsize;
    }
    bool empty(){
        return nowsize == 0;
    }

private:
    const int maxsize = 1000;
    int nowsize;
    T *stackPtr;
};

int main(){
    Stack<double> A;
    A.push(1.1);
    A.push(2.2);
    A.push(3.3);
    std::cout << "The last element: " << A.top() << std::endl;
    std::cout << "The size of this stack: " << A.size() << std::endl;
    std::cout << "Full?: " << A.full() << std::endl;
    std::cout << "Empty?: " << A.empty() << std::endl;
    A.pop();
    std::cout << "Remove last element." << std::endl;
    std::cout << "The last element: " << A.top() << std::endl;
    std::cout << "The size of this stack: " << A.size() << std::endl;
    std::cout << "Full?: " << A.full() << std::endl;
    std::cout << "Empty?: " << A.empty() << std::endl;
    A.clear();
    std::cout << "Delete all entries." << std::endl;
    std::cout << "The size of this stack: " << A.size() << std::endl;
    std::cout << "Full?: " << A.full() << std::endl;
    std::cout << "Empty?: " << A.empty() << std::endl;
    return 0;
}