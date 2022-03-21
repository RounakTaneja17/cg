#include <GL/glut.h>
#include <iostream>
using namespace std;

float a, b, h, k;
void midptellipse()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0);
    float fx, fy, d1, d2, x, y;
    x = 0;
    y = b;
    d1 = (b * b) - (a * a * b) + (0.25 * a * a);
    fx = 2 * b * b * x;
    fy = 2 * a * a * y;
    while (fx < fy)
    {
        glBegin(GL_POINTS);
        glVertex2i(x + h, y + k);
        glVertex2i(-x + h, y + k);
        glVertex2i(x + h, -y + k);
        glVertex2i(-x + h, -y + k);
        glEnd();
        if (d1 < 0)
        {
            x++;
            fx = fx + (2 * b * b);
            d1 = d1 + fx + (b * b);
        }
        else
        {
            x++;
            y--;
            fx = fx + (2 * b * b);
            fy = fy - (2 * a * a);
            d1 = d1 + fx - fy + (b * b);
        }
    }
    d2 = ((b * b) * ((x + 0.5) * (x + 0.5))) + ((a * a) * ((y - 1) * (y - 1))) - (a * a * b * b);
    while (y >= 0)
    {
        glBegin(GL_POINTS);
        glVertex2i(x + h, y + k);
        glVertex2i(-x + h, y + k);
        glVertex2i(x + h, -y + k);
        glVertex2i(-x + h, -y + k);
        glEnd();
        if (d2 > 0)
        {
            y--;
            fy = fy - (2 * a * a);
            d2 = d2 + (a * a) - fy;
        }
        else
        {
            y--;
            x++;
            fx = fx + (2 * b * b);
            fy = fy - (2 * a * a);
            d2 = d2 + fx - fy + (a * a);
        }
    }
    glFlush();
}
void myinit()
{
    glClearColor(1, 1, 1, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}
int main(int argc, char **argv)
{
    cout << "EnterellipseX-radius:";
    cin >> a;
    cout << "EnterellipseY-radius:";
    cin >> b;
    cout << "EnterellipsecenterX-coordinate:";
    cin >> h;
    cout << "EnterellipsecenterY-coordinate:";
    cin >> k;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Ellipse");
    glutDisplayFunc(midptellipse);
    myinit();
    glutMainLoop();
    return 0;
}