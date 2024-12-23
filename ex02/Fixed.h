# ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <cmath>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

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
	
	bool operator < (const Fixed& fixed) const;
	bool operator > (const Fixed& fixed) const;
	bool operator <= (const Fixed& fixed) const;
	bool operator >= (const Fixed& fixed) const;
	bool operator == (const Fixed& fixed) const;
	bool operator != (const Fixed& fixed) const;

	Fixed operator + (const Fixed& fixed) const;
	Fixed operator - (const Fixed& fixed) const;
	Fixed operator * (const Fixed& fixed) const;
	Fixed operator / (const Fixed& fixed) const;

	Fixed& operator ++ ();
	Fixed operator ++ (int);
	Fixed& operator -- ();
	Fixed operator -- (int);

	static Fixed& min(Fixed& a, Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);

	static const Fixed& min(const Fixed& a, const Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);

private:
	int value;
	static const int bits = 8;
};

std::ostream& operator << (std::ostream& os, const Fixed& fixed);

# endif // FIXED_H