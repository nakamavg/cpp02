#include <iostream>
#include <string>

class Fixed {

	private:
		int	nbr;
		static const int bit = 8;
	public:
		Fixed();
		Fixed(const Fixed &obj);
		Fixed &operator=(const Fixed &obj);
		~Fixed();
		int	getRawBits(void) const;
		void setRawBits(int const raw);
};
