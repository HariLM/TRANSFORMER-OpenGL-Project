#ifndef CIRCLE_H
#define CIRCLE_H
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>
class Circle
{
private:
    int depthIndex;
    float color[3];

public:
    void setColor(float r, float g, float b)
    {
        color[0] = r;
        color[1] = g;
        color[2] = b;
    }
    void draw(int r, float xpos, float ypos, int depthIndex, bool hollow)
    {
        this->depthIndex = depthIndex;
        glPushMatrix();
        glTranslatef(xpos, ypos, 0);
        glColor3fv(color);
        if (!hollow)
            glBegin(GL_POLYGON);
        else
            glBegin(GL_POINTS);
        for (int i = 0; i <= 360; i++)
        {
            float x = r * cos((i * 3.142) / 180);
            float y = r * sin((i * 3.142) / 180);
            glVertex3f(x, y, depthIndex);
        }
        glEnd();
        glPopMatrix();
    }
};

#endif /* CIRCLE_H */

