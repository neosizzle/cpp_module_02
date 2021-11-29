#include "Fixed.hpp"

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


/*
** OCF functions
*/
Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	_fp_value = 0;
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