#include <iostream>
#include "complex.hpp"

int main(void) {
    complex<float> c1(1.0, 2.0); //numero float
    complex<float> c2(1.0, -2.0); //numero double

    //stampa
    std::cout << "c1 ha parte reale " << c1.re() << " e parte immaginaria " << c1.imm() << std::endl;
    std::cout << "c2 ha parte reale " << c2.re() << " e parte immaginaria " << c2.imm() << std::endl;

    //sommo
    auto s = c1 + c2;
    std::cout << "c1 + c2 = " << s << std::endl;

    //prodotto
    auto p = c1 * c2;
    std::cout << "c1 * c2 =: " << p << std::endl;

    //coniugato
    std::cout << "Il coniugato di c1 è " << c1.conj() << std::endl;

    return 0;
}