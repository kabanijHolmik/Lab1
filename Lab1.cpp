#include <iostream>
using namespace std;

struct Complex{
    double re;
    double im;

    struct Func{
        Complex* first = nullptr;
        Complex* second = nullptr;

        void AddNumber(double x, double y) {
            Complex* sp = new Complex;
            sp->re = x;
            sp->im = y;
            if (first == nullptr) { first = sp; }
            else { second = sp; }
        }

        void PrintComplex(Complex* r) {
            if(r->im < 0) cout << r->re << r->im << "i" << endl;
            else cout << r->re << "+" << r->im << "i" << endl;
        }

        void Add() {
            Complex* result = new Complex;
            result->re = first->re + second->re;
            result->im = first->im + second-> im;
            PrintComplex(result);
            first = result;
            second = nullptr;
        }

        void Sub() {
            Complex* result = new Complex;
            result->re = first->re - second->re;
            result->im = first->im - second->im;
            PrintComplex(result);
            first = result;
            second = nullptr;
        }

        void Mul() {
            Complex* result = new Complex;
            result->re = first->re * second->re - first->im * second->im;
            result->im = first->re * second->im + first->im * second->re;
            PrintComplex(result);
            first = result;
            second = nullptr;
        }

        void Div() {
            Complex* result = new Complex;
            result->re = (first->re * second->re + first->im * second->im)/(second->re*second->re+second->im*second->im);
            result->im = (second->re * first->im - first->re * second->im)/(second->re * second->re + second->im * second->im);
            PrintComplex(result);
            first = result;
            second = nullptr;
        }

    }f;
    
}a;

int main()
{
    double x, y;
    cin >> x;
    cin >> y;
    a.f.AddNumber(x, y);
    cin >> x;
    cin >> y;
    a.f.AddNumber(x, y);
    a.f.Add();
    cin >> x;
    cin >> y;
    a.f.AddNumber(x, y);
    a.f.Sub();
    cin >> x;
    cin >> y;
    a.f.AddNumber(x, y);
    a.f.Mul();
    cin >> x;
    cin >> y;
    a.f.AddNumber(x, y);
    a.f.Div();
    return 0;
}