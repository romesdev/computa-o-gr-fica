TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += bib
INCLUDEPATH += gui_glut
INCLUDEPATH += pessoal

LIBS += -lGL -lGLU -lglut -l3ds -lSDL_image

SOURCES += main.cpp \
    bib/Camera.cpp \
    bib/CameraDistante.cpp \
    bib/CameraJogo.cpp \
    bib/Desenha.cpp \
    bib/model3ds.cpp \
    bib/Vetor3D.cpp \
    gui_glut/extra.cpp \
    gui_glut/gui.cpp \
    pessoal/banco.cpp \
    pessoal/base.cpp \
    pessoal/coberta.cpp \
    pessoal/estatua.cpp \
    pessoal/monumento.cpp \
    pessoal/objeto.cpp \
    pessoal/carro.cpp

HEADERS += \
    bib/Camera.h \
    bib/CameraDistante.h \
    bib/CameraJogo.h \
    bib/Desenha.h \
    bib/model3ds.h \
    bib/Vetor3D.h \
    gui_glut/extra.h \
    gui_glut/gui.h \
    pessoal/banco.h \
    pessoal/base.h \
    pessoal/coberta.h \
    pessoal/estatua.h \
    pessoal/monumento.h \
    pessoal/objeto.h \
    pessoal/carro.h
