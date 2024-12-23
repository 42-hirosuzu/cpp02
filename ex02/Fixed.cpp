#include "Fixed.h"

Fixed::Fixed() : value(0)
{
	std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const int a)
{
    value = a << bits;
	std::cout << GREEN << "Int constructor called" << RESET << std::endl;
}

Fixed::Fixed(const float a)
{
    value = (int)roundf(a * (1 << bits));
	std::cout << GREEN << "Float constructor called" << RESET << std::endl;
}
Fixed::Fixed(const Fixed& a)
{
    std::cout << GREEN << "Copy constructor called" << RESET << std::endl;
    *this = a;
}

const Fixed& Fixed::operator=(const Fixed& a)
{
    std::cout << GREEN << "Copy assignment operator called" << RESET << std::endl;
    value = a.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << GREEN << "Destructor called" << RESET << std::endl;
}


int Fixed::getRawBits( void ) const
{
	std::cout << GREEN << "getRawBits member function called" << RESET << std::endl;
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


bool Fixed::operator < (const Fixed& fixed) const
{
    return value < fixed.getRawBits();
}

bool Fixed::operator > (const Fixed& fixed) const
{
    return value > fixed.getRawBits();
}

bool Fixed::operator <= (const Fixed& fixed) const
{
    return value <= fixed.getRawBits();
}

bool Fixed::operator >= (const Fixed& fixed) const
{
    return value >= fixed.getRawBits();
}

bool Fixed::operator == (const Fixed& fixed) const
{
    return value == fixed.getRawBits();
}

bool Fixed::operator != (const Fixed& fixed) const
{
    return value != fixed.getRawBits();
}

Fixed Fixed::operator + (const Fixed& fixed) const
{
    return Fixed(toFloat() + fixed.toFloat());
}

Fixed Fixed::operator - (const Fixed& fixed) const
{
    return Fixed(toFloat() - fixed.toFloat());
}

Fixed Fixed::operator * (const Fixed& fixed) const
{
    return Fixed(toFloat() * fixed.toFloat());
}

Fixed Fixed::operator / (const Fixed& fixed) const
{
    return Fixed(toFloat() / fixed.toFloat());
}

Fixed& Fixed::operator ++ ()
{
    value++;
    return *this;
}

Fixed Fixed::operator ++ (int)
{
    Fixed tmp(*this);
    operator++();
    return tmp;
}

Fixed& Fixed::operator -- ()
{
    value--;
    return *this;
}

Fixed Fixed::operator -- (int)
{
    Fixed tmp(*this);
    operator--();
    return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return a < b ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return a > b ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return a < b ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return a > b ? a : b;
}

std::ostream& operator << (std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}
