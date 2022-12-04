#include <iostream>
#include <vector>

using namespace std;

class Polynomial{
public:
    Polynomial();
    Polynomial(vector<double> coefficients);
    ~Polynomial();
    void print();
    int get_degree();
private:
    vector<double> _coefficients;
    int _degree;
};

Polynomial::Polynomial() {
    _coefficients = {0};
    _degree = 0;
}
Polynomial::Polynomial(vector<double> coefficients) {
    _coefficients.assign(coefficients.begin(),coefficients.end());
    int t = 0;
    for (int i = 0; i < _coefficients.size(); ++i) {
        if (_coefficients[i] != 0)
            t ++;
    }
    if (t != 0)
        _degree = _coefficients.size() - 1;
    else
        _degree = 0;
}
Polynomial::~Polynomial() {
}
void Polynomial::print() {
    if (_degree != 0){
        for (int i = 0; i < _degree + 1; ++i) {
            if (_coefficients[i] == 1){
                if (i == 0)
                    cout << "";
                else if (i == _degree)
                    cout << "+1";
                else
                    cout << "+";
            } else if (_coefficients[i] == 0){
                    continue;
            } else if (_coefficients[i] == -1){
                cout << "-";
            } else if (_coefficients[i] > 0){
                if (i == 0)
                    cout <<_coefficients[i];
                else
                    cout << "+" << _coefficients[i];
            } else
                cout << _coefficients[i];

            if (i == _degree - 1){
                cout << "x";
            } else if (i == _degree){
                continue;
            } else
                cout << "x^" << _degree - i;
        }
    } else cout << _coefficients[0];
}
int Polynomial::get_degree() {
    return _degree;
}


int main() {
    Polynomial f({-1, 2, 0, 1, 3});
    cout << f.get_degree() << endl;
    f.print();
    return 0;
}
