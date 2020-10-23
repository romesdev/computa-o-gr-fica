#include "estatua.h"

Estatua::Estatua() : Objeto(4){
    model = new Model3DS("../3ds/Figurine.3DS");
}

Estatua::Estatua(Vetor3D nt, Vetor3D na, Vetor3D ns) : Objeto(4){
    //atributos herdados de OBJETO
    t = nt;
    a = na;
    s = ns;
    model = new Model3DS("../3ds/Figurine.3DS");
    origem = false;
}

void Estatua::desenha()
{
    glPushMatrix();
        Objeto::desenha();

        if (selecionado) {
            glEnable(GL_CULL_FACE);
                 GUI::setColor(0,1,1);
        }
        else{
             GUI::setColor(0.8, 0.6, 0);
        }
        glScalef(1,1,1.2); //ajuste final da escala, podendo ser não-uniforme, independente para cada eixo
        glRotatef(-90,1,0,0); //alinhar o objeto 3ds com os eixos, deixando ele para cima de acordo com o eixo Y
        glTranslatef(0,0,0); //trazer objeto 3ds para origem
        //
        glScalef(0.003,0.003,0.003); //apenas para conseguir enxergar o objeto 3ds

        model->draw();
    glPopMatrix();
}
