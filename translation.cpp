#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;
void init()
{
    glClearColor(1, 1, 1, 1.0);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500, 500.0, -500.0, 500.0);
}
void makeTriangle(float x1, float y1, float x2, float y2, float x3, float y3)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 1.0);
    glBegin(GL_POINTS);
    float m1 = float(y2 - y1) / (x2 - x1);
    float m2 = float(y3 - y2) / (x3 - x2);
    float m3 = float(y1 - y3) / (x1 - x3);
    float c1 = y1 - m1 * x1;
    float c2 = y2 - m2 * x2;
    float c3 = y3 - m3 * x3;
    int i = 0;
    while (x1 + i <= x2)
    {
        glVertex2f(x1 + i, m1 * (x1 + i) + c1);
        i++;
    }
    i = 0;
    while (x2 + i <= x3)
    {
        glVertex2f(x2 + i, m2 * (x2 + i) + c2);
        i++;
    }
    i = 0;
    while (x3 - i >= x1)
    {
        glVertex2f(x3 - i, m3 * (x3 - i) + c3);
        i++;
    }
}
void translate(float x1, float y1, float x2, float y2, float x3, float y3, float xp, float yp)
{
    glClear(GL_COLOR_BUFFER_BIT);
    x1 = x1 + xp;
    x2 = x2 + xp;
    x3 = x3 + xp;
    y1 = y1 + yp;
    y2 = y2 + yp;
    y3 = y3 + yp;
    makeTriangle(x1, y1, x2, y2, x3, y3);
}
void rotation(float x1, float y1, float x2, float y2, float x3, float y3)
{
    translate(x1, y1, x2, y2, x3, y3, -x1, -y1);
    float th = 10 * 3.14159 / 180;
    float new_x1 = (x1 - x1) * cos(th) - (y1 - y1) * sin(th);
    float new_y1 = (x1 - x1) * sin(th) + (y1 - y1) * cos(th);
    float new_x2 = (x2 - x1) * cos(th) - (y2 - y1) * sin(th);
    float new_y2 = (x2 - x1) * sin(th) + (y2 - y1) * cos(th);
    float new_x3 = (x3 - x1) * cos(th) - (y3 - y1) * sin(th);
    float new_y3 = (x3 - x1) * sin(th) + (y3 - y1) * cos(th);
    cout << new_x1 << "" << new_y1 << "" << new_x2 << "" << new_y2 << "" << new_x3 << "" << new_y3;
    makeTriangle(new_x1, new_y1, new_x2, new_y2, new_x3, new_y3);
    translate(new_x1, new_y1, new_x2, new_y2, new_x3, new_y3, 150, 150);
    glEnd();
    glColor3f(0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(-500, 0);
    glVertex2f(500, 0);
    glBegin(GL_LINES);
    glVertex2f(0, -500);
    glVertex2f(0, 500);
    glEnd();
    glFlush();
}
void display()
{
    makeTriangle(150, 150, 180.0, 220.0, 250.0, 100.0);
    rotation(150, 150, 180.0, 220.0, 250.0, 100.0);
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Rotation");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}