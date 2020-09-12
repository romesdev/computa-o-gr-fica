#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#include "CameraDistante.h"
#include "CameraJogo.h"
#include <gui.h>
#include <vector>

#include <objeto.h>
#include <base.h>
#include <monumento.h>
#include <carro.h>
#include <coberta.h>
#include <banco.h>
#include <monumento.h>
#include <estatua.h>

//Model3DS model3ds("../3ds/cartest.3DS");

Camera* cam;
vector<Objeto*> objetos;
int posSelecionado = -1;

void desenha() {
    GUI::displayInit();

    GUI::setLight(1,1,3,5,true,false);
    GUI::setLight(2,-1.5,0.5,-1,true,false);
    //GUI::setLight(3,-5,3,5,true,false);

    GUI::drawOrigin(1);

    GUI::setColor(0.9,1.0,0.9); // rgb (230, 255, 230)
    GUI::drawFloor(19,19);

    for (int i = 0; i < objetos.size(); ++i) {
        glPushMatrix();
            objetos[i]->desenha();
        glPopMatrix();
    }

    if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
        objetos[posSelecionado]->t.x += glutGUI::dtx;
        objetos[posSelecionado]->t.y += glutGUI::dty;
        objetos[posSelecionado]->t.z += glutGUI::dtz;

        objetos[posSelecionado]->a.x += glutGUI::dax;
        objetos[posSelecionado]->a.y += glutGUI::day;
        objetos[posSelecionado]->a.z += glutGUI::daz;

        objetos[posSelecionado]->s.x += glutGUI::dsx;
        objetos[posSelecionado]->s.y += glutGUI::dsy;
        objetos[posSelecionado]->s.z += glutGUI::dsz;
    }

    GUI::displayEnd();
}

bool incluirObjeto = false;

void proximoSelecao(){//seleciona o próximo objeto
    if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
        objetos[posSelecionado]->selecionado = false;
    }

    posSelecionado++;
    posSelecionado = posSelecionado%objetos.size();

    if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
        objetos[posSelecionado]->selecionado = true;
    }
}


void voltarSelecao(){
    if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
        objetos[posSelecionado]->selecionado = false;
    }

    posSelecionado--;

    if (posSelecionado < 0) {
        posSelecionado = objetos.size()-1;
    }
    if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
        objetos[posSelecionado]->selecionado = true;
    }
}

void desabilitarSelecao(){

    if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
        objetos[posSelecionado]->selecionado = false;
    }
    glutGUI::trans_obj = false;
}


void deletarSelecionado(){
    if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
        objetos.erase(objetos.begin()+posSelecionado);
    }
}

void deletarUltimo(){
    if(objetos.size() >0 ){
        objetos.pop_back();
    }
}

void origem(){//mudar o estado de visualização da origem
    if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
        objetos[posSelecionado]->origem = !objetos[posSelecionado]->origem;
    }
}

void salvar(){//salvar dados do projeto em um arquivo
    ofstream arq("cenario.txt");
    arq.clear();
    arq << objetos.size() << "\n";
    for (int i = 0; i < objetos.size();i++) {
        arq << objetos[i]->tipo << "\n";
        arq << objetos[i]->t.x << "\n";
        arq << objetos[i]->t.y << "\n";
        arq << objetos[i]->t.z << "\n";
        arq << objetos[i]->a.x << "\n";
        arq << objetos[i]->a.y << "\n";
        arq << objetos[i]->a.z << "\n";
        arq << objetos[i]->s.x << "\n";
        arq << objetos[i]->s.y << "\n";
        arq << objetos[i]->s.z << "\n";
    }
}
void carregar(){
    ifstream arq("cenario.txt");
    string linha;
    getline(arq,linha);
    int n_obj = std::stoi (linha);
    int tipo;
    double tx, ty, tz, ax, ay, az, sx, sy, sz;
    for( int i = 0; i < n_obj; i++ ){
      getline(arq,linha);
      tipo = std::stoi (linha);
      getline(arq,linha);
      tx = std::stof(linha);
      getline(arq,linha);
      ty = std::stof(linha);
      getline(arq,linha);
      tz = std::stof(linha);
      getline(arq,linha);
      ax = std::stof(linha);
      getline(arq,linha);
      ay = std::stof(linha);
      getline(arq,linha);
      az = std::stof(linha);
      getline(arq,linha);
      sx = std::stof(linha);
      getline(arq,linha);
      sy = std::stof(linha);
      getline(arq,linha);
      sz = std::stof(linha);
      Vetor3D tn = Vetor3D(tx,ty,tz);
      Vetor3D an = Vetor3D(ax,ay,az);
      Vetor3D sn = Vetor3D(sx,sy,sz);
      if( tipo == 1 ){
        objetos.push_back( new Coberta(tn, an, sn) );
      }else if( tipo == 2 ){
        objetos.push_back( new Monumento(tn, an, sn) );
      }
      else if( tipo == 3 ){
              objetos.push_back( new Base(tn, an, sn) );
            }
      else if( tipo == 4 ){
              objetos.push_back( new Estatua(tn, an, sn) );
            }
      else if( tipo == 5 ){
              objetos.push_back( new Banco(tn, an, sn) );
            }

    }
}

void carregarNovamente(){
    objetos.clear();
    carregar();
    glutGUI::trans_obj = false;
}


void teclado(unsigned char key, int x, int y) {
    //if (!incluirObjeto) {
        GUI::keyInit(key,x,y);
    //}



    switch (key) {
    //case 'c': por padrão vai para a camera padrao

    case 't'://habilitar transformações no objeto selecionado
        glutGUI::trans_obj = !glutGUI::trans_obj;
        break;
    case 'l':
        glutGUI::trans_luz = !glutGUI::trans_luz;
        break;
    case 'a': //habilitar adição de objetos no cenário.
        incluirObjeto = !incluirObjeto;
        break;
    case 'p': //selecionar um objeto. podendo pecorrer todos os objetos.
        proximoSelecao();
        break;
    case 'v': //voltar para o objeto selecionado anteriormente.
        voltarSelecao();
        break;
    case 'd'://deletar o objeto selecionado
        deletarSelecionado();
        break;
    case 'u'://deletar o ultimo objeto
        deletarUltimo();
        break;
    case '?'://mudar o estado da visualização da origem
        origem();
        break;
    case '+':
        if (incluirObjeto) {
            objetos.push_back( new Base() );
        }
        break;
    case '-':
        if (incluirObjeto) {
            objetos.push_back( new Coberta() );
        }
        break;
    case 'm':
        if (incluirObjeto) {
            objetos.push_back( new Monumento() );
        }
        break;
    case 'b':
        if (incluirObjeto) {
            objetos.push_back( new Banco() );
        }
        break;
    case '/':
        if (incluirObjeto) {
            objetos.push_back( new Estatua() );
        }
        break;
    case 'f':
        desabilitarSelecao();

    //comandos para a camera
     case '1'://camera visando a ponta do monumento
            glutGUI::cam = new CameraJogo(4, 0 , 5, 5, 3 , 0, 0,1,0);
            break;

    case '2'://visão da estatua e o monomento
            glutGUI::cam = new CameraDistante(-5, 0, 3, 5, 3, 0, 0, 1, 0);
            break;

    case '3'://olhando a silhueta da estatua
           glutGUI::cam = new CameraJogo(-1, 0 , -1, 3, 1, 0, 0,1,0);
           break;

   case '4'://visão da cobertura
           glutGUI::cam = new CameraDistante(-3, 0.5, 5, -5, 1, -1, 0, 1, 0);
           break;
    case '5'://ponta do monumento de outro angulo
           glutGUI::cam = new CameraJogo(8, 0 , 5,  5, 3 , 0, 0,1,0);
           break;

   case '6'://visão estatua e cobertura
           glutGUI::cam = new CameraDistante(7, 0.5, 3, -5, 3, 0, 0, 1, 0);
           break;


    case '0':
           salvar();
           break;
    case '.':
        carregarNovamente();
        break;
    default:
        break;
    }
}

int main(){
    cout << "Hello World!" << endl;
    carregar();
    GUI gui = GUI(800,600,desenha,teclado);
}

