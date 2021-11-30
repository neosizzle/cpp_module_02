#include "Fixed.hpp"
#include <bitset>
/*
** Functions
*/
int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called\n";
	return _fp_value;
}

void Fixed::setRawBits( int const raw )
{
	_fp_value = raw;
} 

float Fixed::toFloat() const
{
	float	 res;
	int		shift;

	shift = pow(2, _fr_bits);
	res = float(_fp_value) / float(shift);
	//std::cout << res << "\n";
	return res;
}

int Fixed::toInt() const
{
	int	res;

	res = _fp_value >> _fr_bits;
	//std::cout << res << "\n";
	return res;
}


/*
** OCF functions
*/
Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	_fp_value = 0;
}

Fixed::Fixed(const int num)
{
	std::cout << "int constructor called\n";
	_fp_value = num << _fr_bits;
	//std::cout << _fp_value << "\n";
}

Fixed::Fixed(const float flt)
{
	int shift;

	shift = pow(2, _fr_bits);
	std::cout << "float constructor called\n";
	// std::cout << flt * power << "\n";
	// std::cout << roundf(flt * power) << "\n";
	_fp_value = roundf(flt * shift);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called\n";
	*this = fixed;
}

Fixed& Fixed::operator = (const Fixed &fixed)
{
	std::cout<<"Assignment operator called \n";
	if (this != &fixed)
		//this->_fp_value = fixed._fp_value;
		this->_fp_value = fixed.getRawBits(); //that missing line
	return *this;	
}

std::ostream& operator << (std::ostream& os, const Fixed &fixed)
{
	float	res;

	res = fixed.toFloat();
	os << res;
	return os;
}