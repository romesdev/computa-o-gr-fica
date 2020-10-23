#ifndef BANCO_H
#define BANCO_H

#include <objeto.h>
#include <Vetor3D.h>

class Banco: public Objeto
{
public:
    Model3DS* model;
public:
    Banco();
    Banco(Vetor3D nt, Vetor3D na, Vetor3D ns);
    void desenha();
};
#endif // BANCO_H
