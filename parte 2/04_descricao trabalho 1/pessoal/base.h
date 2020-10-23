#ifndef BASE_H
#define BASE_H

#include <objeto.h>
#include <Vetor3D.h>

class Base : public Objeto{
public:
    Base();
    Base(Vetor3D nt, Vetor3D na, Vetor3D ns);
    void base();
    void desenha();
};

#endif // BASE_H
