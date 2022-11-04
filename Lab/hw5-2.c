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

int draw = 0, initX, initY;

void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(0, 0.5, 1);
    glutWireCube(0.5);
    glutSwapBuffers();
}

void mouseSpin(int button, int state, int x, int y) {
    if(state == GLUT_DOWN) {
        initX = x;
        initY = y;
        draw = 1;
    } else {
        draw = 0;
    }
}

void mouseSpinMotion(int x, int y) {
    if(draw == 1) {
        glRotatef(x - initX, 1, 0, 0);
        glRotatef(y - initY, 0, 1, 0);
        glutPostRedisplay();
    }
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(500,500);
    
    glutCreateWindow("Mouse Spin");
    
    glClearColor(0, 0, 0, 1);
    glutDisplayFunc(renderScene);
    
    glutMouseFunc(mouseSpin);
    glutMotionFunc(mouseSpinMotion);
    
    glutMainLoop();

    return 1;
}
 


*/
