#include "base.h"

Base::Base() : Objeto(3){

}

Base::Base(Vetor3D nt, Vetor3D na, Vetor3D ns) : Objeto(3){
    //atributos herdados de OBJETO
    t = nt;
    a = na;
    s = ns;
    origem = false;
}

void Base::base(){

    glPushMatrix();

             glPushMatrix();
                //rgb(102, 53, 0)
                //GUI::setColor(0.4,0.207, 0);

                glBegin(GL_POLYGON);
                        glNormal3f(5,6.25,5);
                        glVertex3f( 1.5, 0, 0);
                        glVertex3f( 0, 1, 0);
                        glVertex3f( 0, 0, 1.5);
                glEnd();
                glBegin(GL_POLYGON);
                        glNormal3f(-5,5,4);
                        glVertex3f( 0, 0, 1.5);
                        glVertex3f( 0, 1, 0);
                        glVertex3f( -1.5, 0, 0);
                glEnd();
                glBegin(GL_POLYGON);
                        glNormal3f( 5, 6.25, -5);
                        glVertex3f( 0, 0, -1.5);
                        glVertex3f( 0, 1, 0);
                        glVertex3f( 1.5, 0, 0);
                glEnd();
                glBegin(GL_POLYGON);
                        glNormal3f( -5, 6.25, -5);
                        glVertex3f(-1.5,0,0);
                        glVertex3f( 0, 1, 0);
                        glVertex3f( 0, 0, -1.5);
                glEnd();
                glBegin(GL_POLYGON);
                        glNormal3f( 0, -1, 0);
                        glVertex3f( 0, 0, 1.5);
                        glVertex3f( -1.5, 0, 0);
                        glVertex3f( 0, 0, -1.5);
                        glVertex3f( 1.5, 0, 0);
                        glVertex3f( 0, 0, 1.5);
                glEnd();
            glPopMatrix();


}



void Base::desenha(){

    glPushMatrix();
        Objeto::desenha();

        if (selecionado) {
            GUI::setColor(0,1,1);

        } else {
             GUI::setColor(0.4,0.207, 0);
        }
        //glScalef( 0.8, 1.1, 0.8);
        glRotatef(-180,0,0,1);
        glScalef( 1, 0.7, 1);
        glTranslatef(0,-1,0);
        base();

    glPopMatrix();


}
