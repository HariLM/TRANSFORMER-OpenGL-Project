#ifndef ELLIPSE_H
#define ELLIPSE_H
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>
class Ellipse
{
private:
    float color[3];
    int depthIndex;

public:
    void setColor(float r, float g, float b)
    {
        color[0] = r;
        color[1] = g;
        color[2] = b;
    }
    void draw(int xCenter, int yCenter, int Rx, int Ry, int depthIndex, bool hollow, int startAngle, int stopAngle)
    {
        glPushMatrix();
        glTranslatef(xCenter, yCenter, 0);
        glColor3fv(color);
        if (hollow)
            glBegin(GL_POINTS);
        else if (!hollow)
            glBegin(GL_POLYGON);
        for (float i = startAngle; i <= stopAngle; i++)
        {
            float x = Rx * cos((i * 3.142) / 180);
            float y = Ry * sin((i * 3.142) / 180);
            glVertex3f(x, y, depthIndex);
        }
        glEnd();
        glPopMatrix();
    }
    void draw(int xCenter, int yCenter, int Rx, int Ry, int depthIndex, bool hollow, int startAngle, int stopAngle, int lineWidth)
    {
        glPushMatrix();
        glTranslatef(xCenter, yCenter, 0);
        glColor3fv(color);
        glPointSize(lineWidth);
        if (hollow)
            glBegin(GL_POINTS);
        else if (!hollow)
            glBegin(GL_POLYGON);
        for (float i = startAngle; i <= stopAngle; i++)
        {
            float x = Rx * cos((i * 3.142) / 180);
            float y = Ry * sin((i * 3.142) / 180);
            glVertex3f(x, y, depthIndex);
        }
        glEnd();
        glPopMatrix();
    }
};
#endif /* ELLIPSE_H */