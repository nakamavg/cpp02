#include "Fixed.hpp"

Fixed::Fixed()
	: nbr (0) {
		setRawBits(0);
		std::cout << "Default constructor called\n";
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
