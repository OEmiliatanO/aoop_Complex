#include "complex.h"
#include <cmath>

Complex polar(const double leng, const double arg)
{
    Complex c;
    return c.polar(leng, arg);
}

Complex::Complex(const double re, const double im): re(re), im(im) {}
Complex::Complex(const Complex& c): re(c.re), im(c.im) {}
Complex& Complex::operator=(const Complex& c)
{
    if (&c != this)
    {
        this->re = c.re;
        this->im = c.im;
    }
    return *this;
}

Complex Complex::polar(const double leng, const double arg)
{
    this->re = leng * cos(arg);
    this->im = leng * sin(arg);
    return *this;
}

double Complex::real()
{
    return this->re;
}

double Complex::imag()
{
    return this->im;
}

double Complex::norm()
{
    return this->re * this->re + this->im * this->im;
}

double Complex::abs()
{
    return sqrt(norm());
}

double Complex::arg()
{
    return atan2(this->im, this->re);
}

Complex Complex::operator++() // prefix
{
    this->re += 1;
    this->im += 1;
    return *this;
}

Complex Complex::operator++(int) // postfix
{
    Complex cp = *this;
    this->re += 1;
    this->im += 1;
    return cp;
}

Complex Complex::operator--() // prefix
{
    this->re -= 1;
    this->im -= 1;
    return *this;
}

Complex Complex::operator--(int) // postfix
{
    Complex cp = *this;
    this->re -= 1;
    this->im -= 1;
    return *this;
}

double norm(const Complex& x)
{
    return x.re * x.re + x.im * x.im;
}

double abs(const Complex& x)
{
    return sqrt(norm(x));
}

double arg(const Complex& x)
{
    return atan2(x.im, x.re);
}

Complex operator+(const Complex& x, const Complex& y)
{
    return Complex{x.re + y.re, x.im + y.im};
}
Complex operator-(const Complex& x, const Complex& y)
{
    return Complex{x.re - y.re, x.im - y.im};
}
Complex operator*(const Complex& x, const Complex& y)
{
    return Complex{x.re * y.re - x.im * y.im, x.re * y.im + y.re * x.im};
}
Complex operator/(const Complex& x, const Complex& y)
{
    return Complex((x.re * y.re + x.im * y.im) / norm(y), (x.im * y.re - x.re * y.im) / norm(y));
}
Complex operator+=(Complex& x, const Complex& y)
{
    x = x + y;
    return x;
}
Complex operator-=(Complex& x, const Complex& y)
{
    x = x - y;
    return x;
}
Complex operator*=(Complex& x, const Complex& y)
{
    x = x * y;
    return x;
}
Complex operator/=(Complex& x, const Complex& y)
{
    x = x / y;
    return x;
}

bool operator==(const Complex& x, const Complex& y)
{
    return (&x == &y) || (x.re == y.re && x.im == y.im);
}
bool operator!=(const Complex& x, const Complex& y)
{
    return !(x == y);
}

ostream& operator<<(ostream& o, const Complex& x)
{
    return o << '(' << x.re << ',' << x.im << ')';
}
