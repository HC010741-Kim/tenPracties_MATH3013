#include <iostream>
#include <fstream>
using namespace std;
int main() {
    int age;
    cout << "What is your age?" << endl;
    cin >> age;
    cout << age << endl;
    ofstream myFile;
    myFile.open("../age.txt");
    myFile << age;
    myFile.close();
    return 0;
}
