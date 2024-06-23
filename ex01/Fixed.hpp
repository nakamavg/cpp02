#include <iostream>
#include <string>

class Fixed {

	private:
		int nbr;
		static const int shift = 8;
	public:
		Fixed( );
		Fixed( const int integer );
		Fixed( const float ffloat );
		Fixed( const Fixed &obj );
		Fixed &operator=( const Fixed &obj );
		~Fixed( );
		int getRawBits( void ) const;
		void setRawBits( const int bits );
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &obj );