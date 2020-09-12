#ifndef COBERTA_H
#define COBERTA_H

#include <objeto.h>
#include <Vetor3D.h>


class Coberta: public Objeto{
public:
    Model3DS* model;
public:
    Coberta();
    Coberta(Vetor3D nt, Vetor3D na, Vetor3D ns);
    void desenha();
};

#endif // COBERTA_H
