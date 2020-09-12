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



//    glPushMatrix();

//            //Objeto::desenha();
//            glPushMatrix();
//                GUI::setColor(0.81,0.71, 0.23);
//                Vetor3D v1, v2, v3, normal;
//                glBegin(GL_POLYGON);
//                        glNormal3f(5,6.25,5);
//                        //glVertex3f(2.5,0,0);
//                        //glVertex3f(0,2,0);
//                        //glVertex3f(0,0,2.5);

//                        glVertex3f(2.5,0,0);
//                        glVertex3f(0,2,0);
//                        glVertex3f(0,0,2.5);
//                glEnd();
//                glBegin(GL_POLYGON);
//                        glNormal3f(-5,5,4);
//                        glVertex3f(0,0,2.5);
//                        glVertex3f(0,2,0);
//                        glVertex3f(-2.5,0,0);
//                glEnd();
//                glBegin(GL_POLYGON);
//                        glNormal3f(5,6.25,-5);
//                        glVertex3f(0,0,-2.5);
//                        glVertex3f(0,2,0);
//                        glVertex3f(2.5,0,0);
//                glEnd();
//                glBegin(GL_POLYGON);
//                        glNormal3f(-5,6.25,-5);
//                        glVertex3f(-2.5,0,0);
//                        glVertex3f(0,2,0);
//                        glVertex3f(0,0,-2.5);
//                glEnd();
//                glBegin(GL_POLYGON);
//                        glNormal3f(0,-1,0);
//                        glVertex3f(0,0,2.5);
//                        glVertex3f(-2.5,0,0);
//                        glVertex3f(0,0,-2.5);
//                        glVertex3f(2.5,0,0);
//                        glVertex3f(0,0,2.5);
//                glEnd();
//            glPopMatrix();




//    // Lado branco - TRASEIRA
//    glBegin(GL_POLYGON);
//    glColor3f(   1.0,  1.0, 1.0 );
//    glVertex3f(  0.5, -0.5, 0.5 );
//    glVertex3f(  0.5,  0.5, 0.5 );
//    glVertex3f( -0.5,  0.5, 0.5 );
//    glVertex3f( -0.5, -0.5, 0.5 );
//    glEnd();

//    // Lado roxo - DIREITA
//    glBegin(GL_POLYGON);
//    glColor3f(  1.0,  0.0,  1.0 );
//    glVertex3f( 0.5, -0.5, -0.5 );
//    glVertex3f( 0.5,  0.5, -0.5 );
//    glVertex3f( 0.5,  0.5,  0.5 );
//    glVertex3f( 0.5, -0.5,  0.5 );
//    glEnd();

//    // Lado verde - ESQUERDA
//    glBegin(GL_POLYGON);
//    glColor3f(   0.0,  1.0,  0.0 );
//    glVertex3f( -0.5, -0.5,  0.5 );
//    glVertex3f( -0.5,  0.5,  0.5 );
//    glVertex3f( -0.5,  0.5, -0.5 );
//    glVertex3f( -0.5, -0.5, -0.5 );
//    glEnd();

//    // Lado azul - TOPO
//    glBegin(GL_POLYGON);
//    glColor3f(   0.0,  0.0,  1.0 );
//    glVertex3f(  0.5,  0.5,  0.5 );
//    glVertex3f(  0.5,  0.5, -0.5 );
//    glVertex3f( -0.5,  0.5, -0.5 );
//    glVertex3f( -0.5,  0.5,  0.5 );
//    glEnd();

//    // Lado vermelho - BASE
//    glBegin(GL_POLYGON);
//    glColor3f(   1.0,  0.0,  0.0 );
//    glVertex3f(  0.5, -0.5, -0.5 );
//    glVertex3f(  0.5, -0.5,  0.5 );
//    glVertex3f( -0.5, -0.5,  0.5 );
//    glVertex3f( -0.5, -0.5, -0.5 );
//    glEnd();

//    //glFlush();
//    //glutSwapBuffers();

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

//    glPushMatrix();
//        Objeto::desenha();

//        glScalef(0.7,0.7,0.7);
//        glRotatef(0,1,0,0);
//        glTranslatef(0,0,0);
//        glScalef(1,1,1);
//        //pelvis
//        glPushMatrix();
//            //transformacoes influenciam todo o escopo push/pop
//            glTranslatef(0,-1,0);
//            glRotatef(0,1,0,0);
//            GUI::drawOrigin(0.5);
//            //modelo
//            if (selecionado) {
//                GUI::setColor(1,0,0);
//            } else {
//                GUI::setColor(0,0,1);
//            }
//            GUI::drawBox(-0.5,0.0,-0.5, 0.5,0.5,0.5);

//            //tronco
//            glPushMatrix();
//                glTranslatef(0,0.5,0);
//                glRotatef(glutGUI::lx,1,0,0);
//                GUI::drawOrigin(0.5);
//                //modelo
//                if (selecionado) {
//                    GUI::setColor(0.5,0.5,0.5);
//                } else {
//                    GUI::setColor(1,0,0);
//                }
//                GUI::drawBox(-0.5,0.0,-0.5, 0.5,1.5,0.5);

//                //braco direito
//                glPushMatrix();
//                    //transformacoes influenciam apenas localmente (escopo push/pop mais interno)
//                    glTranslatef(0.5,1.5,0);
//                    glRotatef(glutGUI::ly,0,0,1);
//                    GUI::drawOrigin(0.5);
//                    //modelo
//                    if (selecionado) {
//                        GUI::setColor(1,0,0);
//                    } else {
//                        GUI::setColor(0,1,0);
//                    }
//                    glTranslatef(1,0,0);
//                    GUI::drawBox(-1.0,0.0,-0.1, 1.0,0.2,0.1);
//                glPopMatrix();

//                //braco esquerdo
//                glPushMatrix();
//                    glTranslatef(-0.5,1.5,0);
//                    glRotatef(45,0,0,1);
//                    GUI::drawOrigin(0.5);
//                    //modelo
//                    if (selecionado) {
//                        GUI::setColor(1,0,0);
//                    } else {
//                        GUI::setColor(0,1,0);
//                    }
//                    glTranslatef(-1,0,0);
//                    GUI::drawBox(-1.0,0.0,-0.1, 1.0,0.2,0.1);
//                glPopMatrix();
//            glPopMatrix();
//        glPopMatrix();

//    glPopMatrix();
}
