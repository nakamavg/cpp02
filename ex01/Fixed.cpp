#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
	: nbr (0) {
		setRawBits(0);
		std::cout << "Default constructor called\n";
}
Fixed::Fixed( const int integer ) {
	std::cout << "Int constructor called" << std::endl;
	this->nbr= integer << shift;
}

Fixed::Fixed( float floater ) {
	std::cout << "Float constructor called" << std::endl;
	this->nbr = (int)(roundf(floater * (1 << shift)));
}

Fixed::Fixed(const Fixed &obj) {
	std::cout << "Copy constructor called\n";
	*this = obj;
}

Fixed &Fixed::operator=(const Fixed &obj) {
	std::cout << "Copy assignment operator called\n";
	this->nbr = obj.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
};

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called\n";
	return (this->nbr);
}

void	Fixed::setRawBits(int const raw) {
	this->nbr = raw; 
}

float Fixed::toFloat( void ) const {
	return (((float)(this->nbr)) / (1 << shift));
}

int Fixed::toInt( void ) const {
	return (this->nbr >> shift);
}
std::ostream &operator<<(std::ostream &out, const Fixed &source ) {
	out << source.toFloat();
	return (out);
}