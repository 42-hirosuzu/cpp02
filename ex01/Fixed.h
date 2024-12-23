# ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <cmath>

class Fixed 
{
public:
	Fixed();
	Fixed(const int a);
	Fixed(const float a);
	Fixed(const Fixed& a);
	const Fixed& operator = (const Fixed& a);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;

private:
	int value;
	static const int bits = 8;
};

std::ostream& operator << (std::ostream& os, const Fixed& fixed);

# endif // FIXED_H
