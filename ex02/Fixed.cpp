#include "Fixed.hpp"

Fixed::Fixed( void )
	: nbr (0) {
}

Fixed::Fixed( const int integer ) {
	this->nbr = integer << shift;
}

Fixed::Fixed( float floater ) {
	this->nbr = (int)(roundf(floater * (1 << shift)));
}

Fixed::Fixed( const Fixed &obj ) {
	this->nbr = obj.getRawBits();
}

Fixed &Fixed::operator=( const Fixed &obj ) {
	if (this != &obj)
		this->nbr = obj.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+( const Fixed &obj ) const {
	Fixed res;
	int rawBits;

	rawBits = this->nbr + obj.nbr;
	res.setRawBits(rawBits);
	return (res);
}

Fixed	Fixed::operator-( const Fixed &obj ) const {
	Fixed res;
	int rawBits;

	rawBits = this->nbr - obj.nbr;
	res.setRawBits(rawBits);
	return (res);
}

Fixed	Fixed::operator*( const Fixed &obj ) const {
	Fixed res;
	int rawBits;

	rawBits = this->nbr * obj.nbr / (1 << obj.shift);
	res.setRawBits(rawBits);
	return (res);
}

Fixed	Fixed::operator/( const Fixed &obj ) const {
	Fixed res;
	int rawBits;

	rawBits = this->nbr / (obj.nbr / (1 << obj.shift));
	res.setRawBits(rawBits);
	return (res); 
}

bool	Fixed::operator>( const Fixed &obj ) const {
	if (this->nbr < obj.nbr)
		return false;
	return true;
}
bool	Fixed::operator<( const Fixed &obj ) const {
	if (this->nbr > obj.nbr)
		return false;
	return true;
}

bool	Fixed::operator>=( const Fixed &obj ) const {
	if (this->nbr < obj.nbr)
		return false;
	return true;
}

bool	Fixed::operator<=( const Fixed &obj ) const {
	if (this->nbr > obj.nbr)
		return false;
	return true;
}

bool	Fixed::operator==( const Fixed &obj ) const {
	if (this->nbr != obj.nbr)
		return false;
	return true;
}

bool	Fixed::operator!=( const Fixed &obj ) const {
	if (this->nbr == obj.nbr)
		return false;
	return true;
}

Fixed Fixed::operator++( ) {
	this->nbr++;
	return (*this);
}

Fixed Fixed::operator++( int ) {
	Fixed temp(*this);
	this->nbr++;
	return (temp);
}

Fixed Fixed::operator--( ) {
	this->nbr--;
	return (*this);
}

Fixed Fixed::operator--( int ) {
	Fixed temp(*this);
	this->nbr--;
	return (temp);
}

Fixed::~Fixed( void ) {

}

void	Fixed::setRawBits(const int bits) {
	this->nbr = bits;
}

int	Fixed::getRawBits(void) const {
	return (this->nbr);
}

float Fixed::toFloat( void ) const {
	return (((float)(this->nbr)) / (1 << shift));
}

int Fixed::toInt( void ) const {
	return (this->nbr >> shift);
}

Fixed &Fixed::min(Fixed& n1, Fixed& n2) {
	if ( n1 <= n2 )
		return (n1);
	return (n2);
}

Fixed const &Fixed::min(Fixed const & n1, Fixed const & n2) {
	if ( n1 <= n2 )
		return (n1);
	return (n2);
}

Fixed &Fixed::max(Fixed& n1, Fixed& n2) {
	if ( n1 >= n2 )
		return (n1);
	return (n2);
}

Fixed const &Fixed::max(Fixed const & n1, Fixed const & n2) {
	if ( n1 >= n2 )
		return (n1);
	return (n2);
}

std::ostream &operator<<(std::ostream &out, const Fixed &obj ) {
	out << obj.toFloat();
	return (out);
}
