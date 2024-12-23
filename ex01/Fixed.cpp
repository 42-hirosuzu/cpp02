#include "Fixed.h"

Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
    // std::cout << "value: " << value << " a:0 " << std::endl<< std::endl;
}

Fixed::Fixed(const int a)
{
    value = a << bits;
	std::cout << "Int constructor called" << std::endl;
    // std::cout << "value: " << value << " a: " << a << std::endl<< std::endl;
}

Fixed::Fixed(const float a)
{
    value = (int)roundf(a * (1 << bits));
	std::cout << "Float constructor called" << std::endl;
    // std::cout << "value: " << value << " a: " << a << std::endl<< std::endl;
}
Fixed::Fixed(const Fixed& a)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = a;
    // std::cout << "value: " << value << " a: " << a << std::endl<< std::endl;
}

const Fixed& Fixed::operator=(const Fixed& a)
{
    std::cout << "Copy assignment operator called" << std::endl;
    value = a.getRawBits();
    // std::cout << "value: " << value << " a: " << a << std::endl<< std::endl;
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}


int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return value;
}

void Fixed::setRawBits( int const raw )
{
	value = raw;
}

float Fixed::toFloat( void ) const
{
    return (float)value / (1 << bits);
}



int Fixed::toInt( void ) const
{
    return value >> bits;
}

std::ostream& operator << (std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}
