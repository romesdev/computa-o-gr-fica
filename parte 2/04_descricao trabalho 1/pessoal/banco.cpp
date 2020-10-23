#include "banco.h"

Banco::Banco() : Objeto(5){
    model = new Model3DS("../3ds/banco.3DS");
}

//construtor com a passagem dos vetores (modificando o valor que já está definido em objeto)
Banco::Banco(Vetor3D nt, Vetor3D na, Vetor3D ns) : Objeto(5){
    //atributos herdados de OBJETO
    t = nt;
    a = na;
    s = ns;
    origem = false;
    model = new Model3DS("../3ds/banco.3DS");

}

void Banco::desenha()
{
    glPushMatrix();
        Objeto::desenha();

        if (selecionado) {
            glEnable(GL_CULL_FACE);
            //GUI::drawBox(-1,-1,-1, 1,1,1, true);
            GUI::setColor(0,1,1);//azul para mostrar a seleção

        }
        else{
             //rgb(245, 245, 240)
             GUI::setColor( 0.96, 0.96, 0.94);
        }
        glScalef(1,1,1.2); //ajuste final da escala, podendo ser não-uniforme, independente para cada eixo
        glRotatef(-90,1,0,0); //alinhar o objeto 3ds com os eixos, deixando ele para cima de acordo com o eixo Y
        glTranslatef(0,0,0); //trazer objeto 3ds para origem
        //
        glScalef(0.06,0.06,0.06); //apenas para conseguir enxergar o objeto 3ds
        model->draw();
    glPopMatrix();
}
