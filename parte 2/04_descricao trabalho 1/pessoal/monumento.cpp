#include "monumento.h"

Monumento::Monumento() : Objeto(2){

}

Monumento::Monumento(Vetor3D nt, Vetor3D na, Vetor3D ns) : Objeto(2){
    //atributos herdados de OBJETO
    t = nt;
    a = na;
    s = ns;
    origem = false;
}

void Monumento::monumento()
{
    //face frente
    glBegin(GL_QUADS);
        glNormal3f(0,0,1);
        glVertex3f(0,0,1);
        glVertex3f(1,0,1);
        glVertex3f(1,3,1);
        glVertex3f(0,3,1);
    glEnd();
    //face tras
    glBegin(GL_QUADS);
        glNormal3f(0,0,-1);
        glVertex3f(0,0,0);
        glVertex3f(0,3,0);
        glVertex3f(1,3,0);
        glVertex3f(1,0,0);
    glEnd();
    //face direita
    glBegin(GL_QUADS);
        glNormal3f(1,0,0);
        glVertex3f(1,0,1);
        glVertex3f(1,0,0);
        glVertex3f(1,3,0);
        glVertex3f(1,3,1);
    glEnd();
    //face esquerda
    glBegin(GL_QUADS);
        glNormal3f(-1,0,0);
        glVertex3f(0,0,1);
        glVertex3f(0,3,1);
        glVertex3f(0,3,0);
        glVertex3f(0,0,0);
    glEnd();
    //face superior
    glBegin(GL_QUADS);
        glNormal3f(0,1,0);
        glVertex3f(0,3,0);
        glVertex3f(0,3,1);
        glVertex3f(1,3,1);
        glVertex3f(1,3,0);
    glEnd();
    //face inferior
    glBegin(GL_QUADS);
        glNormal3f(0,-1,0);
        glVertex3f(0,0,0);
        glVertex3f(1,0,0);
        glVertex3f(1,0,1);
        glVertex3f(0,0,1);
    glEnd();


    //parte de cima do monumento

    glPushMatrix();
        glTranslatef(0,1,0);
        glRotatef(-90,0,1,0);
        glRotatef(-45,1,0,0);
        glScalef(1,1.4,1);
        //GUI::drawOrigin(0.5);
        glBegin(GL_POLYGON);
            glNormal3f(0,0,1);
            glVertex3f(0,0,0);
            glVertex3f(1,0,0);
            glVertex3f(0.5,0.5,0);
        glEnd();
    glPopMatrix();
    //frente
    glBegin(GL_POLYGON);
        glNormal3f(0,3,1);
        glVertex3f(0,3,1);
        glVertex3f(1,3,1);
        glVertex3f(0.5,3.5,0.5);
    glEnd();
    //tras
    glBegin(GL_POLYGON);
        glNormal3f(0,3,-1);
        glVertex3f(1,3,0);
        glVertex3f(0,3,0);
        glVertex3f(0.5,3.5,0.5);
    glEnd();
    //direita
    glBegin(GL_POLYGON);
        glNormal3f(1,3,0);
        glVertex3f(1,3,1);
        glVertex3f(1,3,0);
        glVertex3f(0.5,3.5,0.5);
    glEnd();

    //esquerda
    glBegin(GL_POLYGON);
        glNormal3f(-1,3,0);
        glVertex3f(0,3,0);
        glVertex3f(0,3,1);
        glVertex3f(0.5,3.5,0.5);
    glEnd();

}

void Monumento::desenha()
{
    glPushMatrix();
        Objeto::desenha();

        if (selecionado) {
            GUI::setColor(0,1,1);

        } else {
            GUI::setColor(0.9,1,0.9);
        }
        glScalef( 0.8, 1.1, 0.8);

        monumento();

    glPopMatrix();

}
