#pragma once 
#include <iostream>
#include <concepts>  // per il constraint std::floating_point

template <typename T> requires std::floating_point<T>  // Classe per numeri complessi; T tipo floating-point, perché lo voglio double o float

class complex 
{ 
    T p_re;
    T p_imm;

public:
   complex()   //costruttore di default che inizializza a 0+0i
	: p_re(0), p_imm(0)
   {} 
	
	explicit complex(T re) //se avessi dato in input un numero reale e non complesso, il costruttore stampa che in realtà è complesso con p. immaginaria 0
        : p_re(re), p_imm(0)
    {
        std::cout << "converting constructor called" << std::endl;
    }
    complex(T re, T imm) //costruttore user-defined che crea un numero complesso con parte reale e immaginaria specificate dall'utente
		: p_re(re), p_imm(imm) 
	{} 

///
    //metodi per ottenere la parte reale e la parte immaginaria (const perché i metodi non devono modificare lo stato dell'oggetto!)

    //parte reale
    T re(void) const { 
		return p_re;
	}

    //parte immaginaria
    T imm(void) const {
		return p_imm;
	}

    //coniugato
    complex conj(void) const {
        return complex(p_re, -p_imm);
    }

	
	//overload dell'operatore << 
    friend std::ostream& operator<<(std::ostream& os, const complex& c) {
        os << c.p_re;
        if (c.p_imm >= 0) os << "+";
		os << c.p_imm << "i";
		
        return os;
    }
	
	
    //overload dell'operatore +=
    complex& operator+=(const complex& other) {
        p_re += other.p_re;
        p_imm += other.p_imm;
        return *this;
    }

    //overload dell'operatore +
    complex operator+(const complex& other) const {
        return complex(p_re + other.p_re, p_imm + other.p_imm);
    }

    //  Overload dell'operatore *=
    complex& operator*=(const complex& other) {
        T new_re = p_re * other.p_re - p_imm * other.p_imm;
        T new_imm = p_re * other.p_imm + p_imm * other.p_re;
        p_re = new_re;
        p_imm = new_imm;
        return *this;
    }

	//overload dell'operatore *
    complex operator*(const complex& other) const {
        return complex(
            p_re * other.p_re - p_imm * other.p_imm,
            p_re * other.p_imm + p_imm * other.p_re
        );
    }
    
   
	//overload degli operatori tra tipi diversi 
	
	//overload somma di scalare + complesso
    template <typename R>
    friend complex<R> 
	operator+(const R& c, const complex<R>& d) 
	{
        return complex<R>(c + d.p_re, d.p_imm);
    }
	
	
	//overload moltiplicazione complesso * reale
    complex operator*(const T& scal) const {
        return complex(p_re * scal, p_imm * scal);
    }

    //overload moltiplicazione reale * complesso 
    template <typename R>
    friend complex<R> operator*(const R& scal, const complex<R>& c) {
        return complex<R>(scal * c.p_re, scal * c.p_imm);
    }

};