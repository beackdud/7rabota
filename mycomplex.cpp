/*!
	@file
	@brief Файл описания методов класса Complexz
*/

#include <iostream>
#include <cmath>
#include "mycomplex.h"

using namespace std;

/*!
	@brief Действительная составляющая
	@param a_re Действительная составляющая
	@param a_im Мнимая составляющая
*/

Complex::Complex (double aRe, double   aIm)
{   
    Re = aRe;   
    Im = aIm; 
}

/*!
	@brief Конструктор класса
	@param a_re Действительная составляющая aRval
*/

Complex::Complex (const Complex & aRval)
{  
    Re = aRval.Re; 
    Im = aRval.Im;
}

/*!
	@brief Деструктор класса
*/

Complex::~Complex () 
{
    Re = 0.0;
    Im = 0.0;
}

/*!
	@brief Установка значений класса класса
	@param aRe Действительная составляющая 
	@param aIm Мнимая составляющая
*/

void Complex::Set (double aRe, double aIm) 
{   
    Re = aRe;
    Im = aIm;
}

/*!
	@brief Возвращает модуль комплексного числа
	@return Модуль комплесного числа
*/

Complex::operator double ()
{ 
    return abs();
}

/*!
	@brief Возвращает квадратный корень комплексного числа
	@return Квадратный корень комплесного числа
*/

double Complex::abs()
{
    return sqrt(Re * Re + Im * Im);
}

/*!
	@brief Возвращает сумму комплексных числел
	@return Разность комплесных чисел
*/

Complex Complex::operator+ (const Complex & aRval)
{
    Complex Result;
    Result.Re = Re + aRval.Re;
    Result.Im = Im + aRval.Im ;
    return Result;
}

/*!
	@brief Возвращает разность комплексных числел
	@return Сумму комплесных чисел
*/

Complex Complex::operator- (const Complex & aRval) 
{
    Complex Result;
    Result.Re = Re - aRval.Re;
    Result.Im = Im - aRval.Im;
    return Result;
}

/*!
	@brief Возвращает сумму комплексного и дробного числел
	@return Сумму чисел
*/

Complex Complex::operator+ (const double & aval)
{
    Complex result;
    result.Re = Re + aval;
    result.Im = Im;
    return result;
}

/*!
	@brief Возвращает разность комплексного и дробного числел
	@return Сумму чисел
*/

Complex Complex::operator- (const  double & aRval)
{
    Complex Result (*this);
    Result.Re = Re - aRval;
    return Result;
}

/*!
	@brief Возвращает произведение комплексных чисел
	@return Произведение комплексных чисел
*/

Complex Complex::operator* (const Complex & aRval)
{
    Complex Result;
    Result.Re = Re * aRval.Re - Im*aRval.Im;
    Result.Im = Re * aRval.Im + Im*aRval.Re;
    return Result;
}

/*!
	@brief Возвращает произведение комплексного числа на дробное число
	@return Произведение чисел
*/

Complex Complex::operator* (const double & aRval)
{
    Complex Result;
    Result.Re =Re*aRval;
    Result.Im =Im*aRval;
    return Result;
}

/*!
	@brief Возвращает частное комплексного числа на дробное число
	@return Частное чисел
*/

Complex Complex::operator/ (const double & aRval)
{   Complex Result;
    Result.Re = Re / aRval;
    Result.Im = Im / aRval;
    return Result; 
}

Complex & Complex::operator+= (const Complex & arval)
{
    Re += arval.Re;
    Im += arval.Im;
    return * this;
}
Complex & Complex::operator-= (const Complex & aRval)
{ 
    Re -= aRval.Re;
    Im -= aRval.Im; 
    return * this;
}

Complex & Complex::operator*= (const Complex & aRval)
{ 
    double tmpRe = Re;
    Re = Re * aRval.Re - Im * aRval.Im;
    Im = Im * aRval.Re + tmpRe * aRval.Im; 
    return * this;
}

Complex & Complex::operator+= (const double & aRval)
{
    Re+=aRval;
    return * this;
}

Complex & Complex::operator-= (const double & aRval) 
{
    Re -= aRval;
    return * this;
}

Complex & Complex::operator*= (const  double & aRval)
{  
    Re *= aRval;  
    Im *= aRval;   
    return * this; 
}

Complex & Complex::operator/= (const double & aRval)
{ 
    Re /= aRval; 
    Im /= aRval;
    return * this; 
}

Complex & Complex::operator= (const Complex & aRval)
{ 
    Re = aRval.Re; 
    Im = aRval.Im;  
    return * this; 
}

Complex & Complex::operator= (const double & aRval)
{ 
    Re = aRval; 
    Im = 0.0;   
    return *this; 
}

istream & operator >> (istream & stream, Complex & a) 
{
    char tmp[256];  
    stream >> a.Re >> a.Im >> tmp;
    return stream; 
}

ostream & operator<< (ostream & stream, Complex & a)
{
    stream << a.Re; 

    if ( !(a.Im < 0) ) 
        stream << '+';  
        stream << a.Im << 'i';  
        return stream; 
}

Complex operator+ (const double & aLval, const Complex & aRval)
{
    Complex Result;
    Result.Re = aLval+aRval.Re;
    Result.Im = aRval.Im;
    return Result;
}

Complex operator- (const double &aLval, const Complex & aRval)
{
    Complex Result;
    Result.Re = aLval - aRval.Re;
    Result.Im = - aRval.Im;
    return Result;
}

Complex operator* (const double & aLval, const Complex & a)
{ 
    Complex r;
    r.Re = aLval * a.Re;
    r.Im = aLval * a.Im;
    return r;
}