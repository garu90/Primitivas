#include "glvisual.h"

glvisual::glvisual()
{
}


glvisual::~glvisual()
{

}


void glvisual::initializeGL()
{

    glShadeModel(GL_SMOOTH);
    qglClearColor(Qt::black);

    glClearDepth(1.0f);		// Depth Buffer Setup
    glDepthFunc(GL_LEQUAL); //Depth function
    glEnable(GL_DEPTH_TEST);

    glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);
}


void glvisual::resizeGL(int w, int h)
{
    width=w;
    height=h;

    //qDebug()<<width/2<<height/2;

    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f,width,0.0f,height,-1.0f,1.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void glvisual::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    draw();
}

void glvisual::draw()
{
    glBegin(GL_LINES);
    glVertex2d(0,100);
    glVertex2d(100,100);
    glEnd();

}