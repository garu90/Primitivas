#include "primitives.h"

primitives::primitives()
{
}


double primitives::filter(int distance)
{
    //0.5 ->desviación estandar pendiente calcular
    //return exp(-distance)/(2*0.5);
    return 0.5999+0.120*distance+0.6819*(distance*distance)+0.2824*(distance*distance*distance);
}


void primitives::intensifyPixel(int x, int y, double distance)
{
    double intensity=filter(distance);
    glColor3f(intensity,intensity,intensity);
}


point2D::point2D()
{
    this->x=0;
    this->y=0;
}

point2D::point2D(int x, int y)
{
    this->x=x;
    this->y=y;
}

void point2D::setpoint(int x, int y)
{
    this->x=x;
    this->y=y;
}

void point2D::setX(int x)
{
    this->x=x;
}

void point2D::setY(int y)
{
    this->y=y;
}

int point2D::getx()
{
    return x;
}

int point2D::gety()
{
    return y;
}

void point2D::draw()
{
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}



void point2D::drawPixel2D(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}






line::line()
{
    v1.setpoint(0,0);
    v2.setpoint(0,0);
}

line::line(point2D v1, point2D v2)
{
    this->v1=v1;
    this->v2=v2;
}

line::line(int x1, int y1, int x2, int y2)
{
    this->v1.setX(x1);
    this->v1.setY(y1);

    this->v2.setX(x2);
    this->v2.setY(y2);

}

void line::drawLine()
{
    int x0=v1.getx();
    int x1=v2.getx();

    int y0=v1.gety();
    int y1=v2.gety();


    double dx=x1-x0;
    double dy=y1-y0;

    double m= dy/dx;
    float y=y0;
    float x;

    if(m<=1)
    {
        if(dx!=0)
        {

            if(x1>=x0)
            {
                for(x=x0;x<x1;x+=1)
                {
                    drawPixel2D(x,floor(y+0.5));
                    y+=m;
                }
            }
            else
            {
                for(x=x0;x>x1;x--)
                {
                    drawPixel2D(x,floor(y+0.5));
                    y-=m;
                }
            }

        }
        else
        {
            x=x0;
            if(y1>=y0)
            {
                for(y=y0;y<y1;y++)
                {
                    drawPixel2D(x,floor(y+0.5));
                    y++;
                }
            }
            else
            {
                for(y=y0;y>y1;y--)
                {
                    drawPixel2D(x,floor(y+0.5));
                    y--;
                }
            }

        }

    }
    else //m>1
    {
        if(dx!=0)
        {
            x=x0;
            if(y1>=y0)
            {
                for(y=y0;y<y1;y++)
                {
                    drawPixel2D(floor(x+0.5),y);
                    x+=(float)(1.0/m);
                }
            }
            else
            {
                for(y=y0;y>y1;y--)
                {
                    drawPixel2D(floor(x+0.5),y);
                    x-=(float)(1.0/m);
                }
            }

        }
        else
        {
            x=x0;

            for(y=y0;y<y1;y++)
            {
                drawPixel2D(round(x+0.5),y);
                y++;

            }
        }

    }

}
















