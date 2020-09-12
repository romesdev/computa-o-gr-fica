#ifndef ESTATUA_H
#define ESTATUA_H

#include <objeto.h>
#include <Vetor3D.h>


class Estatua: public Objeto{
public:
    Model3DS* model;
public:
    Estatua();
    Estatua(Vetor3D nt, Vetor3D na, Vetor3D ns);
    void desenha();
};



#endif // ESTATUA_H
