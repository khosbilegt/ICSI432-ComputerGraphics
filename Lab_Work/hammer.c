/*
#ifdef __APPLE__
#include <GLUT/GLUT.h>
#include <OpenGL/gl.h>
#else
#include <GL/glut.h>
#endif

#include <math.h>
#include <stdio.h>
#include <stdlib.h>


void drawHammer(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Handle
    //
    //
    glColor3f(0.5, 0.3, 0.3);
    glBegin(GL_POLYGON);
    glVertex3d(0.15, -0.5, 0);
    glVertex3d(0.05, -0.5, 0);
    glVertex3d(0.15, -0.4, 0);
    glVertex3d(0.25, -0.4, 0);
    glEnd();
    
    glColor3f(0.3, 0.2, 0.2);
    glBegin(GL_POLYGON);
    glVertex3d(0.05, 0, 0);
    glVertex3d(0.15, 0, 0);
    glVertex3d(0.15, -0.5, 0);
    glVertex3d(0.05, -0.5, 0);
    glEnd();
    
    glColor3f(0.5, 0.3, 0.3);
    glBegin(GL_POLYGON);
    glVertex3d(0.15, -0.4, 0);
    glVertex3d(0.25, -0.4, 0);
    glVertex3d(0.25, 0, 0);
    glVertex3d(0.15, 0, 0);
    glEnd();

    
    // Top Right
    //
    //
    glColor3d(0.46, 0.46, 0.46);
    glBegin(GL_POLYGON);
    glVertex3d(0.75, 0.7, -1);
    glVertex3d(0.65, 0.7, 0);
    glVertex3f(0.6, 0.8, 0);
    glVertex3f(0.7, 0.8, 0);
    glEnd();
    
    glColor3d(0.36, 0.36, 0.36);
    glBegin(GL_POLYGON);
    glVertex3f(0.6, 0.8, 0);
    glVertex3f(0.7, 0.8, 0);
    glVertex3f(0.4, 0.4, 0);
    glVertex3f(0.3, 0.4, 0);
    glEnd();
    
    glColor3d(0.1, 0.1, 0.5);
    glBegin(GL_POLYGON);
    glVertex3d(0.4, 0.4, 0);
    glVertex3d(0.3, 0.4, 0);
    glVertex3d(0.25, 0.3, 0);
    glVertex3d(0.35, 0.3, 0);
    glEnd();
    
    // CONNECT
    glColor3d(0.1, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3d(0.25, 0.3, 0);
    glVertex3d(0.35, 0.3, 0);
    glVertex3d(0.35, 0, 0);
    glVertex3d(0.25, 0, 0);
    glEnd();
    
    glColor3d(0.1, 0, 0.1);
    glBegin(GL_POLYGON);
    glVertex3d(0.3, -0.1, 0);
    glVertex3d(0.4, -0.1, 0);
    glVertex3d(0.7, 0.3, 0);
    glVertex3d(0.6, 0.3, -1);
    glEnd();
    
    glColor3d(0.1, 0.1, 0.5);
    glBegin(GL_POLYGON);
    glVertex3d(0.35, 0, 0);
    glVertex3d(0.25, 0, 0);
    glVertex3d(0.3, -0.1, 0);
    glVertex3d(0.4, -0.1, 0);
    glEnd();
    
    glColor3d(0.36, 0.36, 0.36);
    glBegin(GL_POLYGON);
    glVertex3d(0.7, 0.3, 0);
    glVertex3d(0.6, 0.3, -1);
    glVertex3d(0.65, 0.4, 0);
    glVertex3d(0.75, 0.4, -1);
    glEnd();
    
    glColor3d(0.56, 0.56, 0.56);
    glBegin(GL_POLYGON);
    glVertex3d(0.65, 0.4, 0);
    glVertex3d(0.75, 0.4, -1);
    glVertex3d(0.75, 0.7, -1);
    glVertex3d(0.65, 0.7, 0);
    glEnd();
    
    
    // Side
    glColor3d(0.56, 0.56, 0.56);
    glBegin(GL_POLYGON);
    glVertex3f(0.7, 0.8, 0);
    glVertex3d(0.75, 0.7, -1);
    glVertex3d(0.75, 0.4, -1);
    glVertex3d(0.7, 0.3, 0);
    glVertex3d(0.4, -0.1, 0);
    glVertex3d(0.35, 0, 0);
    glVertex3d(0.35, 0.3, 0);
    glVertex3f(0.4, 0.4, 0);
    glEnd();
    //
    //
    //
    
    // Top Left
    //
    //
    glColor3d(0.46, 0.46, 0.46);
    glBegin(GL_POLYGON);
    glVertex3d(0.05, 0.7, -1);
    glVertex3d(0.15, 0.7, 0);
    glVertex3f(0.1, 0.8, 0);
    glVertex3f(0, 0.8, 0);
    glEnd();
    
    glColor3d(0.36, 0.36, 0.36);
    glBegin(GL_POLYGON);
    glVertex3f(0.1, 0.8, 0);
    glVertex3f(0, 0.8, 0);
    glVertex3d(-0.3, 0.4, 0);
    glVertex3d(-0.2, 0.4, 0);
    glEnd();
    
    glColor3d(0.46, 0.46, 0.46);
    glBegin(GL_POLYGON);
    glVertex3d(-0.3, 0.4, 0);
    glVertex3d(-0.2, 0.4, 0);
    glVertex3d(-0.25, 0.3, 0);
    glVertex3d(-0.35, 0.3, 0);
    glEnd();
    
    // CONNECT
    glColor3d(0.46, 0.46, 0.46);
    glBegin(GL_POLYGON);
    glVertex3d(-0.25, 0.3, 0);
    glVertex3d(-0.35, 0.3, 0);
    glVertex3d(-0.35, 0, 0);
    glVertex3d(-0.25, 0, 0);
    glEnd();
    
    
    glColor3d(0.46, 0.46, 0.46);
    glBegin(GL_POLYGON);
    glVertex3d(-0.35, 0, 0);
    glVertex3d(-0.25, 0, 0);
    glVertex3d(-0.2, -0.1, 0);
    glVertex3d(-0.3, -0.1, 0);
    glEnd();
    
    // Side
    glColor3d(0.36, 0.36, 0.36);
    glBegin(GL_POLYGON);
    glVertex3f(0.1, 0.8, 0);
    glVertex3d(0.05, 0.7, -1);
    glVertex3d(0.05, 0.4, -1);
    glVertex3d(0.1, 0.3, 0);
    glVertex3d(-0.2, -0.1, 0);
    glVertex3d(-0.25, 0, 0);
    glVertex3d(-0.25, 0.3, 0);
    glVertex3f(-0.2, 0.4, 0);
    glEnd();
    //
    //
    //
    
    // Mid
    //
    //
    glColor3d(0.36, 0.36, 0.36);
    glBegin(GL_POLYGON);
    glVertex3f(0, 0.8, 0);
    glVertex3d(0.05, 0.7, -1);
    glVertex3d(0.05, 0.4, -1);
    glVertex3d(0, 0.3, 0);
    glVertex3d(-0.3, -0.1, 0);
    glVertex3d(-0.35, 0, 0);
    glVertex3d(-0.35, 0.3, 0);
    glVertex3f(-0.3, 0.4, 0);
    glEnd();
    
    glColor3d(0.36, 0.36, 0.36);
    glBegin(GL_POLYGON);
    glVertex3d(0, 0.8, 0);
    glVertex3d(0.7, 0.8, 0);
    glVertex3d(0.4, 0.4, 0);
    glVertex3d(-0.3, 0.4, 0);
    glEnd();
    
    glColor3d(0.46, 0.46, 0.46);
    glBegin(GL_POLYGON);
    glVertex3d(0.4, 0.4, 0);
    glVertex3d(-0.3, 0.4, 0);
    glVertex3d(-0.35, 0.3, 0);
    glVertex3d(0.35, 0.3, 0);
    glEnd();
    
    glColor3d(0.26, 0.26, 0.26);
    glBegin(GL_POLYGON);
    glVertex3d(-0.35, 0.3, 0);
    glVertex3d(0.35, 0.3, 0);
    glVertex3d(0.35, 0, 0);
    glVertex3d(-0.35, 0, 0);
    glEnd();
    
    glColor3d(0.16, 0.16, 0.16);
    glBegin(GL_POLYGON);
    glVertex3d(0.35, 0, 0);
    glVertex3d(-0.35, 0, 0);
    glVertex3d(-0.3, -0.1, 0);
    glVertex3d(0.4, -0.1, 0);
    glEnd();
    
    
    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Draw Polygon");
    
    glutDisplayFunc(drawHammer);
    glClearColor(1, 1, 1, 1);
    
    glutMainLoop();
    return EXIT_SUCCESS;
}

*/
