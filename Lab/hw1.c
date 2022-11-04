/*
#ifdef __APPLE__
#include <GLUT/GLUT.h>
#include <OpenGL/gl.h>
#else
#include <GLUT/GLUT.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sides = 3;
float r = 0.4, g = 0.4, b = 0.4;

void changingShapes(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1, 0, 0);
    glBegin(GL_LINE_LOOP);
         for(int i = 0; i <= 360; i++){
             float angle = 2 * 3.14 * i / 360;
             float x = 0.8 * cos(angle);
             float y = 0.8 * sin(angle);
             glVertex2d(x,y);
         }
    glEnd();
    if(sides > 2) {
        glColor3d(r, g, b);
        glBegin(GL_POLYGON);
             for(int i = 1; i <= sides; i++){
                 float angle = 2 * 3.14 * i / sides;
                 float x = 0.8 * cos(angle);
                 float y = 0.8 * sin(angle);
                 glVertex2d(x,y);
             }
        glEnd();
    }
    glutSwapBuffers();
}

void sideChange(int key, int x, int y) {
    if(key == GLUT_KEY_UP) {
        sides++;
        glutPostRedisplay();
    } else if(key == GLUT_KEY_DOWN) {
        if(sides > 3) {
            sides--;
            glutPostRedisplay();
        }
    }
}

void colorChange(unsigned char key, int x, int y) {
    if(key == 'r') {
        if(r > 1) {
            r = 0;
        }
        r = r + 0.2;
        glutPostRedisplay();
    } else if (key == 'g') {
        if(g > 1) {
            g = 0;
        }
        g = g + 0.2;
        glutPostRedisplay();
    } else if (key == 'b') {
        if(b > 1) {
            b = 0;
        }
        b = b + 0.2;
        glutPostRedisplay();
    }
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Draw Polygon");
    
    glutDisplayFunc(changingShapes);
    glutSpecialFunc(sideChange);
    glutKeyboardFunc(colorChange);
    
    glutMainLoop();
    return EXIT_SUCCESS;
}

*/
