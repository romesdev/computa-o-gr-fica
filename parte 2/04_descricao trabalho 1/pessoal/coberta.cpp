#include "coberta.h"
#include "gui.h"

Coberta::Coberta() : Objeto(1){
    model = new Model3DS("../3ds/tent.3DS");
}

Coberta::Coberta(Vetor3D nt, Vetor3D na, Vetor3D ns) : Objeto(1){
    //atributos herdados de OBJETO
    t = nt;
    a = na;
    s = ns;
    model = new Model3DS("../3ds/tent.3DS");
    origem = false;
}

void Coberta::desenha()
{
    glPushMatrix();
        Objeto::desenha();

        if (selecionado) {
            glEnable(GL_CULL_FACE);
            GUI::setColor(0,1,1);
        }
        else{
            //rgb(194, 194, 163)
            GUI::setColor( 0.76, 0.76, 0.63);
        }

        glScalef(1,1,1.2); //ajuste final da escala, podendo ser não-uniforme, independente para cada eixo
        glRotatef(-90,1,0,0); //alinhar o objeto 3ds com os eixos, deixando ele para cima de acordo com o eixo Y
        glTranslatef(0,0,0); //trazer objeto 3ds para origem
        //
        glScalef(0.00099,0.00199,0.00099); //apenas para conseguir enxergar o objeto 3ds

        model->draw();
    glPopMatrix();
}
