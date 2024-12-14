# ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed 
{
public:
	Fixed();
	Fixed(const Fixed& a);
	const Fixed& operator = (const Fixed& a);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );

private:
	int value;
	static const int bits = 8;
};

# endif // FIXED_H