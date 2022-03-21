#include <GL/glut.h>

void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 200.0, 0.0, 200.0);
}
void DDA(void)
{
    float x1 = 20, y1 = 20, x2 = 100, y2 = 100;
    glClear(GL_COLOR_BUFFER_BIT);
    float dy, dx, step, x, y, k, Xin, Yin;
    dx = x2 - x1;
    dy = y2 - y1;
    if (abs(dx) > abs(dy))
    {
        step = abs(dx);
    }
    else
        step = abs(dy);
    Xin = dx / step;
    Yin = dy / step;
    x = x1;
    y = y1;
    glBegin(GL_POINTS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(x, y);
    for (k = 1; k <= step; k++)
    {
        x = x + Xin;
        y = y + Yin;
        glVertex2i(x, y);
    }
    glEnd();
    glFlush();
}
void Breshnam(void)
{
    int x1 = 20, y1 = 20, x2 = 100, y2 = 100, x, y;
    x = x1;
    y = y1;
    int dx, dy, pk, k, y_inc;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    dx = x2 - x1;
    dy = y2 - y1;
    pk = 2 * dy - dx;

    for (k = 0; k < abs(dx); k++)
    {
        if (pk < 0)
            pk = pk + 2 * dy;
        else
        {
            pk = pk + 2 * dy - 2 * dx;
            y = y + 1;
        }
        x++;
        glVertex2f(x, y);
    }
    glEnd();
    glFlush();
}

void polygon()
{
    glColor3f(1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glVertex2d(70, 70);
    glVertex2d(100, 150);
    glVertex2d(200, 40);
    glEnd();
    glFlush();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowPosition(10, 10);
    glutInitWindowSize(500, 500);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Triangle on Black bg");
    init();
    glutDisplayFunc(polygon);
    glutMainLoop();
}
