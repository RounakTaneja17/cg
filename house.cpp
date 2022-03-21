#include <GL/glut.h>

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}
void buildHouse(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glColor3f(0.5, 1.0, 1.0);
    glVertex2i(50, 0);
    glVertex2i(50, 100);
    glVertex2i(150, 100);
    glVertex2i(150, 0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2i(60, 80);
    glVertex2i(80, 80);
    glVertex2i(80, 65);
    glVertex2i(60, 65);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2i(120, 80);
    glVertex2i(140, 80);
    glVertex2i(140, 65);
    glVertex2i(120, 65);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2i(50, 100);
    glColor3f(0.5, 0.0, 0.3);
    glVertex2i(150, 100);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2i(100, 130);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2i(80, 0);
    glVertex2i(80, 50);
    glVertex2i(120, 50);
    glVertex2i(120, 0);
    glEnd();
    glFlush();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("House");
    init();
    glutDisplayFunc(buildHouse);
    glutMainLoop();
    return 0;
}
