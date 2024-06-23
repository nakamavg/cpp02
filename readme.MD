# ex00

## Introduccion a las clases canonicas ortodoxas

- tenemos que crear una clase canonica ortodoxa 
que tenga

## Default constructor
```c++
Fixed::Fixed()
	: nbr (0) {
		setRawBits(0);
		std::cout << "Default constructor called\n";
}
```
En exte caso cuando inicializamos el objeto
Fixed a por ejemplo.
lo primero que va hacer es setear la variable nbr
delo objeto a 0 y sacar por consola la frase de que
se ha llamado al constructor

## constructor de copia

```c++
Fixed::Fixed(const Fixed &obj) {
	std::cout << "Copy constructor called\n";
	*this = obj;
}
```

- El constructor de copia recibe como parametro
una referencia constante (para asegurarnos de que no se modifique la original) y luego se iguala la clase creada con la recibia

## operador de asignador de copia

- este metodo se llamara todas las veces que usemos el igual entre objetos de nuestra clase y sirve para decirle que tiene que copiar.

```c++
Fixed &Fixed::operator=(const Fixed &obj) {
	std::cout << "Copy assignment operator called\n";
	this->nbr = obj.getRawBits();
	return *this;
}
```

# ex 01

- Este ejercicio nos pide que pasemos float a ints y enteros a floats

- lo primero es tener 2 constructores de sobrecarga:

```c++
Fixed::Fixed( const int integer ) {
	std::cout << "Int constructor called" << std::endl;
	this->nbr= integer << shift;
}

Fixed::Fixed( float floater ) {
	std::cout << "Float constructor called" << std::endl;
	this->nbr = (int)(roundf(floater * (1 << shift)));
}
```
- depende del tipo de dato que le pasemos el constructor
se llamara automaticamente a uno o a otro 

- en ambos casos usaremos el despazamiento para shiftear 8 veces
a la izquierda que es multiplicar por 256
- en el caso de  int :
```c
int integer = 42;
int shift = 8;
int scaled = integer << shift; // 42 * 256 = 10752
```
- en el caso de un float 
```c
float floater = 42.4219f;
int shift = 8;
float scaled = floater * (1 << shift); // 42.4219 * 256 = 10860.0064
int fixed = roundf(scaled); // 10860
```

- Cuando querramos sacarlo por terminal tendremos el dato guardado en este sistema de punto fijo y si queremos volver

usaremos los metodos

```c++
float Fixed::toFloat( void ) const {
	return (((float)(this->nbr)) / (1 << shift));
}

int Fixed::toInt( void ) const {
	return (this->nbr >> shift);
}
```
en ambos casos haremos el paso a la inversa;

# ex02 

- nos piden que programemos todos y cada uno de los operadores matematicos mas el max y el min;

- es importante saber que lo que nos piden es que el ++ vaya sobre el numero en punto fijo entonces si nuestro numero esta reprensentado por 8 bits partiremos de que nuestro incremento sea 1/256 cada ve que hacemos ++;