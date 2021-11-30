#ifndef __FIXED__H__
#define __FIXED__H__
#include <iostream>
#include <cmath>

class Fixed
{
private:
	int	_fp_value;
	static const int _fr_bits = 8;

public:
	Fixed();
	Fixed(const int num);
	Fixed(const float num);
	Fixed(const Fixed &fixed);
	~Fixed();
	Fixed & operator = (const Fixed &fixed);

	int getRawBits( void ) const;
	void setRawBits( int const raw );

	float 	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream& operator<< (std::ostream& os, const Fixed &fixed);

#endif  //!__FIXED__H__