#include <iostream>
#include "complex.hpp"

int main(void) {
    complex<float> c1(1.0f, 2.0f); 
    complex<float> c2(1.0, -2.5); 
    complex<float> c3(6.0f);
	float c4=2.0;

    //stampa
    std::cout << "c1 ha parte reale " << c1.re() << " e parte immaginaria " << c1.imm() << std::endl;
    std::cout << "c2 ha parte reale " << c2.re() << " e parte immaginaria " << c2.imm() << std::endl;
	std::cout << "c3 ha parte reale " << c3.re() << " e parte immaginaria " << c3.imm() << std::endl;
	
    //somma
    auto s = c1 + c2;
    std::cout << "c1 + c2 = " << s << std::endl;
	
	auto t = c4 + c1;
    std::cout << "scalare + c1 = " << t << std::endl;


    //prodotto
    auto p = c1 * c2;
    std::cout << "c1 * c2 =: " << p << std::endl;
	
	auto p1 = c1 * c4; // complesso*reale
    auto p2 = c4 * c1; //reale*complesso

    std::cout << "c1 * scalare c4 = " << p1 << std::endl;
    std::cout << "scalare c4 * c1 = " << p2 << std::endl;

    //coniugato
    std::cout << "Il coniugato di c1 è " << c1.conj() << std::endl;

    return 0;
}