#ifndef __COMPLEX_H__
#define __COMPLEX_H__

#include <iostream>

using std::ostream;

class Complex
{
public:
    Complex(const double re = 0, const double im = 0);
    Complex(const Complex& c);

    Complex& operator=(const Complex& c);

    Complex polar(const double leng, const double arg);

    double real();
    double imag();
    double norm();
    double abs();
    double arg();

    Complex operator++();
    Complex operator++(int);
    Complex operator--();
    Complex operator--(int);

    ~Complex() = default;

    friend Complex polar(const double leng, const double arg);
    friend double norm(const Complex& x);
    friend double abs(const Complex& x);
    friend double arg(const Complex& x);
    friend Complex operator+(const Complex& x, const Complex& y);
    friend Complex operator-(const Complex& x, const Complex& y);
    friend Complex operator*(const Complex& x, const Complex& y);
    friend Complex operator/(const Complex& x, const Complex& y);
    friend Complex operator+=(Complex& x, const Complex& y);
    friend Complex operator-=(Complex& x, const Complex& y);
    friend Complex operator*=(Complex& x, const Complex& y);
    friend Complex operator/=(Complex& x, const Complex& y);
    friend bool operator==(const Complex& x, const Complex& y);
    friend bool operator!=(const Complex& x, const Complex& y);
    friend ostream& operator<<(ostream& o, const Complex& x);

private:
    double re, im;
};

Complex polar(const double leng, const double arg);
double norm(const Complex& x);
double abs(const Complex& x);
double arg(const Complex& x);
Complex operator+(const Complex& x, const Complex& y);
Complex operator-(const Complex& x, const Complex& y);
Complex operator*(const Complex& x, const Complex& y);
Complex operator/(const Complex& x, const Complex& y);
Complex operator+=(Complex& x, const Complex& y);
Complex operator-=(Complex& x, const Complex& y);
Complex operator*=(Complex& x, const Complex& y);
Complex operator/=(Complex& x, const Complex& y);
bool operator==(const Complex& x, const Complex& y);
bool operator!=(const Complex& x, const Complex& y);
ostream& operator<<(ostream& o, const Complex& x);

#endif