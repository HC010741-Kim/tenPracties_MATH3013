#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, unsigned long>phone_numbers ={
            {"Peter", 61231234},
            {"Mary", 68888888},
            {"Tom", 61234567},
            {"Bob", 67654321}
    };
    cout << "Search for existing name Peter, get phone_numbers " << phone_numbers["Peter"] << endl;
    cout << "Search for non-existing name Kim, get value " << phone_numbers["Kim"] << endl;
    bool t = true;
    unsigned long SeachPhone;
    SeachPhone = 68888888;
    for (auto i = phone_numbers.begin(); i != phone_numbers.end() ; ++i) {
        if (i -> second == SeachPhone){
            t = false;
            cout << "Phone numbers " << SeachPhone << " exist, is " << i ->first << endl;
            break;
        }
    }
    if (t){
        cout << "Phone numbers " << SeachPhone << " does not find." << endl;
    }
    t = true;
    SeachPhone = 61111111;
    for (auto i = phone_numbers.begin(); i != phone_numbers.end() ; ++i) {
        if (i -> second == SeachPhone){
            t = false;
            cout << "Phone numbers " << SeachPhone << " exist, is " << i ->first << endl;
            break;
        }
    }
    if (t){
        cout << "Phone numbers " << SeachPhone << " does not find." << endl;
    }
    t = true;
    return 0;
}
