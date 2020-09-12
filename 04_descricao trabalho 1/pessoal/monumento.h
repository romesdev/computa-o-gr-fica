#ifndef MONUMENTO_H
#define MONUMENTO_H

#include <objeto.h>
#include <Vetor3D.h>

class Monumento : public Objeto{
public:
    Monumento();
    Monumento(Vetor3D nt, Vetor3D na, Vetor3D ns);
    void desenha();
    void monumento();

};

#endif // MONUMENTO_H
